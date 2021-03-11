#include "ClassSchedule.h"
#include "mainFrame.h"

#include <wx/wxprec.h>
#include <wx/valnum.h>
#include <wx/timectrl.h>
#include <fstream>
#include <string>

enum
{
	ID_AddEvent = 101,
	ID_ResetEvent = 102,
	ID_ClassScheduleListBox = 111,
	ID_EditEvent = 112,
	ID_DeleteEvent = 113,
	ID_DeleteAllEvent = 114
};

wxBEGIN_EVENT_TABLE(ClassSchedule, wxPanel)
	EVT_BUTTON(ID_AddEvent, ClassSchedule::AddSchedule)
	EVT_BUTTON(ID_EditEvent, ClassSchedule::EditSchedule)
	EVT_BUTTON(ID_ResetEvent, ClassSchedule::ResetField)
	EVT_BUTTON(ID_DeleteEvent, ClassSchedule::DeleteSchedule)
	EVT_BUTTON(ID_DeleteAllEvent, ClassSchedule::DeleteAllSchedule)
	EVT_LISTBOX(ID_ClassScheduleListBox, ClassSchedule::UpdateListSelection)
	EVT_LISTBOX_DCLICK(ID_ClassScheduleListBox, ClassSchedule::SetItemOnSelect)
wxEND_EVENT_TABLE()


ClassSchedule::ClassSchedule(wxWindow* Parent) : wxPanel(Parent, wxID_ANY, wxPoint(0,0), wxSize(500,600))
{
	SetTextStyle();
	wxIntegerValidator<int> DigitValidator;
	//SubjectID
	SubjectIDLabel = new wxStaticText(this, wxID_ANY,
		"Subject ID",
		wxPoint(20, 10));
	SubjectIDLabel->SetFont(Header2);
	SubjectIDTextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(20, 25), wxSize(60, 25), 0,
		wxTextValidator(wxFILTER_DIGITS));
	SubjectIDTextCtrl->SetFont(TextCtrl1);
	//SubjectName
	SubjectNameLabel = new wxStaticText(this, wxID_ANY,
		"Subject name",
		wxPoint(90, 10));
	SubjectNameLabel->SetFont(Header2);
	SubjectNameTextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(90, 25), wxSize(200, 25));
	SubjectNameTextCtrl->SetFont(TextCtrl2);
	//Location
	LocationLabel = new wxStaticText(this, wxID_ANY,
		"Location",
		wxPoint(300, 10));
	LocationLabel->SetFont(Header2);
	LocationtextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(300, 25), wxSize(150, 25));
	LocationtextCtrl->SetFont(TextCtrl2);
	//StartTime
	StartTimeLabel = new wxStaticText(this, wxID_ANY,
		"Start time",
		wxPoint(20, 50));
	StartTimeLabel->SetFont(Header2);
	StartTimePicker = new wxTimePickerCtrl(this, wxID_ANY,
		wxDateTime(0, 0, 0, 0),
		wxPoint(20, 65), wxSize(85, 25));
	StartTimePicker->SetTime(0, 0, 0);
	StartTimePicker->SetFont(TextCtrl2);
	//EndTime
	EndTimeLabel = new wxStaticText(this, wxID_ANY,
		"End time",
		wxPoint(110, 50));
	EndTimeLabel->SetFont(Header2);
	EndTimePicker = new wxTimePickerCtrl(this, wxID_ANY,
		wxDateTime(0, 0, 0, 0),
		wxPoint(110, 65), wxSize(85, 25));
	EndTimePicker->SetTime(0, 0, 0);
	EndTimePicker->SetFont(TextCtrl2);
	//Day
	DayLabel = new wxStaticText(this, wxID_ANY,
		"Day",
		wxPoint(200, 50));
	DayLabel->SetFont(Header2);
	MonCheckmark = new wxCheckBox(this, wxID_ANY,
		"Monday",
		wxPoint(200, 65));
	MonCheckmark->SetFont(TextCtrl2);
	TueCheckmark = new wxCheckBox(this, wxID_ANY,
		"Tuesday",
		wxPoint(200, 80));
	TueCheckmark->SetFont(TextCtrl2);
	WedCheckmark = new wxCheckBox(this, wxID_ANY,
		"Wednesday",
		wxPoint(270, 65));
	WedCheckmark->SetFont(TextCtrl2);
	ThuCheckmark = new wxCheckBox(this, wxID_ANY,
		"Thursday",
		wxPoint(270, 80));
	ThuCheckmark->SetFont(TextCtrl2);
	FriCheckmark = new wxCheckBox(this, wxID_ANY,
		"Friday",
		wxPoint(360, 72));
	FriCheckmark->SetFont(TextCtrl2);
	SatCheckmark = new wxCheckBox(this, wxID_ANY,
		"Saturday",
		wxPoint(420, 65));
	SatCheckmark->SetFont(TextCtrl2);
	SunCheckmark = new wxCheckBox(this, wxID_ANY,
		"Sunday",
		wxPoint(420, 80));
	SunCheckmark->SetFont(TextCtrl2);


	// debug code
	//debug = new wxTextCtrl(this, wxID_ANY, "", wxPoint(20, 180), wxSize(500, 80), wxTE_MULTILINE);
	//dbutton = new wxButton(this, 1, "CLICK", wxPoint(20, 260));

	//Buttons
	AddButton = new wxButton(this, ID_AddEvent,
		"Add",
		wxPoint(20, 110), wxSize(85, 25));
	EditButton = new wxButton(this, ID_EditEvent,
		"Edit Selected",
		wxPoint(120, 110), wxSize(85, 25));
	EditButton->Enable(false);
	ResetButton = new wxButton(this, ID_ResetEvent,
		"Reset all field",
		wxPoint(230, 110), wxSize(100, 25));
	DeleteButton = new wxButton(this, ID_DeleteEvent,
		"Delete Selected",
		wxPoint(20, 355), wxSize(85, 25));
	DeleteButton->Enable(false);
	DeleteAllButton = new wxButton(this, ID_DeleteAllEvent,
		"Delete All",
		wxPoint(120, 355), wxSize(85, 25));
	//Lists
	ClassScheduleLists = new wxListBox(this, ID_ClassScheduleListBox,
		wxPoint(20, 140), wxSize(450, 200), 0, NULL, wxLB_SINGLE | wxLB_HSCROLL);
}

void ClassSchedule::SetTextStyle()
{
	Header1 = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	Header2 = wxFont(7, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	TextCtrl1 = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	TextCtrl2 = wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
}

void ClassSchedule::ResetField(wxCommandEvent& event)
{
	//Information
	SubjectIDTextCtrl->SetValue("");
	SubjectNameTextCtrl->SetValue("");
	LocationtextCtrl->SetValue("");
	//Time
	StartTimePicker->SetTime(0,0,0);
	EndTimePicker->SetTime(0,0,0);
	//Day
	MonCheckmark->SetValue(false);
	TueCheckmark->SetValue(false);
	WedCheckmark->SetValue(false);
	ThuCheckmark->SetValue(false);
	FriCheckmark->SetValue(false);
	SatCheckmark->SetValue(false);
	SunCheckmark->SetValue(false);
	event.Skip();
}

void ClassSchedule::updateEvent(ical::event &EVENT) {
	int StartHr, StartMin, StartSec;
	int EndHr, EndMin, EndSec;
	unsigned int dayBinary =
		 MonCheckmark->GetValue() +
		 TueCheckmark->GetValue() * 2 +
		 WedCheckmark->GetValue() * 4 + 
		 ThuCheckmark->GetValue() * 8 + 
		 FriCheckmark->GetValue() * 16 + 
		 SatCheckmark->GetValue() * 32 + 
		 SunCheckmark->GetValue() * 64;
	
	//Get schedule time.
	StartTimePicker->GetTime(&StartHr, &StartMin, &StartSec);
	EndTimePicker->GetTime(&EndHr, &EndMin, &EndSec);
	 
	EVENT.subjectID = std::string((SubjectIDTextCtrl->GetLineText(0).mb_str()));
	EVENT.subjectName = std::string((SubjectNameTextCtrl->GetLineText(0)).mb_str());
	EVENT.location = std::string((LocationtextCtrl->GetLineText(0)).mb_str()); 

	EVENT.dayBinary = dayBinary;
	EVENT.day = ical::checkbyday(dayBinary);

	EVENT.DTstart = ical::checkDT(StartHr, StartMin, StartSec);
	EVENT.DTend = ical::checkDT(EndHr, EndMin, EndSec);
}

void ClassSchedule::AddSchedule(wxCommandEvent& event) {
	// this is some advance shit that deal with polymorphism , and get data from derived class from base class ( GetParent() )
	mainFrame* m_parent = dynamic_cast<mainFrame*>(GetParent());
	// update event obj
	updateEvent(m_parent->EVENT);
	// append copy of event obj to list
	m_parent->listSchedule.push_back(m_parent->EVENT);

	// debug code
	/*
	wxStreamToTextRedirector redirect(debug);
	std::cout << m_parent->listSchedule.size();
	*/

	// render 
	ClassScheduleLists->Append(renderSchedule(m_parent->EVENT));
	ClassScheduleLists->SetSelection(ClassScheduleLists->GetCount() - 1);
	EditButton->Enable(true);
	DeleteButton->Enable(true);
	event.Skip();
}

void ClassSchedule::EditSchedule(wxCommandEvent& event) {
	// this is some advance shit that deal with polymorphism , and get data from derived class from base class ( GetParent() )
	mainFrame* m_parent = dynamic_cast<mainFrame*>(GetParent());
	
	// modified event of list at selected index to event obj.
	int i = ClassScheduleLists->GetSelection();
	updateEvent(m_parent->listSchedule[i]);

	// render 
	ClassScheduleLists->SetString(i, renderSchedule(m_parent->listSchedule[i]));

	event.Skip();
}
void ClassSchedule::DeleteSchedule(wxCommandEvent& event) {
	mainFrame* m_parent = dynamic_cast<mainFrame*>(GetParent());
	int i = ClassScheduleLists->GetSelection();
	m_parent->listSchedule.erase(m_parent->listSchedule.begin() + i);
	ClassScheduleLists->Delete(i);
	event.Skip();
}
void ClassSchedule::DeleteAllSchedule(wxCommandEvent& event) {
	DeleteAllConfirmDialog = new wxMessageDialog(this,
		"Are you sure you want to delete all schedule?\nThis will delete all schedule.",
		"Confirm",
		wxYES_NO | wxNO_DEFAULT | wxCENTRE | wxICON_QUESTION);
	if (DeleteAllConfirmDialog->ShowModal() == wxID_NO) {event.Skip(); return;}
	mainFrame* m_parent = dynamic_cast<mainFrame*>(GetParent());
	m_parent->listSchedule.clear();
	ClassScheduleLists->Clear();
	EditButton->Enable(false);
	DeleteButton->Enable(false);
	event.Skip();
}

// Enable edit button after select an item on the list.
void ClassSchedule::UpdateListSelection(wxCommandEvent& event) {
	EditButton->Enable(true);
	DeleteButton->Enable(true);
	event.Skip();
}
void ClassSchedule::SetItemOnSelect(wxCommandEvent& event) {
	// update info on all textctrl
	mainFrame* m_parent = dynamic_cast<mainFrame*>(GetParent());
	int i = ClassScheduleLists->GetSelection();
	ical::event ev = m_parent->listSchedule[i];
	//Information
	SubjectIDTextCtrl->SetValue(ev.subjectID);
	SubjectNameTextCtrl->SetValue(ev.subjectName);
	LocationtextCtrl->SetValue(ev.location);
	//Time
	StartTimePicker->SetTime(std::stoi(ev.DTstart.substr(9, 2)), std::stoi(ev.DTstart.substr(11, 2)), std::stoi(ev.DTstart.substr(13, 2)));
	EndTimePicker->SetTime(std::stoi(ev.DTend.substr(9, 2)), std::stoi(ev.DTend.substr(11, 2)), std::stoi(ev.DTend.substr(13, 2)));
	//Day
	MonCheckmark->SetValue(ical::checkbyday(ev.dayBinary, 0));
	TueCheckmark->SetValue(ical::checkbyday(ev.dayBinary, 1));
	WedCheckmark->SetValue(ical::checkbyday(ev.dayBinary, 2));
	ThuCheckmark->SetValue(ical::checkbyday(ev.dayBinary, 3));
	FriCheckmark->SetValue(ical::checkbyday(ev.dayBinary, 4));
	SatCheckmark->SetValue(ical::checkbyday(ev.dayBinary, 5));
	SunCheckmark->SetValue(ical::checkbyday(ev.dayBinary, 6));
	
	event.Skip();
}

wxString ClassSchedule::renderSchedule(ical::event EVENT) {
	wxString temp;

	// can make this more beautiful
	if (EVENT.day != "") {
		temp = "[" + EVENT.subjectID + " " + EVENT.subjectName + "] - " + EVENT.location + " " + EVENT.day + " [" + EVENT.get_startTime() + " - " + EVENT.get_endTime() + "]";
	}
	else temp = "[" + EVENT.subjectID + " " + EVENT.subjectName + "] - " + EVENT.location + "" + EVENT.day + "[" + EVENT.get_startTime() + " - " + EVENT.get_endTime() + "]";

	return temp;
}

void ClassSchedule::renderData() {
	mainFrame* m_parent = dynamic_cast<mainFrame*>(GetParent());

	ClassScheduleLists->Clear();
	for (size_t i = 0; i < m_parent->listSchedule.size(); i++) {
		ClassScheduleLists->Append(renderSchedule(m_parent->listSchedule[i]));
	}
}
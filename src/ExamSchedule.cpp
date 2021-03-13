#include "ExamSchedule.h"
#include <wx/timectrl.h>
#include <fstream>
#include <string>
#include <wx/valnum.h>
#include <wx/wxprec.h>

enum
{
	ID_AddEvent = 101,
	ID_ResetEvent = 102,
	ID_ClassScheduleListBox = 111,
	ID_EditEvent = 112,
	ID_DeleteEvent = 113,
	ID_DeleteAllEvent = 114
};

wxBEGIN_EVENT_TABLE(ExamSchedule, wxPanel)
EVT_BUTTON(ID_AddEvent, ExamSchedule::AddSchedule)
wxEND_EVENT_TABLE()


ExamSchedule::ExamSchedule(wxWindow* Parent) : wxPanel(Parent, wxID_ANY, wxPoint(0, 0), wxSize(500, 600))
{	
	//midterm exam
	SetStyle();
	wxIntegerValidator<int>digitvalidator;
	//SubjectID
	SubjectIDLabel = new wxStaticText(this, wxID_ANY,
		"Subject ID",
		wxPoint(100, 10));
	SubjectIDLabel->SetFont(Header2);
	SubjectIDTextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(100, 25), wxSize(60, 25), 0,
		wxTextValidator(wxFILTER_DIGITS));
	SubjectIDTextCtrl->SetFont(TextCtrl1);
	//SubjectName
	SubjectNameLabel = new wxStaticText(this, wxID_ANY,
		"Subject name",
		wxPoint(170, 10));
	SubjectNameLabel->SetFont(Header2);
	SubjectNameTextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(170, 25), wxSize(200, 25));
	SubjectNameTextCtrl->SetFont(TextCtrl2);
	//Location
	LocationLabel = new wxStaticText(this, wxID_ANY,
		"Location",
		wxPoint(380, 10));
	LocationLabel->SetFont(Header2);
	LocationtextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(380, 25), wxSize(150, 25));
	LocationtextCtrl->SetFont(TextCtrl2);
	//Note
	Note = new wxStaticText(this, wxID_ANY,
		"Note",
		wxPoint(540, 10));
	Note->SetFont(Header2);
	NoteNameTextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(540, 25), wxSize(250, 25),
		wxTE_MULTILINE);
	NoteNameTextCtrl->SetFont(TextCtrl2);


	//StartTime
	StartTimeLabel = new wxStaticText(this, wxID_ANY,
		"Start time",
		wxPoint(100, 50));
	StartTimeLabel->SetFont(Header2);
	StartTimePicker = new wxTimePickerCtrl(this, wxID_ANY,
		wxDateTime(0, 0, 0, 0),
		wxPoint(100, 65), wxSize(85, 25));
	StartTimePicker->SetFont(TextCtrl2);
	//EndTime
	EndTimeLabel = new wxStaticText(this, wxID_ANY,
		"End time",
		wxPoint(190, 50));
	EndTimeLabel->SetFont(Header2);
	EndTimePicker = new wxTimePickerCtrl(this, wxID_ANY,
		wxDateTime(0, 0, 0, 0),
		wxPoint(200, 65), wxSize(85, 25));
	EndTimePicker->SetFont(TextCtrl2);
	//SelectionDate
	SelectionLable = new wxStaticText(this, wxID_ANY,
		"Select M/D/Y",
		wxPoint(380, 50));
	SelectionLable->SetFont(Header2);
	SelectDate = new wxDatePickerCtrl(this, wxID_ANY,
		wxDefaultDateTime,
		wxPoint(380, 65),
		wxSize (85, 25),
		wxDP_DROPDOWN);
	//buttons
	AddButton = new wxButton(this, ID_AddEvent,
		"Add",
		wxPoint(100, 110), wxSize(85, 25));
	EditButton = new wxButton(this, ID_EditEvent,
		"Edit Selected",
		wxPoint(200, 110), wxSize(85, 25));
	EditButton->Enable(false);
	ResetButton = new wxButton(this, ID_ResetEvent,
		"Reset all field",
		wxPoint(310, 110), wxSize(100, 25));
	DeleteButton = new wxButton(this, ID_DeleteEvent,
		"Delete Selected",
		wxPoint(100, 355), wxSize(85, 25));
	DeleteButton->Enable(false);
	DeleteAllButton = new wxButton(this, ID_DeleteAllEvent,
		"Delete All",
		wxPoint(200, 355), wxSize(85, 25));
	//Lists
	ExamScheduleLists = new wxListBox(this, ID_ClassScheduleListBox,
		wxPoint(100, 140), wxSize(450, 200), 0, NULL, wxLB_SINGLE | wxLB_HSCROLL);



	//final exam
	
	//SubjectID
	SubjectIDLabel = new wxStaticText(this, wxID_ANY,
		"Subject ID",
		wxPoint(100, 390));
	SubjectIDLabel->SetFont(Header2);
	SubjectIDTextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(100, 405), wxSize(60, 25), 0,
		wxTextValidator(wxFILTER_DIGITS));
	SubjectIDTextCtrl->SetFont(TextCtrl1);
	//SubjectName
	SubjectNameLabel = new wxStaticText(this, wxID_ANY,
		"Subject name",
		wxPoint(170, 390));
	SubjectNameLabel->SetFont(Header2);
	SubjectNameTextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(170, 405), wxSize(200, 25));
	SubjectNameTextCtrl->SetFont(TextCtrl2);
	//Location
	LocationLabel = new wxStaticText(this, wxID_ANY,
		"Location",
		wxPoint(380, 390));
	LocationLabel->SetFont(Header2);
	LocationtextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(380, 405), wxSize(150, 25));
	LocationtextCtrl->SetFont(TextCtrl2);
	//Note
	Note = new wxStaticText(this, wxID_ANY,
		"Note",
		wxPoint(540, 390));
	Note->SetFont(Header2);
	NoteNameTextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(540, 405), wxSize(250, 25),
		wxTE_MULTILINE);
	NoteNameTextCtrl->SetFont(TextCtrl2);


	//StartTime
	StartTimeLabel = new wxStaticText(this, wxID_ANY,
		"Start time",
		wxPoint(100, 430));
	StartTimeLabel->SetFont(Header2);
	StartTimePicker = new wxTimePickerCtrl(this, wxID_ANY,
		wxDateTime(0, 0, 0, 0),
		wxPoint(100, 445), wxSize(85, 25));
	StartTimePicker->SetFont(TextCtrl2);
	//EndTime
	EndTimeLabel = new wxStaticText(this, wxID_ANY,
		"End time",
		wxPoint(190, 430));
	EndTimeLabel->SetFont(Header2);
	EndTimePicker = new wxTimePickerCtrl(this, wxID_ANY,
		wxDateTime(0, 0, 0, 0),
		wxPoint(200, 445), wxSize(85, 25));
	EndTimePicker->SetFont(TextCtrl2);
	//SelectionDate
	SelectionLable = new wxStaticText(this, wxID_ANY,
		"Select M/D/Y",
		wxPoint(380, 430));
	SelectionLable->SetFont(Header2);
	SelectDate = new wxDatePickerCtrl(this, wxID_ANY,
		wxDefaultDateTime,
		wxPoint(380, 445),
		wxSize (85, 25),
		wxDP_DROPDOWN);
	//buttons
	AddButton = new wxButton(this, ID_AddEvent,
		"Add",
		wxPoint(100, 490), wxSize(85, 25));
	EditButton = new wxButton(this, ID_EditEvent,
		"Edit Selected",
		wxPoint(200, 490), wxSize(85, 25));
	EditButton->Enable(false);
	ResetButton = new wxButton(this, ID_ResetEvent,
		"Reset all field",
		wxPoint(310, 490), wxSize(100, 25));
	DeleteButton = new wxButton(this, ID_DeleteEvent,
		"Delete Selected",
		wxPoint(100, 735), wxSize(85, 25));
	DeleteButton->Enable(false);
	DeleteAllButton = new wxButton(this, ID_DeleteAllEvent,
		"Delete All",
		wxPoint(200, 735), wxSize(85, 25));
	//Lists
	ExamScheduleLists = new wxListBox(this, ID_ClassScheduleListBox,
		wxPoint(100, 520), wxSize(450, 200), 0, NULL, wxLB_SINGLE | wxLB_HSCROLL);

	//Combobox
	wxString InitChoices[2] = {"Midterm", "Final"};
	PeriodSelection = new wxComboBox(this, wxID_ANY,
									 "Midterm", wxPoint(10, 20), wxSize(30, 60),
									 2, InitChoices,
									 wxCB_READONLY); //Try?
}


void ExamSchedule::updateEvent(ical::event event) {
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

	event.untillD = "20210228T000000Z";

	event.subjectName = std::string((SubjectNameTextCtrl->GetLineText(0)).mb_str());
	event.subjectID = std::string((SubjectIDTextCtrl->GetLineText(0).mb_str()));
	event.location = std::string((LocationtextCtrl->GetLineText(0)).mb_str());

	event.dayBinary = dayBinary;
	event.day = ical::checkbyday(dayBinary);

	event.DTstart = ical::checkDT(StartHr, StartMin, StartSec);
	event.DTend = ical::checkDT(EndHr, EndMin, EndSec);
}
	

void ExamSchedule::SetStyle()
{
	Header1 = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	Header2 = wxFont(7, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	TextCtrl1 = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	TextCtrl2 = wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
}

void ExamSchedule::AddSchedule(wxCommandEvent& event)
{
	// update event obj
	ExamSchedule::updateEvent(this->EVENT);
	// append copy of event obj to list
	this->listSchedule.push_back(this->EVENT);

	event.Skip();
}
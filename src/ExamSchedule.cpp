#include "ExamSchedule.h"
#include <wx/timectrl.h>
#include <fstream>
#include <string>
#include <wx/valnum.h>
#include <wx/wxprec.h>

#include "mainFrame.h"

enum
{
	ID_AddEvent = 101,
	ID_ResetEvent = 102,
	ID_ClassScheduleListBox = 111,
	ID_EditEvent = 112,
	ID_DeleteEvent = 113,
	ID_DeleteAllEvent = 114,
	ID_DeleteAllEvent2 = 69,
	ID_midtermListbox = 115,
	ID_finalListbox = 116
};

wxBEGIN_EVENT_TABLE(ExamSchedule, wxPanel)
	EVT_BUTTON(ID_AddEvent, ExamSchedule::AddSchedule)
	EVT_BUTTON(ID_EditEvent, ExamSchedule::EditSchedule)
	EVT_BUTTON(ID_DeleteEvent, ExamSchedule::DeleteSchedule)
	EVT_BUTTON(ID_DeleteAllEvent, ExamSchedule::DeleteAllSchedule)
	EVT_BUTTON(ID_ResetEvent, ExamSchedule::ResetField)
	EVT_LISTBOX(ID_midtermListbox, ExamSchedule::OnC_midterm)
	EVT_LISTBOX(ID_finalListbox, ExamSchedule::OnC_final)
wxEND_EVENT_TABLE()


ExamSchedule::ExamSchedule(wxWindow* Parent) : wxPanel(Parent, wxID_ANY, wxPoint(0, 0), wxSize(500, 600))
{	
	SetStyle();
	wxIntegerValidator<int> digitvalidator;
	//Period Selection
	wxString InitChoices[2] = { "Midterm", "Final" };
	PeriodSelection = new wxComboBox(this, wxID_ANY,
		"Midterm", wxPoint(10, 20), wxSize(80, 25),
		2, InitChoices,
		wxCB_READONLY);
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
		wxPoint(450, 110), wxSize(85, 25));
	DeleteButton->Enable(false);
	DeleteAllButton = new wxButton(this, ID_DeleteAllEvent,
		"Delete All",
		wxPoint(100, 500), wxSize(85, 25));
	DeleteAllButton->Enable(false);

		DeleteAllButtonTwo = new wxButton(this, ID_DeleteAllEvent2,
		"Delete All",
		wxPoint(450,500),
		wxSize(85,25));
	DeleteAllButtonTwo->Enable(false);
	

	//Lists
	MidtermExamScheduleLists = new wxListBox(this, ID_midtermListbox,
		wxPoint(100, 140), wxSize(250, 350), 0, NULL, wxLB_SINGLE | wxLB_HSCROLL);
	FinalExamScheduleLists = new wxListBox(this, ID_finalListbox,
		wxPoint(450, 140), wxSize(250, 350), 0, NULL, wxLB_SINGLE | wxLB_HSCROLL);

	
}

void ExamSchedule::SetStyle()
{
	Header1 = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	Header2 = wxFont(7, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	TextCtrl1 = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	TextCtrl2 = wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
}

void ExamSchedule::updateEvent(ical::event &EVENT) 
{
	int StartHr, StartMin, StartSec;
	int EndHr, EndMin, EndSec;
	//Get schedule time.
	StartTimePicker->GetTime(&StartHr, &StartMin, &StartSec);
	EndTimePicker->GetTime(&EndHr, &EndMin, &EndSec);	

	wxDateTime date = SelectDate->GetValue();

	EVENT.set_D(date.FormatISODate().ToStdString());
	EVENT.subjectID = SubjectIDTextCtrl->GetLineText(0).mb_str();
	EVENT.subjectName = SubjectNameTextCtrl->GetLineText(0).mb_str();
	EVENT.location = std::string((LocationtextCtrl->GetLineText(0)).mb_str()); 
	EVENT.DTstart = ical::checkDT(StartHr, StartMin, StartSec);
	EVENT.DTend = ical::checkDT(EndHr, EndMin, EndSec);
	EVENT.note = NoteNameTextCtrl->GetLineText(0).mb_str();
}

void ExamSchedule::AddSchedule(wxCommandEvent& event) 
{
	updateEvent(EVENT);

	wxString p_select = PeriodSelection->GetStringSelection();
	mainFrame* m_parent = dynamic_cast<mainFrame*>(GetParent());
	if (p_select == "Midterm") {
		m_parent->midtermExam.push_back(EVENT);
		MidtermExamScheduleLists->Append(renderSchedule(EVENT));
	}
	if (p_select == "Final") {
		m_parent->finalExam.push_back(EVENT);
		FinalExamScheduleLists->Append(renderSchedule(EVENT));
	}

	EditButton->Enable(true);
	DeleteButton->Enable(true);
	DeleteAllButton->Enable(true);
	event.Skip();
}

std::string ExamSchedule::renderSchedule(ical::event EVENT) 
{
	std::string temp;
	temp = EVENT.subjectID + "  " + EVENT.subjectName + "  " + EVENT.location + "  " + EVENT.startD + "  " + EVENT.get_startTime() + "  " + EVENT.get_endTime() + " " + EVENT.note;
	return temp;
}

void ExamSchedule::renderData() 
{
	mainFrame* m_parent = dynamic_cast<mainFrame*>(GetParent());

	MidtermExamScheduleLists->Clear();
	FinalExamScheduleLists->Clear();
	
	for (size_t i = 0; i < m_parent->midtermExam.size(); i++) {
		MidtermExamScheduleLists->Append(renderSchedule(m_parent->midtermExam[i]));
	}
	for (size_t i = 0; i < m_parent->finalExam.size(); i++) {
		FinalExamScheduleLists->Append(renderSchedule(m_parent->finalExam[i]));
	}
}

void ExamSchedule::EditSchedule(wxCommandEvent& event) 
{
	wxString p_select = PeriodSelection->GetStringSelection();
	mainFrame* m_parent = dynamic_cast<mainFrame*>(GetParent());
	if (p_select == "Midterm") {
		int i = MidtermExamScheduleLists->GetSelection();
		updateEvent(m_parent->midtermExam[i]);
		MidtermExamScheduleLists->SetString(i, renderSchedule(m_parent->midtermExam[i]));
	}
	if (p_select == "Final") {
		int i = FinalExamScheduleLists->GetSelection();
		updateEvent(m_parent->finalExam[i]);
		FinalExamScheduleLists->SetString(i, renderSchedule(m_parent->finalExam[i]));
	}
	event.Skip();
}

void ExamSchedule::OnC_midterm(wxCommandEvent& event) 
{
	int i = FinalExamScheduleLists->GetSelection();
	FinalExamScheduleLists->Deselect(i);
	s_state = 1;
}

void ExamSchedule::OnC_final(wxCommandEvent& event) 
{
	int i = MidtermExamScheduleLists->GetSelection();
	MidtermExamScheduleLists->Deselect(i);
	s_state = 2;
}

void ExamSchedule::DeleteSchedule(wxCommandEvent& event)
{
	mainFrame* m_parent = dynamic_cast<mainFrame*>(GetParent());
	if (s_state == 1) {
		int m = MidtermExamScheduleLists->GetSelection();
		m_parent->midtermExam.erase(m_parent->midtermExam.begin() + m);
		MidtermExamScheduleLists->Delete(m);
	}
	if (s_state == 2) {
		int f = FinalExamScheduleLists->GetSelection();
		m_parent->finalExam.erase(m_parent->finalExam.begin() + f);
		FinalExamScheduleLists->Delete(f);
	}

	if (m_parent->midtermExam.size() == 0 || m_parent->finalExam.size() == 0) {
		EditButton->Enable(false);
		DeleteButton->Enable(false);
		DeleteAllButton->Enable(false);
	}

	event.Skip();
}

void ExamSchedule::DeleteAllSchedule(wxCommandEvent& event) {
	if (wxMessageBox("This will delete all exam schedule, Are you sure?", "Confirm", wxICON_QUESTION|wxYES_NO) != wxYES) {
		event.Skip();
		return;
	}
	mainFrame* m_parent = dynamic_cast<mainFrame*>(GetParent());

	m_parent->midtermExam.clear();
	m_parent->finalExam.clear();
	MidtermExamScheduleLists->Clear();
	FinalExamScheduleLists->Clear();

	EditButton->Enable(false);
	DeleteButton->Enable(false);
	DeleteAllButton->Enable(false);
	event.Skip();
}

void ExamSchedule::ResetField(wxCommandEvent& event)
{
	SubjectIDTextCtrl->SetValue("");
	SubjectNameTextCtrl->SetValue("");
	LocationtextCtrl->SetValue("");
	NoteNameTextCtrl->SetValue("");

	StartTimePicker->SetTime(0,0,0);
	EndTimePicker->SetTime(0,0,0);

	event.Skip();
}
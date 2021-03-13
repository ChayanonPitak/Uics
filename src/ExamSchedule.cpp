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



ExamSchedule::ExamSchedule(wxWindow* Parent) : wxPanel(Parent, wxID_ANY, wxPoint(0, 0), wxSize(500, 600))
{	
	SetStyle();
	wxIntegerValidator<int>digitvalidator;
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
		wxPoint(100, 355), wxSize(85, 25));
	DeleteButton->Enable(false);
	DeleteAllButton = new wxButton(this, ID_DeleteAllEvent,
		"Delete All",
		wxPoint(200, 355), wxSize(85, 25));

	//Lists
	MidtermExamScheduleLists = new wxListBox(this, ID_ClassScheduleListBox,
		wxPoint(100, 140), wxSize(250, 350), 0, NULL, wxLB_SINGLE | wxLB_HSCROLL);
	FinalExamScheduleLists = new wxListBox(this, ID_ClassScheduleListBox,
		wxPoint(375, 140), wxSize(250, 350), 0, NULL, wxLB_SINGLE | wxLB_HSCROLL);
}
void ExamSchedule::SetStyle()
{
	Header1 = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	Header2 = wxFont(7, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	TextCtrl1 = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	TextCtrl2 = wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
}
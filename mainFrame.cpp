#include "mainFrame.h"
#include "cal.h"

#include <wx/wxprec.h>
#include <wx/valnum.h>
#include <wx/timectrl.h>
#include <wx/datectrl.h>
#include <fstream>
#include <string>

enum
{
	ID_New = 2,
	ID_AddEvent = 11,
};

wxBEGIN_EVENT_TABLE(mainFrame, wxFrame)
	EVT_MENU(ID_New, mainFrame::OnNew)
	EVT_MENU(wxID_ABOUT, mainFrame::OnAbout)
	EVT_MENU(wxID_EXIT, mainFrame::OnExit)
	EVT_BUTTON(ID_AddEvent, mainFrame::AddSchedule)
wxEND_EVENT_TABLE()

mainFrame::mainFrame() : wxFrame(NULL, wxID_ANY, "Uics", wxPoint(100, 100), wxSize(750, 500))
{
	SetTextStyle();
	//File
	FileMenu = new wxMenu;		//Menu - File
	FileMenu->Append(ID_New,		//New
		"New\t Alt+F4",
		"Create new schedule.");
	FileMenu->AppendSeparator();
	FileMenu->Append(wxID_EXIT,		//Exit
		"Exit",
		"Get out of here.");

	HelpMenu = new wxMenu;		//Menu - Help
	HelpMenu->Append(wxID_ABOUT,
		"About",
		"About this software.");

	menuBar = new wxMenuBar;	//MenuBar
	menuBar->Append(FileMenu, "File");
	menuBar->Append(HelpMenu, "Help");
	SetMenuBar(menuBar);

	CreateStatusBar();
	SetStatusText("");
}

void mainFrame::SetTextStyle()
{
	Header1 = new wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	Header2 = new wxFont(7, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	TextCtrl1 = new wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	TextCtrl2 = new wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
}

void mainFrame::OnNew(wxCommandEvent& evt)
{
	wxIntegerValidator<int> DigitValidator;
	//Header
	AddClassScheduleHeader = new wxStaticText(this, wxID_ANY,
		"Add class schedule",
		wxPoint(10, 10));
	AddClassScheduleHeader->SetFont(*Header1);
	//SubjectID
	SubjectIDLabel = new wxStaticText(this, wxID_ANY,
		"Subject ID",
		wxPoint(20, 35));
	SubjectIDLabel->SetFont(*Header2);
	SubjectIDTextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(20, 50), wxSize(60, 25), 0,
		wxTextValidator(wxFILTER_DIGITS));
	SubjectIDTextCtrl->SetFont(*TextCtrl1);
	//SubjectName
	SubjectNameLabel = new wxStaticText(this, wxID_ANY,
		"Subject name",
		wxPoint(90, 35));
	SubjectNameLabel->SetFont(*Header2);
	SubjectNameTextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(90, 50), wxSize(200, 25));
	SubjectNameTextCtrl->SetFont(*TextCtrl2);
	//Location
	LocationLabel = new wxStaticText(this, wxID_ANY,
		"Location",
		wxPoint(300, 35));
	LocationLabel->SetFont(*Header2);
	LocationtextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(300, 50), wxSize(150, 25));
	LocationtextCtrl->SetFont(*TextCtrl2);
	//StartTime
	StartTimeLabel = new wxStaticText(this, wxID_ANY,
		"Start time",
		wxPoint(20, 75));
	StartTimeLabel->SetFont(*Header2);
	StartTimePicker = new wxTimePickerCtrl(this, wxID_ANY,
		wxDateTime(0,0,0,0),
		wxPoint(20, 90), wxSize(85, 25));
	StartTimePicker->SetFont(*TextCtrl2);
	//EndTime
	EndTimeLabel = new wxStaticText(this, wxID_ANY,
		"End time",
		wxPoint(110, 75));
	EndTimeLabel->SetFont(*Header2);
	EndTimePicker = new wxTimePickerCtrl(this, wxID_ANY,
		wxDateTime(0, 0, 0, 0),
		wxPoint(110, 90), wxSize(85, 25));
	EndTimePicker->SetFont(*TextCtrl2);
	//Day
	DayLabel = new wxStaticText(this, wxID_ANY,
		"Day",
		wxPoint(200, 75));
	DayLabel->SetFont(*Header2);
	MonCheckmark = new wxCheckBox(this, wxID_ANY,
		"Monday",
		wxPoint(200, 90));
	MonCheckmark->SetFont(*TextCtrl2);
	TueCheckmark = new wxCheckBox(this, wxID_ANY,
		"Tuesday",
		wxPoint(200, 105));
	TueCheckmark->SetFont(*TextCtrl2);
	WedCheckmark = new wxCheckBox(this, wxID_ANY,
		"Wednesday",
		wxPoint(270, 90));
	WedCheckmark->SetFont(*TextCtrl2);
	ThuCheckmark = new wxCheckBox(this, wxID_ANY,
		"Thursday",
		wxPoint(270, 105));
	ThuCheckmark->SetFont(*TextCtrl2);
	FriCheckmark = new wxCheckBox(this, wxID_ANY,
		"Friday",
		wxPoint(360, 97));
	FriCheckmark->SetFont(*TextCtrl2);
	SatCheckmark = new wxCheckBox(this, wxID_ANY,
		"Saturday",
		wxPoint(420, 90));
	SatCheckmark->SetFont(*TextCtrl2);
	SunCheckmark = new wxCheckBox(this, wxID_ANY,
		"Sunday",
		wxPoint(420, 105));
	SunCheckmark->SetFont(*TextCtrl2);
	//Add
	AddButton = new wxButton(this, ID_AddEvent,
		"Export",
		wxPoint(10, 120), wxSize(100, 30));
	AddButton->SetFont(*Header1);
	FileMenu->Enable(ID_New, false);
}

void mainFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("Uics\nMade by Sixtynine",
		"About",
		wxOK | wxCENTRE);
}
void mainFrame::OnExit(wxCommandEvent& event)
{
	int confirmation = wxMessageBox("Are you sure you want to exit?",
		"Exit",
		wxYES_NO | wxNO_DEFAULT);
	if (confirmation == wxYES) Close(true);
}
void mainFrame::AddSchedule(wxCommandEvent& event)
{
	//Initialize the file.
	std::ofstream dest("calendar.ics", std::ios::app);
	//Copy from cal.h no further change now.
	ical::calendar Event;
	Event.calHeader(dest);
	Event.timezone = "Asia/Bangkok";
	Event.weekstop = "SU";
	Event.freq = "WEEKLY";
	Event.untillD = "20210228T000000Z";
	//Get schedule time.
	int StartHr, StartMin, StartSec;
	StartTimePicker->GetTime(&StartHr, &StartMin, &StartSec);
	int EndHr, EndMin, EndSec;
	EndTimePicker->GetTime(&EndHr, &EndMin, &EndSec);
	unsigned int dayBinary =
		MonCheckmark->GetValue() +
		TueCheckmark->GetValue() * 2 +
		WedCheckmark->GetValue() * 4 + 
		ThuCheckmark->GetValue() * 8 + 
		FriCheckmark->GetValue() * 16 + 
		SatCheckmark->GetValue() * 32 + 
		SunCheckmark->GetValue() * 64;
	Event.createEvent(dest,
		std::string((SubjectIDTextCtrl->GetLineText(0)).mb_str()) + " " + std::string((SubjectNameTextCtrl->GetLineText(0)).mb_str()),	//Name
		std::string((LocationtextCtrl->GetLineText(0)).mb_str()),	//location
		dayBinary,	//Day
		StartHr, StartMin, StartSec, EndHr, EndMin, EndSec);	//Time
	//Copy from cal.h no further change now.
	Event.calFooter(dest);
	event.Skip();
}
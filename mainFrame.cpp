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
	SetStatusText("Uics by SixtyNine.");
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
	//StartTime
	StartTimeLabel = new wxStaticText(this, wxID_ANY,
		"Start time",
		wxPoint(300, 35));
	StartTimeLabel->SetFont(*Header2);
	StartTimePicker = new wxTimePickerCtrl(this, wxID_ANY,
		wxDateTime(0,0,0,0),
		wxPoint(300, 50), wxSize(85, 25));
	StartTimePicker->SetFont(*TextCtrl2);
	//EndTime
	EndTimeLabel = new wxStaticText(this, wxID_ANY,
		"End time",
		wxPoint(395, 35));
	EndTimeLabel->SetFont(*Header2);
	EndTimePicker = new wxTimePickerCtrl(this, wxID_ANY,
		wxDateTime(0, 0, 0, 0),
		wxPoint(395, 50), wxSize(85, 25));
	EndTimePicker->SetFont(*TextCtrl2);
	//Location
	LocationLabel = new wxStaticText(this, wxID_ANY,
		"Location",
		wxPoint(490, 35));
	LocationtextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(490, 50), wxSize(150, 25));
	//Add
	AddButton = new wxButton(this, ID_AddEvent,
		"Export",
		wxPoint(10, 90), wxSize(100, 30));
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
	Event.createEvent(dest, 
		std::string((SubjectIDTextCtrl->GetLineText(0)).mb_str()) + " " +std::string((SubjectNameTextCtrl->GetLineText(0)).mb_str()) + "," +
		"TuF" + "," + std::to_string(StartHr) + ":" + std::to_string(StartMin) + "-" + std::to_string(EndHr) + ":" + std::to_string(EndMin) + "," + 
		std::string((LocationtextCtrl->GetLineText(0)).mb_str()));
	//Copy from cal.h no further change now.
	Event.calFooter(dest);
	event.Skip();
}
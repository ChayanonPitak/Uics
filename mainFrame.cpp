#include "mainFrame.h"
#include "cal.h"

#include <wx/wxprec.h>
#include <wx/valnum.h>

enum
{
	//Menu
	ID_New = 2,

	//Add
	ID_AddEvent = 11
};

wxBEGIN_EVENT_TABLE(mainFrame, wxFrame)
	EVT_MENU(ID_New, mainFrame::OnNew)
	EVT_MENU(wxID_ABOUT, mainFrame::OnAbout)
	EVT_MENU(wxID_EXIT, mainFrame::OnExit)
	EVT_BUTTON(ID_AddEvent, mainFrame::ExportSchedule)
wxEND_EVENT_TABLE()

mainFrame::mainFrame() : wxFrame(NULL, wxID_ANY, "Uics", wxPoint(100, 100), wxSize(750, 500))
{
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

void mainFrame::OnNew(wxCommandEvent& evt)
{
	wxIntegerValidator<int> DigitValidator;
	//SubjectID
	SubjectIDLabel = new wxStaticText(this, wxID_ANY,
		"Subject ID",
		wxPoint(10, 10));
	SubjectIDTextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(70, 10), wxSize(60, 30), 0,
		wxTextValidator(wxFILTER_DIGITS));
	//Add
	AddButton = new wxButton(this, ID_AddEvent,
		"Add",
		wxPoint(140, 10), wxSize(50, 30));
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
void mainFrame::ExportSchedule(wxCommandEvent& event)
{
	event.Skip();
}
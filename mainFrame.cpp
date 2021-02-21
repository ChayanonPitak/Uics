#include "mainFrame.h"
#include "ClassSchedule.h"

#include <wx/wxprec.h>
#include <wx/listbook.h>
#include <fstream>
#include <string>

wxBEGIN_EVENT_TABLE(mainFrame, wxFrame)
	EVT_MENU(wxID_ABOUT, mainFrame::OnAbout)
	EVT_MENU(wxID_EXIT, mainFrame::OnExit)
wxEND_EVENT_TABLE()

mainFrame::mainFrame() : wxFrame(NULL, wxID_ANY, "Uics", wxPoint(100, 100), wxSize(750, 500))
{
	//Menu
	FileMenu = new wxMenu;		//Menu - File
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

	//Panel
	ClassSchedulePanel = new ClassSchedule(this);			//ClassSchedule
	

	//Toolbook
	listBook = new wxListbook(this, wxID_ANY, wxPoint(0, 0), wxSize(750, 500), wxLB_TOP);
	listBook->AddPage(ClassSchedulePanel, "Class Schedule"); //ClassSchedule

	CreateStatusBar();
	SetStatusText("");

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
#include "mainFrame.h"
#include "p_About_cpp.h"
#include "Period_cpp.h"
#include "ClassSchedule_cpp.h"
#include "ExamSchedule_cpp.h"
#include <FileManagement_cpp.h>

#include <wx/wxprec.h>
#include <wx/listbook.h>
#include <wx/listctrl.h>
#include <fstream>
#include <string>

wxBEGIN_EVENT_TABLE(mainFrame, wxFrame)
	EVT_MENU(wxID_ABOUT, mainFrame::OnAbout)
	EVT_MENU(wxID_EXIT, mainFrame::OnExit)
wxEND_EVENT_TABLE()

mainFrame::mainFrame() : wxFrame(NULL, wxID_ANY, "Uics", wxPoint(100, 100), wxSize(750, 500))
{
	SetStyle();
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
	PeriodPanel = new Period(this);						//SemesterPeriod
	ClassSchedulePanel = new ClassSchedule(this);		//ClassSchedule
	ExamSchedulePanel = new ExamSchedule(this);			//ExamSchedule
	FileManagementPanel = new FileManagement(this);	//FileManagement
	

	//Listbook
	listBook = new wxListbook(this, wxID_ANY, wxPoint(0, 0), wxSize(750, 500), wxLB_TOP);
	listBook->AddPage(PeriodPanel, "Semester Period");				//SemesterPeriod
	listBook->AddPage(ClassSchedulePanel, "Class Schedule");		//ClassSchedule
	listBook->AddPage(ExamSchedulePanel, "Examination Schedule");	//ExamSchedule
	listBook->AddPage(FileManagementPanel, "File Management");		//ExamSchedule

	CreateStatusBar();
	SetStatusText("");

}

void mainFrame::SetStyle()
{

}
void mainFrame::OnAbout(wxCommandEvent& event)
{
	p_About* aboutFrame = new p_About(this); 
	aboutFrame->Show(true);
}
void mainFrame::OnExit(wxCommandEvent& event)
{
	int confirmation = wxMessageBox("Are you sure you want to exit?",
		"Exit",
		wxYES_NO | wxNO_DEFAULT);
	if (confirmation == wxYES) Close(true);
}
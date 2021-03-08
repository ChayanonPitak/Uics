#include "mainFrame.h"
#include "p_About.h"
#include "Period.h"
#include "ClassSchedule.h"
#include "ExamSchedule.h"
#include <FileManagement.h>

#include <wx/wxprec.h>
#include <wx/listbook.h>
#include <wx/listctrl.h>
#include <fstream>
#include <string>

wxBEGIN_EVENT_TABLE(mainFrame, wxFrame)
	EVT_MENU(wxID_ABOUT, mainFrame::OnAbout)
	EVT_MENU(wxID_EXIT, mainFrame::OnExit)
	EVT_MENU(wxID_OPEN, mainFrame::OnOpen)
	EVT_MENU(wxID_SAVE, mainFrame::OnSave)
	EVT_MENU(wxID_SAVEAS, mainFrame::OnSaveas)
	EVT_MENU(0, mainFrame::OnScan)
wxEND_EVENT_TABLE()

mainFrame::mainFrame() : wxFrame(NULL, wxID_ANY, "Uics", wxPoint(50, 50), wxSize(800, 600), wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER)
{
	SetStyle();
	//Menu
	FileMenu = new wxMenu;		//Menu - File
	FileMenu->Append(wxID_EXIT,		//Exit
		"Exit",
		"Get out of here.");
	FileMenu->Append(wxID_OPEN);
	FileMenu->Append(wxID_SAVE);
	FileMenu->Append(wxID_SAVEAS);

	ToolMenu = new wxMenu;
	ToolMenu->Append(0, "Scan image", "Scan your schedule.");

	HelpMenu = new wxMenu;		//Menu - Help
	HelpMenu->Append(wxID_ABOUT,
		"About",
		"About this software.");

	menuBar = new wxMenuBar;	//MenuBar
	menuBar->Append(FileMenu, "File");
	menuBar->Append(ToolMenu, "Tools");
	menuBar->Append(HelpMenu, "Help");
	SetMenuBar(menuBar);

	//Panel
	PeriodPanel = new Period(this);						//SemesterPeriod
	ClassSchedulePanel = new ClassSchedule(this);		//ClassSchedule
	ExamSchedulePanel = new ExamSchedule(this);			//ExamSchedule
	

	//Listbook
	listBook = new wxListbook(this, wxID_ANY, wxPoint(0, 0), wxSize(800, 600), wxLB_LEFT);
	listBook->AddPage(PeriodPanel, "Semester Period");				//SemesterPeriod
	listBook->AddPage(ClassSchedulePanel, "Class Schedule");		//ClassSchedule
	listBook->AddPage(ExamSchedulePanel, "Examination Schedule");	//ExamSchedule

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

void mainFrame::OnOpen(wxCommandEvent& event) {
	wxFileDialog
		openFileDialog(this, "Open file", "", "", "", wxFD_OPEN|wxFD_FILE_MUST_EXIST);

	if (openFileDialog.ShowModal() == wxID_CANCEL) return;	

	//ical::loadEvent(ClassSchedulePanel->listSchedule, input_stream);
}

void mainFrame::OnSave(wxCommandEvent& event) {
	
}

void mainFrame::OnSaveas(wxCommandEvent& event) {
	// I don't know why wxFD_SAVE make an assertion when trying to call this func.
	wxFileDialog
		saveFileDialog(this, _("Save XYZ file"), "", "icalSave", "");

	if (saveFileDialog.ShowModal() == wxID_CANCEL) return;



	//ical::saveEvent(ClassSchedulePanel->listSchedule, output_stream);
}

void mainFrame::OnScan(wxCommandEvent& event) {
	wxFileDialog
		openFileDialog(this, _("Open Image file"), "", "", "Image (*.tif,*.png)|*.tif;*.png", wxFD_OPEN|wxFD_FILE_MUST_EXIST);

	if (openFileDialog.ShowModal() == wxID_CANCEL) return;

	wxString path = openFileDialog.GetPath();

	const char* p = path.c_str();

	/* 
	this make "Can't verify memory struct - all bets are off" error 
	I don't know what it is but I thnink it's something about wxWidget memory tracking.
	*/
	std::vector<std::string> data = ical::process_Image(p);

	ical::ocr_to_event(data, listSchedule);

	event.skip();
}
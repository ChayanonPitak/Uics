#include "mainFrame.h"
#include "p_About.h"
#include "Period.h"
#include "ClassSchedule.h"
#include "ExamSchedule.h"

#include <wx/wxprec.h>
#include <wx/listbook.h>
#include <wx/listctrl.h>
#include <fstream>
#include <string>

enum
{
	ID_GetScan = 10,
	ID_Export = 11
};

wxBEGIN_EVENT_TABLE(mainFrame, wxFrame)
	EVT_MENU(wxID_ABOUT, mainFrame::OnAbout)
	EVT_MENU(wxID_EXIT, mainFrame::OnExit)
	EVT_MENU(wxID_OPEN, mainFrame::OnOpen)
	EVT_MENU(wxID_SAVE, mainFrame::OnSave)
	EVT_MENU(wxID_SAVEAS, mainFrame::OnSaveas)
	EVT_MENU(ID_GetScan, mainFrame::OnScan)
	EVT_MENU(ID_Export, mainFrame::OnExport)
	EVT_CLOSE(mainFrame::OnClose)
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
	FileMenu->Append(ID_Export, "Export .ics");

	ToolMenu = new wxMenu;
	ToolMenu->Append(ID_GetScan, "Scan image", "Scan your schedule.");

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
	listBook = new wxListbook(this, wxID_ANY, wxPoint(0, 0), wxSize(1200, 1400), wxLB_LEFT);
	listBook->GetListView()->SetColumnWidth(0, 130);
	listBook->AddPage(ClassSchedulePanel, "Class Schedule");		//ClassSchedule
	listBook->AddPage(ExamSchedulePanel, "Examination Schedule");	//ExamSchedule
	listBook->AddPage(PeriodPanel, "Semester Period");				//SemesterPeriod

	CreateStatusBar();
	SetStatusText("");

}

void mainFrame::SetStyle()
{

}

void mainFrame::OnClose(wxCloseEvent& event) {
	bool file_notSaved = is_saved != true && (listSchedule.size() != 0);
	if (event.CanVeto() && file_notSaved) {
		if (wxMessageBox("You did not save the schedules. Continue?", "Confirm", wxICON_QUESTION|wxYES_NO) != wxYES) 
			{
				event.Veto();
				return;
			}
	}
	event.Skip();
}

void mainFrame::OnAbout(wxCommandEvent& event)
{
	p_About* aboutFrame = new p_About(this); 
	aboutFrame->Show(true);
}

void mainFrame::OnExit(wxCommandEvent& event)
{
	if (is_saved != true && (listSchedule.size() != 0)) {
		if (wxMessageBox("You did not save the schedules. Continue?", "Confirm", wxICON_QUESTION|wxYES_NO) != wxYES)
		{
			event.Skip();
			return;
		}
	}

	int confirmation = wxMessageBox("Are you sure you want to exit?",
		"Exit",
		wxYES_NO | wxNO_DEFAULT);
	if (confirmation == wxYES) Close(true);
}

void mainFrame::OnOpen(wxCommandEvent& event) {

	if (is_loaded == true || is_scanned == true) {
		if (wxMessageBox("This will reset all schedule. Continue?", "Confirm", wxICON_QUESTION|wxYES_NO) != wxYES)
		{
			event.Skip();
			return;
		}
	}

	wxFileDialog
		openFileDialog(this, "Open file", "", "", "Save file (*.txt)|*.txt", wxFD_OPEN|wxFD_FILE_MUST_EXIST);

	if (openFileDialog.ShowModal() == wxID_CANCEL) return;	

	wxString path = openFileDialog.GetPath();
	recent_path = path.mb_str();
	std::ifstream ifs(recent_path);

	ical::loadEvent(listSchedule, ifs);
	ical::loadEvent(midtermExam, ifs);
	ical::loadEvent(finalExam, ifs);
	ical::loadEvent(holidays, ifs);

	is_loaded = true;
	ClassSchedulePanel->renderData();
	PeriodPanel->renderList();
	event.Skip();
}

void mainFrame::OnSave(wxCommandEvent& event) {

	if (is_loaded == true || is_saved == true) {
		std::ofstream ofs(recent_path);
		ical::saveEvent(listSchedule, ofs);
		ical::saveEvent(midtermExam, ofs);
		ical::saveEvent(finalExam, ofs);	
		ical::saveEvent(holidays, ofs);
	}
	else {
		wxFileDialog
			saveFileDialog(this, "Save ical file", "", "ical_save", "Save File (*.txt)|*.txt", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);

		if (saveFileDialog.ShowModal() == wxID_CANCEL) return;

		wxString path = saveFileDialog.GetPath();
		recent_path = path.mb_str();
		std::ofstream ofs(recent_path);

		ical::saveEvent(listSchedule, ofs);
		ical::saveEvent(midtermExam, ofs);
		ical::saveEvent(finalExam, ofs);
		ical::saveEvent(holidays, ofs);

		is_saved = true;
	}

	event.Skip();
}

void mainFrame::OnSaveas(wxCommandEvent& event) {
	// I don't know why wxFD_SAVE make an assertion when trying to call this func.
	// need to always have wild card param to fix assertion
	wxFileDialog
		saveFileDialog(this, "Save ical file", "", "ical_save", "Save File (*.txt)|*.txt", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);

	if (saveFileDialog.ShowModal() == wxID_CANCEL) return;

	wxString path = saveFileDialog.GetPath();
	recent_path = path.mb_str();
	std::ofstream ofs(recent_path);

	ical::saveEvent(listSchedule, ofs);
	ical::saveEvent(midtermExam, ofs);
	ical::saveEvent(finalExam, ofs);
	ical::saveEvent(holidays, ofs);

	is_saved = true;
	event.Skip();
}

void mainFrame::OnScan(wxCommandEvent& event) {

	if (is_scanned == true) {
		if (wxMessageBox("This will reset all schedule. Continue?", "Confirm", wxICON_QUESTION|wxYES_NO) != wxYES)
		{
			event.Skip();
			return;
		}
	}

	wxFileDialog
		openFileDialog(this, "Open Image file", "", "", "Image (*.tif,*.png)|*.tif;*.png", wxFD_OPEN|wxFD_FILE_MUST_EXIST);

	if (openFileDialog.ShowModal() == wxID_CANCEL) return;

	wxString path = openFileDialog.GetPath();

	const char* p = path.c_str();

	/* 
	this make "Can't verify memory struct - all bets are off" error 
	I don't know what it is but I think it's something about wxWidget memory tracking.
	*/
	std::vector<std::string> data = ical::process_Image(p);

	if (ical::ocr_to_event(data, listSchedule)) {
		wxMessageDialog success(this, wxString("Successful scan data"));
		if(success.ShowModal() == wxID_CANCEL) return;
	}
	else  {
		wxMessageDialog fail(this, wxString("Failed to scan data"));
		if(fail.ShowModal() == wxID_CANCEL) return;
	}

	is_scanned = true;
	ClassSchedulePanel->renderData();
	
	event.Skip();
}

void mainFrame::OnExport(wxCommandEvent& event) {
	// I don't know why wxFD_SAVE make an assertion when trying to call this func.
	wxFileDialog
		saveFileDialog(this, "Export .ics file", "", "uics", "Ical Format (*.ics)|*.ics", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);

	if (saveFileDialog.ShowModal() == wxID_CANCEL) return;

	wxString path = saveFileDialog.GetPath();
	std::ofstream ofs(path.mb_str());

	PeriodPanel->updateTime_range();
	ical::calHeader(ofs);
	ical::exportEvent(listSchedule, ofs);
	ical::exportEvent(midtermExam, ofs);
	ical::exportEvent(finalExam, ofs);
	ical::calFooter(ofs);
	
	event.Skip();
}
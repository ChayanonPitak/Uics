#pragma once
#include "Period.h"
#include "ClassSchedule.h"
#include "ExamSchedule.h"
#include "cal.h"
#include "p_About.h"
#include "Help.h"
#include "wxcmake.h"

#include <wx/wxprec.h>
#include <wx/listbook.h>

class mainFrame : public wxFrame
{
public:
	mainFrame();
	
	// data of all event.
	std::vector<ical::event> listSchedule;
	std::vector<ical::event> midtermExam;
	std::vector<ical::event> finalExam;
	std::vector<ical::event> holidays;
	std::vector<ical::event> range;

	// recent save/load path
	std::string recent_path;
	bool is_loaded = false;
	bool is_saved = false;
	bool is_scanned = false;
	bool is_edited = false;

public:
	//Style
	wxFont ListbookHeader;

	//Listbook
	wxListbook* listBook = NULL;

	//Panel
	Period* PeriodPanel = NULL;
	ClassSchedule* ClassSchedulePanel = NULL;
	ExamSchedule* ExamSchedulePanel = NULL;

	//MenuBar
	wxMenuBar* menuBar = NULL;

	//Menu
	wxMenu* FileMenu = NULL;		//File
	wxMenu* HelpMenu = NULL;		//Help
	wxMenu* ToolMenu = NULL;		//Tool

	//Panel
	p_About* AboutFrame = NULL;		//About
	HelpFrame* _helpFrame = NULL;	//Help

	//Functions
	void SetStyle();
	void OnClose(wxCloseEvent& event);
	void OnHelp(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnOpen(wxCommandEvent& event);
	void OnSave(wxCommandEvent& event);
	void OnSaveas(wxCommandEvent& event);
	void OnExport(wxCommandEvent& event);
	void OnScan(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};
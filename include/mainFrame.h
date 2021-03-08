#pragma once
#include "Period.h"
#include "ClassSchedule.h"
#include "ExamSchedule.h"
#include "cal.h"
#include "wxcmake.h"

#include <wx/wxprec.h>
#include <wx/listbook.h>

class mainFrame : public wxFrame
{
public:
	mainFrame();
	
	// data of all event.
	std::vector<ical::event> listSchedule;
	ical::event EVENT;

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
	wxMenu* ToolMenu = NULL;

	//Functions
	void SetStyle();
	void OnAbout(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void OnOpen(wxCommandEvent& event);
	void OnSave(wxCommandEvent& event);
	void OnSaveas(wxCommandEvent& event);
	void OnExport(wxCommandEvent& event);
	void OnScan(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};
#pragma once
#include "Period.h"
#include "ClassSchedule.h"
#include "ExamSchedule.h"
#include "FileManagement.h"

#include <wxcmake.h>
#include <wx/wxprec.h>
#include <wx/listbook.h>

class mainFrame : public wxFrame
{
public:
	mainFrame();

public:
	//Style
	wxFont ListbookHeader;

	//Listbook
	wxListbook* listBook = NULL;

	//Panel
	Period* PeriodPanel = NULL;
	ClassSchedule* ClassSchedulePanel = NULL;
	ExamSchedule* ExamSchedulePanel = NULL;
	FileManagement* FileManagementPanel = NULL;

	//MenuBar
	wxMenuBar* menuBar = NULL;

	//Menu
	wxMenu* FileMenu = NULL;		//File
	wxMenu* HelpMenu = NULL;		//Help

	//Functions
	void SetStyle();
	void OnAbout(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};
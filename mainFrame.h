#pragma once
#include "ClassSchedule.h"

#include <wx/wxprec.h>
#include <wx/listbook.h>

class mainFrame : public wxFrame
{
public:
	mainFrame();

public:
	//Toolbook
	wxListbook* listBook = NULL;

	//Panel
	ClassSchedule* ClassSchedulePanel = NULL;

	//MenuBar
	wxMenuBar* menuBar = NULL;

	//Menu
	wxMenu* FileMenu = NULL;		//File
	wxMenu* HelpMenu = NULL;		//Help

	//Functions
	void OnAbout(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	//void AddSchedule(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};
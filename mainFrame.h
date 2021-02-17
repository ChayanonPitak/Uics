#pragma once
#include <wx/wxprec.h>

class mainFrame : public wxFrame
{
public:
	mainFrame();

public:
	//MenuBar
	wxMenuBar* menuBar = NULL;

	//Menu
	wxMenu* FileMenu = NULL;		//File
	wxMenu* HelpMenu = NULL;		//Help

	//Widgets
	wxStaticText* SubjectIDLabel = NULL;
	wxTextCtrl* SubjectIDTextCtrl = NULL;
	wxStaticText* SubjectNameLabel = NULL;
	wxTextCtrl* SubjectNameTextCtrl = NULL;
	wxButton* AddButton = NULL;
	
	//Functions
	void OnNew(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void ExportSchedule(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};
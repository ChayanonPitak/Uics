#pragma once
#include <wx/wxprec.h>
#include <wx/timectrl.h>

class mainFrame : public wxFrame
{
public:
	mainFrame();

public:
	//TextStyle
	wxFont *Header1, *Header2, *TextCtrl1, *TextCtrl2;
	//MenuBar
	wxMenuBar* menuBar = NULL;

	//Menu
	wxMenu* FileMenu = NULL;		//File
	wxMenu* HelpMenu = NULL;		//Help

	//Widgets
	wxStaticText* AddClassScheduleHeader = NULL;
	wxStaticText* SubjectIDLabel = NULL;
	wxTextCtrl* SubjectIDTextCtrl = NULL;
	wxStaticText* SubjectNameLabel = NULL;
	wxTextCtrl* SubjectNameTextCtrl = NULL;
	wxStaticText* StartTimeLabel = NULL;
	wxTimePickerCtrl* StartTimePicker = NULL;
	wxStaticText* EndTimeLabel = NULL;
	wxTimePickerCtrl* EndTimePicker = NULL;
	wxStaticText* LocationLabel = NULL;
	wxTextCtrl* LocationtextCtrl = NULL;
	wxButton* AddButton = NULL;
	
	//Functions
	void SetTextStyle();
	void OnNew(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void AddSchedule(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};
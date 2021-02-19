#pragma once
#include <wx/wxprec.h>
#include <wx/timectrl.h>

class mainFrame : public wxFrame
{
public:
	mainFrame();

public:
	//TextStyle
	wxFont *Header1 = NULL, *Header2 = NULL, *TextCtrl1 = NULL, *TextCtrl2 = NULL;
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
	wxStaticText* LocationLabel = NULL;
	wxTextCtrl* LocationtextCtrl = NULL;
	wxStaticText* StartTimeLabel = NULL;
	wxTimePickerCtrl* StartTimePicker = NULL;
	wxStaticText* EndTimeLabel = NULL;
	wxTimePickerCtrl* EndTimePicker = NULL;
	wxStaticText* DayLabel = NULL;
	wxCheckBox *SunCheckmark = NULL, *MonCheckmark = NULL, *TueCheckmark = NULL, *WedCheckmark = NULL, *ThuCheckmark = NULL, *FriCheckmark = NULL, *SatCheckmark = NULL;
	wxButton* AddButton = NULL;
	
	//Functions
	void SetTextStyle();
	void OnNew(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
	void AddSchedule(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};
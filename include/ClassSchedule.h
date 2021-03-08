#pragma once
#include <wx/wxprec.h>
#include <wx/listbox.h>
#include "wxcmake.h"
#include "cal.h"

class ClassSchedule : public wxPanel
{
public :
	ClassSchedule(wxWindow* parent);
	
	void updateEvent(ical::event &event);
	
public :
	//Style
	wxFont Header1, Header2, TextCtrl1, TextCtrl2;

	//Widgets
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
	wxCheckBox* SunCheckmark = NULL, * MonCheckmark = NULL, * TueCheckmark = NULL, * WedCheckmark = NULL, * ThuCheckmark = NULL, * FriCheckmark = NULL, * SatCheckmark = NULL;
	wxButton* AddButton = NULL;
	wxButton* EditButton = NULL;
	wxListBox* ClassScheduleLists = NULL;

	//Functions
	void SetTextStyle();
	wxString renderSchedule(ical::event EVENT);
	void AddSchedule(wxCommandEvent& event);
	void EditSchedule(wxCommandEvent& event);
	void UpdateListSelection(wxCommandEvent& event);
	void SetItemOnSelect(wxCommandEvent& event);

	// debug code
	wxDECLARE_EVENT_TABLE();
	wxTextCtrl* debug = NULL;
	wxButton* dbutton = NULL;
};
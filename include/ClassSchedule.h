#pragma once
#include <wx/wxprec.h>
#include <wx/listbox.h>
#include "wxcmake.h"
#include "cal.h"

class ClassSchedule : public wxPanel
{
public :
	ClassSchedule(wxWindow* parent);
	
	ical::event EVENT;
	void updateEvent(ical::event &event);
	void renderData();
	wxString renderSchedule(ical::event EVENT);
	void SetItemOnSelect();

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
	wxButton* ResetButton = NULL;
	wxButton* DeleteButton = NULL;
	wxButton* DeleteAllButton = NULL;
	wxMessageDialog* DeleteAllConfirmDialog = NULL;
	wxListBox* ClassScheduleLists = NULL;

	//Functions
	wxDECLARE_EVENT_TABLE();
	void SetTextStyle();
	void AddSchedule(wxCommandEvent& event);
	void EditSchedule(wxCommandEvent& event);
	void DeleteSchedule(wxCommandEvent& event);
	void DeleteAllSchedule(wxCommandEvent& event);
	void ResetField(wxCommandEvent& event);
	void UpdateListSelection(wxCommandEvent& event);
};
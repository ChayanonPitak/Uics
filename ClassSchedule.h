#pragma once
#include "cal.h"
#include <wx/wxprec.h>
#include <wx/timectrl.h>

class ClassSchedule : public wxPanel
{
public :
	ClassSchedule(wxWindow* parent);
	std::vector<ical::event> listSchedule;

	ical::event EVENT;
	void updateEvent(ical::event event);

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

	//Functions
	void SetTextStyle();
	void AddSchedule(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};
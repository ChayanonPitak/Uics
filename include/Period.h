#pragma once
#include "wxcmake.h"
#include <wx/wxprec.h>
#include <wx/datectrl.h>

class Period : public wxPanel
{
public:
	Period(wxWindow* parent);

	void updateTime_range();

public:
	//Style
	wxFont Header1, Header2, TextCtrl1, TextCtrl2;

	//Widgets
	wxStaticText* PeriodStartLabel = NULL;
	wxDatePickerCtrl* PeriodStartDatePickerLabel = NULL;
	wxStaticText* PeriodEndLabel = NULL;
	wxDatePickerCtrl* PeriodEndDatePickerLabel = NULL;
	wxStaticText* MidtermExaminationStartLabel = NULL;
	wxDatePickerCtrl* MidtermExaminationStartDatePickerCtrl = NULL;
	wxStaticText* MidtermExaminationEndLabel = NULL;
	wxDatePickerCtrl* MidtermExaminationEndDatePickerCtrl = NULL;
	wxStaticText* FinalExaminationStartLabel = NULL;
	wxDatePickerCtrl* FinalExaminationStartDatePickerCtrl = NULL;
	wxStaticText* FinalExaminationEndLabel = NULL;
	wxDatePickerCtrl* FinalExaminationEndDatePickerCtrl = NULL;

	//Functions
	void SetStyle();

	//wxDECLARE_EVENT_TABLE();

	// debug code
	wxDECLARE_EVENT_TABLE();
	void onbutton(wxCommandEvent& event) {
		updateTime_range();
	};
	wxTextCtrl* debug = NULL;
	wxButton* dbutton = NULL;
};

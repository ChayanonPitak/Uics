#pragma once
#include "wxcmake.h"
#include <wx/wxprec.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>

class Period : public wxPanel
{
public:
	Period(wxWindow* parent);

	void updateTime_range();
	void renderList();

public:
	//Style
	wxFont Header1, Header2, TextCtrl1, TextCtrl2;

	//Widgets
	wxStaticText* PeriodLabel = NULL;
	wxStaticText* PeriodStartLabel = NULL;
	wxDatePickerCtrl* PeriodStartDatePickerCtrl = NULL;
	wxStaticText* PeriodEndLabel = NULL;
	wxDatePickerCtrl* PeriodEndDatePickerCtrl = NULL;
	wxStaticText* MidtermExaminationStartLabel = NULL;
	wxDatePickerCtrl* MidtermExaminationStartDatePickerCtrl = NULL;
	wxStaticText* MidtermExaminationEndLabel = NULL;
	wxDatePickerCtrl* MidtermExaminationEndDatePickerCtrl = NULL;
	wxStaticText* FinalExaminationStartLabel = NULL;
	wxDatePickerCtrl* FinalExaminationStartDatePickerCtrl = NULL;
	wxStaticText* FinalExaminationEndLabel = NULL;
	wxDatePickerCtrl* FinalExaminationEndDatePickerCtrl = NULL;

	wxStaticText* HolidayLabel = NULL;
	wxStaticText* HolidayNameLabel = NULL;
	wxTextCtrl* HolidayNameTextCtrl = NULL;
	wxStaticText* HolidayStartDatePickerLabel = NULL;
	wxDatePickerCtrl* HolidayStartDatePickerCtrl = NULL;
	wxCheckBox* SingleHolidayDayCheckMark = NULL;
	wxStaticText* HolidayEndDatePickerLabel = NULL;
	wxDatePickerCtrl* HolidayEndDatePickerCtrl = NULL;
	wxButton* AddButton = NULL;
	wxButton* EditButton = NULL;
	wxButton* ResetButton = NULL;
	wxButton* DeleteButton = NULL;
	wxButton* DeleteAllButton = NULL;
	wxMessageDialog* DeleteAllConfirmDialog = NULL;
	wxListBox* HolidayLists = NULL;


	//Functions
	void SetStyle();
	void CheckSingleDay(wxCommandEvent& event);
	void ResetField(wxCommandEvent& event);
	void SetPeriodRange(wxDateEvent& event);
	void OnAdd(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();

	// debug code
	/*
	void onbutton(wxCommandEvent& event) {
		updateTime_range();
	};
	wxTextCtrl* debug = NULL;
	wxButton* dbutton = NULL;
	*/
};

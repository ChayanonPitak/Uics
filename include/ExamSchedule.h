#pragma once
#include "wxcmake.h"
#include <wx/wxprec.h>
#include "cal.h"
#include <wx/timectrl.h>
#include <wx/datectrl.h>
#include <wx/listbox.h>
#include <wx/combobox.h>

class ExamSchedule : public wxPanel
{
public:
	ExamSchedule(wxWindow* parent);
	std::vector<ical::event> listSchedule;
	
	ical::event EVENT;
	void updateEvent(ical::event &EVENT);
	std::string renderSchedule(ical::event EVENT);
	void renderData();

	
public:
	//Style
	wxFont Header1, Header2, TextCtrl1, TextCtrl2;

	//Functions
	void SetStyle();

	wxStaticText* SubjectIDLabel = NULL;
	wxTextCtrl* SubjectIDTextCtrl = NULL;
	wxStaticText* SubjectNameLabel = NULL;
	wxTextCtrl* SubjectNameTextCtrl = NULL;
	wxStaticText* LocationLabel = NULL;
	wxTextCtrl* LocationtextCtrl = NULL;
	wxStaticText* Note = NULL;
	wxTextCtrl *NoteNameTextCtrl = NULL;
	wxStaticText* StartTimeLabel = NULL;
	wxTimePickerCtrl* StartTimePicker = NULL;
	wxStaticText* EndTimeLabel = NULL;
	wxTimePickerCtrl* EndTimePicker = NULL;
	
	wxStaticText* SelectionLable = NULL;
	wxDatePickerCtrl* SelectDate = NULL;

	wxButton* AddButton = NULL;
	wxButton* EditButton = NULL;
	wxButton* ResetButton = NULL;
	wxButton* DeleteButton = NULL;
	wxButton* DeleteAllButton = NULL;
	wxMessageDialog* DeleteAllConfirmDialog = NULL;
	wxListBox* MidtermExamScheduleLists = NULL;
	wxListBox* FinalExamScheduleLists = NULL;
	
	wxStaticText* PeriodSelectionLabel = NULL;
	wxComboBox* PeriodSelection = NULL;     

	wxDECLARE_EVENT_TABLE();
	void AddSchedule(wxCommandEvent& event);
	void EditSchedule(wxCommandEvent& event);
};

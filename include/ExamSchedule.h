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

	ical::event EVENT;
	unsigned char s_state = 0;

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

	wxButton* DeleteAllButtonTwo = NULL;
	wxButton* AddButtonTwo = NULL;
	wxButton* EditButtonTwo = NULL;
	wxButton* ResetButtonTwo = NULL;
	wxButton* DeleteButtonTwo = NULL;

	

	wxDECLARE_EVENT_TABLE();
	void AddSchedule(wxCommandEvent& event);
	void EditSchedule(wxCommandEvent& event);
	void DeleteSchedule(wxCommandEvent& event);
	void DeleteAllSchedule(wxCommandEvent& event);
	void ResetField(wxCommandEvent& event);
	void OnC_midterm(wxCommandEvent& event);
	void OnC_final(wxCommandEvent& event);
};

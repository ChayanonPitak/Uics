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
	void updateEvent(ical::event event);
	void renderSchedule();
	

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
	wxStaticText* DayLabel = NULL;
	wxCheckBox* SunCheckmark = NULL, * MonCheckmark = NULL, * TueCheckmark = NULL, * WedCheckmark = NULL, * ThuCheckmark = NULL, * FriCheckmark = NULL, * SatCheckmark = NULL;
	
	wxStaticText* SelectionLable = NULL;
	wxDatePickerCtrl* SelectDate = NULL;

	wxButton* AddButton = NULL;
	wxButton* EditButton = NULL;
	wxButton* ResetButton = NULL;
	wxButton* DeleteButton = NULL;
	wxButton* DeleteAllButton = NULL;
	wxMessageDialog* DeleteAllConfirmDialog = NULL;
	wxListBox*ExamScheduleLists = NULL;
	
	wxStaticText* PeriodSelectionLabel = NULL;
	wxComboBox* PeriodSelection = NULL;                     

	//wxDECLARE_EVENT_TABLE();
	void SetTextStyle();
	wxString render(ical::event event);
	void AddSchedule(wxCommandEvent& event);
	void EditSchedule(wxCommandEvent& event);
	void DeleteSchedule(wxCommandEvent& event);
	void DeleteAllSchedule(wxCommandEvent& event);
	void ResetField(wxCommandEvent& event);
	void UpdateListSelection(wxCommandEvent& event);
	void SetItemOnSelect(wxCommandEvent& event);

	

	wxDECLARE_EVENT_TABLE();
};

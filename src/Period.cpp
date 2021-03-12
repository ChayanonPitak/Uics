#include "Period.h"
#include "mainFrame.h"
#include "ClassSchedule.h"

#include <wx/wxprec.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <fstream>
#include <string>

enum
{
	ID_AddDay = 301,
	ID_ResetDay = 302,
	ID_HolidayListBox = 311,
	ID_EditDay = 312,
	ID_DeleteDay = 313,
	ID_DeleteAllDay = 314,
	ID_SingleDayCheckBox = 320,
	ID_PeriodStartDatePick = 330,
	ID_PeriodEndDatePick = 331
};



wxBEGIN_EVENT_TABLE(Period, wxPanel)
	// debug code
	// EVT_BUTTON(1, Period::onbutton)
	// end debug code
	EVT_DATE_CHANGED(ID_PeriodStartDatePick, Period::SetPeriodRange)
	EVT_DATE_CHANGED(ID_PeriodEndDatePick, Period::SetPeriodRange)
	EVT_CHECKBOX(ID_SingleDayCheckBox, Period::CheckSingleDay)
	EVT_BUTTON(ID_ResetDay, Period::ResetField)
wxEND_EVENT_TABLE()



Period::Period(wxWindow* Parent) : wxPanel(Parent, wxID_ANY, wxPoint(0, 0), wxSize(750, 50))
{
	SetStyle();
	// -------- Semester Period ----------
	//Label
	PeriodLabel = new wxStaticText(this, wxID_ANY,
		"Semester Period",
		wxPoint(10, 10));
	PeriodLabel->SetFont(Header1);

	//Semester Period Start
	PeriodStartLabel = new wxStaticText(this, wxID_ANY,
		"Semester Start Date",
		wxPoint(10, 30));
	PeriodStartLabel->SetFont(Header2);
	PeriodStartDatePickerCtrl = new wxDatePickerCtrl(this, ID_PeriodStartDatePick, wxDefaultDateTime,
		wxPoint(10, 45), wxSize(85, 25), wxDP_DROPDOWN);
	PeriodStartDatePickerCtrl->SetFont(TextCtrl2);
	//Semester Period End.
	PeriodEndLabel = new wxStaticText(this, wxID_ANY,
		"Semester End Date",
		wxPoint(110, 30));
	PeriodEndLabel->SetFont(Header2);
	PeriodEndDatePickerCtrl = new wxDatePickerCtrl(this, ID_PeriodEndDatePick, wxDefaultDateTime,
		wxPoint(110, 45), wxSize(85, 25), wxDP_DROPDOWN);
	PeriodEndDatePickerCtrl->SetFont(TextCtrl2);

	//Midterm Exam Period Start.
	MidtermExaminationStartLabel = new wxStaticText(this, wxID_ANY,
		"Midterm Examination Start Date",
		wxPoint(250, 30));
	MidtermExaminationStartLabel->SetFont(Header2);
	MidtermExaminationStartDatePickerCtrl = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime,
		wxPoint(250, 45), wxSize(85, 25), wxDP_DROPDOWN);
	MidtermExaminationStartDatePickerCtrl->SetFont(TextCtrl2);
	//Midterm Exam Period End.
	MidtermExaminationEndLabel = new wxStaticText(this, wxID_ANY,
		"Midterm Examination End Date",
		wxPoint(400, 30));
	MidtermExaminationEndLabel->SetFont(Header2);
	MidtermExaminationEndDatePickerCtrl = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime,
		wxPoint(400, 45), wxSize(85, 25), wxDP_DROPDOWN);
	MidtermExaminationEndDatePickerCtrl->SetFont(TextCtrl2);

	//Final Exam Period Start.
	FinalExaminationStartLabel = new wxStaticText(this, wxID_ANY,
		"Final Examination Start Date",
		wxPoint(250, 80));
	FinalExaminationStartLabel->SetFont(Header2);
	FinalExaminationStartDatePickerCtrl = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime,
		wxPoint(250, 95), wxSize(85, 25), wxDP_DROPDOWN);
	FinalExaminationStartDatePickerCtrl->SetFont(TextCtrl2);
	//Final Exam Period End.
	FinalExaminationEndLabel = new wxStaticText(this, wxID_ANY,
		"Final Examination End Date",
		wxPoint(400, 80));
	FinalExaminationEndLabel->SetFont(Header2);
	FinalExaminationEndDatePickerCtrl = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime, 
		wxPoint(400, 95), wxSize(85, 25), wxDP_DROPDOWN);
	FinalExaminationEndDatePickerCtrl->SetFont(TextCtrl2);

	// -------- Holiday ----------
	//Label
	HolidayLabel = new wxStaticText(this, wxID_ANY,
		"Holiday and cancelation",
		wxPoint(10, 140));
	HolidayLabel->SetFont(Header1);

	//DayName
	HolidayNameLabel = new wxStaticText(this, wxID_ANY,
		"Day",
		wxPoint(10, 160));
	HolidayNameLabel->SetFont(Header2);
	HolidayNameTextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(10, 175), wxSize(150, 25));
	HolidayNameTextCtrl->SetFont(TextCtrl2);

	//StartDate
	HolidayStartDatePickerLabel = new wxStaticText(this, wxID_ANY,
		"Start Date",
		wxPoint(170, 160));
	HolidayStartDatePickerCtrl = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime,
		wxPoint(170, 175), wxSize(85, 25), wxDP_DROPDOWN);
	HolidayStartDatePickerCtrl->SetFont(TextCtrl2);
	HolidayStartDatePickerCtrl->SetRange(PeriodStartDatePickerCtrl->GetValue(), PeriodEndDatePickerCtrl->GetValue());
	SingleHolidayDayCheckMark = new wxCheckBox(this, ID_SingleDayCheckBox,
		"This is single day holiday.",
		wxPoint(170, 205));
	SingleHolidayDayCheckMark->SetValue(false);

	//EndDate
	HolidayEndDatePickerLabel = new wxStaticText(this, wxID_ANY,
		"End Date",
		wxPoint(265, 160));
	HolidayEndDatePickerCtrl = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime,
		wxPoint(265, 175), wxSize(85, 25), wxDP_DROPDOWN);
	HolidayEndDatePickerCtrl->SetFont(TextCtrl2);
	HolidayEndDatePickerCtrl->SetRange(PeriodStartDatePickerCtrl->GetValue(), PeriodEndDatePickerCtrl->GetValue());

	//Buttons
	AddButton = new wxButton(this, ID_AddDay,
		"Add",
		wxPoint(365, 167), wxSize(85, 25));
	EditButton = new wxButton(this, ID_EditDay,
		"Edit Selected",
		wxPoint(460, 167), wxSize(85, 25));
	EditButton->Enable(false);
	ResetButton = new wxButton(this, ID_ResetDay,
		"Reset All Field",
		wxPoint(555, 167), wxSize(85, 25));
	DeleteButton = new wxButton(this, ID_DeleteDay,
		"Delete Selected",
		wxPoint(20, 435), wxSize(85, 25));
	DeleteButton->Enable(false);
	DeleteButton = new wxButton(this, ID_DeleteAllDay,
		"Delete All",
		wxPoint(120, 435), wxSize(85, 25));

	//Lists
	HolidayLists = new wxListBox(this, ID_HolidayListBox,
		wxPoint(20, 220), wxSize(450, 200), 0, NULL, wxLB_SINGLE | wxLB_HSCROLL);

	// debug code
	/*
	debug = new wxTextCtrl(this, wxID_ANY, "", wxPoint(20, 180), wxSize(500, 80), wxTE_MULTILINE);
	dbutton = new wxButton(this, 1, "CLICK", wxPoint(20, 260));
	*/
}

void Period::SetStyle()
{
	Header1 = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	Header2 = wxFont(7, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	TextCtrl1 = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	TextCtrl2 = wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
}

void Period::CheckSingleDay(wxCommandEvent& event)
{
	HolidayEndDatePickerCtrl->Enable(!SingleHolidayDayCheckMark->GetValue());
	event.Skip();
}
void Period::ResetField(wxCommandEvent& event)
{
	HolidayNameTextCtrl->SetValue("");
	HolidayStartDatePickerCtrl->SetValue(PeriodStartDatePickerCtrl->GetValue());
	HolidayEndDatePickerCtrl->SetValue(PeriodStartDatePickerCtrl->GetValue());
	event.Skip();
}
void Period::SetPeriodRange(wxDateEvent& event)
{
	HolidayStartDatePickerCtrl->SetRange(PeriodStartDatePickerCtrl->GetValue(), PeriodEndDatePickerCtrl->GetValue());
	HolidayEndDatePickerCtrl->SetRange(PeriodStartDatePickerCtrl->GetValue(), PeriodEndDatePickerCtrl->GetValue());
	event.Skip();
}

void Period::updateTime_range() {
	wxDateTime wx_Sd = PeriodStartDatePickerCtrl->GetValue();
 	wxDateTime wx_Ed = PeriodEndDatePickerCtrl->GetValue();
	wxDateTime wxMid_s = MidtermExaminationStartDatePickerCtrl->GetValue();
	wxDateTime wxMid_e = MidtermExaminationEndDatePickerCtrl->GetValue();
	wxDateTime wxFinal_s = FinalExaminationStartDatePickerCtrl->GetValue();
	wxDateTime wxFinal_e = FinalExaminationEndDatePickerCtrl->GetValue();

	std::string	Mid_s = wxMid_s.FormatISODate().ToStdString();
	std::string	Mid_e = wxMid_e.FormatISODate().ToStdString();
	std::string	Final_s = wxFinal_s.FormatISODate().ToStdString();
	std::string	Final_e = wxFinal_e.FormatISODate().ToStdString();
	std::string r_start = wx_Sd.FormatISODate().ToStdString();
	std::string r_end = wx_Ed.FormatISODate().ToStdString();

	mainFrame* m_parent = dynamic_cast<mainFrame*>(GetParent());

	// change all exdate for exam period.
	for (size_t i = 0; i < m_parent->listSchedule.size(); i++) {
		m_parent->listSchedule[i].reset_exdate();
		m_parent->listSchedule[i].set_exdate(Mid_s, Mid_e);
		m_parent->listSchedule[i].set_exdate(Final_s, Final_e);
		m_parent->listSchedule[i].set_range(r_start, r_end);
	}
	
}
#include "Period.h"
#include "cal.h"

#include <wx/wxprec.h>
#include <wx/datectrl.h>
#include <fstream>
#include <string>

Period::Period(wxWindow* Parent) : wxPanel(Parent, wxID_ANY, wxPoint(0, 0), wxSize(500, 600))
{
	SetStyle();
	//Semester Period Start
	PeriodStartLabel = new wxStaticText(this, wxID_ANY,
		"Semester Start Date",
		wxPoint(10, 10));
	PeriodStartLabel->SetFont(Header2);
	PeriodStartDatePickerLabel = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime,
		wxPoint(10, 25), wxSize(85, 25), wxDP_DROPDOWN);
	PeriodStartDatePickerLabel->SetFont(TextCtrl2);
	//Semester Period End.
	PeriodEndLabel = new wxStaticText(this, wxID_ANY,
		"Semester End Date",
		wxPoint(130, 10));
	PeriodEndLabel->SetFont(Header2);
	PeriodEndDatePickerLabel = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime,
		wxPoint(130, 25), wxSize(85, 25), wxDP_DROPDOWN);
	PeriodEndDatePickerLabel->SetFont(TextCtrl2);
	//Midterm Exam Period Start.
	MidtermExaminationStartLabel = new wxStaticText(this, wxID_ANY,
		"Midterm Examination Start Date",
		wxPoint(10, 55));
	MidtermExaminationStartLabel->SetFont(Header2);
	MidtermExaminationStartDatePickerCtrl = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime,
		wxPoint(10, 70), wxSize(85, 25), wxDP_DROPDOWN);
	MidtermExaminationStartDatePickerCtrl->SetFont(TextCtrl2);
	//Midterm Exam Period End.
	MidtermExaminationEndLabel = new wxStaticText(this, wxID_ANY,
		"Midterm Examination End Date",
		wxPoint(160, 55));
	MidtermExaminationEndLabel->SetFont(Header2);
	MidtermExaminationEndDatePickerCtrl = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime,
		wxPoint(160, 70), wxSize(85, 25), wxDP_DROPDOWN);
	MidtermExaminationEndDatePickerCtrl->SetFont(TextCtrl2);
	//Final Exam Period Start.
	FinalExaminationStartLabel = new wxStaticText(this, wxID_ANY,
		"Final Examination Start Date",
		wxPoint(10, 95));
	FinalExaminationStartLabel->SetFont(Header2);
	FinalExaminationStartDatePickerCtrl = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime,
		wxPoint(10, 110), wxSize(85, 25), wxDP_DROPDOWN);
	FinalExaminationStartDatePickerCtrl->SetFont(TextCtrl2);
	//Final Exam Period End.
	FinalExaminationEndLabel = new wxStaticText(this, wxID_ANY,
		"Final Examination End Date",
		wxPoint(160, 95));
	FinalExaminationEndLabel->SetFont(Header2);
	FinalExaminationEndDatePickerCtrl = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime,
		wxPoint(160, 110), wxSize(85, 25), wxDP_DROPDOWN);
	FinalExaminationEndDatePickerCtrl->SetFont(TextCtrl2);


}
void Period::SetStyle()
{
	Header1 = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	Header2 = wxFont(7, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	TextCtrl1 = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	TextCtrl2 = wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
}
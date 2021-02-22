#include "Period.h"
#include "cal.h"

#include <wx/wxprec.h>
#include <wx/datectrl.h>
#include <fstream>
#include <string>

Period::Period(wxWindow* Parent) : wxPanel(Parent, wxID_ANY, wxPoint(0, 0), wxSize(750, 50))
{
	SetStyle();
	//Period Start
	PeriodStartLabel = new wxStaticText(this, wxID_ANY,
		"Semester Start Date",
		wxPoint(10, 10));
	PeriodStartLabel->SetFont(Header2);
	PeriodStartDatePickerLabel = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime,
		wxPoint(10, 25), wxSize(85, 25), wxDP_DROPDOWN);
	PeriodStartDatePickerLabel->SetFont(TextCtrl2);
	//Period End.
	PeriodEndLabel = new wxStaticText(this, wxID_ANY,
		"Semester End Date",
		wxPoint(105, 10));
	PeriodEndLabel->SetFont(Header2);
	PeriodEndDatePickerLabel = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime,
		wxPoint(105, 25), wxSize(85, 25), wxDP_DROPDOWN);
	PeriodEndDatePickerLabel->SetFont(TextCtrl2);

}
void Period::SetStyle()
{
	Header1 = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	Header2 = wxFont(7, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	TextCtrl1 = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	TextCtrl2 = wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
}
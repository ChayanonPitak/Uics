#include "ClassSchedule.h"

#include <wx/wxprec.h>
#include <wx/valnum.h>
#include <wx/timectrl.h>
#include <fstream>
#include <string>

enum
{
	ID_AddEvent = 11
};

wxBEGIN_EVENT_TABLE(ClassSchedule, wxPanel)
	EVT_BUTTON(ID_AddEvent, ClassSchedule::AddSchedule)
wxEND_EVENT_TABLE()


ClassSchedule::ClassSchedule(wxWindow* Parent) : wxPanel(Parent, wxID_ANY, wxPoint(0,0), wxSize(750,500))
{
	SetTextStyle();
	wxIntegerValidator<int> DigitValidator;
	//SubjectID
	SubjectIDLabel = new wxStaticText(this, wxID_ANY,
		"Subject ID",
		wxPoint(20, 10));
	SubjectIDLabel->SetFont(Header2);
	SubjectIDTextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(20, 25), wxSize(60, 25), 0,
		wxTextValidator(wxFILTER_DIGITS));
	SubjectIDTextCtrl->SetFont(TextCtrl1);
	//SubjectName
	SubjectNameLabel = new wxStaticText(this, wxID_ANY,
		"Subject name",
		wxPoint(90, 10));
	SubjectNameLabel->SetFont(Header2);
	SubjectNameTextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(90, 25), wxSize(200, 25));
	SubjectNameTextCtrl->SetFont(TextCtrl2);
	//Location
	LocationLabel = new wxStaticText(this, wxID_ANY,
		"Location",
		wxPoint(300, 10));
	LocationLabel->SetFont(Header2);
	LocationtextCtrl = new wxTextCtrl(this, wxID_ANY,
		"",
		wxPoint(300, 25), wxSize(150, 25));
	LocationtextCtrl->SetFont(TextCtrl2);
	//StartTime
	StartTimeLabel = new wxStaticText(this, wxID_ANY,
		"Start time",
		wxPoint(20, 50));
	StartTimeLabel->SetFont(Header2);
	StartTimePicker = new wxTimePickerCtrl(this, wxID_ANY,
		wxDateTime(0, 0, 0, 0),
		wxPoint(20, 65), wxSize(85, 25));
	StartTimePicker->SetFont(TextCtrl2);
	//EndTime
	EndTimeLabel = new wxStaticText(this, wxID_ANY,
		"End time",
		wxPoint(110, 50));
	EndTimeLabel->SetFont(Header2);
	EndTimePicker = new wxTimePickerCtrl(this, wxID_ANY,
		wxDateTime(0, 0, 0, 0),
		wxPoint(110, 65), wxSize(85, 25));
	EndTimePicker->SetFont(TextCtrl2);
	//Day
	DayLabel = new wxStaticText(this, wxID_ANY,
		"Day",
		wxPoint(200, 50));
	DayLabel->SetFont(Header2);
	MonCheckmark = new wxCheckBox(this, wxID_ANY,
		"Monday",
		wxPoint(200, 65));
	MonCheckmark->SetFont(TextCtrl2);
	TueCheckmark = new wxCheckBox(this, wxID_ANY,
		"Tuesday",
		wxPoint(200, 80));
	TueCheckmark->SetFont(TextCtrl2);
	WedCheckmark = new wxCheckBox(this, wxID_ANY,
		"Wednesday",
		wxPoint(270, 65));
	WedCheckmark->SetFont(TextCtrl2);
	ThuCheckmark = new wxCheckBox(this, wxID_ANY,
		"Thursday",
		wxPoint(270, 80));
	ThuCheckmark->SetFont(TextCtrl2);
	FriCheckmark = new wxCheckBox(this, wxID_ANY,
		"Friday",
		wxPoint(360, 72));
	FriCheckmark->SetFont(TextCtrl2);
	SatCheckmark = new wxCheckBox(this, wxID_ANY,
		"Saturday",
		wxPoint(420, 65));
	SatCheckmark->SetFont(TextCtrl2);
	SunCheckmark = new wxCheckBox(this, wxID_ANY,
		"Sunday",
		wxPoint(420, 80));
	SunCheckmark->SetFont(TextCtrl2);
}

void ClassSchedule::SetTextStyle()
{
	Header1 = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	Header2 = wxFont(7, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	TextCtrl1 = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	TextCtrl2 = wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
}

void ClassSchedule::updateEvent(ical::event event) {
	int StartHr, StartMin, StartSec;
	int EndHr, EndMin, EndSec;
	unsigned int dayBinary =
		 MonCheckmark->GetValue() +
		 TueCheckmark->GetValue() * 2 +
		 WedCheckmark->GetValue() * 4 + 
		 ThuCheckmark->GetValue() * 8 + 
		 FriCheckmark->GetValue() * 16 + 
		 SatCheckmark->GetValue() * 32 + 
		 SunCheckmark->GetValue() * 64;
	
	//Get schedule time.
	StartTimePicker->GetTime(&StartHr, &StartMin, &StartSec);
	EndTimePicker->GetTime(&EndHr, &EndMin, &EndSec);
	 
	event.untillD = "20210228T000000Z";

	event.name = std::string((SubjectIDTextCtrl->GetLineText(0).mb_str())) 
					 + " " + std::string((SubjectNameTextCtrl->GetLineText(0)).mb_str());
	event.location = std::string((LocationtextCtrl->GetLineText(0)).mb_str()); 

	event.day = ical::checkbyday(dayBinary);

	event.DTstart = ical::checkDT(StartHr, StartMin, StartSec);
	event.DTend = ical::checkDT(EndHr, EndMin, EndSec);
}

void ClassSchedule::AddSchedule(wxCommandEvent& event)
{
	// update event obj
	ClassSchedule::updateEvent(this->EVENT);
	// append copy of event obj to list
	this->listSchedule.push_back(this->EVENT);

	event.Skip();
}
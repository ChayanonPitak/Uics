#pragma once
#include <wxcmake.h>
#include <wx/wxprec.h>

class ExamSchedule : public wxPanel
{
public:
	ExamSchedule(wxWindow* parent);

public:
	//Style
	wxFont Header1, Header2, TextCtrl1, TextCtrl2;



	//Functions
	void SetStyle();

	//wxDECLARE_EVENT_TABLE();
};

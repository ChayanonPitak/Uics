#pragma once
#include <wx/wxprec.h>

class p_About : public wxFrame
{
public:
	p_About(wxWindow* parent);
public :
	//Text
	wxStaticText* HeaderText = NULL;

	//Style
	wxFont HeaderFont;

	wxGridSizer* HeaderHerderTextsize = nullptr;
};


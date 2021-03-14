#pragma once
#include "wxcmake.h"
#include <wx/wxprec.h>

class p_About : public wxFrame
{
public:
	p_About(wxWindow* parent);
public :
	//Text
	wxStaticText* BigHeaderText = NULL;
	wxStaticText* HeaderText = NULL;
	wxStaticText* HeadText = NULL;
	wxStaticText* Text = NULL;
	wxStaticText* SpecialText = NULL;
	//Style
	wxFont HeaderFont;
	wxFont HeaderFont_01;
	wxFont HeaderFont_02;
	wxFont NormalFont_01;
	wxFont NormalFont_02;
	wxFont SpecialFont_Head;
	wxFont SpecialFont_Text;

	wxGridSizer* HeaderHerderTextsize = nullptr;
};


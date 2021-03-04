#pragma once
#include "wxcmake.h"
#include <wx/wxprec.h>

class FileManagement : public wxPanel
{
public:
	FileManagement(wxWindow* parent);

	void onbutton(wxCommandEvent& WXUNUSED(event));

public:
	//Style
	wxFont Header1, Header2, TextCtrl1, TextCtrl2;

	wxButton *file_button = NULL;

	//Functions
	void SetStyle();

	wxDECLARE_EVENT_TABLE();
};

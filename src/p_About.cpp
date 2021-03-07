 #include "p_About.h"

#include <wx/wxprec.h>

p_About::p_About(wxWindow* parent) :wxFrame (parent, wxID_ANY, "About", wxPoint(150, 150), wxSize(500, 500))
{
	HeaderFont = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	HeaderText = new wxStaticText(this, wxID_ANY,"Software is better for student to study");
	
}                      
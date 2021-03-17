#include "help.h"

#include <wx/listbook.h>
#include <wx/statbmp.h>
#include <wx/wxprec.h>

HelpFrame::HelpFrame(wxWindow* parent) : wxFrame(parent, wxID_ANY, "Help", wxPoint(150, 150), wxSize(1378, 811), wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER & ~wxMAXIMIZE_BOX)
{
	//Panel
	IntroHelpPanel* _IntroHelpPanel = new IntroHelpPanel(this);		//Intro
	PeriodHelpPanel* _PeriodHelpPanel = new PeriodHelpPanel(this);	//Period

	//ListBook
	MainListBook = new wxListbook(this, wxID_ANY, wxPoint(0, 0), wxSize(1378, 811), wxLB_LEFT);
	MainListBook->GetListView()->SetColumnWidth(0, 150);
	MainListBook->AddPage(_IntroHelpPanel, "Introduction");
	MainListBook->AddPage(_PeriodHelpPanel, "Semester Period");
};

IntroHelpPanel::IntroHelpPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxPoint(150, 0), wxSize(1228, 811))
{
	wxInitAllImageHandlers();
	//Images
	Page1 = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help_Intro_1.png", wxBITMAP_TYPE_PNG),
		wxPoint(0, 0));
	Page2 = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help_Intro_2.png", wxBITMAP_TYPE_PNG),
		wxPoint(0, 0));

	//Listbook
	PagesListBook = new wxListbook(this, wxID_ANY, wxPoint(0, 0), wxSize(1228, 811), wxLB_TOP);
	PagesListBook->AddPage(Page1, "Selection");
	PagesListBook->AddPage(Page2, "Exporting");
}

PeriodHelpPanel::PeriodHelpPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxPoint(150, 0), wxSize(1228, 811))
{
	wxInitAllImageHandlers();
	//Images
	Page1 = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help_SemesterPeriod_1.png", wxBITMAP_TYPE_PNG),
		wxPoint(0, 0));
}
#pragma once
#include "wxcmake.h"
#include <wx/listbook.h>
#include <wx/statbmp.h>
#include <wx/wxprec.h>

class IntroHelpPanel : public wxPanel
{
public:
	IntroHelpPanel(wxWindow* Parent);
public:
	//Listbook
	wxListbook* PagesListBook = NULL;

	wxStaticBitmap* Page1 = NULL;
	wxStaticBitmap* Page2 = NULL;
};

class PeriodHelpPanel : public wxPanel
{
public:
	PeriodHelpPanel(wxWindow* Parent);
public:
	wxStaticBitmap* Page1 = NULL;
};

class HelpFrame : public wxFrame
{
public:
	HelpFrame(wxWindow* parent);
public:
	//Listbook
	wxListbook* MainListBook = NULL;

	//Panel
	IntroHelpPanel* _IntroHelpPanel = NULL;		//Intro
	PeriodHelpPanel* _PeriodHelpPanel = NULL;	//Period
};
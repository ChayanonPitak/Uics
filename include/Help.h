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

	//Bitmap
	wxStaticBitmap* FilesBitmap = NULL;
	wxStaticBitmap* MenuBitmap = NULL;
	wxStaticBitmap* ToolsBitmap = NULL;
};

class PeriodHelpPanel : public wxPanel
{
public:
	PeriodHelpPanel(wxWindow* Parent);
public:
	//Listbook
	wxListbook* PagesListBook = NULL;

	//Bitmap
	wxStaticBitmap* SemesterPeriodBitmap = NULL;
	wxStaticBitmap* ExaminationPeriodBitmap = NULL;
	wxStaticBitmap* HolidayBitmap = NULL;
	wxStaticBitmap* HolidayListBitmap = NULL;
};

class ClassScheduleHelpPanel : public wxPanel
{
public:
	ClassScheduleHelpPanel(wxWindow* Parent);
public:
	//Listbook
	wxListbook* PagesListBook = NULL;

	//Bitmap
	wxStaticBitmap* SubjectMetadataBitmap = NULL;
	wxStaticBitmap* TimeBitmap = NULL;
	wxStaticBitmap* DayBitmap = NULL;
	wxStaticBitmap* ListBitmap = NULL;
};

class ExamScheduleHelpPanel : public wxPanel
{
public:
	ExamScheduleHelpPanel(wxWindow* Parent);
public:
	//Listbook
	wxListbook* PagesListBook = NULL;

	//Bitmap
	wxStaticBitmap* PeriodBitmap = NULL;
	wxStaticBitmap* SubjectMetadataBitmap = NULL;
	wxStaticBitmap* TimeBitmap = NULL;
	wxStaticBitmap* ListBitmap = NULL;
};

class HelpFrame : public wxFrame
{
public:
	HelpFrame(wxWindow* parent);
public:
	//Listbook
	wxListbook* MainListBook = NULL;

	//Panel
	IntroHelpPanel* _IntroHelpPanel = NULL;					//Intro
	PeriodHelpPanel* _PeriodHelpPanel = NULL;				//Period
	ClassScheduleHelpPanel* _ClassScheduleHelpPanel = NULL;	//ClassSchedule
	ExamScheduleHelpPanel* _ExamScheduleHelpPanel = NULL;	//ExanSchedule
};
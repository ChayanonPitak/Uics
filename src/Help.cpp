#include "help.h"

#include <wx/listbook.h>
#include <wx/statbmp.h>
#include <wx/wxprec.h>

HelpFrame::HelpFrame(wxWindow* parent) : wxFrame(parent, wxID_ANY, "Help", wxPoint(150, 150), wxSize(1378, 811), wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER & ~wxMAXIMIZE_BOX)
{
	//Panel
	_IntroHelpPanel = new IntroHelpPanel(this);					//Intro
	_PeriodHelpPanel = new PeriodHelpPanel(this);				//Period
	_ClassScheduleHelpPanel = new ClassScheduleHelpPanel(this);	//ClassSchedule
	_ExamScheduleHelpPanel = new ExamScheduleHelpPanel(this);	//ExamSchedule

	//ListBook
	MainListBook = new wxListbook(this, wxID_ANY, wxPoint(0, 0), wxSize(1378, 811), wxLB_LEFT);
	MainListBook->GetListView()->SetColumnWidth(0, 150);
	MainListBook->AddPage(_IntroHelpPanel, "Introduction");
	MainListBook->AddPage(_PeriodHelpPanel, "Semester Period");
	MainListBook->AddPage(_ClassScheduleHelpPanel, "Class Schedule");
	MainListBook->AddPage(_ExamScheduleHelpPanel, "Exam Schedule");
};

IntroHelpPanel::IntroHelpPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxPoint(150, 0), wxSize(1228, 811))
{
	wxInitAllImageHandlers();
	//Images
	FilesBitmap = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help\\File_Guide.jpg", wxBITMAP_TYPE_JPEG),
		wxPoint(0, 0));
	MenuBitmap = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help\\Section_Guide.jpg", wxBITMAP_TYPE_JPEG),
		wxPoint(0, 0));
	ToolsBitmap = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help\\Tool_Guide.jpg", wxBITMAP_TYPE_JPEG),
		wxPoint(0, 0));

	//Listbook
	PagesListBook = new wxListbook(this, wxID_ANY, wxPoint(0, 0), wxSize(1228, 811), wxLB_TOP);
	PagesListBook->AddPage(FilesBitmap, "File Management");
	PagesListBook->AddPage(MenuBitmap, "Menu");
	PagesListBook->AddPage(ToolsBitmap, "Scanning Image");
}

PeriodHelpPanel::PeriodHelpPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxPoint(150, 0), wxSize(1228, 811))
{
	wxInitAllImageHandlers();
	//Images
	SemesterPeriodBitmap = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help\\Semester\\Semester01.jpg", wxBITMAP_TYPE_JPEG),
		wxPoint(0, 0));
	ExaminationPeriodBitmap = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help\\Semester\\Semester02.jpg", wxBITMAP_TYPE_JPEG),
		wxPoint(0, 0));
	HolidayBitmap = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help\\Semester\\Semester03.jpg", wxBITMAP_TYPE_JPEG),
		wxPoint(0, 0));
	HolidayListBitmap = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help\\Semester\\Semester04.jpg", wxBITMAP_TYPE_JPEG),
		wxPoint(0, 0));

	PagesListBook = new wxListbook(this, wxID_ANY, wxPoint(0, 0), wxSize(1228, 811), wxLB_TOP);
	PagesListBook->AddPage(SemesterPeriodBitmap, "Semester Period");
	PagesListBook->AddPage(ExaminationPeriodBitmap, "Examination Period");
	PagesListBook->AddPage(HolidayBitmap, "Holiday");
	PagesListBook->AddPage(HolidayListBitmap, "Holiday list managing");
}

ClassScheduleHelpPanel::ClassScheduleHelpPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxPoint(150, 0), wxSize(1228, 811))
{
	wxInitAllImageHandlers();
	//Images
	SubjectMetadataBitmap = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help\\class_schedule\\ClassSchedule01.jpg", wxBITMAP_TYPE_JPEG),
		wxPoint(0, 0));
	TimeBitmap = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help\\class_schedule\\ClassSchedule02.jpg", wxBITMAP_TYPE_JPEG),
		wxPoint(0, 0));
	DayBitmap = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help\\class_schedule\\ClassSchedule03.jpg", wxBITMAP_TYPE_JPEG),
		wxPoint(0, 0));
	ListBitmap = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help\\class_schedule\\ClassSchedule04.jpg", wxBITMAP_TYPE_JPEG),
		wxPoint(0, 0));

	PagesListBook = new wxListbook(this, wxID_ANY, wxPoint(0, 0), wxSize(1228, 811), wxLB_TOP);
	PagesListBook->AddPage(SubjectMetadataBitmap, "Metadata");
	PagesListBook->AddPage(TimeBitmap, "Time period");
	PagesListBook->AddPage(DayBitmap, "Week interval");
	PagesListBook->AddPage(ListBitmap, "List managing");
}

ExamScheduleHelpPanel::ExamScheduleHelpPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxPoint(150, 0), wxSize(1228, 811))
{
	wxInitAllImageHandlers();
	//Images
	PeriodBitmap = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help\\Exam_schedule\\Exam01.jpg", wxBITMAP_TYPE_JPEG),
		wxPoint(0, 0));
	SubjectMetadataBitmap = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help\\Exam_schedule\\Exam02.jpg", wxBITMAP_TYPE_JPEG),
		wxPoint(0, 0));
	TimeBitmap = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help\\Exam_schedule\\Exam03.jpg", wxBITMAP_TYPE_JPEG),
		wxPoint(0, 0));
	ListBitmap = new wxStaticBitmap(this, wxID_ANY,
		wxBitmap("..\\resources\\Help\\Exam_schedule\\Exam04.jpg", wxBITMAP_TYPE_JPEG),
		wxPoint(0, 0));

	PagesListBook = new wxListbook(this, wxID_ANY, wxPoint(0, 0), wxSize(1228, 811), wxLB_TOP);
	PagesListBook->AddPage(PeriodBitmap, "Period");
	PagesListBook->AddPage(SubjectMetadataBitmap, "Metadata");
	PagesListBook->AddPage(TimeBitmap, "Date and time");
	PagesListBook->AddPage(ListBitmap, "List managing");
}
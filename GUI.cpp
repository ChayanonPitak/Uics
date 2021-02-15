#include "cal.h"
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

//Main App
class UicsMainApp : public wxApp
{
public :
	virtual bool OnInit();
};

//Main frame
class MainFrame : public wxFrame
{
public :
	MainFrame();
private:
	void OnNew(wxCommandEvent& event);		//New file.
	void OnAbout(wxCommandEvent& event);	//About.
	void OnExit(wxCommandEvent& event);		//Close the program.
};
enum
{
	// wxWindows ID
	
};

wxIMPLEMENT_APP(UicsMainApp);
//Execute on startup.
bool UicsMainApp::OnInit()
{
	MainFrame* frame = new MainFrame();
	frame->Show(true);
	return true;						//To check that program initialize correctly.
}

MainFrame::MainFrame() 
	: wxFrame(NULL, wxID_ANY, "Uics")
{
	//Menu elements
	wxMenu* menu_File = new wxMenu;	//File Menu
	menu_File->Append(wxID_NEW);		//New
	menu_File->Append(wxID_EXIT);		//Exit
	
	wxMenu* menu_Help = new wxMenu;	//Help Menu
	menu_Help->Append(wxID_ABOUT);		//About
	//------------------------------------------------
	//Menu bar (located on the top)
	wxMenuBar* menuBar = new wxMenuBar;	//Menu bar
	menuBar->Append(menu_File, "File");		//File
	menuBar->Append(menu_Help, "Help");		//Help
	
	SetMenuBar(menuBar);
	//------------------------------------------------
	//Status bar (located at the bottommost)
	CreateStatusBar();	//Create
	SetStatusText("Uics made by SixtyNine.");	//Status text.
	//------------------------------------------------
	//Event binding
	Bind(wxEVT_MENU, &MainFrame::OnNew, this, wxID_NEW);		//OnNew
	Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);		//OnExit
	Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);	//OnAbout
}

void MainFrame::OnNew(wxCommandEvent& event)
{
	wxMessageBox("New? Nothing here right now.",
		"New",
		wxOK);

}
void MainFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox("Uics\nMade by Sixtynine",
		"About",
		wxOK|wxCENTRE);
}
void MainFrame::OnExit(wxCommandEvent& event)
{
	int confirmation = wxMessageBox("Are you sure you want to exit?",
		"Exit",
		wxYES_NO|wxNO_DEFAULT);
	if (confirmation == wxYES) Close(true);
}
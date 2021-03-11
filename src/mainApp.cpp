#include "mainApp.h"
#include "mainFrame.h"

#include <wx/wxprec.h>

wxIMPLEMENT_APP(mainApp);

bool mainApp::OnInit()
{
	wxInitAllImageHandlers();
	mainFrame* _mainFrame = new mainFrame();
	_mainFrame->SetIcons(wxIconBundle("..\\resources\\icon.png", wxBITMAP_TYPE_PNG));
	_mainFrame->Show(true);
	return true;
}
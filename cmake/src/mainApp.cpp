#include "mainApp.h"
#include "mainFrame.h"

#include <wx/wxprec.h>

wxIMPLEMENT_APP(mainApp);

bool mainApp::OnInit()
{
	mainFrame* _mainFrame = new mainFrame();
	_mainFrame->Show(true);
	return true;
}
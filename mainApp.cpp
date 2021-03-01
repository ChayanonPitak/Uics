#include <wxcmake.h>
#include "mainApp.h"
#include "mainFrame_cpp.h"

#include <wx/wxprec.h>

wxIMPLEMENT_APP(mainApp);

bool mainApp::OnInit()
{
	mainFrame* _mainFrame = new mainFrame();
	_mainFrame->Show(true);
	return true;
}
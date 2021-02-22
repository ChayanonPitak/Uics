#include <wxcmake.h>
#include <wx/wxprec.h>
#include <mainFrame.h>
#include <mainFrame_cpp.h>
#include <mainApp.h>

wxIMPLEMENT_APP(mainApp);

bool mainApp::OnInit()
{
	mainFrame* _mainFrame = new mainFrame();
	_mainFrame->Show(true);
	return true;
}
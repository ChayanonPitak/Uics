#include "FileManagement.h"

#include <wx/wxprec.h>

wxBEGIN_EVENT_TABLE(FileManagement, wxPanel)
	EVT_BUTTON(2, FileManagement::onbutton)
wxEND_EVENT_TABLE()

FileManagement::FileManagement(wxWindow* Parent) : wxPanel(Parent, wxID_ANY, wxPoint(0, 0), wxSize(750, 50))
{
	file_button = new wxButton(this, 2, "OPEN");

	SetStyle();
}

void FileManagement::onbutton(wxCommandEvent& WXUNUSED(event)) {
	wxFileDialog
		openFileDialog(this, ("ahh"));

	if (openFileDialog.ShowModal() == wxID_CANCEL) return;
}

void FileManagement::SetStyle()
{
	Header1 = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	Header2 = wxFont(7, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	TextCtrl1 = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	TextCtrl2 = wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
}
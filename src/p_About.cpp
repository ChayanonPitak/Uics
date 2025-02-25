 #include "p_About.h"

#include <wx/wxprec.h>
#include <wx/window.h>//for back ground color

p_About::p_About(wxWindow* parent) :wxFrame(parent, wxID_ANY, "About", wxPoint(150, 150), wxSize(500, 500))
{   
	//Panel
	_p_AboutPanel = new p_AboutPanel(this);
}

p_AboutPanel::p_AboutPanel(wxWindow* parent):wxPanel(parent,wxID_ANY, wxPoint(150, 150), wxSize(500, 500)){
	//----------------------------------------Font------------------------------------------------------
	HeaderFont = wxFont(18, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	HeaderFont_01 = wxFont(13, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	HeaderFont_02 = wxFont(11, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	NormalFont_01 = wxFont(11, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	NormalFont_02 = wxFont(8, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	SpecialFont_Head = wxFont(18, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT);
	SpecialFont_Text = wxFont(10, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT);
	//----------------------------------------Font------------------------------------------------------
	//BigHead------------------------------

	BigHeaderText = new wxStaticText(this, wxID_ANY, "About Uics", wxPoint(0, 0), wxSize(85, 25));
	BigHeaderText->SetFont(HeaderFont);
	BigHeaderText = new wxStaticText(this, wxID_ANY, "2021", wxPoint(135, 0), wxSize(85, 25));
	BigHeaderText->SetFont(SpecialFont_Head);
	//Header01-----------------------------
	const int plus1 = 120;
	HeaderText = new wxStaticText(this, wxID_ANY, "Developer", wxPoint(10, 50 + plus1), wxSize(85, 25));
	HeaderText->SetFont(HeaderFont_01);
	//Detail01
	HeadText = new wxStaticText(this, wxID_ANY, "TANAT TANGUN", wxPoint(30, 80 + plus1), wxSize(85, 25));
	SpecialText = new wxStaticText(this, wxID_ANY, "630610737", wxPoint(163, 80 + plus1), wxSize(85, 25));
	Text = new wxStaticText(this, wxID_ANY, "-Project manager -Coding Backend", wxPoint(50, 105 + plus1), wxSize(85, 75));
	HeadText->SetFont(HeaderFont_02);
	SpecialText->SetFont(SpecialFont_Text);
	Text->SetFont(NormalFont_01);

	HeadText = new wxStaticText(this, wxID_ANY, "CHAYANON PITAK", wxPoint(30, 130 + plus1), wxSize(85, 25));
	SpecialText = new wxStaticText(this, wxID_ANY, "630610724", wxPoint(178, 130 + plus1), wxSize(85, 25));
	Text = new wxStaticText(this, wxID_ANY, "-Project manager -Coding User interface", wxPoint(50, 155 + plus1), wxSize(85, 75));
	HeadText->SetFont(HeaderFont_02);
	SpecialText->SetFont(SpecialFont_Text);
	Text->SetFont(NormalFont_01);

	HeadText = new wxStaticText(this, wxID_ANY, "CHETSADA CHAINANTI", wxPoint(30, 180 + plus1), wxSize(85, 25));
	SpecialText = new wxStaticText(this, wxID_ANY, "630610723", wxPoint(210, 180 + plus1), wxSize(85, 25));
	Text = new wxStaticText(this, wxID_ANY, "-Coding User interface", wxPoint(50, 205 + plus1), wxSize(85, 165));
	HeadText->SetFont(HeaderFont_02);
	SpecialText->SetFont(SpecialFont_Text);
	Text->SetFont(NormalFont_01);

	HeadText = new wxStaticText(this, wxID_ANY, "TANANUN CHOWDEE", wxPoint(30, 230 + plus1), wxSize(85, 25));
	SpecialText = new wxStaticText(this, wxID_ANY, "630610735", wxPoint(204, 230 + plus1), wxSize(85, 25));
	Text = new wxStaticText(this, wxID_ANY, "-Coding Backend", wxPoint(50, 255 + plus1), wxSize(85, 250));
	HeadText->SetFont(HeaderFont_02);
	SpecialText->SetFont(SpecialFont_Text);
	Text->SetFont(NormalFont_01);

	HeadText = new wxStaticText(this, wxID_ANY, "THIDTANAI KAEWPHET", wxPoint(30, 280 + plus1), wxSize(85, 25));
	SpecialText = new wxStaticText(this, wxID_ANY, "630610741", wxPoint(210, 280 + plus1), wxSize(85, 25));
	Text = new wxStaticText(this, wxID_ANY, "-UI/UX Asset design -Coding User interfacce ", wxPoint(50, 305 + plus1), wxSize(85, 300));
	HeadText->SetFont(HeaderFont_02);
	SpecialText->SetFont(SpecialFont_Text);
	Text->SetFont(NormalFont_01);
	//Header02-----------------------------
	const int plus2 = 0;
	HeaderText = new wxStaticText(this, wxID_ANY, "Uics", wxPoint(10, 50 + plus2), wxSize(85, 25));
	HeaderText->SetFont(HeaderFont_01);
	//Detail02
	HeadText = new wxStaticText(this, wxID_ANY, "Virsion:", wxPoint(30, 80 + plus2), wxSize(85, 25));
	SpecialText = new wxStaticText(this, wxID_ANY, "0.221", wxPoint(90, 82 + plus2), wxSize(85, 25));
	HeadText->SetFont(HeaderFont_02);
	SpecialText->SetFont(SpecialFont_Text);
	HeadText = new wxStaticText(this, wxID_ANY, "Language:", wxPoint(30, 105 + plus2), wxSize(85, 25));
	SpecialText = new wxStaticText(this, wxID_ANY, "English", wxPoint(110, 107 + plus2), wxSize(85, 25));
	HeadText->SetFont(HeaderFont_02);
	SpecialText->SetFont(SpecialFont_Text);
	HeadText = new wxStaticText(this, wxID_ANY, "Last upadate:", wxPoint(30, 130 + plus2), wxSize(85, 25));
	SpecialText = new wxStaticText(this, wxID_ANY, "3/18/2021", wxPoint(130, 132 + plus2), wxSize(85, 25));
	HeadText->SetFont(HeaderFont_02);
	SpecialText->SetFont(SpecialFont_Text);
}
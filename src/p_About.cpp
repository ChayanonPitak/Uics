 #include "p_About.h"

#include <wx/wxprec.h>

p_About::p_About(wxWindow* parent) :wxFrame(parent, wxID_ANY, "About", wxPoint(150, 150), wxSize(500, 500))
{
	//----------------------------------------Font------------------------------------------------------
	HeaderFont = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	HeaderFont_01 = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	HeaderFont_02 = wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	NormalFont_01 = wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	NormalFont_02 = wxFont(5, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	SpecialFont_Head = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT);
	SpecialFont_Text = wxFont(7, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT);
	//----------------------------------------Font------------------------------------------------------
	//BigHead------------------------------

	BigHeaderText = new wxStaticText(this, wxID_ANY, "About Uics", wxPoint(0, 0), wxSize(85, 25));
	BigHeaderText->SetFont(HeaderFont);
	BigHeaderText = new wxStaticText(this, wxID_ANY, "2021", wxPoint(120, 0), wxSize(85, 25));
	BigHeaderText->SetFont(SpecialFont_Head);
	//Header01-----------------------------
	const int plus1 = 120;
	HeaderText = new wxStaticText(this, wxID_ANY, "Developer", wxPoint(10, 50 + plus1), wxSize(85, 25));
	HeaderText->SetFont(HeaderFont_01);
	//Detail01
	HeadText = new wxStaticText(this, wxID_ANY, "TANAT TANGUN", wxPoint(30, 80 + plus1), wxSize(85, 25));
	SpecialText = new wxStaticText(this, wxID_ANY, "630610737", wxPoint(180, 80 + plus1), wxSize(85, 25));
	Text = new wxStaticText(this, wxID_ANY, "-Project manager -Coding", wxPoint(50, 105 + plus1), wxSize(85, 75));
	HeadText->SetFont(HeaderFont_02);
	SpecialText->SetFont(SpecialFont_Text);
	Text->SetFont(NormalFont_01);

	HeadText = new wxStaticText(this, wxID_ANY, "CHAYANON PITAK", wxPoint(30, 130 + plus1), wxSize(85, 25));
	SpecialText = new wxStaticText(this, wxID_ANY, "630610724", wxPoint(180, 130 + plus1), wxSize(85, 25));
	Text = new wxStaticText(this, wxID_ANY, "-Project manager -Coding", wxPoint(50, 155 + plus1), wxSize(85, 75));
	HeadText->SetFont(HeaderFont_02);
	SpecialText->SetFont(SpecialFont_Text);
	Text->SetFont(NormalFont_01);

	HeadText = new wxStaticText(this, wxID_ANY, "CHETSADA CHAINANTI", wxPoint(30, 180 + plus1), wxSize(85, 25));
	SpecialText = new wxStaticText(this, wxID_ANY, "630610723", wxPoint(180, 180 + plus1), wxSize(85, 25));
	Text = new wxStaticText(this, wxID_ANY, "-Coding", wxPoint(50, 205 + plus1), wxSize(85, 165));
	HeadText->SetFont(HeaderFont_02);
	SpecialText->SetFont(SpecialFont_Text);
	Text->SetFont(NormalFont_01);

	HeadText = new wxStaticText(this, wxID_ANY, "TANANUN CHOWDEE", wxPoint(30, 230 + plus1), wxSize(85, 25));
	SpecialText = new wxStaticText(this, wxID_ANY, "630610735", wxPoint(180, 230 + plus1), wxSize(85, 25));
	Text = new wxStaticText(this, wxID_ANY, "-Coding", wxPoint(50, 255 + plus1), wxSize(85, 250));
	HeadText->SetFont(HeaderFont_02);
	SpecialText->SetFont(SpecialFont_Text);
	Text->SetFont(NormalFont_01);

	HeadText = new wxStaticText(this, wxID_ANY, "THIDTANAI KAEWPHET", wxPoint(30, 280 + plus1), wxSize(85, 25));
	SpecialText = new wxStaticText(this, wxID_ANY, "630610741", wxPoint(180, 280 + plus1), wxSize(85, 25));
	Text = new wxStaticText(this, wxID_ANY, "-UI/UX", wxPoint(50, 305 + plus1), wxSize(85, 300));
	HeadText->SetFont(HeaderFont_02);
	SpecialText->SetFont(SpecialFont_Text);
	Text->SetFont(NormalFont_01);
	//Header02-----------------------------
	const int plus2 = 0;
	HeaderText = new wxStaticText(this, wxID_ANY, "Uics", wxPoint(10, 50 + plus2), wxSize(85, 25));
	HeaderText->SetFont(HeaderFont_01);
	//Detail02
	HeadText = new wxStaticText(this, wxID_ANY, "Virsion:", wxPoint(30, 80 + plus2), wxSize(85, 25));
	SpecialText = new wxStaticText(this, wxID_ANY, "0.221", wxPoint(180, 80 + plus2), wxSize(85, 25));
	HeadText->SetFont(HeaderFont_02);
	SpecialText->SetFont(SpecialFont_Text);
	HeadText = new wxStaticText(this, wxID_ANY, "Language:", wxPoint(30, 105 + plus2), wxSize(85, 25));
	SpecialText = new wxStaticText(this, wxID_ANY, "English", wxPoint(180, 105 + plus2), wxSize(85, 25));
	HeadText->SetFont(HeaderFont_02);
	SpecialText->SetFont(SpecialFont_Text);
	HeadText = new wxStaticText(this, wxID_ANY, "Last upadate:", wxPoint(30, 130 + plus2), wxSize(85, 25));
	SpecialText = new wxStaticText(this, wxID_ANY, "3/14/2021", wxPoint(180, 130 + plus2), wxSize(85, 25));
	HeadText->SetFont(HeaderFont_02);
	SpecialText->SetFont(SpecialFont_Text);
}
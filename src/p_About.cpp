 #include "p_About.h"

#include <wx/wxprec.h>

p_About::p_About(wxWindow* parent) :wxFrame (parent, wxID_ANY, "About", wxPoint(150, 150), wxSize(500, 500))
{
	//----------------------------------------Font------------------------------------------------------
	HeaderFont = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	HeaderFont_01 = wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	HeaderFont_02 = wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	NormalFont_01 = wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	NormalFont_02 = wxFont(5, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	SpecialFont_Head = wxFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT);
	SpecialFont_Text = wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT);
	//----------------------------------------Font------------------------------------------------------
	//BigHead------------------------------
	int plus1 = 20;
	BigHeaderText = new wxStaticText(this, wxID_ANY,"About Uics",wxPoint(0, 0), wxSize(85, 25));
	BigHeaderText->SetFont(HeaderFont);
	BigHeaderText = new wxStaticText(this, wxID_ANY, "2021", wxPoint(120, 0), wxSize(85, 25));
	BigHeaderText->SetFont(SpecialFont_Head);
	//Header01-----------------------------
	HeaderText = new wxStaticText(this, wxID_ANY, "Developer", wxPoint(10, 50), wxSize(85, 25));
	HeaderText->SetFont(HeaderFont_01);
	//Detail01
	HeadText = new wxStaticText(this, wxID_ANY, "TANAT TANGUN", wxPoint(30, 80), wxSize(85, 25));
	SpacialText = new wxStaticText(this, wxID_ANY, "630610737", wxPoint(180, 80), wxSize(85, 25));
	Text = new wxStaticText(this, wxID_ANY, "-Project manager -Coding", wxPoint(50, 105), wxSize(85, 75));
	HeadText ->SetFont(HeaderFont_02);
	SpacialText->SetFont(SpecialFont_Text);
	Text->SetFont(NormalFont_01);

	HeadText = new wxStaticText(this, wxID_ANY, "CHAYANON PITAK", wxPoint(30, 130), wxSize(85, 25));
	SpacialText = new wxStaticText(this, wxID_ANY, "630610724", wxPoint(180, 130), wxSize(85, 25));
	Text = new wxStaticText(this, wxID_ANY, "-Project manager -Coding", wxPoint(50, 155), wxSize(85, 75));
	HeadText->SetFont(HeaderFont_02);
	SpacialText->SetFont(SpecialFont_Text);
	Text->SetFont(NormalFont_01);

	HeadText = new wxStaticText(this, wxID_ANY, "CHETSADA CHAINANTI", wxPoint(30, 180), wxSize(85, 25));
	SpacialText = new wxStaticText(this, wxID_ANY, "630610723", wxPoint(180, 180), wxSize(85, 25));
	Text = new wxStaticText(this, wxID_ANY, "-Coding", wxPoint(50, 205), wxSize(85, 165));
	HeadText->SetFont(HeaderFont_02);
	SpacialText->SetFont(SpecialFont_Text);
	Text->SetFont(NormalFont_01);

	HeadText = new wxStaticText(this, wxID_ANY, "TANANUN CHOWDEE", wxPoint(30, 230), wxSize(85, 25));
	SpacialText = new wxStaticText(this, wxID_ANY, "630610735", wxPoint(180, 230), wxSize(85, 25));
	Text = new wxStaticText(this, wxID_ANY, "-Coding", wxPoint(50, 255), wxSize(85, 250));
	HeadText->SetFont(HeaderFont_02);
	SpacialText->SetFont(SpecialFont_Text);
	Text->SetFont(NormalFont_01);

	HeadText = new wxStaticText(this, wxID_ANY, "THIDTANAI KAEWPHET", wxPoint(30, 280), wxSize(85, 25));
	SpacialText = new wxStaticText(this, wxID_ANY, "630610741", wxPoint(180, 280), wxSize(85, 25));
	Text = new wxStaticText(this, wxID_ANY, "-UI/UX", wxPoint(50, 305), wxSize(85, 300));
	HeadText->SetFont(HeaderFont_02);
	SpacialText->SetFont(SpecialFont_Text);
	Text->SetFont(NormalFont_01);

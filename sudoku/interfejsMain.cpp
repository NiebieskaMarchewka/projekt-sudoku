/***************************************************************
 * Name:      interfejsMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    ala ()
 * Created:   2021-05-20
 * Copyright: ala ()
 * License:
 **************************************************************/

#include "interfejsMain.h"
#include <wx/msgdlg.h>
#include "wczytywanie.h"
#include "zapisywanie.h"
#include "algorytm.h"
#include<iostream>
#include<fstream>
#include<string>

//(*InternalHeaders(interfejsDialog)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(interfejsDialog)
const long interfejsDialog::ID_BUTTON1 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL82 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL1 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL2 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL3 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL10 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL11 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL12 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL19 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL20 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL21 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL4 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL5 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL6 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL13 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL14 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL15 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL22 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL23 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL24 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL7 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL8 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL9 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL16 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL17 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL18 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL25 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL26 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL27 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL28 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL29 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL30 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL37 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL38 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL39 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL46 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL47 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL48 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL31 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL32 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL33 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL40 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL41 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL42 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL49 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL50 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL51 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL34 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL35 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL36 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL43 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL44 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL45 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL52 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL53 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL54 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL55 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL56 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL57 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL64 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL65 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL66 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL73 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL74 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL75 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL58 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL59 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL60 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL67 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL68 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL69 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL76 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL77 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL78 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL61 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL62 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL63 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL70 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL71 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL72 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL79 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL80 = wxNewId();
const long interfejsDialog::ID_TEXTCTRL81 = wxNewId();
const long interfejsDialog::ID_BUTTON2 = wxNewId();
const long interfejsDialog::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(interfejsDialog,wxDialog)
    //(*EventTable(interfejsDialog)
    //*)
END_EVENT_TABLE()

interfejsDialog::interfejsDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(interfejsDialog)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer4;
    wxGridSizer* GridSizer1;
    wxGridSizer* GridSizer2;
    wxGridSizer* GridSizer3;
    wxGridSizer* GridSizer4;
    wxGridSizer* GridSizer5;
    wxGridSizer* GridSizer6;
    wxGridSizer* GridSizer7;
    wxGridSizer* GridSizer8;
    wxGridSizer* GridSizer9;

    Create(parent, wxID_ANY, _("SUDOKU"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU|wxCLOSE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    SetBackgroundColour(wxColour(64,64,64));
    FlexGridSizer1 = new wxFlexGridSizer(4, 0, 0, 0);
    FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
    Button1 = new wxButton(this, ID_BUTTON1, _("Wybierz plik"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetToolTip(_("Kliknij, aby wczytać planszę sudoku"));
    FlexGridSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl82 = new wxTextCtrl(this, ID_TEXTCTRL82, wxEmptyString, wxDefaultPosition, wxSize(239,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL82"));
    TextCtrl82->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVEBORDER));
    FlexGridSizer2->Add(TextCtrl82, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(3, 3, -15, -15);
    GridSizer1 = new wxGridSizer(0, 3, -10, -10);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    wxFont TextCtrl1Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl1->SetFont(TextCtrl1Font);
    GridSizer1->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    wxFont TextCtrl2Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl2->SetFont(TextCtrl2Font);
    GridSizer1->Add(TextCtrl2, 1, wxALL, 5);
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    wxFont TextCtrl3Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl3->SetFont(TextCtrl3Font);
    GridSizer1->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl10 = new wxTextCtrl(this, ID_TEXTCTRL10, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    wxFont TextCtrl10Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl10->SetFont(TextCtrl10Font);
    GridSizer1->Add(TextCtrl10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl11 = new wxTextCtrl(this, ID_TEXTCTRL11, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL11"));
    wxFont TextCtrl11Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl11->SetFont(TextCtrl11Font);
    GridSizer1->Add(TextCtrl11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl12 = new wxTextCtrl(this, ID_TEXTCTRL12, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL12"));
    wxFont TextCtrl12Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl12->SetFont(TextCtrl12Font);
    GridSizer1->Add(TextCtrl12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl19 = new wxTextCtrl(this, ID_TEXTCTRL19, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL19"));
    wxFont TextCtrl19Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl19->SetFont(TextCtrl19Font);
    GridSizer1->Add(TextCtrl19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl20 = new wxTextCtrl(this, ID_TEXTCTRL20, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL20"));
    wxFont TextCtrl20Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl20->SetFont(TextCtrl20Font);
    GridSizer1->Add(TextCtrl20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl21 = new wxTextCtrl(this, ID_TEXTCTRL21, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL21"));
    wxFont TextCtrl21Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl21->SetFont(TextCtrl21Font);
    GridSizer1->Add(TextCtrl21, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(GridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer2 = new wxGridSizer(0, 3, -10, -10);
    TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    wxFont TextCtrl4Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl4->SetFont(TextCtrl4Font);
    GridSizer2->Add(TextCtrl4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    wxFont TextCtrl5Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl5->SetFont(TextCtrl5Font);
    GridSizer2->Add(TextCtrl5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl6 = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    wxFont TextCtrl6Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl6->SetFont(TextCtrl6Font);
    GridSizer2->Add(TextCtrl6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl13 = new wxTextCtrl(this, ID_TEXTCTRL13, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL13"));
    wxFont TextCtrl13Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl13->SetFont(TextCtrl13Font);
    GridSizer2->Add(TextCtrl13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl14 = new wxTextCtrl(this, ID_TEXTCTRL14, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL14"));
    wxFont TextCtrl14Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl14->SetFont(TextCtrl14Font);
    GridSizer2->Add(TextCtrl14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl15 = new wxTextCtrl(this, ID_TEXTCTRL15, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL15"));
    wxFont TextCtrl15Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl15->SetFont(TextCtrl15Font);
    GridSizer2->Add(TextCtrl15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl22 = new wxTextCtrl(this, ID_TEXTCTRL22, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL22"));
    wxFont TextCtrl22Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl22->SetFont(TextCtrl22Font);
    GridSizer2->Add(TextCtrl22, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl23 = new wxTextCtrl(this, ID_TEXTCTRL23, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL23"));
    wxFont TextCtrl23Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl23->SetFont(TextCtrl23Font);
    GridSizer2->Add(TextCtrl23, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl24 = new wxTextCtrl(this, ID_TEXTCTRL24, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL24"));
    wxFont TextCtrl24Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl24->SetFont(TextCtrl24Font);
    GridSizer2->Add(TextCtrl24, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(GridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer3 = new wxGridSizer(0, 3, -10, -10);
    TextCtrl7 = new wxTextCtrl(this, ID_TEXTCTRL7, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    wxFont TextCtrl7Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl7->SetFont(TextCtrl7Font);
    GridSizer3->Add(TextCtrl7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl8 = new wxTextCtrl(this, ID_TEXTCTRL8, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    wxFont TextCtrl8Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl8->SetFont(TextCtrl8Font);
    GridSizer3->Add(TextCtrl8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl9 = new wxTextCtrl(this, ID_TEXTCTRL9, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    wxFont TextCtrl9Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl9->SetFont(TextCtrl9Font);
    GridSizer3->Add(TextCtrl9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl16 = new wxTextCtrl(this, ID_TEXTCTRL16, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL16"));
    wxFont TextCtrl16Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl16->SetFont(TextCtrl16Font);
    GridSizer3->Add(TextCtrl16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl17 = new wxTextCtrl(this, ID_TEXTCTRL17, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL17"));
    wxFont TextCtrl17Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl17->SetFont(TextCtrl17Font);
    GridSizer3->Add(TextCtrl17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl18 = new wxTextCtrl(this, ID_TEXTCTRL18, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL18"));
    wxFont TextCtrl18Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl18->SetFont(TextCtrl18Font);
    GridSizer3->Add(TextCtrl18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl25 = new wxTextCtrl(this, ID_TEXTCTRL25, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL25"));
    wxFont TextCtrl25Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl25->SetFont(TextCtrl25Font);
    GridSizer3->Add(TextCtrl25, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl26 = new wxTextCtrl(this, ID_TEXTCTRL26, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL26"));
    wxFont TextCtrl26Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl26->SetFont(TextCtrl26Font);
    GridSizer3->Add(TextCtrl26, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl27 = new wxTextCtrl(this, ID_TEXTCTRL27, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL27"));
    wxFont TextCtrl27Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl27->SetFont(TextCtrl27Font);
    GridSizer3->Add(TextCtrl27, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(GridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer4 = new wxGridSizer(0, 3, -10, -10);
    TextCtrl28 = new wxTextCtrl(this, ID_TEXTCTRL28, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL28"));
    wxFont TextCtrl28Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl28->SetFont(TextCtrl28Font);
    GridSizer4->Add(TextCtrl28, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl29 = new wxTextCtrl(this, ID_TEXTCTRL29, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL29"));
    wxFont TextCtrl29Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl29->SetFont(TextCtrl29Font);
    GridSizer4->Add(TextCtrl29, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl30 = new wxTextCtrl(this, ID_TEXTCTRL30, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL30"));
    wxFont TextCtrl30Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl30->SetFont(TextCtrl30Font);
    GridSizer4->Add(TextCtrl30, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl37 = new wxTextCtrl(this, ID_TEXTCTRL37, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL37"));
    wxFont TextCtrl37Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl37->SetFont(TextCtrl37Font);
    GridSizer4->Add(TextCtrl37, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl38 = new wxTextCtrl(this, ID_TEXTCTRL38, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL38"));
    wxFont TextCtrl38Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl38->SetFont(TextCtrl38Font);
    GridSizer4->Add(TextCtrl38, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl39 = new wxTextCtrl(this, ID_TEXTCTRL39, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL39"));
    wxFont TextCtrl39Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl39->SetFont(TextCtrl39Font);
    GridSizer4->Add(TextCtrl39, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl46 = new wxTextCtrl(this, ID_TEXTCTRL46, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL46"));
    wxFont TextCtrl46Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl46->SetFont(TextCtrl46Font);
    GridSizer4->Add(TextCtrl46, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl47 = new wxTextCtrl(this, ID_TEXTCTRL47, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL47"));
    wxFont TextCtrl47Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl47->SetFont(TextCtrl47Font);
    GridSizer4->Add(TextCtrl47, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl48 = new wxTextCtrl(this, ID_TEXTCTRL48, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL48"));
    wxFont TextCtrl48Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl48->SetFont(TextCtrl48Font);
    GridSizer4->Add(TextCtrl48, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(GridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer5 = new wxGridSizer(0, 3, -10, -10);
    TextCtrl31 = new wxTextCtrl(this, ID_TEXTCTRL31, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL31"));
    wxFont TextCtrl31Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl31->SetFont(TextCtrl31Font);
    GridSizer5->Add(TextCtrl31, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl32 = new wxTextCtrl(this, ID_TEXTCTRL32, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL32"));
    wxFont TextCtrl32Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl32->SetFont(TextCtrl32Font);
    GridSizer5->Add(TextCtrl32, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl33 = new wxTextCtrl(this, ID_TEXTCTRL33, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL33"));
    wxFont TextCtrl33Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl33->SetFont(TextCtrl33Font);
    GridSizer5->Add(TextCtrl33, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl40 = new wxTextCtrl(this, ID_TEXTCTRL40, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL40"));
    wxFont TextCtrl40Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl40->SetFont(TextCtrl40Font);
    GridSizer5->Add(TextCtrl40, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl41 = new wxTextCtrl(this, ID_TEXTCTRL41, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL41"));
    wxFont TextCtrl41Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl41->SetFont(TextCtrl41Font);
    GridSizer5->Add(TextCtrl41, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl42 = new wxTextCtrl(this, ID_TEXTCTRL42, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL42"));
    wxFont TextCtrl42Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl42->SetFont(TextCtrl42Font);
    GridSizer5->Add(TextCtrl42, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl49 = new wxTextCtrl(this, ID_TEXTCTRL49, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL49"));
    wxFont TextCtrl49Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl49->SetFont(TextCtrl49Font);
    GridSizer5->Add(TextCtrl49, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl50 = new wxTextCtrl(this, ID_TEXTCTRL50, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL50"));
    wxFont TextCtrl50Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl50->SetFont(TextCtrl50Font);
    GridSizer5->Add(TextCtrl50, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl51 = new wxTextCtrl(this, ID_TEXTCTRL51, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL51"));
    wxFont TextCtrl51Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl51->SetFont(TextCtrl51Font);
    GridSizer5->Add(TextCtrl51, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(GridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer6 = new wxGridSizer(0, 3, -10, -10);
    TextCtrl34 = new wxTextCtrl(this, ID_TEXTCTRL34, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL34"));
    wxFont TextCtrl34Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl34->SetFont(TextCtrl34Font);
    GridSizer6->Add(TextCtrl34, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl35 = new wxTextCtrl(this, ID_TEXTCTRL35, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL35"));
    wxFont TextCtrl35Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl35->SetFont(TextCtrl35Font);
    GridSizer6->Add(TextCtrl35, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl36 = new wxTextCtrl(this, ID_TEXTCTRL36, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL36"));
    wxFont TextCtrl36Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl36->SetFont(TextCtrl36Font);
    GridSizer6->Add(TextCtrl36, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl43 = new wxTextCtrl(this, ID_TEXTCTRL43, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL43"));
    wxFont TextCtrl43Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl43->SetFont(TextCtrl43Font);
    GridSizer6->Add(TextCtrl43, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl44 = new wxTextCtrl(this, ID_TEXTCTRL44, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL44"));
    wxFont TextCtrl44Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl44->SetFont(TextCtrl44Font);
    GridSizer6->Add(TextCtrl44, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl45 = new wxTextCtrl(this, ID_TEXTCTRL45, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL45"));
    wxFont TextCtrl45Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl45->SetFont(TextCtrl45Font);
    GridSizer6->Add(TextCtrl45, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl52 = new wxTextCtrl(this, ID_TEXTCTRL52, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL52"));
    wxFont TextCtrl52Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl52->SetFont(TextCtrl52Font);
    GridSizer6->Add(TextCtrl52, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl53 = new wxTextCtrl(this, ID_TEXTCTRL53, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL53"));
    wxFont TextCtrl53Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl53->SetFont(TextCtrl53Font);
    GridSizer6->Add(TextCtrl53, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl54 = new wxTextCtrl(this, ID_TEXTCTRL54, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL54"));
    wxFont TextCtrl54Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl54->SetFont(TextCtrl54Font);
    GridSizer6->Add(TextCtrl54, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(GridSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer7 = new wxGridSizer(0, 3, -10, -10);
    TextCtrl55 = new wxTextCtrl(this, ID_TEXTCTRL55, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL55"));
    wxFont TextCtrl55Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl55->SetFont(TextCtrl55Font);
    GridSizer7->Add(TextCtrl55, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl56 = new wxTextCtrl(this, ID_TEXTCTRL56, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL56"));
    wxFont TextCtrl56Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl56->SetFont(TextCtrl56Font);
    GridSizer7->Add(TextCtrl56, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl57 = new wxTextCtrl(this, ID_TEXTCTRL57, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL57"));
    wxFont TextCtrl57Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl57->SetFont(TextCtrl57Font);
    GridSizer7->Add(TextCtrl57, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl64 = new wxTextCtrl(this, ID_TEXTCTRL64, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL64"));
    wxFont TextCtrl64Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl64->SetFont(TextCtrl64Font);
    GridSizer7->Add(TextCtrl64, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl65 = new wxTextCtrl(this, ID_TEXTCTRL65, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL65"));
    wxFont TextCtrl65Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl65->SetFont(TextCtrl65Font);
    GridSizer7->Add(TextCtrl65, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl66 = new wxTextCtrl(this, ID_TEXTCTRL66, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL66"));
    wxFont TextCtrl66Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl66->SetFont(TextCtrl66Font);
    GridSizer7->Add(TextCtrl66, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl73 = new wxTextCtrl(this, ID_TEXTCTRL73, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL73"));
    wxFont TextCtrl73Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl73->SetFont(TextCtrl73Font);
    GridSizer7->Add(TextCtrl73, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl74 = new wxTextCtrl(this, ID_TEXTCTRL74, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL74"));
    wxFont TextCtrl74Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl74->SetFont(TextCtrl74Font);
    GridSizer7->Add(TextCtrl74, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl75 = new wxTextCtrl(this, ID_TEXTCTRL75, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL75"));
    wxFont TextCtrl75Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl75->SetFont(TextCtrl75Font);
    GridSizer7->Add(TextCtrl75, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(GridSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer8 = new wxGridSizer(0, 3, -10, -10);
    TextCtrl58 = new wxTextCtrl(this, ID_TEXTCTRL58, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL58"));
    wxFont TextCtrl58Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl58->SetFont(TextCtrl58Font);
    GridSizer8->Add(TextCtrl58, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl59 = new wxTextCtrl(this, ID_TEXTCTRL59, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL59"));
    wxFont TextCtrl59Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl59->SetFont(TextCtrl59Font);
    GridSizer8->Add(TextCtrl59, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl60 = new wxTextCtrl(this, ID_TEXTCTRL60, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL60"));
    wxFont TextCtrl60Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl60->SetFont(TextCtrl60Font);
    GridSizer8->Add(TextCtrl60, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl67 = new wxTextCtrl(this, ID_TEXTCTRL67, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL67"));
    wxFont TextCtrl67Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl67->SetFont(TextCtrl67Font);
    GridSizer8->Add(TextCtrl67, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl68 = new wxTextCtrl(this, ID_TEXTCTRL68, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL68"));
    wxFont TextCtrl68Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl68->SetFont(TextCtrl68Font);
    GridSizer8->Add(TextCtrl68, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl69 = new wxTextCtrl(this, ID_TEXTCTRL69, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL69"));
    wxFont TextCtrl69Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl69->SetFont(TextCtrl69Font);
    GridSizer8->Add(TextCtrl69, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl76 = new wxTextCtrl(this, ID_TEXTCTRL76, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL76"));
    wxFont TextCtrl76Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl76->SetFont(TextCtrl76Font);
    GridSizer8->Add(TextCtrl76, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl77 = new wxTextCtrl(this, ID_TEXTCTRL77, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL77"));
    wxFont TextCtrl77Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl77->SetFont(TextCtrl77Font);
    GridSizer8->Add(TextCtrl77, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl78 = new wxTextCtrl(this, ID_TEXTCTRL78, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL78"));
    wxFont TextCtrl78Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl78->SetFont(TextCtrl78Font);
    GridSizer8->Add(TextCtrl78, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(GridSizer8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer9 = new wxGridSizer(0, 3, -10, -10);
    TextCtrl61 = new wxTextCtrl(this, ID_TEXTCTRL61, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL61"));
    wxFont TextCtrl61Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl61->SetFont(TextCtrl61Font);
    GridSizer9->Add(TextCtrl61, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl62 = new wxTextCtrl(this, ID_TEXTCTRL62, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL62"));
    wxFont TextCtrl62Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl62->SetFont(TextCtrl62Font);
    GridSizer9->Add(TextCtrl62, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl63 = new wxTextCtrl(this, ID_TEXTCTRL63, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL63"));
    wxFont TextCtrl63Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl63->SetFont(TextCtrl63Font);
    GridSizer9->Add(TextCtrl63, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl70 = new wxTextCtrl(this, ID_TEXTCTRL70, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL70"));
    wxFont TextCtrl70Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl70->SetFont(TextCtrl70Font);
    GridSizer9->Add(TextCtrl70, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl71 = new wxTextCtrl(this, ID_TEXTCTRL71, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL71"));
    wxFont TextCtrl71Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl71->SetFont(TextCtrl71Font);
    GridSizer9->Add(TextCtrl71, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl72 = new wxTextCtrl(this, ID_TEXTCTRL72, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL72"));
    wxFont TextCtrl72Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl72->SetFont(TextCtrl72Font);
    GridSizer9->Add(TextCtrl72, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl79 = new wxTextCtrl(this, ID_TEXTCTRL79, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL79"));
    wxFont TextCtrl79Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl79->SetFont(TextCtrl79Font);
    GridSizer9->Add(TextCtrl79, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl80 = new wxTextCtrl(this, ID_TEXTCTRL80, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL80"));
    wxFont TextCtrl80Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl80->SetFont(TextCtrl80Font);
    GridSizer9->Add(TextCtrl80, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl81 = new wxTextCtrl(this, ID_TEXTCTRL81, wxEmptyString, wxDefaultPosition, wxSize(40,40), wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL81"));
    wxFont TextCtrl81Font(24,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextCtrl81->SetFont(TextCtrl81Font);
    GridSizer9->Add(TextCtrl81, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(GridSizer9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
    Button2 = new wxButton(this, ID_BUTTON2, _("Rozwiąż sudoku"), wxDefaultPosition, wxSize(168,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2->SetToolTip(_("Kliknij, aby rozwiązać sudoku"));
    FlexGridSizer4->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("Zapisz sudoku"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button3->SetToolTip(_("Kliknij, aby zapisać obecną planszę sudoku"));
    FlexGridSizer1->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FileDialog = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&interfejsDialog::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&interfejsDialog::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&interfejsDialog::OnButton3Click);
    //*)

    SetIcon(wxICON(aaaa));

    komorki[0][0]=TextCtrl1;
    komorki[0][1]=TextCtrl2;
    komorki[0][2]=TextCtrl3;
    komorki[0][3]=TextCtrl4;
    komorki[0][4]=TextCtrl5;
    komorki[0][5]=TextCtrl6;
    komorki[0][6]=TextCtrl7;
    komorki[0][7]=TextCtrl8;
    komorki[0][8]=TextCtrl9;
        komorki[1][0]=TextCtrl10;
        komorki[1][1]=TextCtrl11;
        komorki[1][2]=TextCtrl12;
        komorki[1][3]=TextCtrl13;
        komorki[1][4]=TextCtrl14;
        komorki[1][5]=TextCtrl15;
        komorki[1][6]=TextCtrl16;
        komorki[1][7]=TextCtrl17;
        komorki[1][8]=TextCtrl18;
    komorki[2][0]=TextCtrl19;
    komorki[2][1]=TextCtrl20;
    komorki[2][2]=TextCtrl21;
    komorki[2][3]=TextCtrl22;
    komorki[2][4]=TextCtrl23;
    komorki[2][5]=TextCtrl24;
    komorki[2][6]=TextCtrl25;
    komorki[2][7]=TextCtrl26;
    komorki[2][8]=TextCtrl27;
        komorki[3][0]=TextCtrl28;
        komorki[3][1]=TextCtrl29;
        komorki[3][2]=TextCtrl30;
        komorki[3][3]=TextCtrl31;
        komorki[3][4]=TextCtrl32;
        komorki[3][5]=TextCtrl33;
        komorki[3][6]=TextCtrl34;
        komorki[3][7]=TextCtrl35;
        komorki[3][8]=TextCtrl36;
    komorki[4][0]=TextCtrl37;
    komorki[4][1]=TextCtrl38;
    komorki[4][2]=TextCtrl39;
    komorki[4][3]=TextCtrl40;
    komorki[4][4]=TextCtrl41;
    komorki[4][5]=TextCtrl42;
    komorki[4][6]=TextCtrl43;
    komorki[4][7]=TextCtrl44;
    komorki[4][8]=TextCtrl45;
        komorki[5][0]=TextCtrl46;
        komorki[5][1]=TextCtrl47;
        komorki[5][2]=TextCtrl48;
        komorki[5][3]=TextCtrl49;
        komorki[5][4]=TextCtrl50;
        komorki[5][5]=TextCtrl51;
        komorki[5][6]=TextCtrl52;
        komorki[5][7]=TextCtrl53;
        komorki[5][8]=TextCtrl54;
    komorki[6][0]=TextCtrl55;
    komorki[6][1]=TextCtrl56;
    komorki[6][2]=TextCtrl57;
    komorki[6][3]=TextCtrl58;
    komorki[6][4]=TextCtrl59;
    komorki[6][5]=TextCtrl60;
    komorki[6][6]=TextCtrl61;
    komorki[6][7]=TextCtrl62;
    komorki[6][8]=TextCtrl63;
        komorki[7][0]=TextCtrl64;
        komorki[7][1]=TextCtrl65;
        komorki[7][2]=TextCtrl66;
        komorki[7][3]=TextCtrl67;
        komorki[7][4]=TextCtrl68;
        komorki[7][5]=TextCtrl69;
        komorki[7][6]=TextCtrl70;
        komorki[7][7]=TextCtrl71;
        komorki[7][8]=TextCtrl72;
    komorki[8][0]=TextCtrl73;
    komorki[8][1]=TextCtrl74;
    komorki[8][2]=TextCtrl75;
    komorki[8][3]=TextCtrl76;
    komorki[8][4]=TextCtrl77;
    komorki[8][5]=TextCtrl78;
    komorki[8][6]=TextCtrl79;
    komorki[8][7]=TextCtrl80;
    komorki[8][8]=TextCtrl81;


}


interfejsDialog::~interfejsDialog()
{
    //(*Destroy(interfejsDialog)
    //*)
}

void interfejsDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void interfejsDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}


string w2s(wxString w){
    return string(w.mb_str(wxConvUTF8));
}

wxString s2w(string s){
    return wxString(s.c_str(), wxConvUTF8);
}


//int tablica[9][9];          //Tablica, do ktorej beda wczytywane dane z komorek w klasie int






void interfejsDialog::OnButton1Click(wxCommandEvent& event)     //Akcja przycisku "Wybierz plik"
{
    wxFileDialog*dlg_wczytaj_dane=new wxFileDialog(this,_("Wskaż plik z danymi"),_(""),_(""),_("*.txt"),wxFD_OPEN|wxFD_CHANGE_DIR|wxFD_FILE_MUST_EXIST);
      if(dlg_wczytaj_dane->ShowModal()!=wxID_CANCEL)
        {
        TextCtrl82->SetValue(dlg_wczytaj_dane->GetPath());
        }
    delete dlg_wczytaj_dane;
    string sciezka=TextCtrl82->GetValue().ToStdString();

    if(sciezka.length()!=0)
    {
    wczytywanie w(sciezka, tablica);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
                if (tablica[i][j]==0)
                {
                    komorki[i][j]->Clear();
                    komorki[i][j]->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
                    komorki[i][j]->Enable(true);
                }
                else
                {
                    komorki[i][j]->SetValue(s2w(to_string(tablica[i][j])));
                    komorki[i][j]->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
                    komorki[i][j]->Enable(false);
                }
        }
    }
    }
}

void interfejsDialog::OnButton2Click(wxCommandEvent& event)     //Akcja przycisku "Rozwiąż sudoku"

{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
               if((komorki[i][j]->GetValue().ToStdString()).length()==0) tablica[i][j]=0;
               else tablica[i][j]=stoi(komorki[i][j]->GetValue().ToStdString());
        }
    }

    algorytm r(tablica);
    if(r.OK())
    {
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            komorki[i][j]->SetValue(s2w(to_string(tablica[i][j])));

        }
    }
        wxMessageBox(s2w(r.komunikat()), _("Sukces!"), wxICON_INFORMATION);
    }
    else
        wxMessageBox(s2w(r.komunikat()), _("Wystąpił problem!"), wxICON_ERROR);
}


void interfejsDialog::OnButton3Click(wxCommandEvent& event)      //Akcja przycisku "Zapisz sudoku"

{
    wxFileDialog*dlg_zapisz_dane=new wxFileDialog(this,_("Wskaż plik, w którym zapiszesz sudoku lub utwórz nowy"),_(""),_(""),_("*.txt"),wxFD_CHANGE_DIR);
      if(dlg_zapisz_dane->ShowModal()!=wxID_CANCEL)
        {
        TextCtrl82->SetValue(dlg_zapisz_dane->GetPath());
        }
    delete dlg_zapisz_dane;
    string sciezka=TextCtrl82->GetValue().ToStdString();



    if(sciezka.length()!=0)
    {
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
               if((komorki[i][j]->GetValue().ToStdString()).length()==0) tablica[i][j]=0;
               else tablica[i][j]=stoi(komorki[i][j]->GetValue().ToStdString());
        }
    }

        zapisywanie z(sciezka, tablica);
    }
}

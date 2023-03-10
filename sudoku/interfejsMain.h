/***************************************************************
 * Name:      interfejsMain.h
 * Purpose:   Defines Application Frame
 * Author:    ala ()
 * Created:   2021-05-20
 * Copyright: ala ()
 * License:
 **************************************************************/

#ifndef INTERFEJSMAIN_H
#define INTERFEJSMAIN_H

//(*Headers(interfejsDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/filedlg.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
//*)

class interfejsDialog: public wxDialog
{
    public:

        interfejsDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~interfejsDialog();

    private:

        //(*Handlers(interfejsDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnToggleButton2Toggle1(wxCommandEvent& event);
        void OnToggleButton1Toggle(wxCommandEvent& event);
        void OnToggleButton3Toggle(wxCommandEvent& event);
        void OnTextCtrl38Text(wxCommandEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(interfejsDialog)
        static const long ID_BUTTON1;
        static const long ID_TEXTCTRL82;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL10;
        static const long ID_TEXTCTRL11;
        static const long ID_TEXTCTRL12;
        static const long ID_TEXTCTRL19;
        static const long ID_TEXTCTRL20;
        static const long ID_TEXTCTRL21;
        static const long ID_TEXTCTRL4;
        static const long ID_TEXTCTRL5;
        static const long ID_TEXTCTRL6;
        static const long ID_TEXTCTRL13;
        static const long ID_TEXTCTRL14;
        static const long ID_TEXTCTRL15;
        static const long ID_TEXTCTRL22;
        static const long ID_TEXTCTRL23;
        static const long ID_TEXTCTRL24;
        static const long ID_TEXTCTRL7;
        static const long ID_TEXTCTRL8;
        static const long ID_TEXTCTRL9;
        static const long ID_TEXTCTRL16;
        static const long ID_TEXTCTRL17;
        static const long ID_TEXTCTRL18;
        static const long ID_TEXTCTRL25;
        static const long ID_TEXTCTRL26;
        static const long ID_TEXTCTRL27;
        static const long ID_TEXTCTRL28;
        static const long ID_TEXTCTRL29;
        static const long ID_TEXTCTRL30;
        static const long ID_TEXTCTRL37;
        static const long ID_TEXTCTRL38;
        static const long ID_TEXTCTRL39;
        static const long ID_TEXTCTRL46;
        static const long ID_TEXTCTRL47;
        static const long ID_TEXTCTRL48;
        static const long ID_TEXTCTRL31;
        static const long ID_TEXTCTRL32;
        static const long ID_TEXTCTRL33;
        static const long ID_TEXTCTRL40;
        static const long ID_TEXTCTRL41;
        static const long ID_TEXTCTRL42;
        static const long ID_TEXTCTRL49;
        static const long ID_TEXTCTRL50;
        static const long ID_TEXTCTRL51;
        static const long ID_TEXTCTRL34;
        static const long ID_TEXTCTRL35;
        static const long ID_TEXTCTRL36;
        static const long ID_TEXTCTRL43;
        static const long ID_TEXTCTRL44;
        static const long ID_TEXTCTRL45;
        static const long ID_TEXTCTRL52;
        static const long ID_TEXTCTRL53;
        static const long ID_TEXTCTRL54;
        static const long ID_TEXTCTRL55;
        static const long ID_TEXTCTRL56;
        static const long ID_TEXTCTRL57;
        static const long ID_TEXTCTRL64;
        static const long ID_TEXTCTRL65;
        static const long ID_TEXTCTRL66;
        static const long ID_TEXTCTRL73;
        static const long ID_TEXTCTRL74;
        static const long ID_TEXTCTRL75;
        static const long ID_TEXTCTRL58;
        static const long ID_TEXTCTRL59;
        static const long ID_TEXTCTRL60;
        static const long ID_TEXTCTRL67;
        static const long ID_TEXTCTRL68;
        static const long ID_TEXTCTRL69;
        static const long ID_TEXTCTRL76;
        static const long ID_TEXTCTRL77;
        static const long ID_TEXTCTRL78;
        static const long ID_TEXTCTRL61;
        static const long ID_TEXTCTRL62;
        static const long ID_TEXTCTRL63;
        static const long ID_TEXTCTRL70;
        static const long ID_TEXTCTRL71;
        static const long ID_TEXTCTRL72;
        static const long ID_TEXTCTRL79;
        static const long ID_TEXTCTRL80;
        static const long ID_TEXTCTRL81;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        //*)

        //(*Declarations(interfejsDialog)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxFileDialog* FileDialog;
        wxTextCtrl* TextCtrl10;
        wxTextCtrl* TextCtrl11;
        wxTextCtrl* TextCtrl12;
        wxTextCtrl* TextCtrl13;
        wxTextCtrl* TextCtrl14;
        wxTextCtrl* TextCtrl15;
        wxTextCtrl* TextCtrl16;
        wxTextCtrl* TextCtrl17;
        wxTextCtrl* TextCtrl18;
        wxTextCtrl* TextCtrl19;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl20;
        wxTextCtrl* TextCtrl21;
        wxTextCtrl* TextCtrl22;
        wxTextCtrl* TextCtrl23;
        wxTextCtrl* TextCtrl24;
        wxTextCtrl* TextCtrl25;
        wxTextCtrl* TextCtrl26;
        wxTextCtrl* TextCtrl27;
        wxTextCtrl* TextCtrl28;
        wxTextCtrl* TextCtrl29;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl30;
        wxTextCtrl* TextCtrl31;
        wxTextCtrl* TextCtrl32;
        wxTextCtrl* TextCtrl33;
        wxTextCtrl* TextCtrl34;
        wxTextCtrl* TextCtrl35;
        wxTextCtrl* TextCtrl36;
        wxTextCtrl* TextCtrl37;
        wxTextCtrl* TextCtrl38;
        wxTextCtrl* TextCtrl39;
        wxTextCtrl* TextCtrl3;
        wxTextCtrl* TextCtrl40;
        wxTextCtrl* TextCtrl41;
        wxTextCtrl* TextCtrl42;
        wxTextCtrl* TextCtrl43;
        wxTextCtrl* TextCtrl44;
        wxTextCtrl* TextCtrl45;
        wxTextCtrl* TextCtrl46;
        wxTextCtrl* TextCtrl47;
        wxTextCtrl* TextCtrl48;
        wxTextCtrl* TextCtrl49;
        wxTextCtrl* TextCtrl4;
        wxTextCtrl* TextCtrl50;
        wxTextCtrl* TextCtrl51;
        wxTextCtrl* TextCtrl52;
        wxTextCtrl* TextCtrl53;
        wxTextCtrl* TextCtrl54;
        wxTextCtrl* TextCtrl55;
        wxTextCtrl* TextCtrl56;
        wxTextCtrl* TextCtrl57;
        wxTextCtrl* TextCtrl58;
        wxTextCtrl* TextCtrl59;
        wxTextCtrl* TextCtrl5;
        wxTextCtrl* TextCtrl60;
        wxTextCtrl* TextCtrl61;
        wxTextCtrl* TextCtrl62;
        wxTextCtrl* TextCtrl63;
        wxTextCtrl* TextCtrl64;
        wxTextCtrl* TextCtrl65;
        wxTextCtrl* TextCtrl66;
        wxTextCtrl* TextCtrl67;
        wxTextCtrl* TextCtrl68;
        wxTextCtrl* TextCtrl69;
        wxTextCtrl* TextCtrl6;
        wxTextCtrl* TextCtrl70;
        wxTextCtrl* TextCtrl71;
        wxTextCtrl* TextCtrl72;
        wxTextCtrl* TextCtrl73;
        wxTextCtrl* TextCtrl74;
        wxTextCtrl* TextCtrl75;
        wxTextCtrl* TextCtrl76;
        wxTextCtrl* TextCtrl77;
        wxTextCtrl* TextCtrl78;
        wxTextCtrl* TextCtrl79;
        wxTextCtrl* TextCtrl7;
        wxTextCtrl* TextCtrl80;
        wxTextCtrl* TextCtrl81;
        wxTextCtrl* TextCtrl82;
        wxTextCtrl* TextCtrl8;
        wxTextCtrl* TextCtrl9;
        //*)
wxTextCtrl*komorki[9][9];
        DECLARE_EVENT_TABLE()

        int tablica[9][9];
};

#endif // INTERFEJSMAIN_H

/***************************************************************
 * Name:      interfejsApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ala ()
 * Created:   2021-05-20
 * Copyright: ala ()
 * License:
 **************************************************************/

#include "interfejsApp.h"

//(*AppHeaders
#include "interfejsMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(interfejsApp);

bool interfejsApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	interfejsDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}

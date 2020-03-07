/***************************************************************
 * Name:      GUIClienteApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Roy ()
 * Created:   2020-03-06
 * Copyright: Roy ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "GUIClienteApp.h"
#include "GUIClienteMain.h"

IMPLEMENT_APP(GUIClienteApp);

bool GUIClienteApp::OnInit()
{
    GUIClienteFrame* frame = new GUIClienteFrame(0L, _("wxWidgets Application Template"));
    
    frame->Show();
    
    return true;
}

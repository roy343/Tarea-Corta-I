/***************************************************************
 * Name:      GUIClienteMain.h
 * Purpose:   Defines Application Frame
 * Author:    Roy ()
 * Created:   2020-03-06
 * Copyright: Roy ()
 * License:
 **************************************************************/

#ifndef GUICLIENTEMAIN_H
#define GUICLIENTEMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "GUIClienteApp.h"

class GUIClienteFrame: public wxFrame
{
    public:
        GUIClienteFrame(wxFrame *frame, const wxString& title);
        ~GUIClienteFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // GUICLIENTEMAIN_H

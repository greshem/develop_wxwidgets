/////////////////////////////////////////////////////////////////////////////
// Name:        aboutDlg.cpp
// Purpose:
// Author:      Matthew Witherwax
// Modified by:
// Created:     09/03/05 20:36:34
// RCS-ID:
// Copyright:   Copyright (c) 2005 Matthew Witherwax
// Licence:
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma implementation "aboutDlg.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "aboutDlg.h"

////@begin XPM images
////@end XPM images

/*!
 * AboutDlg type definition
 */

IMPLEMENT_DYNAMIC_CLASS( AboutDlg, wxDialog )

/*!
 * AboutDlg event table definition
 */

BEGIN_EVENT_TABLE( AboutDlg, wxDialog )

////@begin AboutDlg event table entries
    EVT_BUTTON( ABOUTOK_BUTTON, AboutDlg::OnAboutokButtonClick )

////@end AboutDlg event table entries

END_EVENT_TABLE()

/*!
 * AboutDlg constructors
 */

AboutDlg::AboutDlg( )
{
}

AboutDlg::AboutDlg( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);
}

/*!
 * AboutDlg creator
 */

bool AboutDlg::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin AboutDlg member initialisation
////@end AboutDlg member initialisation

////@begin AboutDlg creation
    SetExtraStyle(GetExtraStyle()|wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    Centre();
////@end AboutDlg creation
    return TRUE;
}

/*!
 * Control creation for AboutDlg
 */

void AboutDlg::CreateControls()
{
////@begin AboutDlg content construction
    AboutDlg* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxNotebook* itemNotebook3 = new wxNotebook( itemDialog1, INFO_NOTEBOOK, wxDefaultPosition, wxSize(500, 300), wxNB_TOP|wxNB_FIXEDWIDTH );
    itemNotebook3->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxBOLD, false, _T("Courier New")));

    wxHtmlWindow* itemHtmlWindow4 = new wxHtmlWindow( itemNotebook3, ABOUT_HTMLWINDOW, wxDefaultPosition, wxSize(200, 150), wxHW_SCROLLBAR_AUTO|wxSUNKEN_BORDER|wxHSCROLL|wxVSCROLL );

    itemNotebook3->AddPage(itemHtmlWindow4, _("O programie"));

    wxHtmlWindow* itemHtmlWindow5 = new wxHtmlWindow( itemNotebook3, LICENSE_HTMLWINDOW, wxDefaultPosition, wxSize(200, 150), wxHW_SCROLLBAR_AUTO|wxSUNKEN_BORDER|wxHSCROLL|wxVSCROLL );

    itemNotebook3->AddPage(itemHtmlWindow5, _("Licencja"));

    wxHtmlWindow* itemHtmlWindow6 = new wxHtmlWindow( itemNotebook3, CREDITS_HTMLWINDOW, wxDefaultPosition, wxSize(200, 150), wxHW_SCROLLBAR_AUTO|wxSUNKEN_BORDER|wxHSCROLL|wxVSCROLL );

    itemNotebook3->AddPage(itemHtmlWindow6, _("Uznanie"));

    itemBoxSizer2->Add(itemNotebook3, 1, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer7, 0, wxALIGN_RIGHT|wxALL, 5);

    wxButton* itemButton8 = new wxButton( itemDialog1, ABOUTOK_BUTTON, _("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
    itemButton8->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxBOLD, false, _T("Courier New")));
    itemBoxSizer7->Add(itemButton8, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end AboutDlg content construction

    if (wxFileExists(_T("about.htm")))
    {
        wxHtmlWindow* aboutWindow = wxDynamicCast(FindWindow(ABOUT_HTMLWINDOW),
            wxHtmlWindow);
        aboutWindow->LoadPage(_T("about.htm"));
    }
    else
    {
        wxMessageDialog *dlgError=
		new wxMessageDialog(this,_T(
		"Brakuje pliku about.htm.\n  "),
		_T("bbbbbbbbbbbbb "), wxOK | wxCentre | wxICON_ERROR);
        dlgError->ShowModal();
    }

    if (wxFileExists(_T("licensepl.htm")))
    {
        wxHtmlWindow* licenseWindow = wxDynamicCast(FindWindow(LICENSE_HTMLWINDOW),
            wxHtmlWindow);
        licenseWindow->LoadPage(_T("licensepl.htm"));
    }
    else
    {
        wxMessageDialog *dlgError=
		new wxMessageDialog(this,
		_T("EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE"),
		_T("DDDDDDDDDDDDDDD"), wxOK | wxCentre | wxICON_ERROR);
        dlgError->ShowModal();
    }

    if (wxFileExists(_T("creditspl.htm")))
    {
        wxHtmlWindow* creditsWindow = wxDynamicCast(FindWindow(CREDITS_HTMLWINDOW),
            wxHtmlWindow);
        creditsWindow->LoadPage(_T("creditspl.htm"));
    }
    else
    {
        wxMessageDialog *dlgError=
		new wxMessageDialog(this,
		_T("EEEEEEEEEEEEEEEEEEEEEEEEEEEE"),
		_T("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF"), wxOK | wxCentre | wxICON_ERROR);
        dlgError->ShowModal();
    }
}

/*!
 * Should we show tooltips?
 */

bool AboutDlg::ShowToolTips()
{
    return TRUE;
}

/*!
 * Get bitmap resources
 */

wxBitmap AboutDlg::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin AboutDlg bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end AboutDlg bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon AboutDlg::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin AboutDlg icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end AboutDlg icon retrieval
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ABOUTOK_BUTTON
 */

void AboutDlg::OnAboutokButtonClick( wxCommandEvent& event )
{
    Close(FALSE);
}



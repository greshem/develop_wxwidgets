/////////////////////////////////////////////////////////////////////////////
// Name:        aboutDlg.h
// Purpose:     
// Author:      Matthew Witherwax
// Modified by: 
// Created:     09/03/05 20:36:34
// RCS-ID:      
// Copyright:   Copyright (c) 2005 Matthew Witherwax
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _ABOUTDLG_H_
#define _ABOUTDLG_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "aboutDlg.cpp"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/notebook.h"
#include "wx/html/htmlwin.h"
////@end includes
#include "wx/filefn.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ABOUT_DIALOG 10000
#define SYMBOL_ABOUTDLG_STYLE wxCAPTION|wxRESIZE_BORDER|wxCLOSE_BOX
#define SYMBOL_ABOUTDLG_TITLE _("About")
#define SYMBOL_ABOUTDLG_IDNAME ABOUT_DIALOG
#define SYMBOL_ABOUTDLG_SIZE wxDefaultSize
#define SYMBOL_ABOUTDLG_POSITION wxDefaultPosition
#define INFO_NOTEBOOK 10001
#define ABOUT_HTMLWINDOW 10004
#define LICENSE_HTMLWINDOW 10002
#define CREDITS_HTMLWINDOW 10003
#define ABOUTOK_BUTTON 10005
////@end control identifiers

/*!
 * Compatibility
 */

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif
#ifndef wxFIXED_MINSIZE
#define wxFIXED_MINSIZE 0
#endif

/*!
 * AboutDlg class declaration
 */

class AboutDlg: public wxDialog
{    
    DECLARE_DYNAMIC_CLASS( AboutDlg )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    AboutDlg( );
    AboutDlg( wxWindow* parent, wxWindowID id = SYMBOL_ABOUTDLG_IDNAME, const wxString& caption = SYMBOL_ABOUTDLG_TITLE, const wxPoint& pos = SYMBOL_ABOUTDLG_POSITION, const wxSize& size = SYMBOL_ABOUTDLG_SIZE, long style = SYMBOL_ABOUTDLG_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_ABOUTDLG_IDNAME, const wxString& caption = SYMBOL_ABOUTDLG_TITLE, const wxPoint& pos = SYMBOL_ABOUTDLG_POSITION, const wxSize& size = SYMBOL_ABOUTDLG_SIZE, long style = SYMBOL_ABOUTDLG_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin AboutDlg event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ABOUTOK_BUTTON
    void OnAboutokButtonClick( wxCommandEvent& event );

////@end AboutDlg event handler declarations

////@begin AboutDlg member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end AboutDlg member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin AboutDlg member variables
////@end AboutDlg member variables
};

#endif
    // _ABOUTDLG_H_

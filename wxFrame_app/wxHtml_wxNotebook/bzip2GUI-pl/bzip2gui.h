/////////////////////////////////////////////////////////////////////////////
// Name:        bzip2gui.h
// Purpose:
// Author:      Matthew Witherwax
// Modified by:
// Created:     01/01/2006 00:01:21
// RCS-ID:
// Copyright:   Copyright (c) 2005 Matthew Witherwax
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef _BZIP2GUI_H_
#define _BZIP2GUI_H_

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma interface "bzip2gui.cpp"
#endif

/*!
 * Includes
 */

////@begin includes
#include "wx/frame.h"
#include "wx/dirctrl.h"
#include "wx/statusbr.h"
////@end includes
#include "wx/image.h"
#include "aboutDlg.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define BZIP2GUI_FRAME 10000
#define SYMBOL_BZIP2GUI_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxMINIMIZE_BOX|wxCLOSE_BOX
#define SYMBOL_BZIP2GUI_TITLE _("bzip2GUI")
#define SYMBOL_BZIP2GUI_IDNAME BZIP2GUI_FRAME
#define SYMBOL_BZIP2GUI_SIZE wxSize(475, 365)
#define SYMBOL_BZIP2GUI_POSITION wxDefaultPosition
#define MAIN_PANEL 10001
#define SELECT_STATIC 10017
#define FILE_DIRCTRL 10002
#define FILE_STATIC 10007
#define DELETE_CHECKBOX 10008
#define OVERWRITE_CHECKBOX 10009
#define COMPRESS_STATIC 10003
#define COMPRESSLEVEL_STATIC 10004
#define DESCRIPT_STATIC 10018
#define COMPRESSLEVEL_SLIDER 10005
#define LTDMEM_CHECKBOX 10006
#define PATH_STATIC 10010
#define ACTION_BUTTON 10011
#define EXIT_MENU 10013
#define HELP_MENU 10014
#define ABOUT_MENU 10015
#define BZIP2MSG_STATUSBAR 10016
////@end control identifiers

/*!
 * Bzip2GUIApp class declaration
 */

class Bzip2GUIApp: public wxApp
{
    DECLARE_CLASS( Bzip2GUIApp )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    Bzip2GUIApp();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

////@begin Bzip2GUIApp event handler declarations

////@end Bzip2GUIApp event handler declarations

////@begin Bzip2GUIApp member function declarations

////@end Bzip2GUIApp member function declarations

////@begin Bzip2GUIApp member variables
////@end Bzip2GUIApp member variables
};

/*!
 * Application instance declaration
 */

////@begin declare app
DECLARE_APP(Bzip2GUIApp)
////@end declare app

/*!
 * Bzip2GUI class declaration
 */

class Bzip2GUI: public wxFrame
{
    DECLARE_CLASS( Bzip2GUI )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    Bzip2GUI( );
    Bzip2GUI( wxWindow* parent, wxWindowID id = SYMBOL_BZIP2GUI_IDNAME, const wxString& caption = SYMBOL_BZIP2GUI_TITLE, const wxPoint& pos = SYMBOL_BZIP2GUI_POSITION, const wxSize& size = SYMBOL_BZIP2GUI_SIZE, long style = SYMBOL_BZIP2GUI_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_BZIP2GUI_IDNAME, const wxString& caption = SYMBOL_BZIP2GUI_TITLE, const wxPoint& pos = SYMBOL_BZIP2GUI_POSITION, const wxSize& size = SYMBOL_BZIP2GUI_SIZE, long style = SYMBOL_BZIP2GUI_STYLE );

    /// Creates the controls and sizers
    void CreateControls();

////@begin Bzip2GUI event handler declarations

    /// wxEVT_COMMAND_TREE_SEL_CHANGED event handler for FILE_DIRCTRL
    void OnFileDirctrlSelChanged( wxTreeEvent& event );

    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for LTDMEM_CHECKBOX
    void OnLtdmemCheckboxClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ACTION_BUTTON
    void OnActionButtonClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for EXIT_MENU
    void OnExitMenuClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ABOUT_MENU
    void OnAboutMenuClick( wxCommandEvent& event );

////@end Bzip2GUI event handler declarations

////@begin Bzip2GUI member function declarations

    wxFlexGridSizer* GetPathSizer() const { return pathSizer ; }
    void SetPathSizer(wxFlexGridSizer* value) { pathSizer = value ; }

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end Bzip2GUI member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin Bzip2GUI member variables
    wxFlexGridSizer* pathSizer;
////@end Bzip2GUI member variables
};

#endif
    // _BZIP2GUI_H_

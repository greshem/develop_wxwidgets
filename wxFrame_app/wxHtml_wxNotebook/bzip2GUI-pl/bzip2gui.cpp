/////////////////////////////////////////////////////////////////////////////
// Name:        bzip2gui.cpp
// Purpose:
// Author:      Matthew Witherwax
// Modified by:
// Created:     01/01/2006 00:01:21
// RCS-ID:
// Copyright:   Copyright (c) 2005 Matthew Witherwax
// Licence:
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(__APPLE__)
#pragma implementation "bzip2gui.h"
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

#include "bzip2gui.h"

////@begin XPM images
////@end XPM images

/*!
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( Bzip2GUIApp )
////@end implement app

/*!
 * Bzip2GUIApp type definition
 */

IMPLEMENT_CLASS( Bzip2GUIApp, wxApp )

/*!
 * Bzip2GUIApp event table definition
 */

BEGIN_EVENT_TABLE( Bzip2GUIApp, wxApp )

////@begin Bzip2GUIApp event table entries
////@end Bzip2GUIApp event table entries

END_EVENT_TABLE()

/*!
 * Constructor for Bzip2GUIApp
 */

Bzip2GUIApp::Bzip2GUIApp()
{
////@begin Bzip2GUIApp member initialisation
////@end Bzip2GUIApp member initialisation
}

/*!
 * Initialisation for Bzip2GUIApp
 */

bool Bzip2GUIApp::OnInit()
{
////@begin Bzip2GUIApp initialisation
    // Remove the comment markers above and below this block
    // to make permanent changes to the code.

#if wxUSE_XPM
    wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG
    wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG
    wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF
    wxImage::AddHandler(new wxGIFHandler);
#endif
    Bzip2GUI* mainWindow = new Bzip2GUI( NULL, BZIP2GUI_FRAME );
    mainWindow->Show(true);
////@end Bzip2GUIApp initialisation

    return true;
}

/*!
 * Cleanup for Bzip2GUIApp
 */
int Bzip2GUIApp::OnExit()
{
////@begin Bzip2GUIApp cleanup
    return wxApp::OnExit();
////@end Bzip2GUIApp cleanup
}


/*!
 * Bzip2GUI type definition
 */

IMPLEMENT_CLASS( Bzip2GUI, wxFrame )

/*!
 * Bzip2GUI event table definition
 */

BEGIN_EVENT_TABLE( Bzip2GUI, wxFrame )

////@begin Bzip2GUI event table entries
    EVT_TREE_SEL_CHANGED( wxID_TREECTRL, Bzip2GUI::OnFileDirctrlSelChanged )

    EVT_CHECKBOX( LTDMEM_CHECKBOX, Bzip2GUI::OnLtdmemCheckboxClick )

    EVT_BUTTON( ACTION_BUTTON, Bzip2GUI::OnActionButtonClick )

    EVT_MENU( EXIT_MENU, Bzip2GUI::OnExitMenuClick )

    EVT_MENU( ABOUT_MENU, Bzip2GUI::OnAboutMenuClick )

////@end Bzip2GUI event table entries

END_EVENT_TABLE()

/*!
 * Bzip2GUI constructors
 */

Bzip2GUI::Bzip2GUI( )
{
}

Bzip2GUI::Bzip2GUI( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create( parent, id, caption, pos, size, style );
}

/*!
 * Bzip2GUI creator
 */

bool Bzip2GUI::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin Bzip2GUI member initialisation
////@end Bzip2GUI member initialisation

////@begin Bzip2GUI creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    Centre();
////@end Bzip2GUI creation
    return true;
}

/*!
 * Control creation for Bzip2GUI
 */

void Bzip2GUI::CreateControls()
{
////@begin Bzip2GUI content construction
    Bzip2GUI* itemFrame1 = this;

    wxMenuBar* menuBar = new wxMenuBar;
    wxMenu* itemMenu31 = new wxMenu;
    itemMenu31->Append(EXIT_MENU, _("FFFFF"), _T(""), wxITEM_NORMAL);
    menuBar->Append(itemMenu31, _("&Plik"));
    wxMenu* itemMenu33 = new wxMenu;
    itemMenu33->Append(HELP_MENU, _("Pomo&c"), _T(""), wxITEM_NORMAL);
    itemMenu33->Append(ABOUT_MENU, _("&O programie..."), _T(""), wxITEM_NORMAL);
    menuBar->Append(itemMenu33, _("Pomoc"));
    itemFrame1->SetMenuBar(menuBar);

    wxPanel* itemPanel2 = new wxPanel( itemFrame1, MAIN_PANEL, wxDefaultPosition, wxSize(475, 365), wxSUNKEN_BORDER|wxWANTS_CHARS|wxTAB_TRAVERSAL );
    itemPanel2->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _T("Courier New")));

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxVERTICAL);
    itemPanel2->SetSizer(itemBoxSizer3);

    wxStaticText* itemStaticText4 = new wxStaticText( itemPanel2, SELECT_STATIC, _("Wybierz plik:"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
    itemStaticText4->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, _T("Courier New")));
    itemBoxSizer3->Add(itemStaticText4, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP|wxADJUST_MINSIZE, 5);

    wxFlexGridSizer* itemFlexGridSizer5 = new wxFlexGridSizer(1, 2, 0, 0);
    itemBoxSizer3->Add(itemFlexGridSizer5, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT, 5);

    wxGenericDirCtrl* itemGenericDirCtrl6 = new wxGenericDirCtrl( itemPanel2, FILE_DIRCTRL, _T(""), wxDefaultPosition, wxSize(200, 220), 0, _T("All files (*.*)|*.*"), 0 );
    itemFlexGridSizer5->Add(itemGenericDirCtrl6, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxStaticBox* itemStaticBoxSizer7Static = new wxStaticBox(itemPanel2, wxID_ANY, _("Ustawienia"));
    wxStaticBoxSizer* itemStaticBoxSizer7 = new wxStaticBoxSizer(itemStaticBoxSizer7Static, wxVERTICAL);
    itemFlexGridSizer5->Add(itemStaticBoxSizer7, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    wxStaticText* itemStaticText8 = new wxStaticText( itemPanel2, FILE_STATIC, _("Plik:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText8->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, _T("Courier New")));
    itemStaticBoxSizer7->Add(itemStaticText8, 0, wxALIGN_LEFT|wxALL|wxADJUST_MINSIZE, 5);

    wxBoxSizer* itemBoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer7->Add(itemBoxSizer9, 0, wxALIGN_LEFT|wxALL, 0);

    itemBoxSizer9->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5);

    wxCheckBox* itemCheckBox11 = new wxCheckBox( itemPanel2, DELETE_CHECKBOX, _("FFFFFFFFFFFFFFFFFFF"), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    itemCheckBox11->SetValue(true);
    itemCheckBox11->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _T("Courier New")));
    itemBoxSizer9->Add(itemCheckBox11, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer7->Add(itemBoxSizer12, 0, wxALIGN_LEFT|wxALL, 0);

    itemBoxSizer12->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5);

    wxCheckBox* itemCheckBox14 = new wxCheckBox( itemPanel2, OVERWRITE_CHECKBOX, _("sdfadfadfafadfa "), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    itemCheckBox14->SetValue(false);
    itemCheckBox14->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _T("Courier New")));
    itemBoxSizer12->Add(itemCheckBox14, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText15 = new wxStaticText( itemPanel2, COMPRESS_STATIC, _("Kompresja:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText15->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxBOLD, false, _T("Courier New")));
    itemStaticBoxSizer7->Add(itemStaticText15, 0, wxALIGN_LEFT|wxALL|wxADJUST_MINSIZE, 5);

    wxBoxSizer* itemBoxSizer16 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer7->Add(itemBoxSizer16, 0, wxALIGN_LEFT|wxALL, 0);

    itemBoxSizer16->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5);

    wxStaticText* itemStaticText18 = new wxStaticText( itemPanel2, COMPRESSLEVEL_STATIC, _("Poziom kompresji"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText18->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _T("Courier New")));
    itemBoxSizer16->Add(itemStaticText18, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM|wxADJUST_MINSIZE, 5);

    wxBoxSizer* itemBoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer7->Add(itemBoxSizer19, 0, wxALIGN_LEFT|wxALL, 0);

    itemBoxSizer19->Add(9, 5, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5);

    wxStaticText* itemStaticText21 = new wxStaticText( itemPanel2, DESCRIPT_STATIC, _("FFFFFFFFFFFF"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText21->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _T("Courier New")));
    itemBoxSizer19->Add(itemStaticText21, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    itemBoxSizer19->Add(7, 5, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5);

    wxSlider* itemSlider23 = new wxSlider( itemPanel2, COMPRESSLEVEL_SLIDER, 9, 1, 9, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS );
    itemSlider23->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _T("Courier New")));
    itemBoxSizer19->Add(itemSlider23, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    wxBoxSizer* itemBoxSizer24 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer7->Add(itemBoxSizer24, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 0);

    itemBoxSizer24->Add(5, 5, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5);

    wxCheckBox* itemCheckBox26 = new wxCheckBox( itemPanel2, LTDMEM_CHECKBOX, _("safafafsafsafasf "), wxDefaultPosition, wxDefaultSize, wxCHK_2STATE );
    itemCheckBox26->SetValue(false);
    itemCheckBox26->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _T("Courier New")));
    itemBoxSizer24->Add(itemCheckBox26, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFlexGridSizer* itemFlexGridSizer27 = new wxFlexGridSizer(1, 2, 0, 0);
    itemBoxSizer3->Add(itemFlexGridSizer27, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM, 5);

    wxStaticText* itemStaticText28 = new wxStaticText( itemPanel2, PATH_STATIC, _T(""), wxDefaultPosition, wxSize(350, -1), 0 );
    itemStaticText28->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _T("Courier New")));
    itemFlexGridSizer27->Add(itemStaticText28, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL|wxADJUST_MINSIZE, 5);

    wxButton* itemButton29 = new wxButton( itemPanel2, ACTION_BUTTON, _T(""), wxDefaultPosition, wxSize(90, -1), 0 );
    itemButton29->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, _T("Courier New")));
    itemFlexGridSizer27->Add(itemButton29, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStatusBar* itemStatusBar36 = new wxStatusBar( itemFrame1, BZIP2MSG_STATUSBAR, wxST_SIZEGRIP|wxNO_BORDER );
    itemStatusBar36->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, _T("Courier New")));
    itemStatusBar36->SetFieldsCount(1);
    itemFrame1->SetStatusBar(itemStatusBar36);

////@end Bzip2GUI content construction
    pathSizer = itemFlexGridSizer27;
}

/*!
 * Should we show tooltips?
 */

bool Bzip2GUI::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap Bzip2GUI::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin Bzip2GUI bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end Bzip2GUI bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon Bzip2GUI::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin Bzip2GUI icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end Bzip2GUI icon retrieval
}
/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
 */

void Bzip2GUI::OnActionButtonClick( wxCommandEvent& event )
{
    wxStatusBar* statusBar = wxDynamicCast(FindWindow(BZIP2MSG_STATUSBAR),
            wxStatusBar);
    wxGenericDirCtrl* selectedFile = wxDynamicCast(FindWindow(FILE_DIRCTRL),
            wxGenericDirCtrl);
    wxSlider* compressLevel = wxDynamicCast(FindWindow(COMPRESSLEVEL_SLIDER),
            wxSlider);
    wxButton* actionButton = wxDynamicCast(FindWindow(ACTION_BUTTON),
            wxButton);
    wxCheckBox* deleteCheck = wxDynamicCast(FindWindow(DELETE_CHECKBOX),
            wxCheckBox);
    wxCheckBox* overwriteCheck = wxDynamicCast(FindWindow(OVERWRITE_CHECKBOX),
            wxCheckBox);
    wxCheckBox* ltdmemCheck = wxDynamicCast(FindWindow(LTDMEM_CHECKBOX),
            wxCheckBox);
    wxArrayString errors,
        output;
    long status;
    wxString fileName,
        command,
        statusMsg;
    fileName = selectedFile->GetFilePath();
    if (fileName != _T(""))
    {
        if (fileName.AfterLast(_T('.')) == _T("bz") || fileName.AfterLast(_T('.')) == _T("bz2"))
        {
            command << _T("bzip2.exe -dv");
            if (!deleteCheck->IsChecked())
            {
                command << _T("k");
            }
            if (overwriteCheck->IsChecked())
            {
                command << _T("f");
            }
            command << _T(" \"") << fileName << _T("\"");
        }
        else
        {
            command << _T("bzip2.exe -zv");
            if (!deleteCheck->IsChecked())
            {
                command << _T("k");
            }
            if (overwriteCheck->IsChecked())
            {
                command << _T("f");
            }
            if (ltdmemCheck->IsChecked())
            {
                command << _T("s");
            }
            else
            {
                command << compressLevel->GetValue();
            }
            command << _T(" \"") << fileName << _T("\"");
        }
        status = wxExecute(command, output, errors);
        statusMsg = errors[0].AfterFirst(_T(':'));
        if (status != 0)
        {
            wxMessageBox(statusMsg, _T("dafsfa "), wxOK | wxICON_ERROR);
            statusBar->SetStatusText(statusMsg, 0);
        }
        else
        {
            statusBar->SetStatusText(statusMsg, 0);
        }
        selectedFile->ReCreateTree();
        selectedFile->SetPath(fileName.BeforeLast(_T('\\')));
    }
    actionButton->SetLabel(_T(""));
}


/*!
 * wxEVT_COMMAND_TREE_SEL_CHANGED event handler for FILE_DIRCTRL
 */

void Bzip2GUI::OnFileDirctrlSelChanged( wxTreeEvent& event )
{
    wxString filePath,
            fileName;
    //wxStaticText* path = wxDynamicCast(FindWindow(PATH_STATIC), wxStaticText);
    wxGenericDirCtrl* selectedFile = wxDynamicCast(FindWindow(FILE_DIRCTRL),
            wxGenericDirCtrl);
    wxButton* actionButton = wxDynamicCast(FindWindow(ACTION_BUTTON),
            wxButton);
    wxString tempPath;
    filePath = (selectedFile->GetFilePath()).BeforeFirst(_T('\\'));
    if (filePath != _T(""))
    {
        filePath += _T("\\ ... \\");
        tempPath = (selectedFile->GetFilePath()).AfterLast(_T('\\'));
        if (tempPath.Length() > 40)
        {
            tempPath = tempPath.Mid(0,37);
            tempPath << _T("...");
        }
        filePath += tempPath;
    }
   // path->SetLabel(filePath);
    //path->SetLabel(wxT("../"));
    fileName = selectedFile->GetFilePath();
    if (fileName != _T(""))
    {
        if (fileName.AfterLast(_T('.')) == _T("bz") || fileName.AfterLast(_T('.')) == _T("bz2"))
        {
            actionButton->SetLabel(_T("Dekompresja"));
        }
        else
        {
            actionButton->SetLabel(_T("Kompresja"));
        }
    }
    //pathSizer->Layout();
}


/*!
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for LTDMEM_CHECKBOX
 */

void Bzip2GUI::OnLtdmemCheckboxClick( wxCommandEvent& event )
{
    wxCheckBox* ltdmemCheck = wxDynamicCast(FindWindow(LTDMEM_CHECKBOX),
            wxCheckBox);
    wxSlider* compressLevel = wxDynamicCast(FindWindow(COMPRESSLEVEL_SLIDER),
            wxSlider);
    if (ltdmemCheck->IsChecked())
    {
        compressLevel->Enable(false);
    }
    else
    {
        compressLevel->Enable(true);
    }
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for EXIT_MENU
 */

void Bzip2GUI::OnExitMenuClick( wxCommandEvent& event )
{
    Close(true);
}


/*!
 * wxEVT_COMMAND_MENU_SELECTED event handler for ABOUT_MENU
 */

void Bzip2GUI::OnAboutMenuClick( wxCommandEvent& event )
{
    AboutDlg* about = new AboutDlg(this);
    about->Show();
}


//int main()

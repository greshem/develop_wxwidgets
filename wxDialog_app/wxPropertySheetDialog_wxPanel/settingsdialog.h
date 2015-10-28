
#ifndef _SETTINGSDIALOG_H_
#define _SETTINGSDIALOG_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "settingsdialog.h"
#endif


#include "wx/propdlg.h"

#include "wx/bookctrl.h"




#define ID_SETTINGSDIALOG 14000
#define ID_SETTINGS_DIALOG_PANEL 14018
#define ID_SETTINGS_DIALOG_CHECKBOX 14019
#define ID_SETTINGS_DIALOG_CHECKBOX1 14020
#define ID_SETTINGS_DIALOG_TEXTCTRL 14021
#define ID_SETTINGS_DIALOG_BUTTON 14022
#define ID_SETTINGS_DIALOG_PANEL1 14023
#define ID_SETTINGS_DIALOG_CHECKBOX2 14024
#define ID_SETTINGS_DIALOG_CHECKBOX3 14025
#define ID_SETTINGS_DIALOG_RADIOBUTTON 14026
#define ID_SETTINGS_DIALOG_RADIOBUTTON1 14027
#define ID_SETTINGS_DIALOG_RADIOBUTTON2 14028
#define ID_SETTINGS_DIALOG_PANEL2 14029
#define ID_SETTINGS_DIALOG_CHECKBOX4 14030
#define ID_SETTINGS_DIALOG_CHECKBOX5 14031
#define ID_SETTINGS_DIALOG_CHECKBOX6 14032
#define ID_SETTINGS_DIALOG_CHECKBOX7 14033
#define ID_SETTINGS_DIALOG_CHECKLISTBOX 14034
#define SYMBOL_SETTINGSDIALOG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_SETTINGSDIALOG_TITLE _("SettingsDialog")
#define SYMBOL_SETTINGSDIALOG_IDNAME ID_SETTINGSDIALOG
#define SYMBOL_SETTINGSDIALOG_SIZE wxSize(400, 300)
#define SYMBOL_SETTINGSDIALOG_POSITION wxDefaultPosition


#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif


class SettingsDialog: public wxPropertySheetDialog
{
    DECLARE_DYNAMIC_CLASS( SettingsDialog )
    DECLARE_EVENT_TABLE()

public:
    SettingsDialog( );
    SettingsDialog( wxWindow* parent, wxWindowID id = SYMBOL_SETTINGSDIALOG_IDNAME, const wxString& caption = SYMBOL_SETTINGSDIALOG_TITLE, const wxPoint& pos = SYMBOL_SETTINGSDIALOG_POSITION, const wxSize& size = SYMBOL_SETTINGSDIALOG_SIZE, long style = SYMBOL_SETTINGSDIALOG_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_SETTINGSDIALOG_IDNAME, const wxString& caption = SYMBOL_SETTINGSDIALOG_TITLE, const wxPoint& pos = SYMBOL_SETTINGSDIALOG_POSITION, const wxSize& size = SYMBOL_SETTINGSDIALOG_SIZE, long style = SYMBOL_SETTINGSDIALOG_STYLE );

    void CreateControls();


    wxBitmap GetBitmapResource( const wxString& name );

    wxIcon GetIconResource( const wxString& name );

    static bool ShowToolTips();
};

#endif // _SETTINGSDIALOG_H_

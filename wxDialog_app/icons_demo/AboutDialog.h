/**
 * ------------------------
 *  OSS Development Studio
 * ------------------------
 *
 * C++ IDE for GNU GCC Compiler
 *
 * Copyright (C) 2005 Kimmo Lankila, Reijo Tomperi
 *
 * This file is part of OSS Development Studio.
 *
 * OSS Development Studio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * OSS Development Studio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OSS Development Studio; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <wx/wx.h>
#include <wx/image.h>
#include <wx/panel.h>
#include <wx/notebook.h>



/**
 * @brief This is the about box which is shown when user selects 
 * About from the Help-menu. It uses wxNotebook to show tabs
 * for about, license and credit pages.
 */
class AboutDialog : public wxDialog
{
public:


					
	/**
	 * This creates a new tab with text content. Use this to create tabs where
	 * license texts or other text material is to be shown.
	 *
	 * @param parent This should be a pointer to wxNotebook where this tab
	 *        is going to be attached.
	 * @param content The text content to be shown inside this tab.
	 */

	//wxPanel* CreateTab( wxBookCtrlBase* parent, const wxString &content = _T( "" ) );
	wxPanel *CreateTab(wxBookCtrlBase * parent, const wxString &content=_T(""));
		
	/**
	 * This creates a new tab with image and text content. Originally this is
	 * intented to be used only to show the program logo in first page of the
	 * about dialog.
	 *
	 * @param parent This should be a pointer to wxNotebook where this tab
	 *        is going to be attached.
	 * @param logo This should be image in correct size to be shown in the tab.
	 * @param content The text content to be shown inside this tab.
	 */		
	//wxPanel* CreateTab( wxBookCtrlBase* parent, wxIcon &logo, const wxString &content = _T( "" ) );		
	wxPanel *CreateTab(wxBookCtrlBase *parent, wxIcon &logo, const wxString &content=_T("test"));

	AboutDialog( 	wxWindow* parent, 
					wxWindowID id, 
					const wxString& title = _T( "" ), 
					const wxPoint& pos = wxDefaultPosition, 
					const wxSize& size = wxDefaultSize, 
					long style = wxDEFAULT_DIALOG_STYLE, 
					const wxString& name = _T( "dialogBox" ) );


};

#endif // #ifndef ABOUTDIALOG_H

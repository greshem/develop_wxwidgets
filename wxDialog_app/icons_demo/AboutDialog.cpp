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
#include "AboutDialog.h"
#include "AboutTexts.h"
#include "icons/about_logo.xpm"
AboutDialog::AboutDialog( 	wxWindow* parent,
							wxWindowID id,
							const wxString& title,
							const wxPoint& pos,
							const wxSize& size,
							long style,
							const wxString& name )
	: wxDialog( parent, id, title, pos, size, style, name )
{
	wxPanel *mainPanel = new wxPanel( this );
	wxBoxSizer *mainSizer = new wxBoxSizer( wxVERTICAL );
	wxBoxSizer *topPanelSizer = new wxBoxSizer( wxVERTICAL );
	wxBoxSizer *buttonPanelSizer = new wxBoxSizer( wxHORIZONTAL );
	buttonPanelSizer->Add( new wxButton( mainPanel, wxID_OK, _T( "OK" ) ), 0, wxEXPAND | wxALL, 0 );
	wxNotebook *notebook = new wxNotebook( mainPanel, -1 );
	AboutTexts aboutTexts;
	wxIcon largeIcon( about_logo );
	notebook->AddPage( CreateTab( notebook, largeIcon, aboutTexts.m_about ), _T( "About" ) );
	notebook->AddPage( CreateTab( notebook, aboutTexts.m_license ), _T( "License" ) );
	notebook->AddPage( CreateTab( notebook, aboutTexts.m_acknowledgements ), _T( "Acknowledgements" ) );
	notebook->AddPage( CreateTab( notebook, aboutTexts.m_contact ), _T ( "Contact" ) );
	mainSizer->Add( topPanelSizer, 0, wxEXPAND | wxALL, 5 );
	mainSizer->Add( notebook, 1, wxEXPAND | wxALL, 5 );
	mainSizer->Add( buttonPanelSizer, 0, wxALL | wxALIGN_RIGHT, 5 );
	mainPanel->SetSizer( mainSizer );
	mainSizer->SetSizeHints( mainPanel );		
	wxBoxSizer *mainPanelSizer = new wxBoxSizer( wxVERTICAL );
	mainPanelSizer->Add( mainPanel, 1, wxEXPAND | wxALL, 0 );
	SetSizer( mainPanelSizer );
	mainPanelSizer->SetSizeHints( this );	
}

wxPanel* AboutDialog::CreateTab( wxBookCtrlBase* parent, const wxString &content )
{
	wxPanel *mainPanel = new wxPanel( parent );
	wxBoxSizer *mainSizer = new wxBoxSizer( wxVERTICAL );
	wxTextCtrl *textArea = new wxTextCtrl( 	mainPanel, 
											-1, 
											content, 
											wxDefaultPosition, 
											wxSize( 400, 300 ), 
											wxTE_MULTILINE | wxTE_READONLY );
	textArea->SetMaxLength( 0 );
	mainSizer->Add( textArea, 1, wxEXPAND | wxALL, 0 );
	mainPanel->SetSizer( mainSizer );
	mainSizer->SetSizeHints( mainPanel );
	
	return mainPanel;
}


wxPanel* AboutDialog::CreateTab( wxBookCtrlBase* parent, wxIcon &logo, const wxString &content )
{
	wxPanel *mainPanel = new wxPanel( parent );
	wxStaticBitmap *staticBitmap = new wxStaticBitmap( 
		mainPanel, 
		-1, 
		wxBitmap( logo ),
		wxDefaultPosition );
	
	// bitmapPanelSizer is only to add panels top and bottom of the bitmap
	// when small logo doesn't fill the whole area. Because if it doesn't
	// top and bottom areas are not painted correctly if there is no panel there.
	wxBoxSizer *bitmapPanelSizer = new wxBoxSizer( wxHORIZONTAL );
	bitmapPanelSizer->Add( new wxPanel( mainPanel ), 1, wxEXPAND | wxALL, 0 );
	bitmapPanelSizer->Add( staticBitmap, 0, wxALL | wxALIGN_CENTER, 0 );
	bitmapPanelSizer->Add( new wxPanel( mainPanel ), 1, wxEXPAND | wxALL, 0 );

	wxBoxSizer *mainSizer = new wxBoxSizer( wxVERTICAL );
	mainSizer->Add( bitmapPanelSizer, 1, wxEXPAND | wxALL | wxALIGN_CENTER, 10 );
	mainSizer->Add( new wxStaticText( mainPanel, -1, content ), 0, wxEXPAND | wxALL, 10 );
	mainPanel->SetSizer( mainSizer );
	mainSizer->SetSizeHints( mainPanel );
	
	return mainPanel;
}

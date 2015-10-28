#include <wx/textfile.h>
#include <wx/ffile.h>
#include <wx/file.h>
#include <fstream>
#include <string> 
#include <sstream>
#include <iostream>
#include <map>
#include <iostream> 
#include <algorithm>
#include <vector> 
#include <iterator>  
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include <dirent.h>
#include "TestDialog.h"
#include <wx/sizer.h>                                                                               
#include <wx/stattext.h>
#include <wx/dirdlg.h>
#include <wx/msgdlg.h>
#include "./tools.h"

//#include <iconv.h>

BEGIN_EVENT_TABLE(TestDialog, wxDialog)                                             
EVT_BUTTON(wxID_OK, TestDialog::OnButtonClickOK)                                    
EVT_BUTTON(wxID_CANCEL, TestDialog::OnButtonClickCancel)
EVT_BUTTON(ID_WXBUTTON_ONE, TestDialog::OnButtonSelect)
END_EVENT_TABLE()


///////////////////////////////////////////////////////////////////////////
TestDialog::TestDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* topSizer;
	topSizer = new wxBoxSizer( wxVERTICAL );
	
	//行--------------------------------------------------------------------------
   	wxBoxSizer *middleSizer = new wxBoxSizer( wxHORIZONTAL );
	 //wxStaticBoxSizer* middleSizer= new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("label") ), wxVERTICAL );
	 //随意一个按钮	
	 //m_button2 = new wxButton( this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	 //middleSizer->Add( m_button2, 0, wxALL, 5 );
	 //combox	
	 m_comboBox1 = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	 middleSizer->Add( m_comboBox1, 0, wxALL, 5 );
	topSizer->Add( middleSizer, 1, wxEXPAND, 5 );
	
	//行2--------------------------------------------------------------------------
    wxBoxSizer *middleSizer3 = new wxBoxSizer( wxHORIZONTAL );
	 WxButtonSelect= new wxButton(this, ID_WXBUTTON_ONE , _("Demo"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("WxButton4"));
     middleSizer3->Add(WxButtonSelect, 0, wxALL, 10);
     topSizer->Add(middleSizer3, 0, wxALIGN_CENTRE);
	
	//行3--------------------------------------------------------------------------
    wxBoxSizer *middleSizer2 = new wxBoxSizer( wxHORIZONTAL );
    WxButtonOK = new wxButton(this, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("WxButton4"));
    WxButtonCancel = new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("WxButton4"));
    middleSizer2->Add(WxButtonOK, 0, wxALL, 10);
    middleSizer2->Add(WxButtonCancel, 0, wxALL, 10);
    topSizer->Add(middleSizer2, 0, wxALIGN_CENTRE);

	//行4--------------------------------------------------------------------------
    wxBoxSizer *middleSizer4 = new wxBoxSizer( wxHORIZONTAL );
    
    WxTextCtrlLog = new wxTextCtrl( this, ID_WXTEXTCTRL_LOG, wxT("My text\nline1\nline2\nline3\nline4\n"), wxDefaultPosition, wxSize(800, 500), wxTE_MULTILINE),    
    //partSizer->Add(WxTextCtrlLog, 1, wxEXPAND);
	middleSizer4->Add(WxTextCtrlLog, 1, wxEXPAND);
    topSizer->Add(middleSizer4, 0, wxALIGN_CENTRE);

    //从/etc/passwd 读取日志并转成 wxString 并显示. 
    //setlocale(LC_CTYPE, "");
//############################################################################
		string filename = "log.txt";
		FILE *fp;
    	char buffer[8192]={0};
		char buffer_to[8192]={0};
		fp=fopen(filename.c_str(), "r");
		if(NULL == fp)
		{
		}
		if(0==fread(buffer,1,sizeof(buffer),fp))
		{
		}
		fclose(fp);	
		
		EncodeUTF8( buffer, 936, buffer_to ,CP_UTF8 ); 
		
		string str(buffer_to);
		wxString mystr(str.c_str(),wxConvUTF8);
		WxTextCtrlLog->SetValue(mystr);
	
		this->SetSizer( topSizer );
		this->Layout();
		topSizer->Fit( this );
}

TestDialog::~TestDialog()
{
}


void TestDialog::OnButtonClickOK( wxCommandEvent& event )
{
    //wxMessageBox( WxTextServerPath->GetValue());
    wxDialog::EndModal(wxID_OK);
	exit(1);
}

void TestDialog::OnButtonClickCancel( wxCommandEvent& event )
{
    wxDialog::EndModal(wxID_CANCEL);
	exit(1);
}

void TestDialog::OnButtonSelect( wxCommandEvent& event )
{
   	wxMessageBox(wxT("impl"));
}


//########################################################
 DWORD  TestDialog::EncodeUTF8(IN  char	*lpszSource,IN  DWORD	dwSourceCodePage,OUT char	*lpszTarget,IN  DWORD	dwTargetCodePage ) 
{
	DWORD	dwStatus = 0 ;
#ifdef __WIN32__
	DWORD	dwSourceLen = 0 ;
	INT			nUnicodeLen = 0 ;
	wchar_t *	pUnicode = NULL ; 
	BYTE *		pTargetData = NULL ; 
	DWORD	dwTargetLen = 0 ;

	__try
	{
		dwSourceLen = strlen( lpszSource ) ;

		nUnicodeLen = MultiByteToWideChar( dwSourceCodePage, 0 ,lpszSource, -1, NULL, 0 ) ; 

		pUnicode = new wchar_t[nUnicodeLen+1] ; 
		if ( pUnicode == NULL )
		{
			dwStatus = 1 ;
			__leave ;
		}

		memset( pUnicode, 0, ( nUnicodeLen + 1 ) * sizeof( wchar_t ) ) ; 

		MultiByteToWideChar( dwSourceCodePage, 0, lpszSource, -1, (LPWSTR)pUnicode, nUnicodeLen ) ; 

		dwTargetLen = WideCharToMultiByte( dwTargetCodePage, 0, (LPWSTR)pUnicode, -1, (char *)pTargetData, 0, NULL, NULL ) ; 

		pTargetData = new BYTE[dwTargetLen+1] ; 
		if ( pTargetData == NULL )
		{
			dwStatus = 2 ;
			__leave ;
		}

		memset( pTargetData, 0, dwTargetLen + 1 ) ; 

		WideCharToMultiByte( dwTargetCodePage, 0, (LPWSTR)pUnicode, -1, (char *)pTargetData, dwTargetLen, NULL, NULL ) ; 

		strcpy( ( PCHAR )lpszTarget, ( PCHAR )pTargetData ) ;
	}
	__finally
	{
		if ( pUnicode != NULL )
		{
			delete pUnicode ; 
		}
		if ( pTargetData != NULL )
		{
			delete pTargetData ; 
		}
	}
#endif
	return  dwStatus;
}	

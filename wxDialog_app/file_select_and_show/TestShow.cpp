
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
#include <dirent.h>
#include "TestShow.h"
#include <wx/sizer.h>                                                                               
#include <wx/stattext.h>
#include <wx/dirdlg.h>
#include <wx/msgdlg.h>
#include "./tools.h"
#include "log.h"

BEGIN_EVENT_TABLE(TestShow, wxDialog)                                             
EVT_BUTTON(wxID_OK, TestShow::OnButtonClickOK)                                    
EVT_BUTTON(wxID_CANCEL, TestShow::OnButtonClickCancel)
EVT_BUTTON(ID_WXBUTTON_ONE, TestShow::OnButtonSelect)
END_EVENT_TABLE()


///////////////////////////////////////////////////////////////////////////
TestShow::TestShow( wxString file_path,wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* topSizer;
	/////////////////////////////////////
	filename = file_path;
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
    string tmp_str;
   //int ret=shell_exec<char>("cat /etc/passwd", tmp);
    //char tmp_filename[50]={'c','a','t',' '};
    //fixme 有中文就不能正常的显示 WxTextCtrlLog 里面.  
    char buffer[1024]={0};
    char tmp[1024]={0};
    strncpy(tmp,  filename.mb_str(), sizeof(tmp));
    snprintf(buffer, sizeof(buffer), "cat  %s ",   tmp);
	log::Instance()->logger("命令是: %s", buffer);
   int ret=shell_exec<char>(string(buffer), tmp_str);   
    wxString log_str( tmp_str.c_str(),wxConvUTF8);
    WxTextCtrlLog->SetValue(log_str);

	
	//--------------------------------------------------------------------------
	//最后
	this->SetSizer( topSizer );
	this->Layout();
	topSizer->Fit( this );
} 

TestShow::~TestShow()
{
}



void TestShow::OnButtonClickOK( wxCommandEvent& event )
{
    //wxMessageBox( WxTextServerPath->GetValue());
    wxDialog::EndModal(wxID_OK);
	exit(1);
}

void TestShow::OnButtonClickCancel( wxCommandEvent& event )
{
    wxDialog::EndModal(wxID_CANCEL);
	exit(1);
}

void TestShow::OnButtonSelect( wxCommandEvent& event )
{
   	wxMessageBox(wxT("impl"));
}


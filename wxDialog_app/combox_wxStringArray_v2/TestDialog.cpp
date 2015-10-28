//you are Test
#include "TestDialog.h"
#include <wx/sizer.h>                                                                               
#include <wx/stattext.h>
#include <wx/dirdlg.h>
#include <wx/msgdlg.h>

//###################################################
#include <wx/aboutdlg.h>
#include <wx/bitmap.h>
#include <wx/choicdlg.h>
#include  <wx/choicdlg.h>
#include <wx/fileconf.h>
#include <wx/filename.h>
#include <wx/listbox.h> 
#include <wx/numdlg.h>
#include <wx/radiobox.h>
#include <wx/snglinst.h>
#include <wx/socket.h>
#include <wx/sound.h>
#include <wx/splash.h>
#include <wx/textdlg.h>
#include <wx/utils.h>
#include  <wx/filedlg.h>
#include <wx/fontdlg.h>
#include <wx/log.h>
#include <wx/statbmp.h>
#include <wx/filedlg.h>
#include <wx/dirdlg.h>
#include <wx/msgdlg.h>
#include <wx/sizer.h>                                                                               
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/colour.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/font.h>
#include <wx/gdicmn.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/string.h>
#include <wx/wx.h> 

BEGIN_EVENT_TABLE(TestDialog, wxDialog)                                             
EVT_BUTTON(wxID_OK, TestDialog::OnButtonClickOK)                                    
EVT_BUTTON(wxID_CANCEL, TestDialog::OnButtonClickCancel)
EVT_BUTTON(ID_WXBUTTON_ONE, TestDialog::OnButtonSelect)
EVT_COMBOBOX(ID_COMBOX,TestDialog::OnComboBoxUpdate)

END_EVENT_TABLE()


///////////////////////////////////////////////////////////////////////////
TestDialog::TestDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* topSizer;
	topSizer = new wxBoxSizer( wxVERTICAL );
	
	//行 button + combox --------------------------------------------------------------------------
   	wxBoxSizer *middleSizer = new wxBoxSizer( wxHORIZONTAL );
	 //wxStaticBoxSizer* middleSizer= new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("label") ), wxVERTICAL );
	 //随意一个按钮	
	 //m_button2 = new wxButton( this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	 //middleSizer->Add( m_button2, 0, wxALL, 5 );
	 //combox	
	 m_comboBox1 = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	 middleSizer->Add( m_comboBox1, 0, wxALL, 5 );
	topSizer->Add( middleSizer, 1, wxEXPAND, 5 );
	
	//行2-------Buttono 响应-----------------------------------------------------------------
    wxBoxSizer *middleSizer3 = new wxBoxSizer( wxHORIZONTAL );
	 WxButtonSelect= new wxButton(this, ID_WXBUTTON_ONE , _("Demo"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("WxButton4"));
     middleSizer3->Add(WxButtonSelect, 0, wxALL, 10);
     topSizer->Add(middleSizer3, 0, wxALIGN_CENTRE);

	//========================================================================
	wxBoxSizer *middleSizer10 = new wxBoxSizer( wxHORIZONTAL );
	wxArrayString m_DiskCharComboStrings;
	m_DiskCharComboStrings.Add(_T("C:"));
	m_DiskCharComboStrings.Add(_T("D:"));
	m_DiskCharComboStrings.Add(_T("E:"));
	m_DiskCharComboStrings.Add(_T("F:"));
	m_DiskCharComboStrings.Add(_T("G:"));
	m_DiskCharComboStrings.Add(_T("H:"));
	m_DiskCharComboStrings.Add(_T("I:"));
	m_DiskCharComboStrings.Add(_T("J:"));
	m_DiskCharComboStrings.Add(_T("K:"));
	m_DiskCharComboStrings.Add(_T("L:"));
	m_DiskCharComboStrings.Add(_T("M:"));
	m_DiskCharComboStrings.Add(_T("N:"));
	m_DiskCharComboStrings.Add(_T("O:"));
	m_DiskCharComboStrings.Add(_T("P:"));
	m_DiskCharComboStrings.Add(_T("Q:"));
	m_DiskCharComboStrings.Add(_T("R:"));
	m_DiskCharComboStrings.Add(_T("S:"));
	m_DiskCharComboStrings.Add(_T("T:"));
	m_DiskCharComboStrings.Add(_T("U:"));
	m_DiskCharComboStrings.Add(_T("V:"));
	m_DiskCharComboStrings.Add(_T("W:"));
	m_DiskCharComboStrings.Add(_T("X:"));
	m_DiskCharComboStrings.Add(_T("Y:"));
	m_DiskCharComboStrings.Add(_T("Z:"));

    m_comboBox1= new wxComboBox( this, ID_COMBOX, _T(""), wxDefaultPosition, wxSize(120, -1), m_DiskCharComboStrings, wxCB_READONLY );
	m_comboBox1->SetValue(wxT("disk name "));

     middleSizer10->Add(m_comboBox1, 0, wxALL, 10);
     topSizer->Add(middleSizer10, 0, wxALIGN_CENTRE);

	
	//========================================================================
	//行3--OK-Canel------------------------------------------------------------------------
    wxBoxSizer *middleSizer2 = new wxBoxSizer( wxHORIZONTAL );
    WxButtonOK = new wxButton(this, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("WxButton4"));
    WxButtonCancel = new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("WxButton4"));
    middleSizer2->Add(WxButtonOK, 0, wxALL, 10);
    middleSizer2->Add(WxButtonCancel, 0, wxALL, 10);
    topSizer->Add(middleSizer2, 0, wxALIGN_CENTRE);

	
	//--------------------------------------------------------------------------
	//最后
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
void TestDialog::OnComboBoxUpdate ( wxCommandEvent& event )
{
	// Don't show messages for the log output window (it'll crash)
	// fixme 
	// if ( !event.GetEventObject()->IsKindOf(CLASSINFO(wxComboCtrl)) )
	// 	return;

	if ( event.GetEventType() == wxEVT_COMMAND_COMBOBOX_SELECTED )
	{
		wxLogDebug(wxT("EVT_COMBOBOX(id=%i,selection=%i)"),event.GetId(),event.GetSelection());
	}
	else if ( event.GetEventType() == wxEVT_COMMAND_TEXT_UPDATED )
	{
		wxLogDebug(wxT("EVT_TEXT(id=%i,string=\"%s\")"),event.GetId(),event.GetString().c_str());
	}

	wxLogDebug(wxT("EVT_TEXT(id=%i,string=\"%s\")"),event.GetId(),event.GetString().c_str());
	wxString msg;
	//fixme why 字符串为空.
	//msg.Format(wxT("EVT_TEXT(id=%i,string=\"%s\")"),event.GetId(),event.GetString().c_str());
	msg.Printf(wxT("EVT_TEXT(id=%i,string=\"%s\")"),event.GetId(),event.GetString().c_str());
	wxMessageBox(msg);

	//wxLogMe
}




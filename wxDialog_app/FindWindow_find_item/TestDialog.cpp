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
EVT_CHOICE ( ID_CHOICE , TestDialog::OnLogFileChoice)

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
	//########################################################################
	
	wxChoice* 	choice = new wxChoice(this,ID_CHOICE);
	choice->Append(_T("A"));
	choice->Append(_T("B"));
	choice->Append(_T("C"));
	choice->Append(_T("D"));
	choice->Append(_T("E"));
	choice->Append(_T("F"));
	choice->Append(_T("G"));
	wxBoxSizer *middleSizer4 = new wxBoxSizer( wxHORIZONTAL );
	middleSizer4->Add(choice, 0, wxALL, 10);
	topSizer->Add(middleSizer4, 0, wxALIGN_CENTRE);
	
	//########################################################################
	
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

void TestDialog::OnLogFileChoice ( wxCommandEvent& event )
{
   	//wxMessageBox(wxT("impl"));
   	wxChoice *choice=(wxChoice*) FindWindow( ID_CHOICE);
	long offset=choice->GetColumns();
//	wxString msg;
//	msg.Print("%d", offset);
	    wxString logfile=choice->GetStringSelection();
    wxMessageBox(logfile);


}


//you are Test
#include "TestDialog.h"
#include <wx/sizer.h>                                                                               
#include <wx/stattext.h>
#include <wx/dirdlg.h>
#include <wx/msgdlg.h>
#include <wx/html/htmlwin.h>



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
	//添加行
    wxBoxSizer *middleSizer30 = new wxBoxSizer( wxHORIZONTAL );
    //wxHtmlWindow* item = new wxHtmlWindow( this, ID_FRAME_HTMLWINDOW, wxDefaultPosition, wxSize(200, 150), wxHW_SCROLLBAR_AUTO|wxNO_BORDER|wxHSCROLL|wxVSCROLL );
    wxHtmlWindow* item = new wxHtmlWindow( this, wxID_ANY, wxDefaultPosition, wxSize(200, 150), wxHW_SCROLLBAR_AUTO|wxNO_BORDER|wxHSCROLL|wxVSCROLL );
    item->SetPage(_("<h3>wxFrame Demo</h3>\n\nThis demonstrates a wxFrame containing a wxListBox, which itself contains a wxListBox and a wxHtmlWindow. There's also a wxMenuBar,wxToolBar and wxStatusBar."));
    middleSizer30->Add(item, 0, wxALL, 10);
    topSizer->Add(middleSizer30, 0, wxALIGN_CENTRE);
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


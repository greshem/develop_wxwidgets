//you are Test
#include "TestDialog.h"
#include <wx/sizer.h>                                                                               
#include <wx/stattext.h>
#include <wx/dirdlg.h>
#include <wx/msgdlg.h>


BEGIN_EVENT_TABLE(TestDialog, wxDialog)                                             
EVT_BUTTON(wxID_OK, TestDialog::OnButtonClickOK)                                    
EVT_BUTTON(wxID_CANCEL, TestDialog::OnButtonClickCancel)
EVT_BUTTON(ID_WXBUTTON_ONE, TestDialog::OnButtonSelect)

EVT_SPINCTRL  (ID_SPINCTRL,             TestDialog::OnSpinCtrl)
EVT_SPIN_UP   (ID_SPINCTRL,             TestDialog::OnSpinCtrlUp)
EVT_SPIN_DOWN (ID_SPINCTRL,             TestDialog::OnSpinCtrlDown)
EVT_TEXT      (ID_SPINCTRL,             TestDialog::OnSpinCtrlText)

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

    wxBoxSizer *middleSizer30= new wxBoxSizer( wxHORIZONTAL );
	 //m_spin= new wxButton(this, ID_WXBUTTON_ONE , _("Demo"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("WxButton4"));
	 //m_spin= 
    wxSpinCtrl * m_spinctrl = new wxSpinCtrl( this, ID_SPINCTRL, wxEmptyString, wxPoint(200, 160), wxSize(80, wxDefaultCoord) );
    m_spinctrl->SetRange(-10,30);
    m_spinctrl->SetValue(15);

     middleSizer30->Add(m_spinctrl, 0, wxALL, 10);
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

//########################################################################
void TestDialog::OnSpinCtrl(wxSpinEvent& event)
{
    //if ( m_spinctrl )
    	wxSpinCtrl *spin = (wxSpinCtrl*)FindWindow(ID_SPINCTRL);
        wxString s;
        s.Printf( _T("Spin ctrl changed: now %d (from event: %d)\n"),
                 spin->GetValue(), event.GetInt() );
		wxMessageBox(s);
//        m_text->AppendText(s);
}

void TestDialog::OnSpinCtrlUp(wxSpinEvent& event)
{
    //if ( m_spinctrl )
    {    
    	wxSpinCtrl *spin = (wxSpinCtrl*)FindWindow(ID_SPINCTRL);
        wxMessageBox( wxString::Format(
            _T("Spin up: %d (from event: %d)\n"),
            spin->GetValue(), event.GetInt() ) ); 
    }
}

void TestDialog::OnSpinCtrlDown(wxSpinEvent& event)
{
    	wxSpinCtrl *spin = (wxSpinCtrl*)FindWindow(ID_SPINCTRL);
        wxMessageBox( wxString::Format(
            _T("Spin down: %d (from event: %d)\n"),
            spin->GetValue(), event.GetInt() ) );
}


void TestDialog::OnSpinCtrlText(wxCommandEvent& event)
{
    	wxSpinCtrl *spin = (wxSpinCtrl*)FindWindow(ID_SPINCTRL);
        wxString s;
        s.Printf( _T("Spin ctrl text changed: now %d (from event: %s)\n"),
                 spin->GetValue(), event.GetString().c_str() );
//        m_text->AppendText(s);
	wxMessageBox(s); 
}


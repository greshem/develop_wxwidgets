//you are Test
#include "TestDialog.h"
#include <wx/sizer.h>                                                                               
#include <wx/stattext.h>
#include <wx/dirdlg.h>
#include <wx/msgdlg.h>

#include <wx/spinbutt.h>




BEGIN_EVENT_TABLE(TestDialog, wxDialog)                                             
EVT_BUTTON(wxID_OK, TestDialog::OnButtonClickOK)                                    
EVT_BUTTON(wxID_CANCEL, TestDialog::OnButtonClickCancel)
EVT_BUTTON(ID_WXBUTTON_ONE, TestDialog::OnButtonSelect)
EVT_SPIN      (ID_SPIN,                 TestDialog::OnSpinUpdate)
EVT_SPIN_UP   (ID_SPIN,                 TestDialog::OnSpinUp)
EVT_SPIN_DOWN (ID_SPIN,                 TestDialog::OnSpinDown)

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
    wxBoxSizer *middleSizer30 = new wxBoxSizer( wxHORIZONTAL );

    wxSpinButton *m_spinbutton = new wxSpinButton( this, ID_SPIN, wxPoint(103,160) );
  	//wxSpinButton *m_spinbutton =new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 10, 0 );
    m_spinbutton->SetRange(-40,30);
    m_spinbutton->SetValue(11);

     middleSizer30->Add(m_spinbutton, 0, wxALL, 10);
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
void 	TestDialog::OnSpinUpdate ( wxSpinEvent &event   )
{
    wxString value;
    value.Printf( _T("%d"), event.GetPosition() );
	wxSpinButton * spin=(wxSpinButton*) FindWindow(ID_SPIN);
    spin->SetValue( event.GetPosition() );

    value.Printf( _T("Spin control range: (%d, %d), current = %d\n"),
		spin->GetMin(), spin->GetMax(),
                 spin->GetValue());

    //m_text->AppendText(value);

	wxMessageBox(value);
}

void TestDialog::OnSpinUp (  wxSpinEvent &event  )
{
    wxString value;
	wxSpinButton * spin=(wxSpinButton*) FindWindow(ID_SPIN);
    value.Printf( _T("Spin control up: current = %d\n"),
                 spin->GetValue());

    if ( event.GetPosition() > 17 )
    {
        value += _T("Preventing the spin button from going above 17.\n");

        event.Veto();
    }

	wxMessageBox(value);
    //m_text->AppendText(value);

}
void TestDialog::OnSpinDown ( wxSpinEvent &event  )
{
    wxString value;
	wxSpinButton * spin=(wxSpinButton*) FindWindow(ID_SPIN);
    value.Printf( _T("Spin control down: current = %d\n"),
                 spin->GetValue());

    if ( event.GetPosition() < -17 )
    {
        value += _T("Preventing the spin button from going below -17.\n");

        event.Veto();
    }
	wxMessageBox(value);
    //m_text->AppendText(value);

}


//you are Test
#include "TestDialog.h"
#include <wx/sizer.h>                                                                               
#include <wx/stattext.h>
#include <wx/dirdlg.h>
#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include <wx/log.h>


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
	
	//�� button + combox --------------------------------------------------------------------------
   	wxBoxSizer *middleSizer = new wxBoxSizer( wxHORIZONTAL );
	 //wxStaticBoxSizer* middleSizer= new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("label") ), wxVERTICAL );
	 //����һ����ť	
	 //m_button2 = new wxButton( this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	 //middleSizer->Add( m_button2, 0, wxALL, 5 );
	 //combox	
	 m_comboBox1 = new wxComboBox( this, wxID_ANY, wxT("Combo!"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	 middleSizer->Add( m_comboBox1, 0, wxALL, 5 );
	topSizer->Add( middleSizer, 1, wxEXPAND, 5 );
	
	//��2-------Buttono ��Ӧ-----------------------------------------------------------------
    wxBoxSizer *middleSizer3 = new wxBoxSizer( wxHORIZONTAL );
	 WxButtonSelect= new wxButton(this, ID_WXBUTTON_ONE , _("Demo"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("WxButton4"));
     middleSizer3->Add(WxButtonSelect, 0, wxALL, 10);
     topSizer->Add(middleSizer3, 0, wxALIGN_CENTRE);
	
	//��3--OK-Canel------------------------------------------------------------------------
    wxBoxSizer *middleSizer2 = new wxBoxSizer( wxHORIZONTAL );
    WxButtonOK = new wxButton(this, wxID_OK, _("OK"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("WxButton4"));
    WxButtonCancel = new wxButton(this, wxID_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, wxT("WxButton4"));
    middleSizer2->Add(WxButtonOK, 0, wxALL, 10);
    middleSizer2->Add(WxButtonCancel, 0, wxALL, 10);
    topSizer->Add(middleSizer2, 0, wxALIGN_CENTRE);

	
	//--------------------------------------------------------------------------
	//���
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
//   	wxMessageBox(wxT("impl"));
    wxFileDialog dialog(this,
                        _T("Testing save file dialog"),
                        wxEmptyString,
                        _T("myletter.doc"),
                        _T("Text files (*.txt)|*.txt|Document files (*.doc)|*.doc"),
                        wxFD_SAVE|wxFD_OVERWRITE_PROMPT);

    dialog.SetFilterIndex(1);

    if (dialog.ShowModal() == wxID_OK)
    {
        wxLogMessage(_T("%s, filter %d"),
                     dialog.GetPath().c_str(), dialog.GetFilterIndex());
    }

}

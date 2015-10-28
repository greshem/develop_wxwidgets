
#ifndef _MY_TEXT_CTRL_H
#define _MY_TEXT_CTRL_H

#include <wx/textctrl.h>

//---------------------------------------------------------------------------
class MyTextCtrl : public wxTextCtrl
{
public:
	MyTextCtrl(wxWindow *parent, wxWindowID id, const wxString &value = wxEmptyString, const wxPoint &pos = wxDefaultPosition, 
				const wxSize &size = wxDefaultSize, long style = 0, 
				const wxValidator& validator = wxDefaultValidator, 
				const wxString &name = wxTextCtrlNameStr );

	void OnChar(wxKeyEvent& event);

	int		m_nLimitCount ; //  �����ֽ���
	bool	m_bCharUpper ;  //  Сдת��Ϊ��С
	bool	m_bOnlyNum ;	//  ֻ��������
	bool	m_bOnlyMac ;	//	ֻ����MAC��ַ���� 
	bool	m_bOnlyIp ;		//  ֻ����IP��ַ����
	bool    m_bLimitSpace;  //  ���ƿո�
	bool	m_bGroup;
	bool    m_bOnlyUser;	// �������������ַ�����źͿո�������ַ���/\"[]:<>+=;,?*@
	bool    m_bOnlyPCName;	//

	void SetLimitCount( int nCount ) ;
	void MakeUpper( bool bUpper ) ;
	void SetOnlyNum( bool bOnlyNum ) ;
	void SetOnlyMac( bool bOnlyMac ) ;
	void SetOnlyIp( bool bOnlyIp ) ;
	void SetLimitSpace( int nSpace ) ;
	void SetGroupName( bool bGroup );
	void SetPCName( bool bPCName );
	void SetUserName( bool bUser );

private:
	void OnCharOnlyNum(wxKeyEvent& event, int keycode);
	void OnCharGroup(wxKeyEvent& event, int keycode);
	void OnCharOnlyIp(wxKeyEvent& event, int keycode);
	void OnCharOnlyMac(wxKeyEvent& event, int keycode);
	void OnCharOnlyPCName(wxKeyEvent& event, int keycode);
	void OnCharOnlyUser(wxKeyEvent& event, int keycode);
	void OnCharCharUpper(wxKeyEvent& event, int keycode);

	DECLARE_EVENT_TABLE()
};

//---------------------------------------------------------------------------

#endif

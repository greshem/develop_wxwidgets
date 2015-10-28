//�ı��ؼ�,  ������Ķ��������ж�.
#include <wx/wx.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>

#include "MyTextCtrl.h"

BEGIN_EVENT_TABLE(MyTextCtrl, wxTextCtrl)
EVT_CHAR(MyTextCtrl::OnChar)
END_EVENT_TABLE()

MyTextCtrl::MyTextCtrl(wxWindow *parent, wxWindowID id, const wxString &value, const wxPoint &pos, const wxSize &size, long style, const wxValidator& validator, const wxString &name )
:wxTextCtrl()
,m_nLimitCount(65535)
,m_bCharUpper(false)
,m_bOnlyNum(false)
,m_bOnlyMac(false)
,m_bOnlyIp(false)
,m_bLimitSpace(false)
,m_bGroup(false)
,m_bOnlyUser(false)
,m_bOnlyPCName(false)
{
	Create(parent, id, value, pos, size, style, validator, name ) ;
}

//��ֵ0-9 ���ж�.
void MyTextCtrl::OnCharOnlyNum(wxKeyEvent& event, int keycode)
{
	if ( keycode != WXK_BACK && keycode != WXK_DELETE && keycode != WXK_LEFT && keycode != WXK_RIGHT 
		&& ( keycode > '9' || keycode < '0' ) )
	{
		return ;
	}
	else
	{
		event.Skip() ;
	}
}
//ASCII ���Ʒ�?
void MyTextCtrl::OnCharGroup(wxKeyEvent& event, int keycode)
{
	if ( keycode == WXK_BACK || keycode == WXK_DELETE 
		|| keycode == WXK_LEFT || keycode == WXK_RIGHT )
	{
		event.Skip() ;
	}

	if ( keycode < '0' 
		|| ( keycode > '9' && keycode < 'A' ) 
		|| ( keycode > 'Z' && keycode < 'a' ) 
		|| ( keycode > 'z' && keycode < 127 ) )
	{
		return ;
	}
	else
	{
		event.Skip() ;
	}
}

//ip��ַ���ж�.
void MyTextCtrl::OnCharOnlyIp(wxKeyEvent& event, int keycode)
{
	if ( keycode != WXK_BACK && keycode != WXK_DELETE && keycode != WXK_LEFT && keycode != WXK_RIGHT && keycode !='.'
		&& ( keycode > '9' || keycode < '0' ) )
	{
		return ;
	}
	else
	{
		event.Skip() ;
	}
}

//mac��ַ���ж�.
void MyTextCtrl::OnCharOnlyMac(wxKeyEvent& event, int keycode)
{
	if ( keycode != WXK_BACK && keycode != WXK_DELETE && keycode != WXK_LEFT && keycode != WXK_RIGHT 
		&& ( keycode > '9' || keycode < '0' ) && ( keycode > 'f' || keycode <'a') && (keycode > 'F' || keycode <'A'))
	{
		return ;
	}
	else if( keycode >= 'a' && keycode <= 'z' )
	{
		event.m_keyCode = event.m_keyCode - 'a' + 'A';
		wxString text(wxChar(keycode - 'a' + 'A'), 1);
		WriteText(text);
	}
	else
	{
		event.Skip();

	}
}
//netware �Ļ��������ֵ��ж�.
void MyTextCtrl::OnCharOnlyPCName(wxKeyEvent& event, int keycode)
{
	if ( keycode == WXK_BACK || keycode == WXK_DELETE 
		|| keycode == WXK_LEFT || keycode == WXK_RIGHT )
	{
		event.Skip() ;
	}

	if ( (keycode < '0' && keycode != 45)
		|| ( keycode > '9' && keycode < 'A' ) 
		|| ( keycode > 'Z' && keycode < 'a' ) 
		|| ( keycode > 'z' && keycode < 127 ) )
	{
		return ;
	}
	else
	{
		event.Skip() ;
	}
}
//�û��ж�
void MyTextCtrl::OnCharOnlyUser(wxKeyEvent& event, int keycode)
{
	if ( keycode == WXK_BACK || keycode == WXK_DELETE 
		|| keycode == WXK_LEFT || keycode == WXK_RIGHT )
	{
		event.Skip() ;
	}

	if ( keycode < '!' || keycode == 34 
		|| ( keycode > 41 && keycode < 45)
		|| ( keycode > 45 && keycode < 48 )
		|| ( keycode > 57 && keycode < 65 )
		|| ( keycode > 90 && keycode < 94 )
		|| keycode == 124 )
	{
		return ;
	}
	else
	{
		event.Skip() ;
	}
}
//��д��ĸ�Ĵ���.
void MyTextCtrl::OnCharCharUpper(wxKeyEvent& event, int keycode)
{
	if ( m_bCharUpper )
	{
		if (keycode >= 'a' && keycode <= 'z')
		{
			event.m_keyCode = event.m_keyCode - 'a' + 'A';
			wxString text(wxChar(keycode - 'a' + 'A'), 1);
			WriteText(text);
		}
		else
			event.Skip();
	}
	else
	{
		event.Skip() ;
	}
}

//onChar ��Ϣ����.
void MyTextCtrl::OnChar(wxKeyEvent& event)
{
	if ( event.ControlDown() ) 
	{
		event.Skip() ;
		return ;
	}

	int keycode = event.GetKeyCode();
	wxString	strValue = GetValue() ;

	if ( m_bOnlyNum )
		OnCharOnlyNum(event, keycode);
	else if( m_bGroup )
		OnCharGroup(event, keycode);
	else if ( m_bOnlyIp )
		OnCharOnlyIp(event, keycode);
	else if( m_bOnlyMac )
		OnCharOnlyMac(event, keycode);
	else if( m_bOnlyPCName )
		OnCharOnlyPCName(event, keycode);
	else if( m_bOnlyUser )
		OnCharOnlyUser(event, keycode);
	else
		OnCharCharUpper(event, keycode);
}

void MyTextCtrl::SetLimitCount( int nCount ) 
{
	SetMaxLength( nCount );
}

void MyTextCtrl::MakeUpper( bool bUpper ) 
{
	m_bCharUpper = bUpper ;
}

void MyTextCtrl::SetOnlyNum( bool bOnlyNum ) 
{
	m_bOnlyNum = bOnlyNum ;
}

void MyTextCtrl::SetOnlyMac( bool bOnlyMac )
{
	m_bOnlyMac = bOnlyMac ;
	if ( bOnlyMac ) SetMaxLength( 12 ) ;
}

void MyTextCtrl::SetOnlyIp( bool bOnlyIp )
{
	m_bOnlyIp = bOnlyIp ;
	if ( bOnlyIp ) SetMaxLength( 15 ) ;
}

void MyTextCtrl::SetGroupName( bool bGroup )
{
	m_bGroup = bGroup ;
	if ( bGroup ) SetMaxLength( 20 ) ;
} 

void MyTextCtrl::SetPCName( bool bPCName )
{
	m_bOnlyPCName = bPCName;
}
void MyTextCtrl::SetUserName( bool bUser )
{
	m_bOnlyUser = bUser;
}


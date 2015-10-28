
#include <wx/wx.h>
#include <wx/socket.h>
#include <wx/thread.h>
#include <wx/log.h>
#include <wx/tokenzr.h>

int main()
{
	wxDatagramSocket *m_pSocket=NULL;

    wxIPV4address   LocalAddress ;
    LocalAddress.AnyAddress() ;
    LocalAddress.Service( 7498 ) ;

	m_pSocket = new wxDatagramSocket( LocalAddress, wxSOCKET_REUSEADDR ) ;
	if ( !m_pSocket->IsOk())
	{
		m_pSocket->Destroy() ;
		m_pSocket = NULL ;
	}


	wxIPV4address	From;
	From.Hostname(_T("192.168.21.167"));
	From.Service( 7494 ) ;
	char buffer[1024];
	m_pSocket->SendTo( From, buffer, sizeof(buffer) ) ;

}

void recv_loop()
{
	wxDatagramSocket *m_pSocket=NULL;

	wxIPV4address	From;
	From.Hostname(_T("192.168.21.167"));
	From.Service( 7494 ) ;

	char szSendBuf[4096];

	while(1)
	{
		if (!m_pSocket->WaitForRead(0, 500))
				continue;
		m_pSocket->RecvFrom( From, szSendBuf, 4096 );

		if ( m_pSocket->Error() )
		{
			int dwStatus = m_pSocket->LastError();
			continue;
		}


	}

}

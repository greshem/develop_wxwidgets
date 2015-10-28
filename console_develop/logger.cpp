#include <wx/string.h>
#include <wx/wx.h> 
#define CHAR char

void IOCM_LogFile( wxString & strMsg )
{
	wxString	strLogPath = _T("./");
	strLogPath+= _T("OutputMsg.log") ;

	CHAR		szLogPath[260] = { 0 } ;
	CHAR		szInputString[1024] = { 0 } ;
	FILE		*pLogFile = NULL ;

	try
	{
		strcpy( szLogPath, strLogPath.mb_str() ) ;
		if ( strMsg.length() < sizeof( szInputString ) )
		{
			strcpy( szInputString, strMsg.mb_str() ) ;
		}
		else
		{
			strncpy( szInputString, strMsg.mb_str(), 1000 ) ;
		}

		pLogFile = fopen( szLogPath, "a" ) ;
		if ( pLogFile != NULL )
		{
			fseek( pLogFile, 0, SEEK_END ) ;
			long lLen = ftell( pLogFile ) ;
			if ( lLen >= 100 * 1024 * 1024 )
			{
				fclose( pLogFile ) ;
				remove( szLogPath ) ;
				pLogFile = fopen( szLogPath, "a" ) ;
				if ( pLogFile != NULL )
				{
					fputs( szInputString, pLogFile ) ;
					fclose( pLogFile ) ;
				}
			}
			else
			{
				fputs( szInputString, pLogFile ) ;
				fclose( pLogFile ) ;
			}
		}
	}
	catch ( ... )
	{

	}
}

void IOCM_LogFile( wxChar * pszMsg ) 
{
	wxString	strLogPath = _T("./");
				strLogPath+=_T("OutputMsg.log") ;
	wxString	strMsg = pszMsg ;

	CHAR		szLogPath[260] = { 0 } ;
	CHAR		szInputString[1024] = { 0 } ;
	FILE		*pLogFile = NULL ;

	try
	{
		strcpy( szLogPath, strLogPath.mb_str() ) ;
		if ( strMsg.length() < sizeof( szInputString ) )
		{
			strcpy( szInputString, strMsg.mb_str() ) ;
		}
		else
		{
			strncpy( szInputString, strMsg.mb_str(), 1000 ) ;
		}

		pLogFile = fopen( szLogPath, "a" ) ;
		if ( pLogFile != NULL )
		{
			fseek( pLogFile, 0, SEEK_END ) ;
			long lLen = ftell( pLogFile ) ;
			if ( lLen >= 100 * 1024 * 1024 )
			{
				fclose( pLogFile ) ;
				remove( szLogPath ) ;
				pLogFile = fopen( szLogPath, "a" ) ;
				if ( pLogFile != NULL )
				{
					fputs( szInputString, pLogFile ) ;
					fclose( pLogFile ) ;
				}
			}
			else
			{
				fputs( szInputString, pLogFile ) ;
				fclose( pLogFile ) ;
			}
		}
	}
	catch ( ... )
	{

	}
}

void IOCM_LogError( 
				   int    dwErrorCode , 
				   const wxChar* lpszErrorPos , 
				   int    dwErrorLine )
{
	wxString	strMsg ;

	strMsg.Printf( _T("DLXP20081210  Status: %d Source: %s Line %d\n"), dwErrorCode , lpszErrorPos , dwErrorLine ) ;

	//wxLogMessage( strMsg );
	IOCM_LogFile( strMsg ) ;
}
//========================================================================

int main()
{
	IOCM_LogFile( _T("linux\n"));
	IOCM_LogError(100, _T("linux\n"), __LINE__);
}


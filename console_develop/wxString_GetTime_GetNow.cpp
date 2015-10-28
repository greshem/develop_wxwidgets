#include <wx/wx.h>
#include <string> 
#include <sstream>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
//处理2012-5-18 14:59:22 这样的时间字符串,  来自于   还原点配置文件.
long GetTime( wxString strTime )
{
	long lTime = 0 ;
	long lYear = 0 ;
	long lMonth = 0 ;
	long lDay = 0 ;
	long lHour = 0 ;
	long lMinute = 0 ;
	long lSecond = 0 ;

	wxString strYear = strTime.BeforeFirst( _T('-') ) ;
	strYear.ToLong( &lYear ) ;

	wxString strMonth = strTime.AfterFirst( _T('-') ) ;
	strMonth = strMonth.BeforeFirst( _T('-') ) ;
	strMonth.ToLong( &lMonth ) ;

	wxString strDay = strTime.BeforeFirst( _T(' ') ) ;
	strDay = strDay.AfterLast( _T('-') ) ;
	strDay.ToLong( &lDay ) ;

	wxString strHour = strTime.AfterFirst( _T(' ') ) ;
	strHour = strHour.BeforeFirst( _T(':') ) ;
	strHour.ToLong( &lHour ) ;

	wxString strMinute = strTime.BeforeLast( _T(':') ) ;
	strMinute = strMinute.AfterLast( _T(':') ) ;
	strMinute.ToLong( &lMinute ) ;

	wxString strSecond = strTime.AfterLast( _T(':') ) ;
	strSecond.ToLong( &lSecond ) ;

	wxDateTime Date( lDay, (wxDateTime::Month)(lMonth - 1), lYear, lHour, lMinute, lSecond ) ;

	lTime = Date.GetTicks() ;

	return lTime ;
}

int main()
{
	wxString time_str=_T("2012-5-18 14:59:22");
	string   stl_str(time_str.mb_str());
	long tmp= GetTime(time_str);
	printf("%ld\n", tmp);
	printf("%s\n", stl_str.c_str());

	char buffer[128]={0};
 	time_t t=tmp;
    //t=time(NULL);
    strftime(buffer, sizeof(buffer), "%Y_%m_%d_%T\n", localtime(&t));
    printf("%s", buffer);
}


#include <wx/string.h>
#include <wx/wx.h> 

//bool wxGetDiskSpace(const wxString& path, wxLongLong *total = NULL, wxLongLong *free = NULL)
int main()
{
	wxLongLong  total;
	wxLongLong  free;
	
	wxGetDiskSpace(wxT("/"), &total, &free);
	
	wxString log_str= _T("Total=") + total.ToString();
	log_str+=  _T("free")+ free.ToString()+_T("\n");
	
	wxLogMessage(log_str);
	
	//这里wxwidgets 自动会添加 stda 的指令 告诉你 这边 有问题, 让你自己去查问题.
	//printf("total: %d , free %d \n",  total, free);, 
}



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
	
	//����wxwidgets �Զ������ stda ��ָ�� ������ ��� ������, �����Լ�ȥ������.
	//printf("total: %d , free %d \n",  total, free);, 
}



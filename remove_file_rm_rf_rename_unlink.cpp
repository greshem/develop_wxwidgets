
// :wxRemoveFile
// bool wxRemoveFile(const wxString& file)
// ɾ�� file �ļ�, ���� true ��ʾ�ɹ���

// ::wxRenameFile
// bool wxRenameFile(const wxString& file1, const wxString& file2, bool overwrite = true)
// ������ file1 Ϊ file2, ���� true ��ʾ�ɹ���
// ��Ŀ���ļ��Ѿ�����ʱ�� �� overwrite ����Ϊ true (Ĭ��), �ļ���������, overwrite Ϊ false, ������������, ��������ʧ�ܡ�

// bool wxRmdir(const wxString& dir, int flags=0)
// ɾ�� dir Ŀ¼, ���� true ��ʾ�ɹ��� ���������ʹ����Ч��
// ���� flags ĿǰΪ��������, ���Ժ���ܻ�ʹ�õ���
// ��ע�⻹��һ�� wxRmDir ����, �ú����ǿ���ֲ�Բ���ϵͳ�ӿڱ�׼���� rmdir() �ķ�װ, ���᷵��һ�� int �͵Ĵ����ʶ���� bool ��( ��������������Ŀǰ�� wxRmdir ��ͬ ), ��Ҫ������������Ū������


#include <wx/string.h>
#include <wx/wx.h> 

int main()
{
	if(wxRemoveFile(_T("/tmp/tmp.tmp")))
	{
		printf("remove file success \n");
	}
	else
	{
		printf("remove file failure  \n");
	}
}



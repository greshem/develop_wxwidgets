
#include <wx/string.h>
#include <wx/wx.h> 
//   wxCharBuffer �� * �ķ��ű������� ���Զ���   c++ ���� ����ͨ�� string �����й���, 
//		�������  c ����ֻ����ͨ�� wxCharBuffer�� data ��������ȡ����. 
using namespace std;
int main(int argc, char *argv[])
{
	wxString tmp=_T("BBBBBB");
	const wxCharBuffer buffer= tmp.mb_str(wxConvUTF8);
	printf("%s\n",   buffer.data());
	//printf("%s\n",  (char*) buffer);  #  core dump 
	string tmp2(buffer);
	cout<<tmp2<<endl;

	printf("%s\n", tmp.mb_str().data());
}

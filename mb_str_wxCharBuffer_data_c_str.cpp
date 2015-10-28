
#include <wx/string.h>
#include <wx/wx.h> 
//   wxCharBuffer 的 * 的符号被重载了 所以对于   c++ 总是 可以通过 string 来进行构造, 
//		但与对于  c 语言只能能通过 wxCharBuffer的 data 方法来获取数据. 
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

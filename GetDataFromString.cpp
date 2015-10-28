#include <wx/string.h>
#include <wx/wx.h> 

//0008qianqian0008wenwen110008wenwen2200101234567890
//8  qianqian
//8  wenwen11
//8  wenwen22
//10 1234567890
void GetDataFromString(wxString &stream, wxString &data)
{
	wxString strLen = stream.Left(4);
	long    lLen;
	strLen.ToLong(&lLen);
	stream = stream.Right(stream.Len() - 4);
	data = stream.Left(lLen);
	stream = stream.Right(stream.Len() - lLen);
}

int main()
{
	wxString input_str=wxT("0008qianqian0008wenwen110008wenwen2200101234567890");
	wxString data;
	while(!input_str.IsEmpty())
	{
		GetDataFromString(input_str, data);
		printf("%s\n", data.mb_str().data());
	}
}


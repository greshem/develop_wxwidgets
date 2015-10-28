
// :wxRemoveFile
// bool wxRemoveFile(const wxString& file)
// 删除 file 文件, 返回 true 表示成功。

// ::wxRenameFile
// bool wxRenameFile(const wxString& file1, const wxString& file2, bool overwrite = true)
// 重命名 file1 为 file2, 返回 true 表示成功。
// 当目标文件已经存在时， 若 overwrite 参数为 true (默认), 文件将被覆盖, overwrite 为 false, 不进行重命名, 函数返回失败。

// bool wxRmdir(const wxString& dir, int flags=0)
// 删除 dir 目录, 翻译 true 表示成功。 在虚拟机下使用无效。
// 参数 flags 目前为保留参数, 在以后可能会使用到。
// 请注意还有一个 wxRmDir 函数, 该函数是可移植性操作系统接口标准函数 rmdir() 的封装, 它会返回一个 int 型的错误标识代替 bool 型( 但是在其他方面目前与 wxRmdir 相同 ), 不要将这两个函数弄混淆。


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



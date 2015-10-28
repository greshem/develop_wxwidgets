
#include <wx/wx.h> 
#include "Test.h" 
//#2011_03_11_16:46:24   星期五   add by greshem
//# 这里的 MyFrame1 继承来自 wxFrame  可以由不同的工具生成  wxGlade 
class MyApp : public wxApp
{
public:
    virtual bool OnInit();

};


IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    
    // create the main application window
    // MyFrame1 *frame = new MyFrame1(NULL, 0, _T("AccessTest wxWidgets App"),
    //                            wxPoint(50, 50), wxSize(450, 340), 0);
    // frame->Show(true);

	TestDialog * mainWindow = new  TestDialog(NULL);
	mainWindow->ShowModal();
	//mainWindow->Destory();

	

	

    // success: wxApp::OnRun() will be called which will enter the main message
    // loop and the application will run. If we returned false here, the
    // application would exit immediately.
    //wxMessageBox( _T("This sample has to be compiled with wxUSE_ACCESSIBILITY"), _T("Building error"), wxOK);

    return true;
}

//int main()


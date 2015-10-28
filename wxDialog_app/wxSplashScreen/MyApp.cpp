
#include <wx/wx.h> 
#include "TestDialog.h" 
#include <wx/bitmap.h>
#include <wx/splash.h>

//#2011_03_11_16:46:24   星期五   add by greshem
//# 这里的 MyFrame1 继承来自 wxFrame  可以由不同的工具生成  wxGlade 
class MyApp : public wxApp
{
public:
    virtual bool OnInit();

};


IMPLEMENT_APP(MyApp)

void Splash()
{
	wxBitmap bitmap;
	if (bitmap.LoadFile(wxT("./gnome-64.png"), wxBITMAP_TYPE_PNG))
	{
	  wxSplashScreen* splash = new wxSplashScreen(bitmap,
		  wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
		  6000, NULL, -1, wxDefaultPosition, wxDefaultSize,
		  wxSIMPLE_BORDER|wxSTAY_ON_TOP);
	}
  	wxYield();
}

bool MyApp::OnInit()
{
    
    // create the main application window
    // MyFrame1 *frame = new MyFrame1(NULL, 0, _T("AccessTest wxWidgets App"),
    //                            wxPoint(50, 50), wxSize(450, 340), 0);
    // frame->Show(true);
    //fixme not show the splash.
	Splash();
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


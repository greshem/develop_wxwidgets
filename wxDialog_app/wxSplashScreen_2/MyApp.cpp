
#include <wx/wx.h> 
#include <wx/splash.h>
#include "icons/about_logo.xpm"
#include "TestDialog.h" 
//#2011_03_11_16:46:24   ������   add by greshem
//# ����� MyFrame1 �̳����� wxFrame  �����ɲ�ͬ�Ĺ�������  wxGlade 
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

   wxBitmap bitmap;

	bitmap = wxBitmap(about_logo);

	//bool ok = frame->m_isPda
	//       ? bitmap.Ok()
	//      : bitmap.LoadFile(_T("splash.png"), wxBITMAP_TYPE_PNG);

        new wxSplashScreen(bitmap,
            wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,
            6000, NULL, wxID_ANY, wxDefaultPosition, wxDefaultSize,
			wxSIMPLE_BORDER);
            //wxSIMPLE_BORDER|wxSTAY_ON_TOP);
    wxYield();



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


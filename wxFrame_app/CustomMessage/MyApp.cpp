
#include <wx/wx.h> 
#include "TestFrame.h" 
//#2011_03_11_16:46:24   星期五   add by greshem
//# 这里的 TestFrame1 继承来自 wxFrame  可以由不同的工具生成  wxGlade 
class MyApp : public wxApp
{
public:
    virtual bool OnInit();

};


IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    TestFrame *frame = new TestFrame(_T("Event wxWidgets Sample"),
                                 wxPoint(50, 50), wxSize(600, 340));

    frame->Show(true);

    return true;
}

//int main()



#include <wx/wx.h> 
#include "TestFrame.h" 
//#2011_03_11_16:46:24   ������   add by greshem
//# ����� TestFrame1 �̳����� wxFrame  �����ɲ�ͬ�Ĺ�������  wxGlade 
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


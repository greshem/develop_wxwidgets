 #include <stdlib.h>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string> 
#include <dirent.h>
#include <fstream>
#include <iterator>  
#include <vector> 
#include <algorithm>
#include <iostream> 
#include <map>
#include <wx/wx.h>
#include <wx/thread.h>
#include <wx/confbase.h>
#include <wx/encconv.h>
using namespace std;
int main(int argc, char *argv[])
{
 
 wxConfigBase *pConfig = wxConfigBase::Get();
  if ( pConfig == __null )
    return 1;


  //pConfig->Write(L"/Controls/Text", m_text->GetValue());
  //pConfig->Write(L"/Controls/Check", m_check->GetValue());


  int x, y, w, h;
  //GetClientSize(&w, &h);
  //GetPosition(&x, &y);
  pConfig->Write(L"/MainFrame/x", (long) x);
  pConfig->Write(L"/MainFrame/y", (long) y);
  pConfig->Write(L"/MainFrame/w", (long) w);
  pConfig->Write(L"/MainFrame/h", (long) h);

  pConfig->Write(L"/TestValue", L"A test value");
}

#include <stdlib.h>
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
#include <wx/datetime.h>
#include <wx/generic/dcpsg.h>
 

//wxPostScriptDC::Clear()
//wxPostScriptDC::DestroyClippingRegion()
//wxPostScriptDC::DoBlit(int, int, int, int, wxDC*, int, int, int, bool, int, int)
//wxPostScriptDC::DoCrossHair(int, int)
//wxPostScriptDC::DoDrawArc(int, int, int, int, int, int)
//wxPostScriptDC::DoDrawBitmap(wxBitmap const&, int, int, bool)
//wxPostScriptDC::DoDrawEllipse(int, int, int, int)
//wxPostScriptDC::DoDrawEllipticArc(int, int, int, int, double, double)
//wxPostScriptDC::DoDrawIcon(wxIcon const&, int, int)
//wxPostScriptDC::DoDrawLine(int, int, int, int)
//wxPostScriptDC::DoDrawLines(int, wxPoint*, int, int)
//wxPostScriptDC::DoDrawPoint(int, int)
//wxPostScriptDC::DoDrawPolygon(int, wxPoint*, int, int, int)
//wxPostScriptDC::DoDrawPolyPolygon(int, int*, wxPoint*, int, int, int)
//wxPostScriptDC::DoDrawRectangle(int, int, int, int)
//wxPostScriptDC::DoDrawRotatedText(wxString const&, int, int, double)
//wxPostScriptDC::DoDrawRoundedRectangle(int, int, int, int, double)
//wxPostScriptDC::DoDrawSpline(wxList*)
//wxPostScriptDC::DoDrawText(wxString const&, int, int)
//wxPostScriptDC::DoFloodFill(int, int, wxColour const&, int)
//wxPostScriptDC::DoGetPixel(int, int, wxColour*) const
//wxPostScriptDC::DoGetSize(int*, int*) const
//wxPostScriptDC::DoGetSizeMM(int*, int*) const
//wxPostScriptDC::DoGetTextExtent(wxString const&, int*, int*, int*, int*, wxFont*) const
//wxPostScriptDC::DoSetClippingRegion(int, int, int, int)
//wxPostScriptDC::EndDoc()
//wxPostScriptDC::EndPage()
//wxPostScriptDC::GetCharHeight() const
//wxPostScriptDC::GetCharWidth() const
//wxPostScriptDC::GetClassInfo() const
//wxPostScriptDC::GetPPI() const
//wxPostScriptDC::GetResolution()
//wxPostScriptDC::IsOk() const
//wxPostScriptDC::PsPrint(char const*)
//wxPostScriptDC::PsPrintf(wchar_t const*, ...)
//wxPostScriptDC::PsPrint(int)
//wxPostScriptDC::SetAxisOrientation(bool, bool)
//wxPostScriptDC::SetBackground(wxBrush const&)
//wxPostScriptDC::SetBrush(wxBrush const&)
//wxPostScriptDC::SetDeviceOrigin(int, int)
//wxPostScriptDC::SetFont(wxFont const&)
//wxPostScriptDC::SetLogicalFunction(int)
//wxPostScriptDC::SetPen(wxPen const&)
//wxPostScriptDC::SetResolution(int)
//wxPostScriptDC::StartDoc(wxString const&)
//wxPostScriptDC::StartPage()
//wxPostScriptDC::wxCreateObject()
//wxPostScriptDC::~wxPostScriptDC()
//wxPostScriptDC::wxPostScriptDC()
//wxPostScriptDC::wxPostScriptDC(wxPrintData const&)
//

using namespace std;
int main(int argc, char *argv[])
{
	
	wxPostScriptDC a;
	return 0;
}

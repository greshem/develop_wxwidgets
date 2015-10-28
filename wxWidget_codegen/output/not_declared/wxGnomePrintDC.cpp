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
 

//wxGnomePrintDC::Clear()
//wxGnomePrintDC::DestroyClippingRegion()
//wxGnomePrintDC::DoBlit(int, int, int, int, wxDC*, int, int, int, bool, int, int)
//wxGnomePrintDC::DoCrossHair(int, int)
//wxGnomePrintDC::DoDrawArc(int, int, int, int, int, int)
//wxGnomePrintDC::DoDrawBitmap(wxBitmap const&, int, int, bool)
//wxGnomePrintDC::DoDrawEllipse(int, int, int, int)
//wxGnomePrintDC::DoDrawEllipticArc(int, int, int, int, double, double)
//wxGnomePrintDC::DoDrawIcon(wxIcon const&, int, int)
//wxGnomePrintDC::DoDrawLine(int, int, int, int)
//wxGnomePrintDC::DoDrawLines(int, wxPoint*, int, int)
//wxGnomePrintDC::DoDrawPoint(int, int)
//wxGnomePrintDC::DoDrawPolygon(int, wxPoint*, int, int, int)
//wxGnomePrintDC::DoDrawPolyPolygon(int, int*, wxPoint*, int, int, int)
//wxGnomePrintDC::DoDrawRectangle(int, int, int, int)
//wxGnomePrintDC::DoDrawRotatedText(wxString const&, int, int, double)
//wxGnomePrintDC::DoDrawRoundedRectangle(int, int, int, int, double)
//wxGnomePrintDC::DoDrawSpline(wxList*)
//wxGnomePrintDC::DoDrawText(wxString const&, int, int)
//wxGnomePrintDC::DoFloodFill(int, int, wxColour const&, int)
//wxGnomePrintDC::DoGetPixel(int, int, wxColour*) const
//wxGnomePrintDC::DoGetSize(int*, int*) const
//wxGnomePrintDC::DoGetSizeMM(int*, int*) const
//wxGnomePrintDC::DoGetTextExtent(wxString const&, int*, int*, int*, int*, wxFont*) const
//wxGnomePrintDC::DoSetClippingRegion(int, int, int, int)
//wxGnomePrintDC::EndDoc()
//wxGnomePrintDC::EndPage()
//wxGnomePrintDC::GetCharHeight() const
//wxGnomePrintDC::GetCharWidth() const
//wxGnomePrintDC::GetClassInfo() const
//wxGnomePrintDC::GetPPI() const
//wxGnomePrintDC::GetResolution()
//wxGnomePrintDC::IsOk() const
//wxGnomePrintDC::makeEllipticalPath(int, int, int, int)
//wxGnomePrintDC::SetAxisOrientation(bool, bool)
//wxGnomePrintDC::SetBackground(wxBrush const&)
//wxGnomePrintDC::SetBrush(wxBrush const&)
//wxGnomePrintDC::SetDeviceOrigin(int, int)
//wxGnomePrintDC::SetFont(wxFont const&)
//wxGnomePrintDC::SetLogicalFunction(int)
//wxGnomePrintDC::SetLogicalOrigin(int, int)
//wxGnomePrintDC::SetPen(wxPen const&)
//wxGnomePrintDC::SetPrintData(wxPrintData const&)
//wxGnomePrintDC::SetResolution(int)
//wxGnomePrintDC::StartDoc(wxString const&)
//wxGnomePrintDC::StartPage()
//wxGnomePrintDC::~wxGnomePrintDC()
//wxGnomePrintDC::wxGnomePrintDC(wxPrintData const&)
//

using namespace std;
int main(int argc, char *argv[])
{
	
	wxGnomePrintDC a;
	return 0;
}

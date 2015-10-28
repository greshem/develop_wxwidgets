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
//#include <gtest/gtest.h>
//2011_03_09 by greshem. 

#include <wx/wx.h>
#include <wx/thread.h>
#include <wx/confbase.h>
#include <wx/encconv.h>
#include <wx/datetime.h>
#include <wx/bitmap.h>


//wxBitmap::CloneRefData(wxObjectRefData const*) const
//wxBitmap::ConvertToImage() const
//wxBitmap::CopyFromIcon(wxIcon const&)
//wxBitmap::CreateFromImageAsPixbuf(wxImage const&)
//wxBitmap::CreateFromImageAsPixmap(wxImage const&, int)
//wxBitmap::CreateFromImage(wxImage const&, int)
//wxBitmap::Create(int, int, int)
//wxBitmap::CreateRefData() const
//wxBitmap::GetClassInfo() const
//wxBitmap::GetDepth() const
//wxBitmap::GetHeight() const
//wxBitmap::GetMask() const
//wxBitmap::GetPalette() const
//wxBitmap::GetPixbuf() const
//wxBitmap::GetPixmap() const
//wxBitmap::GetRawData(wxPixelDataBase&, int)
//wxBitmap::GetSubBitmap(wxRect const&) const
//wxBitmap::GetWidth() const
//wxBitmap::HasAlpha() const
//wxBitmap::HasPixbuf() const
//wxBitmap::HasPixmap() const
//wxBitmap::InitStandardHandlers()
//wxBitmap::IsOk() const
//wxBitmap::LoadFile(wxString const&, wxBitmapType)
//wxBitmap::PurgeOtherRepresentations(wxBitmap::Representation)
//wxBitmap::Rescale(int, int, int, int, int, int) const
//wxBitmap::SaveFile(wxString const&, wxBitmapType, wxPalette const*) const
//wxBitmap::SetDepth(int)
//wxBitmap::SetHeight(int)
//wxBitmap::SetMask(wxMask*)
//wxBitmap::SetPalette(wxPalette const&)
//wxBitmap::SetPixbuf(_GdkPixbuf*, int)
//wxBitmap::SetPixmap(_GdkDrawable*)
//wxBitmap::SetWidth(int)
//wxBitmap::UngetRawData(wxPixelDataBase&)
//wxBitmap::UseAlpha()
//wxBitmap::~wxBitmap()
//wxBitmap::wxBitmap(char const* const*)
//wxBitmap::wxBitmap(char const*, int, int, int)
//wxBitmap::wxBitmap(int, int, int)
//wxBitmap::wxBitmap(wxString const&, wxBitmapType)
//wxBitmap::wxCreateObject()
//

using namespace std;
int main(int argc, char *argv[])
{
	wxInitialize();

	//wxBitmap  a(100,100,16);
	wxBitmap  a(100,100);
	a.SaveFile(_T("a.bmp"), wxBITMAP_TYPE_BMP);	
	return 0;
}

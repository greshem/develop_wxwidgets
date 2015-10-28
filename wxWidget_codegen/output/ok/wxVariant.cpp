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
#include <wx/variant.h>
 

//wxVariant::Append(wxVariant const&)
//wxVariant::Clear()
//wxVariant::ClearList()
//wxVariant::Convert(bool*) const
//wxVariant::Convert(double*) const
//wxVariant::Convert(long*) const
//wxVariant::Convert(wchar_t*) const
//wxVariant::Convert(wxDateTime*) const
//wxVariant::Convert(wxString*) const
//wxVariant::Delete(unsigned int)
//wxVariant::GetArrayString() const
//wxVariant::GetBool() const
//wxVariant::GetChar() const
//wxVariant::GetClassInfo() const
//wxVariant::GetCount() const
//wxVariant::GetDateTime() const
//wxVariant::GetDouble() const
//wxVariant::GetList() const
//wxVariant::GetLong() const
//wxVariant::GetString() const
//wxVariant::GetType() const
//wxVariant::GetVoidPtr() const
//wxVariant::GetWxObjectPtr() const
//wxVariant::Insert(wxVariant const&)
//wxVariant::IsNull() const
//wxVariant::IsType(wxString const&) const
//wxVariant::IsValueKindOf(wxClassInfo const*) const
//wxVariant::MakeNull()
//wxVariant::MakeString() const
//wxVariant::Member(wxVariant const&) const
//wxVariant::NullList()
//wxVariant::operator=(bool)
//wxVariant::operator==(bool) const
//wxVariant::operator!=(bool) const
//wxVariant::operator=(double)
//wxVariant::operator==(double) const
//wxVariant::operator!=(double) const
//wxVariant::operator=(long)
//wxVariant::operator==(long) const
//wxVariant::operator!=(long) const
//wxVariant::operator[](unsigned int)
//wxVariant::operator[](unsigned int) const
//wxVariant::operator=(void*)
//wxVariant::operator==(void*) const
//wxVariant::operator!=(void*) const
//wxVariant::operator=(wchar_t)
//wxVariant::operator==(wchar_t) const
//wxVariant::operator=(wchar_t const*)
//wxVariant::operator!=(wchar_t) const
//wxVariant::operator=(wxArrayString const&)
//wxVariant::operator==(wxArrayString const&) const
//wxVariant::operator!=(wxArrayString const&) const
//wxVariant::operator=(wxDateTime const&)
//wxVariant::operator==(wxDateTime const&) const
//wxVariant::operator!=(wxDateTime const&) const
//wxVariant::operator=(wxList const&)
//wxVariant::operator==(wxList const&) const
//wxVariant::operator!=(wxList const&) const
//wxVariant::operator=(wxObject*)
//wxVariant::operator==(wxObject*) const
//wxVariant::operator!=(wxObject*) const
//wxVariant::operator=(wxString const&)
//wxVariant::operator==(wxString const&) const
//wxVariant::operator!=(wxString const&) const
//wxVariant::operator=(wxVariant const&)
//wxVariant::operator==(wxVariant const&) const
//wxVariant::operator!=(wxVariant const&) const
//wxVariant::operator=(wxVariantData*)
//wxVariant::Ref(wxVariant const&)
//wxVariant::SetData(wxVariantData*)
//wxVariant::UnRef()
//wxVariant::wxCreateObject()
//wxVariant::~wxVariant()
//wxVariant::wxVariant()
//wxVariant::wxVariant(bool, wxString const&)
//wxVariant::wxVariant(double, wxString const&)
//wxVariant::wxVariant(int, wxString const&)
//wxVariant::wxVariant(long, wxString const&)
//wxVariant::wxVariant(short, wxString const&)
//wxVariant::wxVariant(void*, wxString const&)
//wxVariant::wxVariant(wchar_t const*, wxString const&)
//wxVariant::wxVariant(wchar_t, wxString const&)
//wxVariant::wxVariant(wxArrayString const&, wxString const&)
//wxVariant::wxVariant(wxDateTime const&, wxString const&)
//wxVariant::wxVariant(wxList const&, wxString const&)
//wxVariant::wxVariant(wxObject*, wxString const&)
//wxVariant::wxVariant(wxString const&, wxString const&)
//wxVariant::wxVariant(wxVariant const&)
//wxVariant::wxVariant(wxVariantData*, wxString const&)
//

using namespace std;
int main(int argc, char *argv[])
{
	
	wxVariant a;
	return 0;
}

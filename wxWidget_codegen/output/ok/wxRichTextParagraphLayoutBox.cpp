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
#include <wx/richtext/richtextbuffer.h>
 

//wxRichTextParagraphLayoutBox::AddImage(wxImage const&, wxTextAttrEx*)
//wxRichTextParagraphLayoutBox::AddParagraphs(wxString const&, wxTextAttrEx*)
//wxRichTextParagraphLayoutBox::AddParagraph(wxString const&, wxTextAttrEx*)
//wxRichTextParagraphLayoutBox::ApplyStyleSheet(wxRichTextStyleSheet*)
//wxRichTextParagraphLayoutBox::Clear()
//wxRichTextParagraphLayoutBox::ClearListStyle(wxRichTextRange const&, int)
//wxRichTextParagraphLayoutBox::CollectStyle(wxTextAttrEx&, wxTextAttrEx const&, long&, int&)
//wxRichTextParagraphLayoutBox::CopyFragment(wxRichTextRange const&, wxRichTextParagraphLayoutBox&)
//wxRichTextParagraphLayoutBox::Copy(wxRichTextParagraphLayoutBox const&)
//wxRichTextParagraphLayoutBox::DeleteRange(wxRichTextRange const&)
//wxRichTextParagraphLayoutBox::DoGetStyle(long, wxTextAttrEx&, bool)
//wxRichTextParagraphLayoutBox::DoNumberList(wxRichTextRange const&, wxRichTextRange const&, int, wxRichTextListStyleDefinition*, int, int, int)
//wxRichTextParagraphLayoutBox::Draw(wxDC&, wxRichTextRange const&, wxRichTextRange const&, wxRect const&, int, int)
//wxRichTextParagraphLayoutBox::FindNextParagraphNumber(wxRichTextParagraph*, wxRichTextAttr&) const
//wxRichTextParagraphLayoutBox::GetClassInfo() const
//wxRichTextParagraphLayoutBox::GetInvalidRange(bool) const
//wxRichTextParagraphLayoutBox::GetLeafObjectAtPosition(long) const
//wxRichTextParagraphLayoutBox::GetLineAtPosition(long, bool) const
//wxRichTextParagraphLayoutBox::GetLineAtYPosition(int) const
//wxRichTextParagraphLayoutBox::GetLineCount() const
//wxRichTextParagraphLayoutBox::GetLineForVisibleLineNumber(long) const
//wxRichTextParagraphLayoutBox::GetLineSizeAtPosition(long, bool) const
//wxRichTextParagraphLayoutBox::GetParagraphAtLine(long) const
//wxRichTextParagraphLayoutBox::GetParagraphAtPosition(long, bool) const
//wxRichTextParagraphLayoutBox::GetParagraphForLine(wxRichTextLine*) const
//wxRichTextParagraphLayoutBox::GetParagraphLength(long) const
//wxRichTextParagraphLayoutBox::GetParagraphText(long) const
//wxRichTextParagraphLayoutBox::GetRangeSize(wxRichTextRange const&, wxSize&, int&, wxDC&, int, wxPoint) const
//wxRichTextParagraphLayoutBox::GetStyleForRange(wxRichTextRange const&, wxTextAttrEx&)
//wxRichTextParagraphLayoutBox::GetStyle(long, wxRichTextAttr&)
//wxRichTextParagraphLayoutBox::GetStyle(long, wxTextAttrEx&)
//wxRichTextParagraphLayoutBox::GetText() const
//wxRichTextParagraphLayoutBox::GetTextForRange(wxRichTextRange const&) const
//wxRichTextParagraphLayoutBox::GetUncombinedStyle(long, wxRichTextAttr&)
//wxRichTextParagraphLayoutBox::GetUncombinedStyle(long, wxTextAttrEx&)
//wxRichTextParagraphLayoutBox::GetVisibleLineNumber(long, bool, bool) const
//wxRichTextParagraphLayoutBox::HasCharacterAttributes(wxRichTextRange const&, wxRichTextAttr const&) const
//wxRichTextParagraphLayoutBox::HasCharacterAttributes(wxRichTextRange const&, wxTextAttrEx const&) const
//wxRichTextParagraphLayoutBox::HasParagraphAttributes(wxRichTextRange const&, wxRichTextAttr const&) const
//wxRichTextParagraphLayoutBox::HasParagraphAttributes(wxRichTextRange const&, wxTextAttrEx const&) const
//wxRichTextParagraphLayoutBox::Init()
//wxRichTextParagraphLayoutBox::InsertFragment(long, wxRichTextParagraphLayoutBox&)
//wxRichTextParagraphLayoutBox::Invalidate(wxRichTextRange const&)
//wxRichTextParagraphLayoutBox::Layout(wxDC&, wxRect const&, int)
//wxRichTextParagraphLayoutBox::NumberList(wxRichTextRange const&, wxRichTextListStyleDefinition*, int, int, int)
//wxRichTextParagraphLayoutBox::NumberList(wxRichTextRange const&, wxString const&, int, int, int)
//wxRichTextParagraphLayoutBox::PositionToXY(long, long*, long*) const
//wxRichTextParagraphLayoutBox::PromoteList(int, wxRichTextRange const&, wxRichTextListStyleDefinition*, int, int)
//wxRichTextParagraphLayoutBox::PromoteList(int, wxRichTextRange const&, wxString const&, int, int)
//wxRichTextParagraphLayoutBox::Reset()
//wxRichTextParagraphLayoutBox::SetDefaultStyle(wxTextAttrEx const&)
//wxRichTextParagraphLayoutBox::SetListStyle(wxRichTextRange const&, wxRichTextListStyleDefinition*, int, int, int)
//wxRichTextParagraphLayoutBox::SetListStyle(wxRichTextRange const&, wxString const&, int, int, int)
//wxRichTextParagraphLayoutBox::SetStyle(wxRichTextRange const&, wxRichTextAttr const&, int)
//wxRichTextParagraphLayoutBox::SetStyle(wxRichTextRange const&, wxTextAttrEx const&, int)
//wxRichTextParagraphLayoutBox::wxCreateObject()
//wxRichTextParagraphLayoutBox::wxRichTextParagraphLayoutBox(wxRichTextObject*)
//wxRichTextParagraphLayoutBox::XYToPosition(long, long) const
//

using namespace std;
int main(int argc, char *argv[])
{
	
	wxRichTextParagraphLayoutBox a;
	return 0;
}

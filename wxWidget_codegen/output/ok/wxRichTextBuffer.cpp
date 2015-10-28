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
#include <wx/richtext/richtextstyles.h>
 

//wxRichTextBuffer::AddEventHandler(wxEvtHandler*)
//wxRichTextBuffer::AddHandler(wxRichTextFileHandler*)
//wxRichTextBuffer::BeginAlignment(wxTextAttrAlignment)
//wxRichTextBuffer::BeginBatchUndo(wxString const&)
//wxRichTextBuffer::BeginBold()
//wxRichTextBuffer::BeginCharacterStyle(wxString const&)
//wxRichTextBuffer::BeginFontSize(int)
//wxRichTextBuffer::BeginFont(wxFont const&)
//wxRichTextBuffer::BeginItalic()
//wxRichTextBuffer::BeginLeftIndent(int, int)
//wxRichTextBuffer::BeginLineSpacing(int)
//wxRichTextBuffer::BeginListStyle(wxString const&, int, int)
//wxRichTextBuffer::BeginNumberedBullet(int, int, int, int)
//wxRichTextBuffer::BeginParagraphSpacing(int, int)
//wxRichTextBuffer::BeginParagraphStyle(wxString const&)
//wxRichTextBuffer::BeginRightIndent(int)
//wxRichTextBuffer::BeginStandardBullet(wxString const&, int, int, int)
//wxRichTextBuffer::BeginStyle(wxTextAttrEx const&)
//wxRichTextBuffer::BeginSuppressUndo()
//wxRichTextBuffer::BeginSymbolBullet(wxString const&, int, int, int)
//wxRichTextBuffer::BeginTextColour(wxColour const&)
//wxRichTextBuffer::BeginUnderline()
//wxRichTextBuffer::BeginURL(wxString const&, wxString const&)
//wxRichTextBuffer::CanPasteFromClipboard() const
//wxRichTextBuffer::CleanUpHandlers()
//wxRichTextBuffer::ClearEventHandlers()
//wxRichTextBuffer::ClearStyleStack()
//wxRichTextBuffer::CopyToClipboard(wxRichTextRange const&)
//wxRichTextBuffer::Copy(wxRichTextBuffer const&)
//wxRichTextBuffer::DeleteRangeWithUndo(wxRichTextRange const&, wxRichTextCtrl*)
//wxRichTextBuffer::Dump()
//wxRichTextBuffer::EndAllStyles()
//wxRichTextBuffer::EndBatchUndo()
//wxRichTextBuffer::EndStyle()
//wxRichTextBuffer::EndSuppressUndo()
//wxRichTextBuffer::FindHandlerFilenameOrType(wxString const&, int)
//wxRichTextBuffer::FindHandler(int)
//wxRichTextBuffer::FindHandler(wxString const&)
//wxRichTextBuffer::FindHandler(wxString const&, int)
//wxRichTextBuffer::GetClassInfo() const
//wxRichTextBuffer::GetExtWildcard(bool, bool, wxArrayInt*)
//wxRichTextBuffer::GetStyleForNewParagraph(long, bool, bool) const
//wxRichTextBuffer::Init()
//wxRichTextBuffer::InitStandardHandlers()
//wxRichTextBuffer::InsertHandler(wxRichTextFileHandler*)
//wxRichTextBuffer::InsertImageWithUndo(long, wxRichTextImageBlock const&, wxRichTextCtrl*, int)
//wxRichTextBuffer::InsertNewlineWithUndo(long, wxRichTextCtrl*, int)
//wxRichTextBuffer::InsertParagraphsWithUndo(long, wxRichTextParagraphLayoutBox const&, wxRichTextCtrl*, int)
//wxRichTextBuffer::InsertTextWithUndo(long, wxString const&, wxRichTextCtrl*, int)
//wxRichTextBuffer::LoadFile(wxInputStream&, int)
//wxRichTextBuffer::LoadFile(wxString const&, int)
//wxRichTextBuffer::PasteFromClipboard(long)
//wxRichTextBuffer::PopStyleSheet()
//wxRichTextBuffer::PushStyleSheet(wxRichTextStyleSheet*)
//wxRichTextBuffer::RemoveEventHandler(wxEvtHandler*, bool)
//wxRichTextBuffer::RemoveHandler(wxString const&)
//wxRichTextBuffer::ResetAndClearCommands()
//wxRichTextBuffer::SaveFile(wxOutputStream&, int)
//wxRichTextBuffer::SaveFile(wxString const&, int)
//wxRichTextBuffer::SendEvent(wxEvent&, bool)
//wxRichTextBuffer::SetRenderer(wxRichTextRenderer*)
//wxRichTextBuffer::SetStyleSheetAndNotify(wxRichTextStyleSheet*)
//wxRichTextBuffer::SubmitAction(wxRichTextAction*)
//wxRichTextBuffer::wxCreateObject()
//wxRichTextBuffer::~wxRichTextBuffer()
//

using namespace std;
int main(int argc, char *argv[])
{
	
	wxRichTextBuffer a;
	return 0;
}

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
#include <wx/richtext/richtextctrl.h>
#include <wx/richtext/richtextstyles.h>
 

//wxRichTextCtrl::AddImage(wxImage const&)
//wxRichTextCtrl::AddParagraph(wxString const&)
//wxRichTextCtrl::AppendText(wxString const&)
//wxRichTextCtrl::ApplyAlignmentToSelection(wxTextAttrAlignment)
//wxRichTextCtrl::ApplyBoldToSelection()
//wxRichTextCtrl::ApplyItalicToSelection()
//wxRichTextCtrl::ApplyStyleSheet(wxRichTextStyleSheet*)
//wxRichTextCtrl::ApplyStyle(wxRichTextStyleDefinition*)
//wxRichTextCtrl::ApplyUnderlineToSelection()
//wxRichTextCtrl::CanCopy() const
//wxRichTextCtrl::CanCut() const
//wxRichTextCtrl::CanDeleteSelection() const
//wxRichTextCtrl::CanPaste() const
//wxRichTextCtrl::CanRedo() const
//wxRichTextCtrl::CanUndo() const
//wxRichTextCtrl::Clear()
//wxRichTextCtrl::ClearAvailableFontNames()
//wxRichTextCtrl::ClearListStyle(wxRichTextRange const&, int)
//wxRichTextCtrl::Command(wxCommandEvent&)
//wxRichTextCtrl::Copy()
//wxRichTextCtrl::Create(wxWindow*, int, wxString const&, wxPoint const&, wxSize const&, long, wxValidator const&, wxString const&)
//wxRichTextCtrl::Cut()
//wxRichTextCtrl::DeleteSelectedContent(long*)
//wxRichTextCtrl::DeleteSelection()
//wxRichTextCtrl::Delete(wxRichTextRange const&)
//wxRichTextCtrl::DiscardEdits()
//wxRichTextCtrl::DoGetBestSize() const
//wxRichTextCtrl::DoLoadFile(wxString const&, int)
//wxRichTextCtrl::DoSaveFile(wxString const&, int)
//wxRichTextCtrl::DoSetSelection(long, long, bool)
//wxRichTextCtrl::DoSetValue(wxString const&, int)
//wxRichTextCtrl::DoWriteText(wxString const&, int)
//wxRichTextCtrl::ExtendSelection(long, long, int)
//wxRichTextCtrl::FindNextWordPosition(int) const
//wxRichTextCtrl::Freeze()
//wxRichTextCtrl::GetAdjustedCaretPosition(long) const
//wxRichTextCtrl::GetAvailableFontNames()
//wxRichTextCtrl::GetCaretPositionForIndex(long, wxRect&)
//wxRichTextCtrl::GetClassInfo() const
//wxRichTextCtrl::GetDefaultStyle() const
//wxRichTextCtrl::GetDefaultStyleEx() const
//wxRichTextCtrl::GetEventHashTable() const
//wxRichTextCtrl::GetEventTable() const
//wxRichTextCtrl::GetFirstVisiblePoint() const
//wxRichTextCtrl::GetFirstVisiblePosition() const
//wxRichTextCtrl::GetInsertionPoint() const
//wxRichTextCtrl::GetLastPosition() const
//wxRichTextCtrl::GetLineLength(long) const
//wxRichTextCtrl::GetLineText(long) const
//wxRichTextCtrl::GetLogicalPoint(wxPoint const&) const
//wxRichTextCtrl::GetNumberOfLines() const
//wxRichTextCtrl::GetPhysicalPoint(wxPoint const&) const
//wxRichTextCtrl::GetRange(long, long) const
//wxRichTextCtrl::GetSelection(long*, long*) const
//wxRichTextCtrl::GetSelectionRange() const
//wxRichTextCtrl::GetStringSelection() const
//wxRichTextCtrl::GetStyleForRange(wxRichTextRange const&, wxRichTextAttr&)
//wxRichTextCtrl::GetStyleForRange(wxRichTextRange const&, wxTextAttrEx&)
//wxRichTextCtrl::GetStyle(long, wxRichTextAttr&)
//wxRichTextCtrl::GetStyle(long, wxTextAttr&)
//wxRichTextCtrl::GetStyle(long, wxTextAttrEx&)
//wxRichTextCtrl::GetUncombinedStyle(long, wxRichTextAttr&)
//wxRichTextCtrl::GetUncombinedStyle(long, wxTextAttr&)
//wxRichTextCtrl::GetUncombinedStyle(long, wxTextAttrEx&)
//wxRichTextCtrl::GetValue() const
//wxRichTextCtrl::GetVisibleLineForCaretPosition(long) const
//wxRichTextCtrl::HasSelection() const
//wxRichTextCtrl::HitTest(wxPoint const&, long*) const
//wxRichTextCtrl::HitTest(wxPoint const&, long*, long*) const
//wxRichTextCtrl::Init()
//wxRichTextCtrl::IsEditable() const
//wxRichTextCtrl::IsModified() const
//wxRichTextCtrl::IsPositionVisible(long) const
//wxRichTextCtrl::IsSelectionAligned(wxTextAttrAlignment)
//wxRichTextCtrl::IsSelectionBold()
//wxRichTextCtrl::IsSelectionItalics()
//wxRichTextCtrl::IsSelectionUnderlined()
//wxRichTextCtrl::KeyboardNavigate(int, int)
//wxRichTextCtrl::LayoutContent(bool)
//wxRichTextCtrl::LineBreak()
//wxRichTextCtrl::MarkDirty()
//wxRichTextCtrl::MoveCaretBack(long)
//wxRichTextCtrl::MoveCaretForward(long)
//wxRichTextCtrl::MoveCaret(long, bool)
//wxRichTextCtrl::MoveDown(int, int)
//wxRichTextCtrl::MoveEnd(int)
//wxRichTextCtrl::MoveHome(int)
//wxRichTextCtrl::MoveLeft(int, int)
//wxRichTextCtrl::MoveRight(int, int)
//wxRichTextCtrl::MoveToLineEnd(int)
//wxRichTextCtrl::MoveToLineStart(int)
//wxRichTextCtrl::MoveToParagraphEnd(int)
//wxRichTextCtrl::MoveToParagraphStart(int)
//wxRichTextCtrl::MoveUp(int, int)
//wxRichTextCtrl::Newline()
//wxRichTextCtrl::NumberList(wxRichTextRange const&, wxRichTextListStyleDefinition*, int, int, int)
//wxRichTextCtrl::NumberList(wxRichTextRange const&, wxString const&, int, int, int)
//wxRichTextCtrl::OnCaptureLost(wxMouseCaptureLostEvent&)
//wxRichTextCtrl::OnChar(wxKeyEvent&)
//wxRichTextCtrl::OnClear(wxCommandEvent&)
//wxRichTextCtrl::OnContextMenu(wxContextMenuEvent&)
//wxRichTextCtrl::OnCopy(wxCommandEvent&)
//wxRichTextCtrl::OnCut(wxCommandEvent&)
//wxRichTextCtrl::OnDropFiles(wxDropFilesEvent&)
//wxRichTextCtrl::OnEraseBackground(wxEraseEvent&)
//wxRichTextCtrl::OnIdle(wxIdleEvent&)
//wxRichTextCtrl::OnKillFocus(wxFocusEvent&)
//wxRichTextCtrl::OnLeftClick(wxMouseEvent&)
//wxRichTextCtrl::OnLeftDClick(wxMouseEvent&)
//wxRichTextCtrl::OnLeftUp(wxMouseEvent&)
//wxRichTextCtrl::OnMiddleClick(wxMouseEvent&)
//wxRichTextCtrl::OnMoveMouse(wxMouseEvent&)
//wxRichTextCtrl::OnPaint(wxPaintEvent&)
//wxRichTextCtrl::OnPaste(wxCommandEvent&)
//wxRichTextCtrl::OnRedo(wxCommandEvent&)
//wxRichTextCtrl::OnRightClick(wxMouseEvent&)
//wxRichTextCtrl::OnScroll(wxScrollWinEvent&)
//wxRichTextCtrl::OnSelectAll(wxCommandEvent&)
//wxRichTextCtrl::OnSetFocus(wxFocusEvent&)
//wxRichTextCtrl::OnSize(wxSizeEvent&)
//wxRichTextCtrl::OnUndo(wxCommandEvent&)
//wxRichTextCtrl::OnUpdateClear(wxUpdateUIEvent&)
//wxRichTextCtrl::OnUpdateCopy(wxUpdateUIEvent&)
//wxRichTextCtrl::OnUpdateCut(wxUpdateUIEvent&)
//wxRichTextCtrl::OnUpdatePaste(wxUpdateUIEvent&)
//wxRichTextCtrl::OnUpdateRedo(wxUpdateUIEvent&)
//wxRichTextCtrl::OnUpdateSelectAll(wxUpdateUIEvent&)
//wxRichTextCtrl::OnUpdateUndo(wxUpdateUIEvent&)
//wxRichTextCtrl::PageDown(int, int)
//wxRichTextCtrl::PageUp(int, int)
//wxRichTextCtrl::PaintBackground(wxDC&)
//wxRichTextCtrl::Paste()
//wxRichTextCtrl::PositionCaret()
//wxRichTextCtrl::PositionToXY(long, long*, long*) const
//wxRichTextCtrl::PromoteList(int, wxRichTextRange const&, wxRichTextListStyleDefinition*, int, int)
//wxRichTextCtrl::PromoteList(int, wxRichTextRange const&, wxString const&, int, int)
//wxRichTextCtrl::Redo()
//wxRichTextCtrl::Remove(long, long)
//wxRichTextCtrl::Replace(long, long, wxString const&)
//wxRichTextCtrl::ScrollIntoView(long, int)
//wxRichTextCtrl::SelectAll()
//wxRichTextCtrl::SelectNone()
//wxRichTextCtrl::SelectWord(long)
//wxRichTextCtrl::SetCaretPosition(long, bool)
//wxRichTextCtrl::SetDefaultStyleToCursorStyle()
//wxRichTextCtrl::SetDefaultStyle(wxTextAttr const&)
//wxRichTextCtrl::SetDefaultStyle(wxTextAttrEx const&)
//wxRichTextCtrl::SetEditable(bool)
//wxRichTextCtrl::SetFont(wxFont const&)
//wxRichTextCtrl::SetInsertionPointEnd()
//wxRichTextCtrl::SetInsertionPoint(long)
//wxRichTextCtrl::SetListStyle(wxRichTextRange const&, wxRichTextListStyleDefinition*, int, int, int)
//wxRichTextCtrl::SetListStyle(wxRichTextRange const&, wxString const&, int, int, int)
//wxRichTextCtrl::SetSelection(long, long)
//wxRichTextCtrl::SetSelectionRange(wxRichTextRange const&)
//wxRichTextCtrl::SetStyleEx(long, long, wxTextAttrEx const&, int)
//wxRichTextCtrl::SetStyleEx(wxRichTextRange const&, wxRichTextAttr const&, int)
//wxRichTextCtrl::SetStyleEx(wxRichTextRange const&, wxTextAttrEx const&, int)
//wxRichTextCtrl::SetStyle(long, long, wxTextAttr const&)
//wxRichTextCtrl::SetStyle(long, long, wxTextAttrEx const&)
//wxRichTextCtrl::SetStyle(wxRichTextRange const&, wxRichTextAttr const&)
//wxRichTextCtrl::SetupScrollbars(bool)
//wxRichTextCtrl::ShowPosition(long)
//wxRichTextCtrl::Thaw()
//wxRichTextCtrl::Undo()
//wxRichTextCtrl::WordLeft(int, int)
//wxRichTextCtrl::WordRight(int, int)
//wxRichTextCtrl::WriteImage(wxBitmap const&, int)
//wxRichTextCtrl::WriteImage(wxImage const&, int)
//wxRichTextCtrl::WriteImage(wxRichTextImageBlock const&)
//wxRichTextCtrl::WriteImage(wxString const&, int)
//wxRichTextCtrl::WriteText(wxString const&)
//wxRichTextCtrl::~wxRichTextCtrl()
//wxRichTextCtrl::wxRichTextCtrl()
//wxRichTextCtrl::wxRichTextCtrl(wxWindow*, int, wxString const&, wxPoint const&, wxSize const&, long, wxValidator const&, wxString const&)
//wxRichTextCtrl::XYToPosition(long, long) const
//

using namespace std;
int main(int argc, char *argv[])
{
	
	wxRichTextCtrl a;
	return 0;
}

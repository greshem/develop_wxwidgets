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
 

//wxGenericTreeCtrl::AddRoot(wxString const&, int, int, wxTreeItemData*)
//wxGenericTreeCtrl::AdjustMyScrollbars()
//wxGenericTreeCtrl::AssignButtonsImageList(wxImageList*)
//wxGenericTreeCtrl::CalculateLevel(wxGenericTreeItem*, wxDC&, int, int&)
//wxGenericTreeCtrl::CalculateLineHeight()
//wxGenericTreeCtrl::CalculatePositions()
//wxGenericTreeCtrl::CalculateSize(wxGenericTreeItem*, wxDC&)
//wxGenericTreeCtrl::ChildrenClosing(wxGenericTreeItem*)
//wxGenericTreeCtrl::CollapseAndReset(wxTreeItemId const&)
//wxGenericTreeCtrl::Collapse(wxTreeItemId const&)
//wxGenericTreeCtrl::Create(wxWindow*, int, wxPoint const&, wxSize const&, long, wxValidator const&, wxString const&)
//wxGenericTreeCtrl::DeleteAllItems()
//wxGenericTreeCtrl::DeleteChildren(wxTreeItemId const&)
//wxGenericTreeCtrl::Delete(wxTreeItemId const&)
//wxGenericTreeCtrl::DoDirtyProcessing()
//wxGenericTreeCtrl::DoGetBestSize() const
//wxGenericTreeCtrl::DoInsertAfter(wxTreeItemId const&, wxTreeItemId const&, wxString const&, int, int, wxTreeItemData*)
//wxGenericTreeCtrl::DoInsertItem(wxTreeItemId const&, unsigned int, wxString const&, int, int, wxTreeItemData*)
//wxGenericTreeCtrl::DoSelectItem(wxTreeItemId const&, bool, bool)
//wxGenericTreeCtrl::DoTreeHitTest(wxPoint const&, int&) const
//wxGenericTreeCtrl::DrawBorder(wxTreeItemId const&)
//wxGenericTreeCtrl::DrawDropEffect(wxGenericTreeItem*)
//wxGenericTreeCtrl::DrawLine(wxTreeItemId const&, bool)
//wxGenericTreeCtrl::EditLabel(wxTreeItemId const&, wxClassInfo*)
//wxGenericTreeCtrl::EndEditLabel(wxTreeItemId const&, bool)
//wxGenericTreeCtrl::EnsureVisible(wxTreeItemId const&)
//wxGenericTreeCtrl::Expand(wxTreeItemId const&)
//wxGenericTreeCtrl::FillArray(wxGenericTreeItem*, wxArrayTreeItemIds&) const
//wxGenericTreeCtrl::FindItem(wxTreeItemId const&, wxString const&) const
//wxGenericTreeCtrl::Freeze()
//wxGenericTreeCtrl::GetBoundingRect(wxTreeItemId const&, wxRect&, bool) const
//wxGenericTreeCtrl::GetChildrenCount(wxTreeItemId const&, bool) const
//wxGenericTreeCtrl::GetClassDefaultAttributes(wxWindowVariant)
//wxGenericTreeCtrl::GetClassInfo() const
//wxGenericTreeCtrl::GetCount() const
//wxGenericTreeCtrl::GetEditControl() const
//wxGenericTreeCtrl::GetEventHashTable() const
//wxGenericTreeCtrl::GetEventTable() const
//wxGenericTreeCtrl::GetFirstChild(wxTreeItemId const&, void*&) const
//wxGenericTreeCtrl::GetFirstVisibleItem() const
//wxGenericTreeCtrl::GetItemBackgroundColour(wxTreeItemId const&) const
//wxGenericTreeCtrl::GetItemData(wxTreeItemId const&) const
//wxGenericTreeCtrl::GetItemFont(wxTreeItemId const&) const
//wxGenericTreeCtrl::GetItemImage(wxTreeItemId const&, wxTreeItemIcon) const
//wxGenericTreeCtrl::GetItemParent(wxTreeItemId const&) const
//wxGenericTreeCtrl::GetItemTextColour(wxTreeItemId const&) const
//wxGenericTreeCtrl::GetItemText(wxTreeItemId const&) const
//wxGenericTreeCtrl::GetLastChild(wxTreeItemId const&) const
//wxGenericTreeCtrl::GetLineHeight(wxGenericTreeItem*) const
//wxGenericTreeCtrl::GetNextChild(wxTreeItemId const&, void*&) const
//wxGenericTreeCtrl::GetNextSibling(wxTreeItemId const&) const
//wxGenericTreeCtrl::GetNextVisible(wxTreeItemId const&) const
//wxGenericTreeCtrl::GetNext(wxTreeItemId const&) const
//wxGenericTreeCtrl::GetPrevSibling(wxTreeItemId const&) const
//wxGenericTreeCtrl::GetPrevVisible(wxTreeItemId const&) const
//wxGenericTreeCtrl::GetSelections(wxArrayTreeItemIds&) const
//wxGenericTreeCtrl::Init()
//wxGenericTreeCtrl::IsBold(wxTreeItemId const&) const
//wxGenericTreeCtrl::IsExpanded(wxTreeItemId const&) const
//wxGenericTreeCtrl::IsSelected(wxTreeItemId const&) const
//wxGenericTreeCtrl::IsVisible(wxTreeItemId const&) const
//wxGenericTreeCtrl::ItemHasChildren(wxTreeItemId const&) const
//wxGenericTreeCtrl::OnChar(wxKeyEvent&)
//wxGenericTreeCtrl::OnGetToolTip(wxTreeEvent&)
//wxGenericTreeCtrl::OnInternalIdle()
//wxGenericTreeCtrl::OnKillFocus(wxFocusEvent&)
//wxGenericTreeCtrl::OnMouse(wxMouseEvent&)
//wxGenericTreeCtrl::OnPaint(wxPaintEvent&)
//wxGenericTreeCtrl::OnRenameAccept(wxGenericTreeItem*, wxString const&)
//wxGenericTreeCtrl::OnRenameCancelled(wxGenericTreeItem*)
//wxGenericTreeCtrl::OnRenameTimer()
//wxGenericTreeCtrl::OnSetFocus(wxFocusEvent&)
//wxGenericTreeCtrl::OnSize(wxSizeEvent&)
//wxGenericTreeCtrl::PaintItem(wxGenericTreeItem*, wxDC&)
//wxGenericTreeCtrl::PaintLevel(wxGenericTreeItem*, wxDC&, int, int&)
//wxGenericTreeCtrl::Refresh(bool, wxRect const*)
//wxGenericTreeCtrl::RefreshLine(wxGenericTreeItem*)
//wxGenericTreeCtrl::RefreshSelected()
//wxGenericTreeCtrl::RefreshSelectedUnder(wxGenericTreeItem*)
//wxGenericTreeCtrl::RefreshSubtree(wxGenericTreeItem*)
//wxGenericTreeCtrl::ResetTextControl()
//wxGenericTreeCtrl::ScrollTo(wxTreeItemId const&)
//wxGenericTreeCtrl::SelectItemRange(wxGenericTreeItem*, wxGenericTreeItem*)
//wxGenericTreeCtrl::SelectItem(wxTreeItemId const&, bool)
//wxGenericTreeCtrl::SendDeleteEvent(wxGenericTreeItem*)
//wxGenericTreeCtrl::SetBackgroundColour(wxColour const&)
//wxGenericTreeCtrl::SetButtonsImageList(wxImageList*)
//wxGenericTreeCtrl::SetFont(wxFont const&)
//wxGenericTreeCtrl::SetForegroundColour(wxColour const&)
//wxGenericTreeCtrl::SetImageList(wxImageList*)
//wxGenericTreeCtrl::SetIndent(unsigned int)
//wxGenericTreeCtrl::SetItemBackgroundColour(wxTreeItemId const&, wxColour const&)
//wxGenericTreeCtrl::SetItemBold(wxTreeItemId const&, bool)
//wxGenericTreeCtrl::SetItemData(wxTreeItemId const&, wxTreeItemData*)
//wxGenericTreeCtrl::SetItemDropHighlight(wxTreeItemId const&, bool)
//wxGenericTreeCtrl::SetItemFont(wxTreeItemId const&, wxFont const&)
//wxGenericTreeCtrl::SetItemHasChildren(wxTreeItemId const&, bool)
//wxGenericTreeCtrl::SetItemImage(wxTreeItemId const&, int, wxTreeItemIcon)
//wxGenericTreeCtrl::SetItemTextColour(wxTreeItemId const&, wxColour const&)
//wxGenericTreeCtrl::SetItemText(wxTreeItemId const&, wxString const&)
//wxGenericTreeCtrl::SetStateImageList(wxImageList*)
//wxGenericTreeCtrl::SetWindowStyle(long)
//wxGenericTreeCtrl::SortChildren(wxTreeItemId const&)
//wxGenericTreeCtrl::TagAllChildrenUntilLast(wxGenericTreeItem*, wxGenericTreeItem*, bool)
//wxGenericTreeCtrl::TagNextChildren(wxGenericTreeItem*, wxGenericTreeItem*, bool)
//wxGenericTreeCtrl::Thaw()
//wxGenericTreeCtrl::Toggle(wxTreeItemId const&)
//wxGenericTreeCtrl::Unselect()
//wxGenericTreeCtrl::UnselectAll()
//wxGenericTreeCtrl::UnselectAllChildren(wxGenericTreeItem*)
//wxGenericTreeCtrl::wxCreateObject()
//wxGenericTreeCtrl::~wxGenericTreeCtrl()
//

using namespace std;
int main(int argc, char *argv[])
{
	
	wxGenericTreeCtrl a;
	return 0;
}

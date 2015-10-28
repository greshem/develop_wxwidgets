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
#include <wx/generic/listctrl.h>
 

//wxGenericListCtrl::Arrange(int)
//wxGenericListCtrl::AssignImageList(wxImageList*, int)
//wxGenericListCtrl::CalculateAndSetHeaderHeight()
//wxGenericListCtrl::ClearAll()
//wxGenericListCtrl::CreateHeaderWindow()
//wxGenericListCtrl::Create(wxWindow*, int, wxPoint const&, wxSize const&, long, wxValidator const&, wxString const&)
//wxGenericListCtrl::DeleteAllColumns()
//wxGenericListCtrl::DeleteAllItems()
//wxGenericListCtrl::DeleteColumn(int)
//wxGenericListCtrl::DeleteItem(long)
//wxGenericListCtrl::DoClientToScreen(int*, int*) const
//wxGenericListCtrl::DoGetBestSize() const
//wxGenericListCtrl::DoPopupMenu(wxMenu*, int, int)
//wxGenericListCtrl::DoScreenToClient(int*, int*) const
//wxGenericListCtrl::EditLabel(long, wxClassInfo*)
//wxGenericListCtrl::EnsureVisible(long)
//wxGenericListCtrl::FindItem(long, unsigned long)
//wxGenericListCtrl::FindItem(long, wxPoint const&, int)
//wxGenericListCtrl::FindItem(long, wxString const&, bool)
//wxGenericListCtrl::Freeze()
//wxGenericListCtrl::GetBackgroundColour() const
//wxGenericListCtrl::GetClassDefaultAttributes(wxWindowVariant)
//wxGenericListCtrl::GetClassInfo() const
//wxGenericListCtrl::GetColumnCount() const
//wxGenericListCtrl::GetColumn(int, wxListItem&) const
//wxGenericListCtrl::GetColumnWidth(int) const
//wxGenericListCtrl::GetCountPerPage() const
//wxGenericListCtrl::GetDropTarget() const
//wxGenericListCtrl::GetEditControl() const
//wxGenericListCtrl::GetEventHashTable() const
//wxGenericListCtrl::GetEventTable() const
//wxGenericListCtrl::GetForegroundColour() const
//wxGenericListCtrl::GetImageList(int) const
//wxGenericListCtrl::GetItemBackgroundColour(long) const
//wxGenericListCtrl::GetItemCount() const
//wxGenericListCtrl::GetItemData(long) const
//wxGenericListCtrl::GetItemFont(long) const
//wxGenericListCtrl::GetItemPosition(long, wxPoint&) const
//wxGenericListCtrl::GetItemRect(long, wxRect&, int) const
//wxGenericListCtrl::GetItemSpacing(bool) const
//wxGenericListCtrl::GetItemSpacing() const
//wxGenericListCtrl::GetItemState(long, long) const
//wxGenericListCtrl::GetItemTextColour(long) const
//wxGenericListCtrl::GetItemText(long) const
//wxGenericListCtrl::GetItem(wxListItem&) const
//wxGenericListCtrl::GetNextItem(long, int, int) const
//wxGenericListCtrl::GetScrollPos(int) const
//wxGenericListCtrl::GetSelectedItemCount() const
//wxGenericListCtrl::GetTextColour() const
//wxGenericListCtrl::GetTopItem() const
//wxGenericListCtrl::GetViewRect() const
//wxGenericListCtrl::HitTest(wxPoint const&, int&, long*) const
//wxGenericListCtrl::InsertColumn(long, wxListItem&)
//wxGenericListCtrl::InsertColumn(long, wxString const&, int, int)
//wxGenericListCtrl::InsertItem(long, int)
//wxGenericListCtrl::InsertItem(long, wxString const&)
//wxGenericListCtrl::InsertItem(long, wxString const&, int)
//wxGenericListCtrl::InsertItem(wxListItem&)
//wxGenericListCtrl::OnGetItemAttr(long) const
//wxGenericListCtrl::OnGetItemColumnImage(long, long) const
//wxGenericListCtrl::OnGetItemImage(long) const
//wxGenericListCtrl::OnGetItemText(long, long) const
//wxGenericListCtrl::OnInternalIdle()
//wxGenericListCtrl::OnSize(wxSizeEvent&)
//wxGenericListCtrl::Refresh(bool, wxRect const*)
//wxGenericListCtrl::RefreshItem(long)
//wxGenericListCtrl::RefreshItems(long, long)
//wxGenericListCtrl::ResizeReportView(bool)
//wxGenericListCtrl::ScrollList(int, int)
//wxGenericListCtrl::SetBackgroundColour(wxColour const&)
//wxGenericListCtrl::SetColumn(int, wxListItem&)
//wxGenericListCtrl::SetColumnWidth(int, int)
//wxGenericListCtrl::SetCursor(wxCursor const&)
//wxGenericListCtrl::SetDropTarget(wxDropTarget*)
//wxGenericListCtrl::SetFocus()
//wxGenericListCtrl::SetFont(wxFont const&)
//wxGenericListCtrl::SetForegroundColour(wxColour const&)
//wxGenericListCtrl::SetImageList(wxImageList*, int)
//wxGenericListCtrl::SetItemBackgroundColour(long, wxColour const&)
//wxGenericListCtrl::SetItemColumnImage(long, long, int)
//wxGenericListCtrl::SetItemCount(long)
//wxGenericListCtrl::SetItemData(long, long)
//wxGenericListCtrl::SetItemFont(long, wxFont const&)
//wxGenericListCtrl::SetItemImage(long, int, int)
//wxGenericListCtrl::SetItem(long, int, wxString const&, int)
//wxGenericListCtrl::SetItemPosition(long, wxPoint const&)
//wxGenericListCtrl::SetItemPtrData(long, unsigned long)
//wxGenericListCtrl::SetItemSpacing(int, bool)
//wxGenericListCtrl::SetItemState(long, long, long)
//wxGenericListCtrl::SetItemTextColour(long, wxColour const&)
//wxGenericListCtrl::SetItemText(long, wxString const&)
//wxGenericListCtrl::SetItem(wxListItem&)
//wxGenericListCtrl::SetScrollPos(int, int, bool)
//wxGenericListCtrl::SetSingleStyle(long, bool)
//wxGenericListCtrl::SetTextColour(wxColour const&)
//wxGenericListCtrl::SetWindowStyleFlag(long)
//wxGenericListCtrl::SortItems(int (*)(long, long, long), long)
//wxGenericListCtrl::Thaw()
//wxGenericListCtrl::wxCreateObject()
//wxGenericListCtrl::~wxGenericListCtrl()
//wxGenericListCtrl::wxGenericListCtrl()
//

using namespace std;
int main(int argc, char *argv[])
{
	
	wxGenericListCtrl a;
	return 0;
}

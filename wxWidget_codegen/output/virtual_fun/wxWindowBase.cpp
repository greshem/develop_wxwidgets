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
#include <wx/caret.h>
#include <wx/containr.h>
#include <wx/layout.h>
#include <wx/validate.h>
#include <wx/window.h>
 

//wxWindowBase::AddChild(wxWindowBase*)
//wxWindowBase::AddConstraintReference(wxWindowBase*)
//wxWindowBase::AdjustForLayoutDirection(int, int, int) const
//wxWindowBase::AdjustForParentClientOrigin(int&, int&, int) const
//wxWindowBase::CaptureMouse()
//wxWindowBase::ClearBackground()
//wxWindowBase::Close(bool)
//wxWindowBase::ConvertDialogToPixels(wxPoint const&)
//wxWindowBase::ConvertPixelsToDialog(wxPoint const&)
//wxWindowBase::CreateBase(wxWindowBase*, int, wxPoint const&, wxSize const&, long, wxValidator const&, wxString const&)
//wxWindowBase::DeleteRelatedConstraints()
//wxWindowBase::Destroy()
//wxWindowBase::DestroyChildren()
//wxWindowBase::DoCentre(int)
//wxWindowBase::DoFindFocus()
//wxWindowBase::DoGetBestSize() const
//wxWindowBase::DoGetScreenPosition(int*, int*) const
//wxWindowBase::DoGetVirtualSize() const
//wxWindowBase::DoHitTest(int, int) const
//wxWindowBase::DoIsExposed(int, int) const
//wxWindowBase::DoIsExposed(int, int, int, int) const
//wxWindowBase::DoMoveInTabOrder(wxWindow*, wxWindowBase::MoveKind)
//wxWindowBase::DoPhase(int)
//wxWindowBase::DoSetSizeHints(int, int, int, int, int, int)
//wxWindowBase::DoSetToolTip(wxToolTip*)
//wxWindowBase::DoSetVirtualSize(int, int)
//wxWindowBase::DoSetWindowVariant(wxWindowVariant)
//wxWindowBase::DoUpdateWindowUI(wxUpdateUIEvent&)
//wxWindowBase::Enable(bool)
//wxWindowBase::FindFocus()
//wxWindowBase::FindWindowById(long, wxWindow const*)
//wxWindowBase::FindWindowByLabel(wxString const&, wxWindow const*)
//wxWindowBase::FindWindowByName(wxString const&, wxWindow const*)
//wxWindowBase::FindWindow(long) const
//wxWindowBase::FindWindow(wxString const&) const
//wxWindowBase::Fit()
//wxWindowBase::FitInside()
//wxWindowBase::GetAncestorWithCustomPalette() const
//wxWindowBase::GetBackgroundColour() const
//wxWindowBase::GetBorder(long) const
//wxWindowBase::GetCapture()
//wxWindowBase::GetClassDefaultAttributes(wxWindowVariant)
//wxWindowBase::GetClassInfo() const
//wxWindowBase::GetClientAreaOrigin() const
//wxWindowBase::GetClientSizeConstraint(int*, int*) const
//wxWindowBase::GetDefaultBorder() const
//wxWindowBase::GetEffectiveMinSize() const
//wxWindowBase::GetEventHashTable() const
//wxWindowBase::GetEventTable() const
//wxWindowBase::GetFont() const
//wxWindowBase::GetForegroundColour() const
//wxWindowBase::GetHelpTextAtPoint(wxPoint const&, wxHelpEvent::Origin) const
//wxWindowBase::GetPositionConstraint(int*, int*) const
//wxWindowBase::GetSizeConstraint(int*, int*) const
//wxWindowBase::GetUpdateClientRect() const
//wxWindowBase::GetWindowBorderSize() const
//wxWindowBase::InheritAttributes()
//wxWindowBase::InitDialog()
//wxWindowBase::InvalidateBestSize()
//wxWindowBase::IsShownOnScreen() const
//wxWindowBase::IsTopLevel() const
//wxWindowBase::Layout()
//wxWindowBase::LayoutPhase1(int*)
//wxWindowBase::LayoutPhase2(int*)
//wxWindowBase::MakeModal(bool)
//wxWindowBase::MoveConstraint(int, int)
//wxWindowBase::Navigate(int)
//wxWindowBase::NotifyCaptureLost()
//wxWindowBase::OnHelp(wxHelpEvent&)
//wxWindowBase::OnInitDialog(wxInitDialogEvent&)
//wxWindowBase::OnMiddleClick(wxMouseEvent&)
//wxWindowBase::OnSysColourChanged(wxSysColourChangedEvent&)
//wxWindowBase::PopEventHandler(bool)
//wxWindowBase::PushEventHandler(wxEvtHandler*)
//wxWindowBase::ReleaseMouse()
//wxWindowBase::RemoveChild(wxWindowBase*)
//wxWindowBase::RemoveConstraintReference(wxWindowBase*)
//wxWindowBase::RemoveEventHandler(wxEvtHandler*)
//wxWindowBase::Reparent(wxWindowBase*)
//wxWindowBase::ResetConstraints()
//wxWindowBase::SatisfyConstraints()
//wxWindowBase::SendDestroyEvent()
//wxWindowBase::SetBackgroundColour(wxColour const&)
//wxWindowBase::SetCaret(wxCaret*)
//wxWindowBase::SetConstraintSizes(bool)
//wxWindowBase::SetConstraints(wxLayoutConstraints*)
//wxWindowBase::SetContainingSizer(wxSizer*)
//wxWindowBase::SetCursor(wxCursor const&)
//wxWindowBase::SetFont(wxFont const&)
//wxWindowBase::SetForegroundColour(wxColour const&)
//wxWindowBase::SetHelpTextForId(wxString const&)
//wxWindowBase::SetHelpText(wxString const&)
//wxWindowBase::SetInitialSize(wxSize const&)
//wxWindowBase::SetPalette(wxPalette const&)
//wxWindowBase::SetSizeConstraint(int, int, int, int)
//wxWindowBase::SetSizerAndFit(wxSizer*, bool)
//wxWindowBase::SetSizer(wxSizer*, bool)
//wxWindowBase::SetToolTip(wxString const&)
//wxWindowBase::SetValidator(wxValidator const&)
//wxWindowBase::SetVirtualSizeHints(int, int, int, int)
//wxWindowBase::SetWindowVariant(wxWindowVariant)
//wxWindowBase::Show(bool)
//wxWindowBase::ToggleWindowStyle(int)
//wxWindowBase::TransferDataFromWindow()
//wxWindowBase::TransferDataToWindow()
//wxWindowBase::TryParent(wxEvent&)
//wxWindowBase::TryValidator(wxEvent&)
//wxWindowBase::UnsetConstraints(wxLayoutConstraints*)
//wxWindowBase::UpdateWindowUI(long)
//wxWindowBase::Validate()
//wxWindowBase::~wxWindowBase()
//wxWindowBase::wxWindowBase()
//wxWindow::DoMoveInTabOrder(wxWindow*, wxWindowBase::MoveKind)
//

using namespace std;
int main(int argc, char *argv[])
{
	
	wxWindowBase a;
	return 0;
}

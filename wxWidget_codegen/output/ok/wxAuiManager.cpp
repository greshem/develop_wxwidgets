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
#include <wx/aui/framemanager.h>
 

//wxAuiManager::AddPane(wxWindow*, int, wxString const&)
//wxAuiManager::AddPane(wxWindow*, wxAuiPaneInfo const&)
//wxAuiManager::AddPane(wxWindow*, wxAuiPaneInfo const&, wxPoint const&)
//wxAuiManager::CalculateHintRect(wxWindow*, wxPoint const&, wxPoint const&)
//wxAuiManager::ClosePane(wxAuiPaneInfo&)
//wxAuiManager::CreateFloatingFrame(wxWindow*, wxAuiPaneInfo const&)
//wxAuiManager::DetachPane(wxWindow*)
//wxAuiManager::DoDrop(wxAuiDockInfoArray&, wxAuiPaneInfoArray&, wxAuiPaneInfo&, wxPoint const&, wxPoint const&)
//wxAuiManager::DoFrameLayout()
//wxAuiManager::DrawHintRect(wxWindow*, wxPoint const&, wxPoint const&)
//wxAuiManager::GetAllPanes()
//wxAuiManager::GetArtProvider() const
//wxAuiManager::GetClassInfo() const
//wxAuiManager::GetDockPixelOffset(wxAuiPaneInfo&)
//wxAuiManager::GetDockSizeConstraint(double*, double*) const
//wxAuiManager::GetEventHashTable() const
//wxAuiManager::GetEventTable() const
//wxAuiManager::GetFlags() const
//wxAuiManager::GetFrame() const
//wxAuiManager::GetManagedWindow() const
//wxAuiManager::GetManager(wxWindow*)
//wxAuiManager::GetPanePart(wxWindow*)
//wxAuiManager::GetPanePositionsAndSizes(wxAuiDockInfo&, wxArrayInt&, wxArrayInt&)
//wxAuiManager::GetPane(wxString const&)
//wxAuiManager::GetPane(wxWindow*)
//wxAuiManager::HideHint()
//wxAuiManager::HitTest(int, int)
//wxAuiManager::InsertPane(wxWindow*, wxAuiPaneInfo const&, int)
//wxAuiManager::LayoutAddDock(wxSizer*, wxAuiDockInfo&, wxAuiDockUIPartArray&, bool)
//wxAuiManager::LayoutAddPane(wxSizer*, wxAuiDockInfo&, wxAuiPaneInfo&, wxAuiDockUIPartArray&, bool)
//wxAuiManager::LayoutAll(wxAuiPaneInfoArray&, wxAuiDockInfoArray&, wxAuiDockUIPartArray&, bool)
//wxAuiManager::LoadPaneInfo(wxString, wxAuiPaneInfo&)
//wxAuiManager::LoadPerspective(wxString const&, bool)
//wxAuiManager::MaximizePane(wxAuiPaneInfo&)
//wxAuiManager::OnChildFocus(wxChildFocusEvent&)
//wxAuiManager::OnEraseBackground(wxEraseEvent&)
//wxAuiManager::OnFindManager(wxAuiManagerEvent&)
//wxAuiManager::OnFloatingPaneActivated(wxWindow*)
//wxAuiManager::OnFloatingPaneClosed(wxWindow*, wxCloseEvent&)
//wxAuiManager::OnFloatingPaneMoved(wxWindow*, wxDirection)
//wxAuiManager::OnFloatingPaneMoveStart(wxWindow*)
//wxAuiManager::OnFloatingPaneMoving(wxWindow*, wxDirection)
//wxAuiManager::OnFloatingPaneResized(wxWindow*, wxSize const&)
//wxAuiManager::OnHintFadeTimer(wxTimerEvent&)
//wxAuiManager::OnLeaveWindow(wxMouseEvent&)
//wxAuiManager::OnLeftDown(wxMouseEvent&)
//wxAuiManager::OnLeftUp(wxMouseEvent&)
//wxAuiManager::OnMotion(wxMouseEvent&)
//wxAuiManager::OnPaint(wxPaintEvent&)
//wxAuiManager::OnPaneButton(wxAuiManagerEvent&)
//wxAuiManager::OnRender(wxAuiManagerEvent&)
//wxAuiManager::OnSetCursor(wxSetCursorEvent&)
//wxAuiManager::OnSize(wxSizeEvent&)
//wxAuiManager::ProcessDockResult(wxAuiPaneInfo&, wxAuiPaneInfo const&)
//wxAuiManager::ProcessMgrEvent(wxAuiManagerEvent&)
//wxAuiManager::Render(wxDC*)
//wxAuiManager::Repaint(wxDC*)
//wxAuiManager::RestoreMaximizedPane()
//wxAuiManager::RestorePane(wxAuiPaneInfo&)
//wxAuiManager::SavePaneInfo(wxAuiPaneInfo&)
//wxAuiManager::SavePerspective()
//wxAuiManager::SetArtProvider(wxAuiDockArt*)
//wxAuiManager::SetDockSizeConstraint(double, double)
//wxAuiManager::SetFlags(unsigned int)
//wxAuiManager::SetFrame(wxFrame*)
//wxAuiManager::SetManagedWindow(wxWindow*)
//wxAuiManager::ShowHint(wxRect const&)
//wxAuiManager::StartPaneDrag(wxWindow*, wxPoint const&)
//wxAuiManager::UnInit()
//wxAuiManager::Update()
//wxAuiManager::UpdateButtonOnScreen(wxAuiDockUIPart*, wxMouseEvent const&)
//wxAuiManager::UpdateHintWindowConfig()
//wxAuiManager::~wxAuiManager()
//wxAuiManager::wxAuiManager(wxWindow*, unsigned int)
//

using namespace std;
int main(int argc, char *argv[])
{
	
	wxAuiManager a;
	return 0;
}

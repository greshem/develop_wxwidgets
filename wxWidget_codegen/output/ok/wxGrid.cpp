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
#include <wx/generic/grid.h>
 

//wxGrid::AppendCols(int, bool)
//wxGrid::AppendRows(int, bool)
//wxGrid::AutoSize()
//wxGrid::AutoSizeColLabelSize(int)
//wxGrid::AutoSizeColOrRow(int, bool, bool)
//wxGrid::AutoSizeRowLabelSize(int)
//wxGrid::BlockToDeviceRect(wxGridCellCoords const&, wxGridCellCoords const&)
//wxGrid::CacheAttr(int, int, wxGridCellAttr*) const
//wxGrid::CalcCellsExposed(wxRegion const&)
//wxGrid::CalcColLabelsExposed(wxRegion const&)
//wxGrid::CalcDimensions()
//wxGrid::CalcRowLabelsExposed(wxRegion const&)
//wxGrid::CalcWindowSizes()
//wxGrid::CanEnableCellControl() const
//wxGrid::CanHaveAttributes()
//wxGrid::CellToRect(int, int)
//wxGrid::ChangeCursorMode(wxGrid::CursorMode, wxWindow*, bool)
//wxGrid::ClearAttrCache()
//wxGrid::ClearGrid()
//wxGrid::ClearSelection()
//wxGrid::Create()
//wxGrid::CreateGrid(int, int, wxGrid::wxGridSelectionModes)
//wxGrid::Create(wxWindow*, int, wxPoint const&, wxSize const&, long, wxString const&)
//wxGrid::DeleteCols(int, int, bool)
//wxGrid::DeleteRows(int, int, bool)
//wxGrid::DeselectCell(int, int)
//wxGrid::DeselectCol(int)
//wxGrid::DeselectRow(int)
//wxGrid::DoEndDragMoveCol()
//wxGrid::DoEndDragResizeCol()
//wxGrid::DoEndDragResizeRow()
//wxGrid::DoGetBestSize() const
//wxGrid::DrawAllGridLines(wxDC&, wxRegion const&)
//wxGrid::DrawCellBorder(wxDC&, wxGridCellCoords const&)
//wxGrid::DrawCellHighlight(wxDC&, wxGridCellAttr const*)
//wxGrid::DrawCell(wxDC&, wxGridCellCoords const&)
//wxGrid::DrawColLabels(wxDC&, wxArrayInt const&)
//wxGrid::DrawColLabel(wxDC&, int)
//wxGrid::DrawGridCellArea(wxDC&, wxGridCellCoordsArray const&)
//wxGrid::DrawGridSpace(wxDC&)
//wxGrid::DrawHighlight(wxDC&, wxGridCellCoordsArray const&)
//wxGrid::DrawRowLabels(wxDC&, wxArrayInt const&)
//wxGrid::DrawRowLabel(wxDC&, int)
//wxGrid::DrawTextRectangle(wxDC&, wxArrayString const&, wxRect const&, int, int, int)
//wxGrid::DrawTextRectangle(wxDC&, wxString const&, wxRect const&, int, int, int)
//wxGrid::Enable(bool)
//wxGrid::EnableCellEditControl(bool)
//wxGrid::EnableDragCell(bool)
//wxGrid::EnableDragColMove(bool)
//wxGrid::EnableDragColSize(bool)
//wxGrid::EnableDragGridSize(bool)
//wxGrid::EnableDragRowSize(bool)
//wxGrid::EnableEditing(bool)
//wxGrid::EnableGridLines(bool)
//wxGrid::EndBatch()
//wxGrid::Fit()
//wxGrid::ForceRefresh()
//wxGrid::GetCellAlignment(int, int, int*, int*)
//wxGrid::GetCellAttr(int, int) const
//wxGrid::GetCellBackgroundColour(int, int)
//wxGrid::GetCellEditor(int, int)
//wxGrid::GetCellFont(int, int)
//wxGrid::GetCellOverflow(int, int)
//wxGrid::GetCellRenderer(int, int)
//wxGrid::GetCellSize(int, int, int*, int*)
//wxGrid::GetCellTextColour(int, int)
//wxGrid::GetClassInfo() const
//wxGrid::GetColGridLinePen(int)
//wxGrid::GetColLabelAlignment(int*, int*)
//wxGrid::GetColLabelTextOrientation()
//wxGrid::GetColLabelValue(int)
//wxGrid::GetColLeft(int) const
//wxGrid::GetColMinimalAcceptableWidth() const
//wxGrid::GetColMinimalWidth(int) const
//wxGrid::GetColRight(int) const
//wxGrid::GetColSize(int)
//wxGrid::GetColWidth(int) const
//wxGrid::GetDefaultCellAlignment(int*, int*)
//wxGrid::GetDefaultCellBackgroundColour()
//wxGrid::GetDefaultCellFont()
//wxGrid::GetDefaultCellOverflow()
//wxGrid::GetDefaultCellTextColour()
//wxGrid::GetDefaultColSize()
//wxGrid::GetDefaultEditor() const
//wxGrid::GetDefaultEditorForCell(int, int) const
//wxGrid::GetDefaultEditorForType(wxString const&) const
//wxGrid::GetDefaultGridLinePen()
//wxGrid::GetDefaultRenderer() const
//wxGrid::GetDefaultRendererForCell(int, int) const
//wxGrid::GetDefaultRendererForType(wxString const&) const
//wxGrid::GetDefaultRowSize()
//wxGrid::GetDividerPen() const
//wxGrid::GetEventHashTable() const
//wxGrid::GetEventTable() const
//wxGrid::GetModelValues()
//wxGrid::GetOrCreateCellAttr(int, int) const
//wxGrid::GetRowBottom(int) const
//wxGrid::GetRowGridLinePen(int)
//wxGrid::GetRowHeight(int) const
//wxGrid::GetRowLabelAlignment(int*, int*)
//wxGrid::GetRowLabelValue(int)
//wxGrid::GetRowMinimalAcceptableHeight() const
//wxGrid::GetRowMinimalHeight(int) const
//wxGrid::GetRowSize(int)
//wxGrid::GetRowTop(int) const
//wxGrid::GetSelectedCells() const
//wxGrid::GetSelectedCols() const
//wxGrid::GetSelectedRows() const
//wxGrid::GetSelectionBlockBottomRight() const
//wxGrid::GetSelectionBlockTopLeft() const
//wxGrid::GetSelectionMode() const
//wxGrid::GetTextBoxSize(wxDC const&, wxArrayString const&, long*, long*)
//wxGrid::HideCellEditControl()
//wxGrid::HighlightBlock(int, int, int, int)
//wxGrid::Init()
//wxGrid::InitColWidths()
//wxGrid::InitRowHeights()
//wxGrid::InsertCols(int, int, bool)
//wxGrid::InsertRows(int, int, bool)
//wxGrid::IsCellEditControlEnabled() const
//wxGrid::IsCellEditControlShown() const
//wxGrid::IsCurrentCellReadOnly() const
//wxGrid::IsInSelection(int, int) const
//wxGrid::IsReadOnly(int, int) const
//wxGrid::IsSelection()
//wxGrid::IsVisible(int, int, bool)
//wxGrid::LookupAttr(int, int, wxGridCellAttr**) const
//wxGrid::MakeCellVisible(int, int)
//wxGrid::MoveCursorDownBlock(bool)
//wxGrid::MoveCursorDown(bool)
//wxGrid::MoveCursorLeftBlock(bool)
//wxGrid::MoveCursorLeft(bool)
//wxGrid::MoveCursorRightBlock(bool)
//wxGrid::MoveCursorRight(bool)
//wxGrid::MoveCursorUpBlock(bool)
//wxGrid::MoveCursorUp(bool)
//wxGrid::MovePageDown()
//wxGrid::MovePageUp()
//wxGrid::OnChar(wxKeyEvent&)
//wxGrid::OnEraseBackground(wxEraseEvent&)
//wxGrid::OnKeyDown(wxKeyEvent&)
//wxGrid::OnKeyUp(wxKeyEvent&)
//wxGrid::OnPaint(wxPaintEvent&)
//wxGrid::OnSize(wxSizeEvent&)
//wxGrid::ProcessColLabelMouseEvent(wxMouseEvent&)
//wxGrid::ProcessCornerLabelMouseEvent(wxMouseEvent&)
//wxGrid::ProcessGridCellMouseEvent(wxMouseEvent&)
//wxGrid::ProcessRowLabelMouseEvent(wxMouseEvent&)
//wxGrid::ProcessTableMessage(wxGridTableMessage&)
//wxGrid::Redimension(wxGridTableMessage&)
//wxGrid::Refresh(bool, wxRect const*)
//wxGrid::RegisterDataType(wxString const&, wxGridCellRenderer*, wxGridCellEditor*)
//wxGrid::SaveEditControlValue()
//wxGrid::SelectAll()
//wxGrid::SelectBlock(int, int, int, int, bool)
//wxGrid::SelectCol(int, bool)
//wxGridSelection::SetSelectionMode(wxGrid::wxGridSelectionModes)
//wxGridSelection::wxGridSelection(wxGrid*, wxGrid::wxGridSelectionModes)
//wxGrid::SelectRow(int, bool)
//wxGrid::SendEvent(int, int, int)
//wxGrid::SendEvent(int, int, int, wxMouseEvent&)
//wxGrid::SetAttr(int, int, wxGridCellAttr*)
//wxGrid::SetCellAlignment(int, int, int, int)
//wxGrid::SetCellBackgroundColour(int, int, wxColour const&)
//wxGrid::SetCellEditor(int, int, wxGridCellEditor*)
//wxGrid::SetCellFont(int, int, wxFont const&)
//wxGrid::SetCellHighlightColour(wxColour const&)
//wxGrid::SetCellHighlightPenWidth(int)
//wxGrid::SetCellHighlightROPenWidth(int)
//wxGrid::SetCellOverflow(int, int, bool)
//wxGrid::SetCellRenderer(int, int, wxGridCellRenderer*)
//wxGrid::SetCellSize(int, int, int, int)
//wxGrid::SetCellTextColour(int, int, wxColour const&)
//wxGrid::SetCellValue(int, int, wxString const&)
//wxGrid::SetColAttr(int, wxGridCellAttr*)
//wxGrid::SetColFormatBool(int)
//wxGrid::SetColFormatCustom(int, wxString const&)
//wxGrid::SetColFormatFloat(int, int, int)
//wxGrid::SetColFormatNumber(int)
//wxGrid::SetColLabelAlignment(int, int)
//wxGrid::SetColLabelSize(int)
//wxGrid::SetColLabelTextOrientation(int)
//wxGrid::SetColLabelValue(int, wxString const&)
//wxGrid::SetColMinimalAcceptableWidth(int)
//wxGrid::SetColMinimalWidth(int, int)
//wxGrid::SetColPos(int, int)
//wxGrid::SetColSize(int, int)
//wxGrid::SetCurrentCell(wxGridCellCoords const&)
//wxGrid::SetDefaultCellAlignment(int, int)
//wxGrid::SetDefaultCellBackgroundColour(wxColour const&)
//wxGrid::SetDefaultCellFont(wxFont const&)
//wxGrid::SetDefaultCellOverflow(bool)
//wxGrid::SetDefaultCellTextColour(wxColour const&)
//wxGrid::SetDefaultColSize(int, bool)
//wxGrid::SetDefaultEditor(wxGridCellEditor*)
//wxGrid::SetDefaultRenderer(wxGridCellRenderer*)
//wxGrid::SetDefaultRowSize(int, bool)
//wxGrid::SetGridLineColour(wxColour const&)
//wxGrid::SetLabelBackgroundColour(wxColour const&)
//wxGrid::SetLabelFont(wxFont const&)
//wxGrid::SetLabelTextColour(wxColour const&)
//wxGrid::SetModelValues()
//wxGrid::SetOrCalcColumnSizes(bool, bool)
//wxGrid::SetOrCalcRowSizes(bool, bool)
//wxGrid::SetReadOnly(int, int, bool)
//wxGrid::SetRowAttr(int, wxGridCellAttr*)
//wxGrid::SetRowLabelAlignment(int, int)
//wxGrid::SetRowLabelSize(int)
//wxGrid::SetRowLabelValue(int, wxString const&)
//wxGrid::SetRowMinimalAcceptableHeight(int)
//wxGrid::SetRowMinimalHeight(int, int)
//wxGrid::SetRowSize(int, int)
//wxGrid::SetSelectionMode(wxGrid::wxGridSelectionModes)
//wxGrid::SetTable(wxGridTableBase*, bool, wxGrid::wxGridSelectionModes)
//wxGrid::ShowCellEditControl()
//wxGrid::StringToLines(wxString const&, wxArrayString&)
//wxGrid::wxCreateObject()
//wxGrid::~wxGrid()
//wxGrid::wxGrid()
//wxGrid::wxGrid(wxWindow*, int, wxPoint const&, wxSize const&, long, wxString const&)
//wxGrid::XToCol(int, bool)
//wxGrid::XToEdgeOfCol(int)
//wxGrid::XYToCell(int, int, wxGridCellCoords&)
//wxGrid::YToEdgeOfRow(int)
//wxGrid::YToRow(int)
//

using namespace std;
int main(int argc, char *argv[])
{
	
	wxGrid a;
	return 0;
}

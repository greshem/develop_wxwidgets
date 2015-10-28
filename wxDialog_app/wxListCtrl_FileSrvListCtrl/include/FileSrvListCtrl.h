#pragma once
#include <wx/wx.h>
#include <wx/listctrl.h>

struct FileSrvListData 
{
	wxString mappingPanelName;
	wxString serverPath;
};

class FileSrvListCtrl :
	public wxListCtrl
{
private:
	DECLARE_EVENT_TABLE()

public:
	FileSrvListCtrl( wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxLC_REPORT, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxListCtrlNameStr)
		: wxListCtrl( parent, id, pos, size, style, validator, name )
		, m_pParent( parent )
		, m_pcitemSelect(-1)
	{
	}
	~FileSrvListCtrl(void){}

	void OnMouseLeftDown(wxMouseEvent& event);
//	void OnClnColClick(wxListEvent& event);
	void OnActivated(wxListEvent& event);//双击选择一项的时候，对这项做修改操作等
	void OnItemSelected(wxListEvent& event);
	void OnItemUnSelected(wxListEvent& event);

	void SetHeadText();
	void InsertData(FileSrvListData* pdata);

	//通过数据引擎更新数据. 
	void UpdateData();
	void AddDemoData();



	wxString GetItemColumnText(long pcitem, wxString tagName);

private:
	wxWindow *m_pParent;
	long m_pcitemSelect;
};

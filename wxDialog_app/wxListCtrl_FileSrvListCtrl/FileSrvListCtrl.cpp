//文件列表控件. 
#include "include/FileSrvListCtrl.h"
#include "include/StationListCtrl.h"
#include "include/UI_data_struct.h"

BEGIN_EVENT_TABLE( FileSrvListCtrl, wxListCtrl )

EVT_LEFT_DOWN( FileSrvListCtrl::OnMouseLeftDown )
//EVT_LIST_COL_CLICK(ID_LIST_FILE,FileSrvListCtrl::OnClnColClick)
EVT_LIST_ITEM_ACTIVATED(ID_LIST_FILE,FileSrvListCtrl::OnActivated)
EVT_LIST_ITEM_SELECTED(ID_LIST_FILE,FileSrvListCtrl::OnItemSelected)
EVT_LIST_ITEM_DESELECTED(ID_LIST_FILE,FileSrvListCtrl::OnItemUnSelected)

END_EVENT_TABLE()


void FileSrvListCtrl::OnMouseLeftDown(wxMouseEvent& event)
{
	//int flags = wxLIST_HITTEST_ONITEM;
	//if ( wxNOT_FOUND != HitTest( event.GetPosition(), flags , NULL ) )
	//{
	//	m_flagSelectItem = TRUE;
	//}
	//else
	//{
	//	m_flagSelectItem = FALSE; 
	//}
	event.Skip();
}

void FileSrvListCtrl::OnActivated(wxListEvent& event)
{
	wxEvtHandler *pHandler = m_pParent->GetParent()->GetEventHandler();
	wxCommandEvent commandevent( wxEVT_COMMAND_BUTTON_CLICKED, ID_WXBUTTON_FILE_MODIFY );//双击选择一项的时候，对这项做修改操作等
	commandevent.SetEventObject( pHandler );
	pHandler->ProcessEvent( commandevent );
}

void FileSrvListCtrl::OnItemSelected(wxListEvent& event)
{
	if (m_pcitemSelect == -1)
	{
		m_pcitemSelect = GetNextItem(m_pcitemSelect, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);

		wxString strpc;
		if (m_pcitemSelect != -1)
		{
			strpc = GetItemColumnText(m_pcitemSelect, wxT("PC"));
			//....这里可以做一些自己要求的操作

		}
	}
}
void FileSrvListCtrl::OnItemUnSelected(wxListEvent& event)
{
	m_pcitemSelect = -1;
}

wxString FileSrvListCtrl::GetItemColumnText(long pcitem, wxString tagName)
{
	wxListItem Item;
	Item.SetId( pcitem );

	if (tagName == _("MappingPanelName"))
		Item.SetColumn( 0 );
	else if (tagName == _("ServerPath"))
		Item.SetColumn( 1 );
	else
		return wxT("");

	Item.SetMask( wxLIST_MASK_TEXT );
	GetItem( Item );
	return Item.GetText();
}

void FileSrvListCtrl::SetHeadText()
{
	long	nPos = 0;
	wxListItem Item;

	Item.SetText( _("MappingPanelName") );
	InsertColumn( nPos, Item );
	SetColumnWidth( nPos++, 150 );

	Item.SetText( _("ServerPath") );
	InsertColumn( nPos, Item );
	SetColumnWidth( nPos++, 200 );
}

void FileSrvListCtrl::InsertData(FileSrvListData* pdata)
{
	long nPos = GetItemCount();

	long		nSubPos = 1;
	InsertItem( nPos, pdata->mappingPanelName);
	SetItem(nPos, nSubPos++, pdata->serverPath);
}

//fixme 这里还是 伪造的数据 应该从配置文件里面获取. 
void FileSrvListCtrl::UpdateData()
{
	FileSrvListData data;
	//wxString name=m_db.GetVolName();
	//wxString path=m_db.GetVolPath();

	//wxString  wxstr = wxString( strstring.c_str(), wxConvUTF8);


	data.mappingPanelName =  wxT("Disk");
	data.serverPath =  wxT("/vld/disk");

	InsertData(&data);
}
void FileSrvListCtrl::AddDemoData()
{
	SetHeadText();

	FileSrvListData data;
	for(int i=0; i<=10; i++)
	{
		data.mappingPanelName = wxT("demo_Disk");
		data.serverPath = wxT("/demo/vld/disk");
		InsertData(&data);
	}
}
/*
//下面的代码是点击列，实现排序，如果不要可以删除
unsigned char bListColStatusFile = 0x00;

// 列的选中状态
enum COL_STATUS
{
	COL1 = 0x80,	// 第一列被选中
	COL2 = 0x40,
	COL3 = 0x20,
	COL4 = 0x10,
	COL5 = 0x08,
	COL6 = 0x04,
	COL7 = 0x05,
	COL8 = 0x01
};

typedef struct _File_SORT_INFO 
{
	int nCol;
	FileSrvListCtrl *pdata;
} FILESORTINFO, *PFILESORTINFO;

int wxCALLBACK ListCompareFunctionFile(long item1, long item2, long sortData);

int wxCALLBACK ListCompareFunctionFile(long item1, long item2, long sortData)
{
	FileSrvListCtrl *pList = (FileSrvListCtrl*)((PFILESORTINFO)sortData)->pdata;
	int nCol = ((PFILESORTINFO)sortData)->nCol;
	wxListItem ListItem;
	ListItem.SetId( item1 );
	ListItem.SetColumn( nCol );
	ListItem.SetMask( wxLIST_MASK_TEXT );
	pList->GetItem( ListItem );
	wxString Item1Text = ListItem.GetText();

	ListItem.SetId( item2 );
	ListItem.SetColumn( nCol );
	ListItem.SetMask( wxLIST_MASK_TEXT );
	pList->GetItem( ListItem );
	wxString Item2Text = ListItem.GetText();

	bool bUppder = FALSE;

	switch ( nCol )
	{
	case 0:
		if ( COL1 == (bListColStatusFile & COL1) )
		{
			bUppder = TRUE;
		}
		break;

	case 1:
		if ( COL2 == (bListColStatusFile & COL2) )
		{
			bUppder = TRUE;
		}
		break;

	case 2:
		if ( COL3 == (bListColStatusFile & COL3) )
		{
			bUppder = TRUE;
		}
		break;

	case 3:
		if ( COL4 == (bListColStatusFile & COL4) )
		{
			bUppder = TRUE;
		}
		break;

	case 4:
		if ( COL5 == (bListColStatusFile & COL5) )
		{
			bUppder = TRUE;
		}
		break;

	}

	if ( bUppder )
	{
		return ::wxStrcmp( Item1Text, Item2Text );
	}
	else
	{
		return ::wxStrcmp( Item2Text, Item1Text );
	}
}

void FileSrvListCtrl::OnClnColClick(wxListEvent& event)
{
	for ( int i = 0; i < GetItemCount(); i++ )
	{
		SetItemData( i, i );
	}

	int nValue = event.GetColumn();
	switch ( nValue )
	{
	case 0:
		bListColStatusFile ^= COL1;
		break;

	case 1:
		bListColStatusFile ^= COL2;
		break;

	case 2:
		bListColStatusFile ^= COL3;
		break;

	case 3:
		bListColStatusFile ^= COL4;
		break;

	case 4:
		bListColStatusFile ^= COL5;
		break;

	}
	FILESORTINFO SortInfo;
	SortInfo.nCol = nValue;
	SortInfo.pdata = this;
	SortItems( ListCompareFunctionFile, (long)&SortInfo );
}
*/

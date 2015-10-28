//客户端工作站列表.
#include "include/LsofFileListCtrl.h"
#include "include/UI_data_struct.h"
#include "include/protocol.h"
#include "include/tools.h"
#include "include/log.h"
#include "include/Cmd_str_to_struct.h"
//#include "../../network/client/Client_reponse_data_dump.h"
#include "include/Cmd_str_to_struct.h"

BEGIN_EVENT_TABLE( LsofFileListCtrl, wxListCtrl )

EVT_LEFT_DOWN( LsofFileListCtrl::OnMouseLeftDown )
//EVT_LIST_COL_CLICK(ID_LIST_STATION,LsofFileListCtrl::OnClnColClick)
//EVT_LIST_ITEM_ACTIVATED(ID_LIST_STATION,LsofFileListCtrl::OnActivated)
EVT_LIST_ITEM_SELECTED(ID_LIST_STATION,LsofFileListCtrl::OnItemSelected)
EVT_LIST_ITEM_DESELECTED(ID_LIST_STATION,LsofFileListCtrl::OnItemUnSelected)

END_EVENT_TABLE()


void LsofFileListCtrl::OnMouseLeftDown(wxMouseEvent& event)
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

//列表的激活 事件  和wx的事件还是有区别的.
void LsofFileListCtrl::OnActivated(wxListEvent& event)
{
	wxEvtHandler *pHandler = m_pParent->GetParent()->GetEventHandler();
	wxCommandEvent commandevent( wxEVT_COMMAND_BUTTON_CLICKED, ID_WXBUTTON_STATION_VIEWFILE );//双击选择一项的时候，对这项做修改操作等
	commandevent.SetEventObject( pHandler );
	pHandler->ProcessEvent( commandevent );
}

void LsofFileListCtrl::OnItemSelected(wxListEvent& event)
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
void LsofFileListCtrl::OnItemUnSelected(wxListEvent& event)
{
	m_pcitemSelect = -1;
}

wxString LsofFileListCtrl::GetItemColumnText(long pcitem, wxString tagName)
{
	wxListItem Item;
	Item.SetId( pcitem );

	if (tagName == _("Mac"))
		Item.SetColumn( 0 );
	else if (tagName == _("IP"))
		Item.SetColumn( 1 );
	else if (tagName == _("ConnectStatus"))
		Item.SetColumn( 2 );
	else if (tagName == _("ProcessID"))
		Item.SetColumn( 3 );
	else if (tagName == _("ConnectTime"))
		Item.SetColumn( 4 );
	else if (tagName == _("LoginUser"))
		Item.SetColumn( 5 );
	else
		return wxT("");

	Item.SetMask( wxLIST_MASK_TEXT );
	GetItem( Item );
	return Item.GetText();
}

//设置list 的头部 ,
void LsofFileListCtrl::SetHeadText()
{
	long	nPos = 0;
	wxListItem Item;

	Item.SetText( _("FileList") );
	InsertColumn( nPos, Item );
	SetColumnWidth( nPos++, 300 );
}

//list插入数据.
void LsofFileListCtrl::InsertData(wxString fileName)
{
	long nPos = GetItemCount();

	long		nSubPos = 1;
	InsertItem( nPos, fileName);
	//添加之后 crash bug.
	//SetItem(nPos, nSubPos, fileName);
	//
	// SetItem(nPos, nSubPos++, pdata->ip);
	// SetItem(nPos, nSubPos++, pdata->connectStatus);
	// SetItem(nPos, nSubPos++, pdata->processId);
	// SetItem(nPos, nSubPos++, pdata->connectTime);
	// SetItem(nPos, nSubPos++, pdata->loginUser);
}

void LsofFileListCtrl::AddDemoData()
{
	string outstring;

	SetHeadText();

	int count=0;
	for(int i=0; i<=10; i++)
	{
		wxString msg;
		msg.Printf(wxT("/root/file_%d.txt"), i);
		InsertData(msg);
	}

}


void LsofFileListCtrl::AddLsofFiles(int pid)
{
	SetHeadText();

    char cmd[1024]={0};
	string output;
    snprintf(cmd, sizeof(cmd), "lsof -p %d |awk '{print $NF}' ", pid); 
    int ret=shell_exec<char>(string(cmd), output);   
    vector<string> lines;
    split (output, lines);
	
	vector<string>::iterator it;
	for(it= lines.begin();it!= lines.end(); it++)
	{
 		wxString tmp((*it).c_str(), wxConvUTF8);
		InsertData(tmp);
//		InsertData(wxT("aaaaa"));
	}
}
/*
//下面的代码是点击列，实现排序，如果不要可以删除
unsigned char bListColStatus = 0x00;

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

typedef struct _STATION_SORT_INFO 
{
	int nCol;
	LsofFileListCtrl *pdata;
} STATIONSORTINFO, *PSTATIONSORTINFO;

int wxCALLBACK ListCompareFunction(long item1, long item2, long sortData);

int wxCALLBACK ListCompareFunction(long item1, long item2, long sortData)
{
	LsofFileListCtrl *pList = (LsofFileListCtrl*)((PSTATIONSORTINFO)sortData)->pdata;
	int nCol = ((PSTATIONSORTINFO)sortData)->nCol;
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
		if ( COL1 == (bListColStatus & COL1) )
		{
			bUppder = TRUE;
		}
		break;

	case 1:
		if ( COL2 == (bListColStatus & COL2) )
		{
			bUppder = TRUE;
		}
		break;

	case 2:
		if ( COL3 == (bListColStatus & COL3) )
		{
			bUppder = TRUE;
		}
		break;

	case 3:
		if ( COL4 == (bListColStatus & COL4) )
		{
			bUppder = TRUE;
		}
		break;

	case 4:
		if ( COL5 == (bListColStatus & COL5) )
		{
			bUppder = TRUE;
		}
		break;
	case 5:
		if ( COL6 == (bListColStatus & COL6) )
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

void LsofFileListCtrl::OnClnColClick(wxListEvent& event)
{
	for ( int i = 0; i < GetItemCount(); i++ )
	{
		SetItemData( i, i );
	}

	int nValue = event.GetColumn();
	switch ( nValue )
	{
	case 0:
		bListColStatus ^= COL1;
		break;

	case 1:
		bListColStatus ^= COL2;
		break;

	case 2:
		bListColStatus ^= COL3;
		break;

	case 3:
		bListColStatus ^= COL4;
		break;

	case 4:
		bListColStatus ^= COL5;
		break;

	case 5:
		bListColStatus ^= COL6;
		break;

	}
	STATIONSORTINFO SortInfo;
	SortInfo.nCol = nValue;
	SortInfo.pdata = this;
	SortItems( ListCompareFunction, (long)&SortInfo );
}
*/

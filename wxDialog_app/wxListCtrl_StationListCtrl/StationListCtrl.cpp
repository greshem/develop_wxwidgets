//客户端工作站列表.
#include "include/StationListCtrl.h"
#include "include/UI_data_struct.h"
#include "include/protocol.h"
#include "include/tools.h"
#include "include/log.h"
#include "include/Cmd_str_to_struct.h"

BEGIN_EVENT_TABLE( StationListCtrl, wxListCtrl )

EVT_LEFT_DOWN( StationListCtrl::OnMouseLeftDown )
EVT_LIST_COL_CLICK(ID_LIST_STATION,StationListCtrl::OnClnColClick)
EVT_LIST_ITEM_ACTIVATED(ID_LIST_STATION,StationListCtrl::OnActivated)
EVT_LIST_ITEM_SELECTED(ID_LIST_STATION,StationListCtrl::OnItemSelected)
EVT_LIST_ITEM_DESELECTED(ID_LIST_STATION,StationListCtrl::OnItemUnSelected)

END_EVENT_TABLE()


void StationListCtrl::OnMouseLeftDown(wxMouseEvent& event)
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
void StationListCtrl::OnActivated(wxListEvent& event)
{
	// wxEvtHandler *pHandler = m_pParent->GetParent()->GetEventHandler();
	// wxCommandEvent commandevent( wxEVT_COMMAND_BUTTON_CLICKED, ID_WXBUTTON_STATION_VIEWFILE );//双击选择一项的时候，对这项做修改操作等
	// commandevent.SetEventObject( pHandler );
	// pHandler->ProcessEvent( commandevent );
}

void StationListCtrl::OnItemSelected(wxListEvent& event)
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
void StationListCtrl::OnItemUnSelected(wxListEvent& event)
{
	m_pcitemSelect = -1;
}

wxString StationListCtrl::GetItemColumnText(long pcitem, wxString tagName)
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

wxString StationListCtrl::GetItemColumnText(long pcitem, int offset)
{
	wxListItem Item;
	Item.SetId( pcitem );
	Item.SetColumn(offset);


	Item.SetMask( wxLIST_MASK_TEXT );
	GetItem( Item );
	return Item.GetText();
}


//设置list 的头部 ,
void StationListCtrl::SetHeadText()
{
	long	nPos = 0;
	wxListItem Item;

	Item.SetText( _("Mac") );
	InsertColumn( nPos, Item );
	SetColumnWidth( nPos++, 140 );

	Item.SetText( _("IP") );
	InsertColumn( nPos, Item );
	SetColumnWidth( nPos++, 90 );

	Item.SetText( _("ConnectStatus") );
	InsertColumn( nPos, Item );
	SetColumnWidth( nPos++, 120 );

	Item.SetText( _("ProcessID") );
	InsertColumn( nPos, Item );
	SetColumnWidth( nPos++, 100 );

	Item.SetText( _("ConnectTime") );
	InsertColumn( nPos, Item );
	SetColumnWidth( nPos++, 90 );

	//Item.SetText( _("LoginUser") );
	Item.SetText( _("command_line") );
	InsertColumn( nPos, Item );
	//设置长度, list 一个 row  的长度. 
	SetColumnWidth( nPos++, 180 );
}

//list插入数据.
void StationListCtrl::InsertData(StationListData* pdata)
{
	long nPos = GetItemCount();

	long		nSubPos = 1;
	InsertItem( nPos, pdata->mac);
	SetItem(nPos, nSubPos++, pdata->ip);
	SetItem(nPos, nSubPos++, pdata->connectStatus);
	SetItem(nPos, nSubPos++, pdata->processId);
	SetItem(nPos, nSubPos++, pdata->connectTime);
	SetItem(nPos, nSubPos++, pdata->loginUser);
}

void StationListCtrl::AddDemoData()
{
	string outstring;
	vector<response_501> vec_response501;
	vector<string> lines;
    log::Instance()->logger("调用协议501  对应的数据显示代码. \n");
    int shell_ret=shell_exec<char>(string("ps -elf |grep init"), outstring);  
    split (outstring, lines);
    Cmd_str_to_struct::change_2_vec(lines, vec_response501);

	SetHeadText();

	//for(int i=0; i<=10; i++)
	int count=0;
	vector<response_501>::iterator it;
	for(it=vec_response501.begin(); it!= vec_response501.end(); it++)
	{
		StationListData data;
		wxString msg;
		msg.Printf(wxT(" aa:bb:cc:dd:ee:%d"), count);
			data.mac =msg;
		msg.Printf(wxT("192.168.1.%d"), count);
			data.ip = wxT("192.158.1.1");
		msg.Printf(wxT("fauluer_%d"), count);
			data.connectStatus = msg;
		msg.Printf(wxT("%d"), it->pid);
			data.processId = msg;
		msg.Printf(wxT("%d"), it->elapsed_time);
			data.connectTime = msg;
		//msg.Printf(wxT("%s"),  cmdline);
		wxString cmdline(it->cmdline, wxConvUTF8);
			data.loginUser = cmdline;
		
		InsertData(&data);
		count++;
	}

}
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
	StationListCtrl *pdata;
} STATIONSORTINFO, *PSTATIONSORTINFO;

int wxCALLBACK ListCompareFunction(long item1, long item2, long sortData);

int wxCALLBACK ListCompareFunction(long item1, long item2, long sortData)
{
	StationListCtrl *pList = (StationListCtrl*)((PSTATIONSORTINFO)sortData)->pdata;
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

void StationListCtrl::OnClnColClick(wxListEvent& event)
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

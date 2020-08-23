// AdapaterSelection.cpp : implementation file
//

#include "stdafx.h"
#include "CapturePacket.h"
#include "AdapaterSelection.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdapaterSelection dialog


CAdapaterSelection::CAdapaterSelection(CWnd* pParent /*=NULL*/)
	: CDialog(CAdapaterSelection::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdapaterSelection)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAdapaterSelection::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdapaterSelection)
	DDX_Control(pDX, IDC_TREE_NETWORKADAPTERS, m_treeAdapater);
	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAdapaterSelection, CDialog)
	//{{AFX_MSG_MAP(CAdapaterSelection)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_NETWORKADAPTERS, OnDblclkTreeNetworkadapters)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdapaterSelection message handlers

BOOL CAdapaterSelection::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here	
    
	//³õÊ¼»¯Ê÷ÐÎÑ¡Ôñ
    HTREEITEM root = m_treeAdapater.InsertItem(_T("ÍøÂçÊÊÅäÆ÷"));
	
	if(pcap_findalldevs(&m_pAllDevs, m_strErrorBuf) == -1)
		return FALSE;

	for(m_pDev = m_pAllDevs;m_pDev != NULL;m_pDev = m_pDev->next)
	{
		char temp[400];
		CString strText;
		HTREEITEM hSubItem = m_treeAdapater.InsertItem(m_pDev->name,root);
		if(m_pDev->description != NULL)
		{
		    strText.Format("Íø¿¨ÃèÊöÐÅÏ¢ : %s",m_pDev->description);
			m_treeAdapater.InsertItem(strText,hSubItem);
		}
		else
		{
			m_treeAdapater.InsertItem("Íø¿¨ÃèÊöÐÅÏ¢ : ¿Õ",hSubItem);
		}

		if(m_pDev->addresses != NULL && m_pDev->addresses->addr != NULL)
		{
			iptos(((struct sockaddr_in *)m_pDev->addresses->addr)->sin_addr.s_addr,temp);
			strText.Format("IPµØÖ· : %s",temp);
			m_treeAdapater.InsertItem(strText,hSubItem);			
		}
		else
		{
			m_treeAdapater.InsertItem("IPµØÖ· :  ¿Õ",hSubItem);
		}

		if(m_pDev->addresses != NULL && m_pDev->addresses->broadaddr != NULL)
		{
			iptos(((struct sockaddr_in *)m_pDev->addresses->broadaddr)->sin_addr.s_addr,temp);		
			strText.Format("¹ã²¥µØÖ· : %s",temp);
			m_treeAdapater.InsertItem(strText,hSubItem);	

		}
		else
		{
			m_treeAdapater.InsertItem("¹ã²¥µØÖ· : ÎÞ",hSubItem);
		}

		if(m_pDev->addresses!=NULL && m_pDev->addresses->netmask!=NULL)
		{
			iptos(((struct sockaddr_in *)m_pDev->addresses->netmask)->sin_addr.s_addr,temp);
			strText.Format("×ÓÍøÑÚÂë : %s",temp);
			m_treeAdapater.InsertItem(strText,hSubItem);	
		}	
		else
		{
			m_treeAdapater.InsertItem("×ÓÍøÑÚÂë : ¿Õ",hSubItem);
		}

		if(m_pDev->addresses!=NULL && m_pDev->addresses->dstaddr!=NULL)
		{
			iptos(((struct sockaddr_in *)m_pDev->addresses->dstaddr)->sin_addr.s_addr,temp);			
			strText.Format("Ä¿µØµØÖ· : %s",temp);
			m_treeAdapater.InsertItem(strText,hSubItem);	
		}
		else
		{
			m_treeAdapater.InsertItem("Ä¿µØµØÖ· : ÎÞ",hSubItem);
		}		

	}
	m_pDev = NULL;
	m_treeAdapater.Expand(root,TVE_EXPAND);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAdapaterSelection::OnOK() 
{
	// TODO: Add extra validation here
	if(m_pDev == NULL)
	{
		MessageBox("ÇëË«»÷Ñ¡ÔñÍø¿¨!");
		return;
	}
	if(m_pDev->addresses == NULL)
	{
		MessageBox("²»ÄÜÑ¡ÔñÐéÄâÍø¿¨!");
		return;
	}
	MessageBox("Íø¿¨°ó¶¨³É¹¦!");

	CDialog::OnOK();
}

pcap_if_t* CAdapaterSelection::getDevice()
{
	if(m_pDev == NULL)
		return NULL;
	return m_pDev;
}
void CAdapaterSelection::iptos(u_long in, char output[])
{
	u_char *p;
    p = (u_char *)&in;
    sprintf(output, "%d.%d.%d.%d", p[0], p[1], p[2], p[3]);
}

void CAdapaterSelection::OnDblclkTreeNetworkadapters(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	HTREEITEM hSubItem = m_treeAdapater.GetSelectedItem();
	if(m_treeAdapater.GetParentItem(hSubItem) == NULL)
		return;

    else if( m_treeAdapater.GetItemText(m_treeAdapater.GetParentItem(hSubItem)) != "ÍøÂçÊÊÅäÆ÷")
		hSubItem = m_treeAdapater.GetParentItem(hSubItem);

	m_pDev=m_pAllDevs;

	while(strcmp(m_pDev->name,m_treeAdapater.GetItemText(hSubItem)) != 0)
	{	//ÕÒµ½±»Ñ¡ÖÐÍø¿¨
		m_pDev = m_pDev->next;
	}
    *pResult = 0;
}

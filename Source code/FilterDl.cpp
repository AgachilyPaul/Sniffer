// FilterDl.cpp : implementation file
//

#include "stdafx.h"
#include "CapturePacket.h"
#include "FilterDl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFilterDl dialog


CFilterDl::CFilterDl(CWnd* pParent /*=NULL*/)
	: CDialog(CFilterDl::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFilterDl)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFilterDl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFilterDl)
	DDX_Control(pDX, IDC_TAB_CTR, m_tCtr);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFilterDl, CDialog)
	//{{AFX_MSG_MAP(CFilterDl)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_CTR, OnSelchangeTabCtr)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFilterDl message handlers

BOOL CFilterDl::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	TCITEM item;
	item.mask = TCIF_TEXT;
	item.pszText = "第一页";

	m_tCtr.InsertItem (0,&item);
	item.pszText ="第二页";
	m_tCtr.InsertItem (1,&item);

	m_dlg1.Create (IDD_ABOUTBOX,&m_tCtr);
	m_dlg2.Create (IDD_DIALOG_OUTPUTDATA,&m_tCtr);

	m_dlg1.SetWindowPos (NULL,10,30,400,100,SWP_SHOWWINDOW);
	m_dlg2.SetWindowPos (NULL,10,30,400,100,SWP_HIDEWINDOW );  

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CFilterDl::OnSelchangeTabCtr(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

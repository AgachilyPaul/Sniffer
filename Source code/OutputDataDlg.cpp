// OutputDataDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CapturePacket.h"
#include "OutputDataDlg.h"
#include "DirDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutputDataDlg dialog


COutputDataDlg::COutputDataDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COutputDataDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COutputDataDlg)
	m_strDirPath = _T("");
	m_strFileName = _T("");
	//}}AFX_DATA_INIT
}


void COutputDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COutputDataDlg)
	DDX_Text(pDX, IDC_EDIT_DIRPATH, m_strDirPath);
	DDX_Text(pDX, IDC_EDIT_FILENAME, m_strFileName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COutputDataDlg, CDialog)
	//{{AFX_MSG_MAP(COutputDataDlg)
	ON_BN_CLICKED(IDC_BUTTON_SELECTIONDIR, OnButtonSelectiondir)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutputDataDlg message handlers

void COutputDataDlg::OnButtonSelectiondir() 
{
	// TODO: Add your control notification handler code here
	//CDirDlg dlg(true,"*.XML","MyFile",NULL,"扩展名(*.XML)   and   *.XML   and     and  ",0);
	//dlg.DoModal();
	UpdateData();
	CDirDialog dlg;
	if( dlg.DoBrowse( this ) > 0)
	{
		m_strDirPath = dlg.m_strPath;		
	}
    UpdateData(false);
}

void COutputDataDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if( m_strFileName.GetLength() <= 0 )
	{
		AfxMessageBox("文件名为空");
		return ;
	}
	else if( m_strFileName.Find(".xml") <= 0 )
	{
		m_strFileName += ".xml";
	}

	if( m_strDirPath.GetLength() <= 0 )
	{
		AfxMessageBox("文件路径为空");
		return ;
	}
	UpdateData(false);
	CDialog::OnOK();
}

BOOL COutputDataDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	// TODO: Add extra initialization here
	struct tm *p;
	char buf[40];
	long ltime;
	time(&ltime);
	p=localtime(&ltime);
	strftime(buf,29,"%a %d %b %Y %H %M %S GMT",p);
	UpdateData();
	m_strFileName.Format("%s的数据文件",buf);
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

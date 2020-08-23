// CapturePacketDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CapturePacket.h"
#include "CapturePacketDlg.h"
#include "AdapaterSelection.h"
#include "FramePacket.h"
#include "IPPacket.h"
#include "udpPacket.h"
#include "tcpPacket.h"
#include "arpPacket.h"
#include "OutputDataDlg.h"
#include "FilterDl.h"

#define WM_SYSTEMTRAY WM_USER + 1

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCapturePacketDlg dialog

CCapturePacketDlg::CCapturePacketDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCapturePacketDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCapturePacketDlg)
	m_strArpCount = _T("");
	m_strOtherCount = _T("");
	m_strTcpCount = _T("");
	m_strTotalCount = _T("");
	m_strUdpCount = _T("");
	m_lArpCount	= 0;
	m_lOtherCount = 0;
	m_lTcpCount	= 0;
	m_lTotalCount	= 0;
	m_lUdpCount	= 0;
	m_strFilterString = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON_SYSTEMTRAY);
}

void CCapturePacketDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCapturePacketDlg)
	DDX_Control(pDX, IDC_EDIT_PACKETHEX, m_editHex);
	DDX_Control(pDX, IDC_TREE_SINGERPACKET, m_treeSingerPacket);
	DDX_Control(pDX, IDC_LIST_PACKETINFO, m_listPacket);
	DDX_Text(pDX, IDC_EDIT_ARPPACKETCOUNT, m_strArpCount);
	DDX_Text(pDX, IDC_EDIT_OTHRERPACKETCOUNT, m_strOtherCount);
	DDX_Text(pDX, IDC_EDIT_TCPPACKETCOUNT, m_strTcpCount);
	DDX_Text(pDX, IDC_EDIT_TOTALPACKETCOUNT, m_strTotalCount);
	DDX_Text(pDX, IDC_EDIT_UDPPACKETCOUNT, m_strUdpCount);
	DDX_Text(pDX, IDC_EDIT_FILTER, m_strFilterString);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCapturePacketDlg, CDialog)
	//{{AFX_MSG_MAP(CCapturePacketDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENU_NETWORKCONFIGURATION, OnMenuNetworkconfiguration)
	ON_UPDATE_COMMAND_UI(ID_MENU_NETWORKCONFIGURATION, OnUpdateMenuNetworkconfiguration)
	ON_COMMAND(ID_MENU_START, OnMenuStart)
	ON_UPDATE_COMMAND_UI(ID_MENU_START, OnUpdateMenuStart)
	ON_COMMAND(ID_MENU_ABOUTAUTHOR, OnMenuAboutauthor)
	ON_UPDATE_COMMAND_UI(ID_MENU_ABOUTAUTHOR, OnUpdateMenuAboutauthor)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_PACKETINFO, OnItemchangedListPacketinfo)
	ON_COMMAND(ID_MENU_DATAOUTPUT, OnMenuDataoutput)
	ON_UPDATE_COMMAND_UI(ID_MENU_DATAOUTPUT, OnUpdateMenuDataoutput)
	ON_WM_CLOSE()
	ON_COMMAND(IDR_MENU_STSHOW, OnMenuStshow)
	ON_COMMAND(IDR_MENU_STEXIT, OnMenuStexit)
	ON_BN_CLICKED(IDC_BUTTON_FILTERAPPLY, OnButtonFilterapply)
	ON_BN_CLICKED(IDC_BUTTON_FILTERTEST, OnButtonFiltertest)
	ON_BN_CLICKED(IDC_BUTTON_FILTERSAVE, OnButtonFiltersave)
	ON_COMMAND(ID_MENU_STOP, OnMenuStop)
	ON_UPDATE_COMMAND_UI(ID_MENU_STOP, OnUpdateMenuStop)
	ON_COMMAND(ID_MENU_EXIT, OnMenuExit)
	ON_MESSAGE(WM_SYSTEMTRAY, OnSystemTray)//用于系统托盘
	ON_COMMAND(ID_MENU_HELPDOCUMENT, OnMenuHelpdocument)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCapturePacketDlg message handlers

BOOL CCapturePacketDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_pDevice = NULL;
	m_bFlag = false;
	//设置列信息
    m_listPacket.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_listPacket.InsertColumn(0,"编号",LVCFMT_RIGHT,50);
	m_listPacket.InsertColumn(1,"时间戳",LVCFMT_RIGHT,120);
	m_listPacket.InsertColumn(2,"源网卡地址",LVCFMT_RIGHT,120);
	m_listPacket.InsertColumn(3,"目的网卡地址",LVCFMT_RIGHT,120);
	m_listPacket.InsertColumn(4,"长度",LVCFMT_RIGHT,50);
	m_listPacket.InsertColumn(5,"协议",LVCFMT_RIGHT,50);
	m_listPacket.InsertColumn(6,"源端口",LVCFMT_LEFT,50);
	m_listPacket.InsertColumn(7,"源IP地址",LVCFMT_LEFT,120);
	m_listPacket.InsertColumn(8,"目的IP地址",LVCFMT_LEFT,120);
	m_listPacket.InsertColumn(10,"目的端口",LVCFMT_LEFT,50);
    LoadFilterString();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCapturePacketDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCapturePacketDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCapturePacketDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCapturePacketDlg::OnMenuNetworkconfiguration() 
{
	// TODO: Add your command handler code here
	//用于选择网卡信息

	CAdapaterSelection dlg;
	if(dlg.DoModal() == IDOK)
	{
        m_pDevice = dlg.getDevice();
	}
	
}

void CCapturePacketDlg::OnUpdateMenuNetworkconfiguration(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void pcap_handle(u_char *user, const struct pcap_pkthdr *pkt_header, const u_char *pkt_data)
{
     CCapturePacketDlg *pDlg = (CCapturePacketDlg *)AfxGetApp()->GetMainWnd();
	 //处理添加到数据类型中
	 pDlg->processPacket(pkt_header,pkt_data);
	 pDlg = NULL;
}

DWORD WINAPI CapturePacket(LPVOID lpParam)
{
     CCapturePacketDlg *pDlg = (CCapturePacketDlg *)lpParam;
	 pcap_t *pCap;
	 char	strErrorBuf[PCAP_ERRBUF_SIZE];
    
	if((pCap=pcap_open_live(pDlg->getDevice()->name,65536,1,1000,strErrorBuf))==NULL)
	{		
		return -1;
	}

	if (pDlg->m_strFilterString.GetLength() > 0)
	{
		struct bpf_program fcode;
        bpf_u_int32 NetMask;
		NetMask=0xffffff;

		char filter[1024];		
		strcpy(filter, pDlg->m_strFilterString.GetBuffer(pDlg->m_strFilterString.GetLength()));
		pDlg->m_strFilterString.ReleaseBuffer();	
		
		//compile the filter
		if(pcap_compile(pCap, &fcode, filter, 1, NetMask) < 0)
		{
			//fprintf(stderr,"\nError compiling filter: wrong syntax.\n");
			AfxMessageBox("编译字符串失败,程序无法启动进行抓包，请确认规则的正确性");
			return -1;
		}

		//set the filter
		if(pcap_setfilter(pCap, &fcode)<0)
		{
			//fprintf(stderr,"\nError setting the filter\n");
			AfxMessageBox("设置过滤串失败");
			return -1;
		}

	}

    do
	{
		pcap_loop(pCap,1,pcap_handle,NULL);
	}while(pDlg->getFlag());

	pcap_close(pCap);
	pDlg = NULL;
	return 1;	 
}

void CCapturePacketDlg::OnMenuStart() 
{
	// TODO: Add your command handler code here
	if(m_pDevice == NULL)
	{
		MessageBox("请选择网卡");
		return ;
	}    
	m_bFlag = true;
	CreateThread(NULL,NULL,CapturePacket,(LPVOID)this,true,NULL);
  //  AfxBeginThread(AFX_THREADPROC(CapturePacket),(LPVOID)this);
}

void CCapturePacketDlg::OnUpdateMenuStart(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_bFlag)
		pCmdUI->Enable(false);
	
}

pcap_if_t * CCapturePacketDlg::getDevice()
{
	if( m_pDevice == NULL)
		return NULL;
	return m_pDevice;
}

bool CCapturePacketDlg::getFlag()
{
     return m_bFlag;
}

//处理全部的网络数据
void CCapturePacketDlg::processPacket(const pcap_pkthdr *pkt_header, const u_char *pkt_data)
{
	//用于存诸网络中的数据，并保存到CArray中,以备将来使用
	struct pcap_pkthdr *pHeader = new pcap_pkthdr;
    u_char *pData;
	unsigned char *pPosition = (unsigned char *)pkt_data;	

	long nIndex = 0;//标识当前的数据包位置
	long nCount = 0;//标识后来
	char strData[20];//标识数据

	pHeader->caplen=pkt_header->caplen;
	pHeader->len=pkt_header->len;

	pData=new unsigned char[pHeader->len];
	memcpy((void *)pData,pkt_data,pHeader->len);

	m_pktHeaders.Add(pHeader);
	m_pktDatas.Add(pData);

	nIndex=m_pktHeaders.GetSize()-1;
	sprintf(strData,"%07d",nIndex+1);
	nCount=m_listPacket.InsertItem(nIndex,strData,0);
    m_lTotalCount++;//总数据包加1
	CFramePacket *pFramePacket = new CFramePacket(pData,14);
	CString strStamp;
	struct tm *ltime;    
	ltime=localtime(&pkt_header->ts.tv_sec); 
    strStamp.Format("%d-%d-%d %d:%d:%d",ltime->tm_year+1900,ltime->tm_mon+1,ltime->tm_mday,ltime->tm_hour,ltime->tm_min,ltime->tm_sec);
	CString strLength;
	strLength.Format("%ld",pHeader->len);
	m_listPacket.SetItemText(nCount,1,strStamp);
	m_listPacket.SetItemText(nCount,2,pFramePacket->GetMacSrcAddr());
	m_listPacket.SetItemText(nCount,3,pFramePacket->GetMacDestAddr());
	m_listPacket.SetItemText(nCount,4,strLength);
	if(pFramePacket->GetType() == 0x0800)
	{
		CIPPacket ipPacket(pData+14,pHeader->len-14);
		m_listPacket.SetItemText(nCount,5,ipPacket.GetProtocol());
        m_listPacket.SetItemText(nCount,7,ipPacket.GetSrcIP());
		m_listPacket.SetItemText(nCount,8,ipPacket.GetDestIP());
		if(ipPacket.GetProtocol() == "UDP")
		{
			CUDPPacket *pUDPPacket = new CUDPPacket(ipPacket.GetTData(),ipPacket.GetDataLength());
			m_listPacket.SetItemText(nCount,6,pUDPPacket->GetSrcPort());
			m_listPacket.SetItemText(nCount,9,pUDPPacket->GetDestPort());
			delete pUDPPacket;
			pUDPPacket = NULL;
			m_lUdpCount++;//UDP包加1
		}
		else if(ipPacket.GetProtocol() == "TCP")
		{
            CTCPPacket *pTCPPacket = new CTCPPacket(ipPacket.GetTData(),ipPacket.GetDataLength());
			m_listPacket.SetItemText(nCount,6,pTCPPacket->GetSrcPort());
			m_listPacket.SetItemText(nCount,9,pTCPPacket->GetDestPort());
			delete pTCPPacket;
			pTCPPacket = NULL;
			m_lTcpCount++;//TCP包加1
		}
	}
	else if(pFramePacket->GetType() == 0x0806)
	{
        m_listPacket.SetItemText(nCount,5,"ARP");
		CARPPacket *pARPPacket = new CARPPacket(pData+14,pHeader->len-14);
	    m_listPacket.SetItemText(nCount,7,pARPPacket->GetSPAddr());
		m_listPacket.SetItemText(nCount,8,pARPPacket->GetDPAddr());
		delete pARPPacket;
		pARPPacket = NULL;
		m_lArpCount++;//ARP包加1
	}
	else if(pFramePacket->GetType() == 0x8035)
	{
		m_listPacket.SetItemText(nCount,5,"RARP");
		CARPPacket *pRARPPacket = new CARPPacket(pData+14,pHeader->len-14);
	    m_listPacket.SetItemText(nCount,7,pRARPPacket->GetSPAddr());
		m_listPacket.SetItemText(nCount,8,pRARPPacket->GetDPAddr());
		delete pRARPPacket;
		pRARPPacket = NULL;
		m_lOtherCount++;
	}
	else
	{
        CString strProtocol;
		strProtocol.Format("0X%x",pFramePacket->GetType());
		m_listPacket.SetItemText(nCount,5,strProtocol);
		m_lOtherCount++;
	}
	delete pFramePacket;
	pFramePacket = NULL;	

	ShowPacketCount();//显示统计量信息
}

BOOL CCapturePacketDlg::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::OnNotify(wParam, lParam, pResult);
}

void CCapturePacketDlg::OnMenuAboutauthor() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlg;
	dlg.DoModal();
	
}

void CCapturePacketDlg::OnUpdateMenuAboutauthor(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}

void CCapturePacketDlg::ShowPacketForTree(const pcap_pkthdr *pkt_header, const u_char *pkt_data,long index)
{
	m_treeSingerPacket.DeleteAllItems();
	CString strTitle;
	strTitle.Format("第%ld个数据包",index+1);
    HTREEITEM hRoot = m_treeSingerPacket.InsertItem(strTitle);
	HTREEITEM hSubItem = m_treeSingerPacket.InsertItem("链路层数据",hRoot);
    CFramePacket *pFramePacket = new CFramePacket(pkt_data,14);
    HTREEITEM hItem = m_treeSingerPacket.InsertItem("源MAC地址 : "+pFramePacket->GetMacSrcAddr(),hSubItem);
	hItem = m_treeSingerPacket.InsertItem("目的MAC地址 : "+pFramePacket->GetMacDestAddr(),hSubItem);
	CString strType;
	strType.Format("类型 : 0X%x",pFramePacket->GetType());
	hItem = m_treeSingerPacket.InsertItem(strType,hSubItem);
    

	if(pFramePacket->GetType() == 0x0800)
	{
		hSubItem = m_treeSingerPacket.InsertItem("网络层数据",hRoot);
		CIPPacket ipPacket(pkt_data+14,pkt_header->len-14);
		hItem = m_treeSingerPacket.InsertItem("协议 : IP",hSubItem);
		hItem = m_treeSingerPacket.InsertItem("源IP : "+ipPacket.GetSrcIP(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("目的IP : "+ipPacket.GetDestIP(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("版本号: "+ipPacket.GetVersion(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("TTL值: "+ipPacket.GetTTL(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("总长度: "+ipPacket.GetTotalLength(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("头长度: "+ipPacket.GetHeaderLength(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("MF: "+ipPacket.GetMF(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("DF: "+ipPacket.GetDF(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("数据长度: "+ipPacket.GetDLength(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("校验和: "+ipPacket.GetCheckSum(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("优先级: "+ipPacket.GetPrecedence(),hSubItem);
		HTREEITEM h1 = m_treeSingerPacket.InsertItem("可靠性: "+ipPacket.GetReliability(),hItem);
		h1 = m_treeSingerPacket.InsertItem("延迟: "+ipPacket.GetDelay(),hItem);
		h1 = m_treeSingerPacket.InsertItem("吞吐量: "+ipPacket.GetThroughtPut(),hItem);
		hItem = m_treeSingerPacket.InsertItem("IP标识: "+ipPacket.GetIdentification(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("服务类型: "+ipPacket.GetServiceType(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("选项长度: "+ipPacket.GetOptLength(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("选项内容: "+ipPacket.GetOptions(),hSubItem);
		
        hSubItem = m_treeSingerPacket.InsertItem("传输层数据",hRoot);
		if(ipPacket.GetProtocol() == "UDP")
		{			
			CUDPPacket *pUDPPacket = new CUDPPacket(ipPacket.GetTData(),ipPacket.GetDataLength());
			hItem = m_treeSingerPacket.InsertItem("协议 : UDP",hSubItem);
			hItem = m_treeSingerPacket.InsertItem("源端口 : "+pUDPPacket->GetSrcPort(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("目的端口: "+pUDPPacket->GetDestPort(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("总长度: "+pUDPPacket->GetTotalLen(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("数据长度: "+pUDPPacket->GetDataLen(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("校验和: "+pUDPPacket->GetCheckSum(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("数据值: "+pUDPPacket->GetData(),hSubItem);
			delete pUDPPacket;
			pUDPPacket = NULL;		
		}
		else if(ipPacket.GetProtocol() == "TCP")
		{
			/*
用于建立连接 /用于   ，从当前  
*/
            CTCPPacket *pTCPPacket = new CTCPPacket(ipPacket.GetTData(),ipPacket.GetDataLength());
			hItem = m_treeSingerPacket.InsertItem("协议 : TCP",hSubItem);
			hItem = m_treeSingerPacket.InsertItem("源端口 : "+pTCPPacket->GetSrcPort(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("目的端口: "+pTCPPacket->GetDestPort(),hSubItem);

			hItem = m_treeSingerPacket.InsertItem("顺序号: "+pTCPPacket->GetSeqNum(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("确认号: "+pTCPPacket->GetAckNum(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("头部长: "+pTCPPacket->GetHeadLen(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("紧急指针: "+pTCPPacket->GetURG(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("确认号是否合法: "+pTCPPacket->GetACK(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("是否带有PUSH标志: "+pTCPPacket->GetPSH(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("是否复位: "+pTCPPacket->GetRST(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("是否建立连接: "+pTCPPacket->GetSYN(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("是否释放连接: "+pTCPPacket->GetFIN(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("窗口大小: "+pTCPPacket->GetWindowSize(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("校验和: "+pTCPPacket->GetCheckSum(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("顺序号到紧急数据偏移量: "+pTCPPacket->GetUrgPos(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("选项长度: "+pTCPPacket->GetOptLen(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("选项数据: "+pTCPPacket->GetOptions(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("数据长度: "+pTCPPacket->GetDataLen(),hSubItem);
			hItem = m_treeSingerPacket.InsertItem("数据: "+pTCPPacket->GetData(),hSubItem);
			delete pTCPPacket;
			pTCPPacket = NULL;			
		}
		m_treeSingerPacket.Expand(hSubItem,TVE_EXPAND);
	}
	else if(pFramePacket->GetType() == 0x0806)
	{
		CARPPacket *pARPPacket = new CARPPacket(pkt_data+14,pkt_header->len-14);
		hItem = m_treeSingerPacket.InsertItem("协议 : ARP",hSubItem);
		hItem = m_treeSingerPacket.InsertItem("源IP : "+pARPPacket->GetSPAddr(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("目的IP: "+pARPPacket->GetDPAddr(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("硬件地址类型: "+pARPPacket->GetHaddrtype(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("协议地址类型: "+pARPPacket->GetPaddrtype(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("硬件地址长度: "+pARPPacket->GetHaddrlen(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("协议地址长度: "+pARPPacket->GetPaddrlen(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("操作类型: "+pARPPacket->GetOperation(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("发送站点硬件地址: "+pARPPacket->GetSHaddr(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("目的站点硬件地址: "+pARPPacket->GetDHaddr(),hSubItem);
	    delete pARPPacket;
		pARPPacket = NULL;
	}
	else if(pFramePacket->GetType() == 0x8035)
	{
	    CARPPacket *pARPPacket = new CARPPacket(pkt_data+14,pkt_header->len-14);
		hItem = m_treeSingerPacket.InsertItem("协议 : RARP",hSubItem);
		hItem = m_treeSingerPacket.InsertItem("源IP : "+pARPPacket->GetSPAddr(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("目的IP: "+pARPPacket->GetDPAddr(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("硬件地址类型: "+pARPPacket->GetHaddrtype(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("协议地址类型: "+pARPPacket->GetPaddrtype(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("硬件地址长度: "+pARPPacket->GetHaddrlen(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("协议地址长度: "+pARPPacket->GetPaddrlen(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("操作类型: "+pARPPacket->GetOperation(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("发送站点硬件地址: "+pARPPacket->GetSHaddr(),hSubItem);
		hItem = m_treeSingerPacket.InsertItem("目的站点硬件地址: "+pARPPacket->GetDHaddr(),hSubItem);
	    delete pARPPacket;
		pARPPacket = NULL;
	}
	else
	{
       
	}
    delete pFramePacket;
	pFramePacket = NULL;
	m_treeSingerPacket.Expand(hRoot,TVE_EXPAND);
    m_treeSingerPacket.Expand(hSubItem,TVE_EXPAND);
	CString strHex;
	int nCount = 0;
	CString strText;
	for (unsigned short i = 0; i < pkt_header->caplen ; i++)
    {
		CString hex;
		if ( (i % 16) == 0) 
		{
			nCount++;
			hex.Format("\x0d\x0a 0X%04x   ",nCount);
			
			if( i != 0)
			{
				strHex +="  "+strText ;
			    strText = "";
			}
			strHex += hex;
		}
        hex.Format("%.2x ", pkt_data[i-1]);
		strHex += hex; 
        hex.Format("%c",pkt_data[i-1]);
		strText += hex;		           
    }
	if( strText != "")
		strHex += strText;
	m_editHex.SetWindowText(strHex);	
}

void CCapturePacketDlg::OnItemchangedListPacketinfo(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	POSITION pos=m_listPacket.GetFirstSelectedItemPosition();
	if(pos==NULL) 
		return;

	long index=m_listPacket.GetNextSelectedItem(pos);
	if(index < 0)
		return ;

	ShowPacketForTree(m_pktHeaders.GetAt(index),m_pktDatas.GetAt(index),index);
	*pResult = 0;
}

void CCapturePacketDlg::OnMenuDataoutput() 
{
	// TODO: Add your command handler code here	
	COutputDataDlg dlg;
	if( dlg.DoModal() == IDOK)
	{
		CString strFile = dlg.m_strDirPath+dlg.m_strFileName;
		if(createXML(strFile))
		{
			AfxMessageBox("数据文件导出成功");
		}
		else
		{
			AfxMessageBox("数据文件导出失败");
		}
	}
}

void CCapturePacketDlg::OnUpdateMenuDataoutput(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	
}
bool CCapturePacketDlg::createXML(CString strFileName)
{
	FILE *pFile ;
    pFile = fopen(strFileName,"w+");
	if(pFile == NULL)
	{
		AfxMessageBox("创建文件失败");
		return false;
	}
	fputs("<?xml version=\"1.0\" encoding=\"GBK\"?>",pFile);
	fputs("<Data>",pFile);
	for(int nIndex = 0;nIndex < m_pktDatas.GetSize();nIndex++)
	{
		CString str;
		str.Format("<item id =\"%d\">",nIndex);
		fputs(str,pFile);
		insertNode(pFile,m_pktHeaders.GetAt(nIndex),m_pktDatas.GetAt(nIndex));
		fputs("</item>",pFile);
	}
	fputs("</Data>",pFile);
	fclose(pFile);
	return true;
}
void CCapturePacketDlg::insertNode(FILE *pFile,const struct pcap_pkthdr *pkt_header, const u_char *pkt_data)
{
	fputs("<itemdata>",pFile);
	CString strHex;
	for (unsigned short i = 0; i < pkt_header->caplen ; i++)
	{
		CString hex;
		hex.Format("%.2x ", pkt_data[i-1]);
		strHex += hex;
	}
	fputs(strHex,pFile);
	fputs("</itemdata>",pFile);

}
//用于在显示前台中的统计量
void CCapturePacketDlg::ShowPacketCount()
{
	m_strArpCount.Format("%ld",m_lArpCount);
	this->SetDlgItemText(IDC_EDIT_ARPPACKETCOUNT,m_strArpCount);
	m_strOtherCount.Format("%ld",m_lOtherCount);
	this->SetDlgItemText(IDC_EDIT_OTHRERPACKETCOUNT,m_strOtherCount);
	m_strTcpCount.Format("%ld",m_lTcpCount);
	this->SetDlgItemText(IDC_EDIT_TCPPACKETCOUNT,m_strTcpCount);
	m_strTotalCount.Format("%ld",m_lTotalCount);
	this->SetDlgItemText(IDC_EDIT_TOTALPACKETCOUNT,m_strTotalCount);
	m_strUdpCount.Format("%ld",m_lUdpCount);
	this->SetDlgItemText(IDC_EDIT_UDPPACKETCOUNT,m_strUdpCount);
}
//回调函数，用于处理系统托盘
LRESULT CCapturePacketDlg::OnSystemTray(WPARAM wParam, LPARAM lParam)
{
	BringWindowToTop();
	if (wParam == ID_SYSTEMTRAY)
	{
		switch (lParam)
		{
		case WM_LBUTTONDBLCLK:
			{
				NOTIFYICONDATA nid;
				nid.cbSize = sizeof(NOTIFYICONDATA);
				nid.hWnd = m_hWnd;
				nid.uID = ID_SYSTEMTRAY;
				nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
				nid.uCallbackMessage = WM_SYSTEMTRAY;
				nid.hIcon = AfxGetApp()->LoadIcon(IDI_ICON_SYSTEMTRAY);
				strcpy(nid.szTip, "监控器在前台工作..");
				::Shell_NotifyIcon(NIM_MODIFY, &nid);
				ShowWindow(SW_SHOW);
			}
			break;
		case WM_RBUTTONDOWN:
			{
				CMenu menu;
				menu.LoadMenu(IDR_MENU_SYSTEMTRAY);
				CMenu *pMenu = menu.GetSubMenu(0);
				ASSERT(pMenu != NULL);
				CPoint point;
				GetCursorPos(&point);
				pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
					point.x, point.y, this);
				PostMessage(WM_NULL);
			}
			break;
		default:
			NOTIFYICONDATA nid;
			nid.cbSize = sizeof(NOTIFYICONDATA);
			nid.hWnd = m_hWnd;
			nid.uID = ID_SYSTEMTRAY;
			nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
			nid.uCallbackMessage = WM_SYSTEMTRAY;
			nid.hIcon = AfxGetApp()->LoadIcon(IDI_ICON_SYSTEMTRAY);
			strcpy(nid.szTip, "监控器在工作中....");
			::Shell_NotifyIcon(NIM_MODIFY, &nid);
			break;
		}
	}
	return 1;
}

void CCapturePacketDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	NOTIFYICONDATA nid;
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = this->m_hWnd;
    nid.uID = ID_SYSTEMTRAY;
	nid.uFlags = NIF_MESSAGE|NIF_ICON|NIF_TIP;
    nid.uCallbackMessage = WM_SYSTEMTRAY;	
	nid.hIcon = AfxGetApp()->LoadIcon(IDI_ICON_SYSTEMTRAYQQ);
    strcpy(nid.szTip, "监控器在后台工作...");
	Shell_NotifyIcon(NIM_ADD, &nid);
	ShowWindow(SW_HIDE);
	//CDialog::OnClose();
}

void CCapturePacketDlg::OnMenuStshow() 
{
	// TODO: Add your command handler code here
	ShowWindow(SW_SHOW);
}

void CCapturePacketDlg::OnMenuStexit() 
{
	// TODO: Add your command handler code here
	exit(0);
}

void CCapturePacketDlg::OnButtonFilterapply() 
{
	// TODO: Add your control notification handler code here
	if( getDevice() == NULL )
	{
		AfxMessageBox("你还没有选择要加载的网卡");
		return ;
	}
	m_bFlag = false ;
//	Sleep(2000);
	UpdateData();
	UpdateData(false);
	
	AfxMessageBox(m_strFilterString+"正在应用生效");
	OnMenuStart();
	
}

void CCapturePacketDlg::OnButtonFiltertest() 
{
	// TODO: Add your control notification handler code here
	struct bpf_program fcode;
    bpf_u_int32 NetMask;
	NetMask=0xffffff;
    pcap_t *pCap;
    char strErrorBuf[1025];
    OnButtonFiltersave();
	char filter[1024];		
	strcpy(filter, m_strFilterString.GetBuffer(m_strFilterString.GetLength()));
	m_strFilterString.ReleaseBuffer();	
	
	if( getDevice() != NULL )
	{		
		if((pCap=pcap_open_live(getDevice()->name,65536,1,1000,strErrorBuf))==NULL)
		{		
			return ;
		}
		if(pcap_compile(pCap, &fcode, filter, 1, NetMask) < 0)
		{
			//fprintf(stderr,"\nError compiling filter: wrong syntax.\n");
			AfxMessageBox("编译字符串失败,请确认你的规则编写的正确性，或查看帮助文档中规则的编写规范");
			return ;
		}
		AfxMessageBox("规则:"+m_strFilterString+"\n测试通过!!!!");	
		pcap_close(pCap);
	}
	else
		AfxMessageBox("当前没有选持要测试的网卡");
}

void CCapturePacketDlg::OnButtonFiltersave() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	FILE *fp ;
	fp = fopen("configuration\\filter.cp","w");
	if(NULL == fp)
	{
		MessageBox("写过滤串信息失败");
		return ;
	}
	fputs(m_strFilterString,fp);
	fclose(fp);
	UpdateData(false);	
}

bool CCapturePacketDlg::LoadFilterString()
{
	FILE *fp ;
	fp = fopen("configuration\\filter.cp","r");
	if(NULL == fp)
	{
		return false;
	}
	char buf[1024];
	int nCount = 0;
	while(!feof(fp))
	{
		buf[nCount++] = fgetc(fp);
	}
	if(nCount > 0)
		buf[nCount-1] = '\0';
	else 
		buf[nCount] = '\0';
    fclose(fp);
	UpdateData();
	m_strFilterString.Format("%s",buf);
	UpdateData(false);
	return true;
}

void CCapturePacketDlg::OnMenuStop() 
{
	// TODO: Add your command handler code here
	m_bFlag = false ;
}

void CCapturePacketDlg::OnUpdateMenuStop(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(!m_bFlag)
		pCmdUI->Enable(false);
	
}

void CCapturePacketDlg::OnMenuExit() 
{
	// TODO: Add your command handler code here1
	//exit(0);
	CFilterDl dlg;
	dlg.DoModal();
	
}

void CCapturePacketDlg::OnMenuHelpdocument() 
{
	// TODO: Add your command handler code here
	ShellExecute(NULL,NULL,"help.CHM",NULL,NULL,SW_SHOW);
}

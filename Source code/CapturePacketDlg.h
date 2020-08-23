// CapturePacketDlg.h : header file
//

#if !defined(AFX_CAPTUREPACKETDLG_H__1BFEE5B3_9DC0_42BB_955D_3A36A36EC438__INCLUDED_)
#define AFX_CAPTUREPACKETDLG_H__1BFEE5B3_9DC0_42BB_955D_3A36A36EC438__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCapturePacketDlg dialog

class CCapturePacketDlg : public CDialog
{
// Construction
public:
	void ShowPacketForTree(const pcap_pkthdr *pkt_header,const u_char *pkt_data,long index);
	void processPacket(const struct pcap_pkthdr *pkt_header, const u_char *pkt_data);
	bool getFlag();
	pcap_if_t* getDevice();
	void ShowPacketCount();
	LRESULT OnSystemTray(WPARAM wParam, LPARAM lParam);//用于系统托盘
	CCapturePacketDlg(CWnd* pParent = NULL);	// standard constructor
    
// Dialog Data
	//{{AFX_DATA(CCapturePacketDlg)
	enum { IDD = IDD_CAPTUREPACKET_DIALOG };
	CEdit	m_editHex;
	CTreeCtrl	m_treeSingerPacket;
	CListCtrl	m_listPacket;
	CString	m_strArpCount;
	CString	m_strOtherCount;
	CString	m_strTcpCount;
	CString	m_strTotalCount;
	CString	m_strUdpCount;
	CString	m_strFilterString;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCapturePacketDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCapturePacketDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMenuNetworkconfiguration();
	afx_msg void OnUpdateMenuNetworkconfiguration(CCmdUI* pCmdUI);
	afx_msg void OnMenuStart();
	afx_msg void OnUpdateMenuStart(CCmdUI* pCmdUI);
	afx_msg void OnMenuAboutauthor();
	afx_msg void OnUpdateMenuAboutauthor(CCmdUI* pCmdUI);
	afx_msg void OnItemchangedListPacketinfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuDataoutput();
	afx_msg void OnUpdateMenuDataoutput(CCmdUI* pCmdUI);
	afx_msg void OnClose();
	afx_msg void OnMenuStshow();
	afx_msg void OnMenuStexit();
	afx_msg void OnButtonFilterapply();
	afx_msg void OnButtonFiltertest();
	afx_msg void OnButtonFiltersave();
	afx_msg void OnMenuStop();
	afx_msg void OnUpdateMenuStop(CCmdUI* pCmdUI);
	afx_msg void OnMenuExit();
	afx_msg void OnMenuHelpdocument();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	pcap_if_t *m_pDevice;//所选中的网卡地址
	bool	  m_bFlag;//查看是否开始
	CArray<const struct pcap_pkthdr *,const struct pcap_pkthdr *>  m_pktHeaders;
	CArray<const u_char *,const u_char *>  m_pktDatas; 
	long	m_lArpCount;
	long	m_lOtherCount;
	long	m_lTcpCount;
	long	m_lTotalCount;
	long	m_lUdpCount;
private:
	bool LoadFilterString( );
	bool createXML(CString strFileName);
	void insertNode(FILE *pFile,const struct pcap_pkthdr *pkt_header, const u_char *pkt_data);	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAPTUREPACKETDLG_H__1BFEE5B3_9DC0_42BB_955D_3A36A36EC438__INCLUDED_)

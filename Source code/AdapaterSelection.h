#if !defined(AFX_ADAPATERSELECTION_H__008F79F9_1EFF_44D1_8D44_8550C9A33621__INCLUDED_)
#define AFX_ADAPATERSELECTION_H__008F79F9_1EFF_44D1_8D44_8550C9A33621__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AdapaterSelection.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAdapaterSelection dialog

class CAdapaterSelection : public CDialog
{
// Construction
public:
	void iptos(u_long in,char output[]);
	CAdapaterSelection(CWnd* pParent = NULL);   // standard constructor
	pcap_if_t *getDevice();

// Dialog Data
	//{{AFX_DATA(CAdapaterSelection)
	enum { IDD = IDD_DIALOG_NETWORKADAPTER };
	CTreeCtrl	m_treeAdapater;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdapaterSelection)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAdapaterSelection)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDblclkTreeNetworkadapters(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	pcap_if_t *m_pAllDevs;
	pcap_if_t *m_pDev;	
    char m_strErrorBuf[PCAP_ERRBUF_SIZE];
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADAPATERSELECTION_H__008F79F9_1EFF_44D1_8D44_8550C9A33621__INCLUDED_)

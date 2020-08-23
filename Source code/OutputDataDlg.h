#if !defined(AFX_OUTPUTDATADLG_H__8E6815A4_F132_4D46_AE90_0169DCF59DB3__INCLUDED_)
#define AFX_OUTPUTDATADLG_H__8E6815A4_F132_4D46_AE90_0169DCF59DB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OutputDataDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COutputDataDlg dialog

class COutputDataDlg : public CDialog
{
// Construction
public:
	COutputDataDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COutputDataDlg)
	enum { IDD = IDD_DIALOG_OUTPUTDATA };
	CString	m_strDirPath;
	CString	m_strFileName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutputDataDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COutputDataDlg)
	afx_msg void OnButtonSelectiondir();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTPUTDATADLG_H__8E6815A4_F132_4D46_AE90_0169DCF59DB3__INCLUDED_)

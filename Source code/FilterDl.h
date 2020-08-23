#if !defined(AFX_FILTERDL_H__57BF688D_A8BF_408D_A9CC_B79FA33B8694__INCLUDED_)
#define AFX_FILTERDL_H__57BF688D_A8BF_408D_A9CC_B79FA33B8694__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FilterDl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFilterDl dialog

class CFilterDl : public CDialog
{
// Construction
public:
	CDialog m_dlg2;
	CDialog m_dlg1;
	CFilterDl(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFilterDl)
	enum { IDD = IDD_DIALOG_FILTER };
	CTabCtrl	m_tCtr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFilterDl)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFilterDl)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTabCtr(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILTERDL_H__57BF688D_A8BF_408D_A9CC_B79FA33B8694__INCLUDED_)

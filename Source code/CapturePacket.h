// CapturePacket.h : main header file for the CAPTUREPACKET application
//

#if !defined(AFX_CAPTUREPACKET_H__B6800C22_A30B_4CCA_AEEB_63C3033EFC8E__INCLUDED_)
#define AFX_CAPTUREPACKET_H__B6800C22_A30B_4CCA_AEEB_63C3033EFC8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCapturePacketApp:
// See CapturePacket.cpp for the implementation of this class
//

class CCapturePacketApp : public CWinApp
{
public:
	CCapturePacketApp();


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCapturePacketApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCapturePacketApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAPTUREPACKET_H__B6800C22_A30B_4CCA_AEEB_63C3033EFC8E__INCLUDED_)

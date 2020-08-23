// DirDialog.h: interface for the CDirDialog class.
//
//////////////////////////////////////////////////////////////////////
#if !defined(AFX_DIRDIALOG_H__FFC582A2_6403_462D_830F_8EF883EA047E__INCLUDED_)
#define AFX_DIRDIALOG_H__FFC582A2_6403_462D_830F_8EF883EA047E__INCLUDED_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CDirDialog  
{
public:
 int DoBrowse(CWnd *pwndParent);
 CDirDialog();
 virtual ~CDirDialog(); 
public:
 CString m_strPath;
 CString m_strInitDir;
 CString m_strSelDir;
 CString m_strWindowTitle;
 int m_iImageIndex;
};
#endif // !defined(AFX_DIRDIALOG_H__FFC582A2_6403_462D_830F_8EF883EA047E__INCLUDED_)

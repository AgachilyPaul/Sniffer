// ARPPacket.h: interface for the CARPPacket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARPPACKET_H__C7D20E2C_108E_4D22_A2ED_2AB018EBCFAD__INCLUDED_)
#define AFX_ARPPACKET_H__C7D20E2C_108E_4D22_A2ED_2AB018EBCFAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CARPPacket  
{
public:
	CARPPacket();
	virtual ~CARPPacket();
	CARPPacket(const unsigned char *buf,const unsigned int buflen);
private:
	int		m_nHaddrtype;//硬件地址类型
	int		m_nPaddrtype;//协议地址类型
	int		m_nHaddrlen;//硬件地址长度
	int		m_nPaddrlen;//协议地址长度
	int		m_nOperation;//操作类型
	BYTE	m_cSHaddr[6];//发送站点硬件地址
	int		m_nSPaddr;//发送站点协议地址
	BYTE	m_cDHaddr[6];//目的站点硬件地址
	int		m_nDPaddr;//目的站点协议地址
public:
	CString		GetSPAddr();
	CString		GetDPAddr();
	CString		GetHaddrtype();//硬件地址类型
	CString		GetPaddrtype();//协议地址类型
	CString		GetHaddrlen();//硬件地址长度
	CString		GetPaddrlen();//协议地址长度
	CString		GetOperation();//操作类型
	CString	    GetSHaddr();//发送站点硬件地址
	CString	    GetDHaddr();//目的站点硬件地址
private:
	CString		GetData(int nNum,BYTE *pByte = NULL,bool bFlag = true);

};

#endif // !defined(AFX_ARPPACKET_H__C7D20E2C_108E_4D22_A2ED_2AB018EBCFAD__INCLUDED_)

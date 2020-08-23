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
	int		m_nHaddrtype;//Ӳ����ַ����
	int		m_nPaddrtype;//Э���ַ����
	int		m_nHaddrlen;//Ӳ����ַ����
	int		m_nPaddrlen;//Э���ַ����
	int		m_nOperation;//��������
	BYTE	m_cSHaddr[6];//����վ��Ӳ����ַ
	int		m_nSPaddr;//����վ��Э���ַ
	BYTE	m_cDHaddr[6];//Ŀ��վ��Ӳ����ַ
	int		m_nDPaddr;//Ŀ��վ��Э���ַ
public:
	CString		GetSPAddr();
	CString		GetDPAddr();
	CString		GetHaddrtype();//Ӳ����ַ����
	CString		GetPaddrtype();//Э���ַ����
	CString		GetHaddrlen();//Ӳ����ַ����
	CString		GetPaddrlen();//Э���ַ����
	CString		GetOperation();//��������
	CString	    GetSHaddr();//����վ��Ӳ����ַ
	CString	    GetDHaddr();//Ŀ��վ��Ӳ����ַ
private:
	CString		GetData(int nNum,BYTE *pByte = NULL,bool bFlag = true);

};

#endif // !defined(AFX_ARPPACKET_H__C7D20E2C_108E_4D22_A2ED_2AB018EBCFAD__INCLUDED_)

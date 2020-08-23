// UDPPacket.h: interface for the CUDPPacket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UDPPACKET_H__5FFF1B9D_B0D8_4511_8DA1_1A728F489C4F__INCLUDED_)
#define AFX_UDPPACKET_H__5FFF1B9D_B0D8_4511_8DA1_1A728F489C4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUDPPacket  
{
public:
	CUDPPacket();
	virtual ~CUDPPacket();
	CUDPPacket(unsigned char *buf,int buflen);
private:
	unsigned int m_uSrcPort;//Դ�˿�
	unsigned int m_uDestPort;//Ŀ�Ķ˿�
	int		m_nTotalLen;//�ܳ�
	int		m_nCheckSum;//У���
	unsigned int m_uDataLen;
	char *m_pData;
public:
	CString		GetSrcPort();
	CString		GetDestPort();
	CString		GetTotalLen();//�ܳ�
	CString		GetCheckSum();//У���
	CString		GetDataLen();
	CString     GetData();
private:
	CString		GetInt(int nNumm,char *pData = NULL,bool nFlag = true);

};

#endif // !defined(AFX_UDPPACKET_H__5FFF1B9D_B0D8_4511_8DA1_1A728F489C4F__INCLUDED_)

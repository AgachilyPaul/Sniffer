// ICMPPacket.h: interface for the CICMPPacket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICMPPACKET_H__CABDF666_2AA2_404E_8C4A_DA67CDB15C09__INCLUDED_)
#define AFX_ICMPPACKET_H__CABDF666_2AA2_404E_8C4A_DA67CDB15C09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CICMPPacket  
{
public:
	CICMPPacket();
	virtual ~CICMPPacket();
	CICMPPacket(unsigned char *buf,int buflen);
private:
	int		m_nType;//����
	int		m_nCode;//����
	int		m_nCheckSum;//У���
	int		m_nDataLen;//���ݳ���
	unsigned char *m_pData;//����
	unsigned int  m_nGatewayAddr;//���ص�ַ
	unsigned int  m_nIdentification;//��ʶ
	unsigned int  m_nSequence;//˳���
	unsigned int  m_nInittime;//��ʼʱ���
	unsigned int  m_nReceivetime;//����ʱ���
	unsigned int  m_Sendtime;//����ʱ���
	unsigned int  m_Addrmask;//��ַ����
};

#endif // !defined(AFX_ICMPPACKET_H__CABDF666_2AA2_404E_8C4A_DA67CDB15C09__INCLUDED_)

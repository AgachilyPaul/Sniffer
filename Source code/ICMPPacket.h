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
	int		m_nType;//类型
	int		m_nCode;//代号
	int		m_nCheckSum;//校验和
	int		m_nDataLen;//数据长度
	unsigned char *m_pData;//数据
	unsigned int  m_nGatewayAddr;//网关地址
	unsigned int  m_nIdentification;//标识
	unsigned int  m_nSequence;//顺序号
	unsigned int  m_nInittime;//初始时间戳
	unsigned int  m_nReceivetime;//接收时间戳
	unsigned int  m_Sendtime;//发送时间戳
	unsigned int  m_Addrmask;//地址掩码
};

#endif // !defined(AFX_ICMPPACKET_H__CABDF666_2AA2_404E_8C4A_DA67CDB15C09__INCLUDED_)

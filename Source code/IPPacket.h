// IPPacket.h: interface for the CIPPacket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IPPACKET_H__E7869A50_D11B_487D_807D_657E4C3D2A97__INCLUDED_)
#define AFX_IPPACKET_H__E7869A50_D11B_487D_807D_657E4C3D2A97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CIPPacket  
{
public:
	CIPPacket();
	CIPPacket(const unsigned char* buf,int buflen);
	virtual ~CIPPacket();
private:
	int		m_nVersion;	//版本
	int		m_nHeaderLength;	//头部长度
	int		m_nServiceType;	//服务类型 type of service
	int		m_nPrecedence;	//优先级
	bool	m_bDelay;	//延迟
	bool	m_bThroughtPut;	//吞吐量
	bool	m_bReliability;	//可靠性
	unsigned int m_uTotalLength;	//总长total length
	int		m_nIdentification;	//标识
	bool	m_bDF;	//不要分段
	bool	m_bMF;	//还有进一步的分段
	int		m_nFragOffSet;	//分段偏移fragment offset
	int		m_nTTL;	//生命期time to live
	int		m_nProtocol;	//协议,如TCP,UDP
	unsigned int m_nCheckSum;	//头部校验和
	long	m_lSrcIP;	//源IP地址
	long	m_lDestIP;	//目的IP地址
	int		m_nOptLength;	//选项长度
	unsigned char *m_pOptions;	//选项内容
	int		m_nDataLength;	//数据长度
	unsigned char *m_pData;	//数据内容
public:
	CString		GetProtocol();
	CString		GetDestIP();
	CString		GetSrcIP();
    unsigned char* GetTData();
	int			GetDataLength();
	CString		GetVersion();	//版本
	CString		GetHeaderLength();	//头部长度
	CString		GetServiceType();	//服务类型 type of service
	CString		GetPrecedence();	//优先级
	CString	    GetDelay();	//延迟
	CString	    GetThroughtPut();	//吞吐量
	CString	    GetReliability();	//可靠性
	CString     GetTotalLength();	//总长total length
	CString		GetIdentification();	//标识
	CString		GetDF();	//不要分段
	CString		GetMF();	//还有进一步的分段
	CString		GetFragOffSet();	//分段偏移fragment offset
	CString		GetTTL();	//生命期time to live
	CString     GetCheckSum();	//头部校验和
	CString		GetOptLength();	//选项长度
	CString     GetOptions();	//选项内容
	CString		GetDLength();	//数据长度
private:
	CString		GetInt(int nNum);
	CString		GetBool(bool nBool);

};

#endif // !defined(AFX_IPPACKET_H__E7869A50_D11B_487D_807D_657E4C3D2A97__INCLUDED_)

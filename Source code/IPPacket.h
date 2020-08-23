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
	int		m_nVersion;	//�汾
	int		m_nHeaderLength;	//ͷ������
	int		m_nServiceType;	//�������� type of service
	int		m_nPrecedence;	//���ȼ�
	bool	m_bDelay;	//�ӳ�
	bool	m_bThroughtPut;	//������
	bool	m_bReliability;	//�ɿ���
	unsigned int m_uTotalLength;	//�ܳ�total length
	int		m_nIdentification;	//��ʶ
	bool	m_bDF;	//��Ҫ�ֶ�
	bool	m_bMF;	//���н�һ���ķֶ�
	int		m_nFragOffSet;	//�ֶ�ƫ��fragment offset
	int		m_nTTL;	//������time to live
	int		m_nProtocol;	//Э��,��TCP,UDP
	unsigned int m_nCheckSum;	//ͷ��У���
	long	m_lSrcIP;	//ԴIP��ַ
	long	m_lDestIP;	//Ŀ��IP��ַ
	int		m_nOptLength;	//ѡ���
	unsigned char *m_pOptions;	//ѡ������
	int		m_nDataLength;	//���ݳ���
	unsigned char *m_pData;	//��������
public:
	CString		GetProtocol();
	CString		GetDestIP();
	CString		GetSrcIP();
    unsigned char* GetTData();
	int			GetDataLength();
	CString		GetVersion();	//�汾
	CString		GetHeaderLength();	//ͷ������
	CString		GetServiceType();	//�������� type of service
	CString		GetPrecedence();	//���ȼ�
	CString	    GetDelay();	//�ӳ�
	CString	    GetThroughtPut();	//������
	CString	    GetReliability();	//�ɿ���
	CString     GetTotalLength();	//�ܳ�total length
	CString		GetIdentification();	//��ʶ
	CString		GetDF();	//��Ҫ�ֶ�
	CString		GetMF();	//���н�һ���ķֶ�
	CString		GetFragOffSet();	//�ֶ�ƫ��fragment offset
	CString		GetTTL();	//������time to live
	CString     GetCheckSum();	//ͷ��У���
	CString		GetOptLength();	//ѡ���
	CString     GetOptions();	//ѡ������
	CString		GetDLength();	//���ݳ���
private:
	CString		GetInt(int nNum);
	CString		GetBool(bool nBool);

};

#endif // !defined(AFX_IPPACKET_H__E7869A50_D11B_487D_807D_657E4C3D2A97__INCLUDED_)

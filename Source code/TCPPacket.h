// TCPPacket.h: interface for the CTCPPacket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TCPPACKET_H__8EC6C630_C16F_446F_9A03_E86E99A89BE4__INCLUDED_)
#define AFX_TCPPACKET_H__8EC6C630_C16F_446F_9A03_E86E99A89BE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTCPPacket  
{
public:
	CTCPPacket();
	virtual ~CTCPPacket();
	CTCPPacket(unsigned char *buf,int buflen);
private:
	int		m_nSrcPort;//Դ�˿�
	int		m_nDestPort;//Ŀ�Ķ˿�
	unsigned int m_uSeqNum;//˳���
	unsigned int m_uAckNum;//ȷ�Ϻ�
	int		m_nHeadLen;//ͷ����
	bool	m_bURG;//Ϊ1��ʾʹ�ý���ָ��
	bool	m_bACK;//Ϊ1��ʾȷ�ϺźϷ�
	bool	m_bPSH;//��ʾ����PUSH��־������
	bool	m_bRST;//������������������ԭ���ĸ�λ
	bool	m_bSYN;//���ڽ�������
	bool	m_bFIN;//�����ͷ�����
	int		m_nWindowSize;//���ڴ�С
	int		m_nCheckSum;//У���
	int		m_nUrgPos;//����ָ�룬�ӵ�ǰ˳��ŵ���������λ��ƫ����
	int		m_nOptLen;//ѡ���
	unsigned char *m_pOptions;
	int		m_nDataLen;
	unsigned char *m_pData;
public:
	CString		GetSrcPort();
	CString		GetDestPort();
	CString		GetSeqNum();//˳���
	CString		GetAckNum();//ȷ�Ϻ�
	CString		GetHeadLen();//ͷ����
	CString		GetURG();//Ϊ1��ʾʹ�ý���ָ��
	CString		GetACK();//Ϊ1��ʾȷ�ϺźϷ�
	CString		GetPSH();//��ʾ����PUSH��־������
	CString		GetRST();//������������������ԭ���ĸ�λ
	CString		GetSYN();//���ڽ�������
	CString		GetFIN();//�����ͷ�����
	CString		GetWindowSize();//���ڴ�С
	CString		GetCheckSum();//У���
	CString		GetUrgPos();//����ָ�룬�ӵ�ǰ˳��ŵ���������λ��ƫ����
	CString		GetOptLen();//ѡ���
	CString		GetOptions();//ѡ��ֵ
	CString		GetDataLen();//���ݳ���
	CString		GetData();//����ֵ
private:
	CString		GetStr(unsigned int nNum,unsigned char * pData = NULL,bool nFlag = true);
	CString		GetBool(bool nFlag);
};

#endif // !defined(AFX_TCPPACKET_H__8EC6C630_C16F_446F_9A03_E86E99A89BE4__INCLUDED_)

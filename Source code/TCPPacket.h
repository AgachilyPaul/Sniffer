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
	int		m_nSrcPort;//源端口
	int		m_nDestPort;//目的端口
	unsigned int m_uSeqNum;//顺序号
	unsigned int m_uAckNum;//确认号
	int		m_nHeadLen;//头部长
	bool	m_bURG;//为1表示使用紧急指针
	bool	m_bACK;//为1表示确认号合法
	bool	m_bPSH;//表示带有PUSH标志的数据
	bool	m_bRST;//用于主机崩溃或其他原因后的复位
	bool	m_bSYN;//用于建立连接
	bool	m_bFIN;//用于释放连接
	int		m_nWindowSize;//窗口大小
	int		m_nCheckSum;//校验和
	int		m_nUrgPos;//紧急指针，从当前顺序号到紧急数据位置偏移量
	int		m_nOptLen;//选项长度
	unsigned char *m_pOptions;
	int		m_nDataLen;
	unsigned char *m_pData;
public:
	CString		GetSrcPort();
	CString		GetDestPort();
	CString		GetSeqNum();//顺序号
	CString		GetAckNum();//确认号
	CString		GetHeadLen();//头部长
	CString		GetURG();//为1表示使用紧急指针
	CString		GetACK();//为1表示确认号合法
	CString		GetPSH();//表示带有PUSH标志的数据
	CString		GetRST();//用于主机崩溃或其他原因后的复位
	CString		GetSYN();//用于建立连接
	CString		GetFIN();//用于释放连接
	CString		GetWindowSize();//窗口大小
	CString		GetCheckSum();//校验和
	CString		GetUrgPos();//紧急指针，从当前顺序号到紧急数据位置偏移量
	CString		GetOptLen();//选项长度
	CString		GetOptions();//选项值
	CString		GetDataLen();//数据长度
	CString		GetData();//数据值
private:
	CString		GetStr(unsigned int nNum,unsigned char * pData = NULL,bool nFlag = true);
	CString		GetBool(bool nFlag);
};

#endif // !defined(AFX_TCPPACKET_H__8EC6C630_C16F_446F_9A03_E86E99A89BE4__INCLUDED_)

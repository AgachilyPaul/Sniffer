// TCPPacket.cpp: implementation of the CTCPPacket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CapturePacket.h"
#include "TCPPacket.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTCPPacket::CTCPPacket()
{

}

CTCPPacket::~CTCPPacket()
{
	if(m_pData != NULL)
		delete[] m_pData;
	if(m_pOptions != NULL)
		delete[] m_pOptions ;
}

CTCPPacket::CTCPPacket(unsigned char *buf,int buflen)
{
	unsigned char *pos;
	pos = (unsigned char *)buf;
	m_nSrcPort = (*pos)*0x100+(*(pos+1));

	pos+=2;
	m_nDestPort = (*pos)*0x100+(*(pos+1));

	pos+=2;
	m_uSeqNum = (*pos)*0x1000000+(*(pos+1))*0x10000+(*(pos+2))*0x100+(*(pos+3));

	pos+=4;
	m_uAckNum = (*pos)*0x1000000+(*(pos+1))*0x10000+(*(pos+2))*0x100+(*(pos+3));

	pos+=4;
	m_nHeadLen = (*pos)/16;

	pos++;
	if(*pos & 0x20)
		m_bURG=true;
	else 
		m_bURG=false;
	if(*pos & 0x10)
		m_bACK=true;
	else
		m_bACK=false;
	if(*pos & 0x08)
		m_bPSH=true;
	else
		m_bPSH=false;
	if(*pos & 0x04)
		m_bRST=true;
	else
		m_bRST=false;
	if(*pos & 0x02)
		m_bSYN=true;
	else
		m_bSYN=false;
	if(*pos & 0x01)
		m_bFIN=true;
	else
		m_bFIN=false;

	pos++;
	m_nWindowSize = (*pos)*0x100+(*(pos+1));

	pos+=2;
	m_nCheckSum = (*pos)*0x100+(*(pos+1));

	pos+=2;
	m_nUrgPos = (*pos)*0x100+(*(pos+1));

	if(m_nHeadLen > 5)
	{
		pos+=2;
		m_nOptLen = m_nHeadLen*4-20;
		m_pOptions = new unsigned char[m_nOptLen];
		memcpy(m_pOptions,buf+20,m_nOptLen);
	}
	else
	{
		m_nOptLen = 0;
		m_pOptions = NULL;
	}

	pos = (unsigned char *)(buf+m_nHeadLen*4);
	m_nDataLen = buflen-m_nHeadLen*4;
	if(m_nDataLen>0)
	{
		m_pData = new unsigned char[m_nDataLen];
		memcpy(m_pData,buf+m_nHeadLen*4,m_nDataLen);
	}
	else
	{
		m_pData=NULL;
		m_nDataLen=0;
	}

}

CString CTCPPacket::GetSrcPort()
{
	return	GetStr(m_nSrcPort);
}

CString CTCPPacket::GetDestPort()
{
	return	GetStr(m_nDestPort);
}
CString CTCPPacket::GetSeqNum()
{
	return GetStr(m_uSeqNum);//顺序号
}
CString CTCPPacket::GetAckNum()
{
	return GetStr(m_uAckNum);//确认号
}
CString CTCPPacket::GetHeadLen()
{
	return GetStr(m_nHeadLen);//头部长
}
CString CTCPPacket::GetURG()
{
	return GetBool(m_bURG);//为1表示使用紧急指针
}
CString CTCPPacket::GetACK()
{
	return GetBool(m_bACK);//为1表示确认号合法
}
CString CTCPPacket::GetPSH()
{
	return GetBool(m_bPSH);//表示带有PUSH标志的数据
}
CString CTCPPacket::GetRST()
{
	return GetBool(m_bRST);//用于主机崩溃或其他原因后的复位
}
CString CTCPPacket::GetSYN()
{
	return GetBool(m_bSYN);//用于建立连接
}
CString CTCPPacket::GetFIN()
{
	return GetBool(m_bFIN);//用于释放连接
}
CString CTCPPacket::GetWindowSize()
{
	return GetStr(m_nWindowSize);//窗口大小
}
CString CTCPPacket::GetCheckSum()
{
	return GetStr(m_nCheckSum);//校验和
}
CString CTCPPacket::GetUrgPos()
{
	return GetStr(m_nUrgPos);//紧急指针，从当前顺序号到紧急数据位置偏移量
}
CString CTCPPacket::GetOptLen()
{
	return GetStr(m_nOptLen);//选项长度
}
CString CTCPPacket::GetOptions()
{
	return GetStr(0,m_pOptions,false);//选项值
}
CString CTCPPacket::GetDataLen()
{
	return GetStr(m_nDataLen);//数据长度
}
CString CTCPPacket::GetData()
{
	return GetStr(0,m_pData,false);//数据值
}
CString CTCPPacket::GetStr(unsigned int nNum,unsigned char * pData,bool nFlag)
{
	CString str;
	if(nFlag)
		str.Format("%u",nNum);
	else
	{
		if(pData != NULL)
		  str.Format("%s",pData);
		else
		  str = "空";
	}
	return str;
}
CString CTCPPacket::GetBool(bool nFlag)
{
	if(nFlag)
		return "TRUE";
	return "FALSE";
}
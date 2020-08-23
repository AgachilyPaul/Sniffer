// UDPPacket.cpp: implementation of the CUDPPacket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CapturePacket.h"
#include "UDPPacket.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUDPPacket::CUDPPacket()
{

}

CUDPPacket::~CUDPPacket()
{
	if(m_pData != NULL)
		delete[] m_pData;
}

CUDPPacket::CUDPPacket(unsigned char *buf,int buflen)
{
	
	unsigned char *pos;

	pos=(unsigned char *)buf;
	m_uSrcPort = (*pos)*0x100+(*(pos+1));

	pos+=2;
	m_uDestPort = (*pos)*0x100+(*(pos+1));

	pos+=2;
	m_nTotalLen=(*pos)*0x100+(*(pos+1));

	pos+=2;
	m_nCheckSum=(*pos)*0x100+(*(pos+1));

	m_uDataLen=buflen-8;
	if(m_uDataLen > 0)
	{
		m_pData=new char[m_uDataLen];
		memcpy(m_pData,buf+8,m_uDataLen);
	}
	else
		m_pData=NULL;

}

CString CUDPPacket::GetDestPort()
{
	return GetInt(m_uDestPort);
}

CString CUDPPacket::GetSrcPort()
{
	return GetInt(m_uSrcPort);
}

CString	CUDPPacket::GetTotalLen()
{
	return GetInt(m_nTotalLen);	
}
CString	CUDPPacket::GetCheckSum()
{
	return GetInt(m_nCheckSum);
}
CString	CUDPPacket::GetDataLen()
{
	return GetInt(m_uDataLen);
}
CString CUDPPacket::GetData()
{
	return GetInt(0,m_pData,false);
}
CString	CUDPPacket::GetInt(int nNum,char *pData,bool nFlag)
{
	CString str;
	if(nFlag)
	  str.Format("%d",nNum);
	else
	{
		if(pData != NULL)
		  str.Format("%s",pData);
		else
		  str = "Пе";
	}
	return str;
}
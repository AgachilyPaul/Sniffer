// FramePacket.cpp: implementation of the CFramePacket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CapturePacket.h"
#include "FramePacket.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFramePacket::CFramePacket()
{

}

CFramePacket::~CFramePacket()
{

}

CFramePacket::CFramePacket(const unsigned char *buf,int buflen)
{
	//unsigned char *buf=new unsigned char[bufferlen];
	//int buflen=bufferlen;
	unsigned char *pPos;	
	pPos=(unsigned char *)buf;

	for(int i=0;i<6;i++)
	{
		m_nDestAddr[i] = *pPos;
		pPos++;
	}

	for(i=0;i<6;i++)
	{
		m_nSrcAddr[i] = *pPos;
		pPos++;
	}

	m_nType = (*pPos)*0x100+(*(pPos+1));
}

void CFramePacket::GetMacSrcAddr(char *str)
{
	sprintf(str,"%02X-%02X-%02X-%02X-%02X-%02X",m_nSrcAddr[0],m_nSrcAddr[1],m_nSrcAddr[2],m_nSrcAddr[3],m_nSrcAddr[4],m_nSrcAddr[5]);
}

CString CFramePacket::GetMacSrcAddr()
{
	CString str;
	str.Format("%02X-%02X-%02X-%02X-%02X-%02X",m_nSrcAddr[0],m_nSrcAddr[1],m_nSrcAddr[2],m_nSrcAddr[3],m_nSrcAddr[4],m_nSrcAddr[5]);
	return str;
}

void CFramePacket::GetMacDestAddr(char *str)
{
	sprintf(str,"%02X-%02X-%02X-%02X-%02X-%02X",m_nDestAddr[0],m_nDestAddr[1],m_nDestAddr[2],m_nDestAddr[3],m_nDestAddr[4],m_nDestAddr[5]);
}

CString CFramePacket::GetMacDestAddr()
{
	CString str;
	str.Format("%02X-%02X-%02X-%02X-%02X-%02X",m_nDestAddr[0],m_nDestAddr[1],m_nDestAddr[2],m_nDestAddr[3],m_nDestAddr[4],m_nDestAddr[5]);
	return str;
}

int CFramePacket::GetType()
{
	return m_nType;
}

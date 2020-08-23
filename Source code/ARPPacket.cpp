// ARPPacket.cpp: implementation of the CARPPacket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CapturePacket.h"
#include "ARPPacket.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CARPPacket::CARPPacket()
{

}

CARPPacket::~CARPPacket()
{

}
CARPPacket::CARPPacket(const unsigned char *buf,const unsigned int buflen)
{
	unsigned char *pos=(unsigned char *)buf;
	m_nHaddrtype=(*pos)*0x100+(*(pos+1));

	pos+=2;
	m_nPaddrtype=(*pos)*0x100+(*(pos+1));

	pos+=2;
	m_nHaddrlen=(*pos);

	pos++;
	m_nPaddrlen=(*pos);

	pos++;
	m_nOperation=(*pos)*0x100+(*(pos+1));

	pos+=2;
	for(int i=0;i<6;i++)
	{		
		m_cSHaddr[i]=BYTE(*pos);
		pos++;
	}

	m_nSPaddr=(*pos)*0x1000000+(*(pos+1))*0x10000+(*(pos+2))*0x100+(*(pos+3));

	pos+=4;
	for(i=0;i<6;i++)
	{
		m_cDHaddr[i]=BYTE(*pos);
		pos++;
	}

	m_nDPaddr=(*pos)*0x1000000+(*(pos+1))*0x10000+(*(pos+2))*0x100+(*(pos+3));
}

CString CARPPacket::GetSPAddr()
{
	CString str;
	unsigned char *p;

	p=(unsigned char *)&m_nSPaddr;
	str.Format("%003u.%003u.%003u.%003u",p[3],p[2],p[1],p[0]);
	return str;
}
CString CARPPacket::GetDPAddr()
{
	CString str;
	unsigned char *p;

	p=(unsigned char *)&m_nDPaddr;
	str.Format("%003u.%003u.%003u.%003u",p[3],p[2],p[1],p[0]);
	return str;
}

CString CARPPacket::GetHaddrtype()
{
	return GetData(m_nHaddrtype);//硬件地址类型 
}
CString CARPPacket::GetPaddrtype()
{
	return GetData(m_nPaddrtype);//协议地址类型
}
CString CARPPacket::GetHaddrlen()
{
	return GetData(m_nHaddrlen);//硬件地址长度
}
CString CARPPacket::GetPaddrlen()
{
	return GetData(m_nPaddrlen);//协议地址长度
}
CString CARPPacket::GetOperation()
{
	return GetData(m_nOperation);//操作类型
}
CString CARPPacket::GetSHaddr()
{
	return GetData(0,m_cSHaddr,false);//发送站点硬件地址
}
CString CARPPacket::GetDHaddr()
{
	return GetData(0,m_cDHaddr,false);//目的站点硬件地址
}
CString CARPPacket::GetData(int nNum,BYTE *pByte,bool bFlag)
{
	CString str;
	if( bFlag )
		str.Format("%d",nNum);
	else
	{
		if( pByte != NULL )
		  str.Format("%02X:%02X:%02X:%02X:%02X:%02X",pByte[0],pByte[1],pByte[2],pByte[3],pByte[4],pByte[5]);
		else
		  str = "空";
	}
	return str;
}
// IPPacket.cpp: implementation of the CIPPacket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CapturePacket.h"
#include "IPPacket.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIPPacket::CIPPacket()
{

}

CIPPacket::~CIPPacket()
{
	if(m_pData != NULL)
		delete[] m_pData;
	if(m_pOptions != NULL)
		delete[] m_pOptions;
}

//用于初始化IP头信息
CIPPacket::CIPPacket(const unsigned char *buf,int buflen)
{
	unsigned char *pos;
		
	pos=(unsigned char *)buf;
	m_nVersion=*pos/16;
	m_nHeaderLength = *pos%16;

	pos++;
	m_nServiceType=*pos;
	m_nPrecedence=(*pos & 16)*4+(*pos & 8)*2+(*pos & 4);
	if(*pos & 16)
		m_bDelay = true;
	else 
		m_bDelay = false;
	if(*pos & 8)
		m_bThroughtPut = true;
	else
		m_bThroughtPut = false;
	if(*pos & 4)
		m_bReliability = true;
	else
		m_bReliability = false;

	pos++;
	m_uTotalLength=(*pos)*256+(*(pos+1));

	pos+=2;
	m_nIdentification=(*pos)*256+(*(pos+1));

	pos+=2;
	if(*pos & 64)
		m_bDF=true;
	else
		m_bDF=false;
	if(*pos & 32)
		m_bMF=true;
	else
		m_bMF=false;
	m_nFragOffSet=(*pos%32)*256+(*(pos+1));

	pos+=2;
	m_nTTL = *pos;

	pos++;
	m_nProtocol = *pos;

	pos++;
	m_nCheckSum = (*pos)*256+(*(pos+1));

	pos+=2;
	m_lSrcIP = (*pos)*0x1000000+(*(pos+1))*0x10000+(*(pos+2))*0x100+(*(pos+3));

	pos+=4;
	m_lDestIP = (*pos)*0x1000000+(*(pos+1))*0x10000+(*(pos+2))*0x100+(*(pos+3));


	if(m_nHeaderLength > 5)
	{
		pos += 4;
		m_nOptLength=(m_nHeaderLength-5)*4;
		m_pOptions=new unsigned char[m_nOptLength];
		memcpy(m_pOptions,buf+20,m_nOptLength);
	}
	else
	{
		m_nOptLength = 0;
		m_pOptions = NULL;
	}
	
	pos=(unsigned char *)(buf+m_nHeaderLength*4);
	m_nDataLength = m_uTotalLength-m_nHeaderLength*4;
	if(m_nDataLength > 0)
	{
		m_pData=new unsigned char[m_nDataLength];
		memcpy(m_pData,buf+m_nHeaderLength*4,m_nDataLength);
	}
	else
		m_pData = NULL;
}
	
CString CIPPacket::GetProtocol()
{
	CString str;
	switch(m_nProtocol)
	{
		case 6:
			str.Format("TCP");break;
		case 17:
			str.Format("UDP");break;
		case 1:
			str.Format("ICMP");break;
		case 89:
			str.Format("OSPF");break;
		default:
			str.Format("%d",m_nProtocol);
	}
	return str;
}

CString CIPPacket::GetDestIP()
{
	CString str;
	int temp = m_lDestIP;
	unsigned char i0,i1,i2,i3;

	i0=(temp & 0xff000000)/0x1000000;
	i1=(temp & 0x00ff0000)/0x10000;
	i2=(temp & 0x0000ff00)/0x100;
	i3=temp & 0x000000ff;
	str.Format("%003u.%003u.%003u.%003u",i0,i1,i2,i3);

	return str;
}

CString CIPPacket::GetSrcIP()
{
	CString str;
	int temp=m_lSrcIP;
	unsigned char i0,i1,i2,i3;

	i0=(temp & 0xff000000)/0x1000000;
	i1=(temp & 0x00ff0000)/0x10000;
	i2=(temp & 0x0000ff00)/0x100;
	i3=temp & 0x000000ff;
	str.Format("%003u.%003u.%003u.%003u",i0,i1,i2,i3);

	return str;
}
unsigned char* CIPPacket::GetTData()
{
	if(m_pData != NULL)
		return m_pData;

	return NULL;
}

int	CIPPacket::GetDataLength()
{
	return m_nDataLength;
}

//得到版本号
CString	CIPPacket::GetVersion()
{
	return GetInt( m_nVersion );
}
//头部长度
CString  CIPPacket::GetHeaderLength()	
{
    return GetInt( m_nHeaderLength );
}

//服务类型 type of service
CString  CIPPacket::GetServiceType()
{
	return GetInt( m_nServiceType );
}

//优先级
CString  CIPPacket::GetPrecedence()
{
	return GetInt( m_nPrecedence );
}

//延迟
CString  CIPPacket::GetDelay()
{
	return GetBool( m_bDelay );
}

//吞吐量
CString  CIPPacket::GetThroughtPut()
{
	return GetBool( m_bThroughtPut );
}

//可靠性
CString  CIPPacket::GetReliability() 
{
	return GetBool( m_bReliability );
}

//总长total length
CString  CIPPacket::GetTotalLength()
{
	return GetInt( m_uTotalLength );
}

//标识
CString  CIPPacket::GetIdentification()
{
	return GetInt( m_nIdentification );
}
//不要分段
CString  CIPPacket::GetDF()
{
	return GetBool( m_bDF );
}

//还有进一步的分段
CString  CIPPacket::GetMF()
{
	return GetBool( m_bMF );
}

//分段偏移fragment offset
CString  CIPPacket::GetFragOffSet()
{	
	return GetInt( m_nFragOffSet );

}

//生命期time to live
CString  CIPPacket::GetTTL()
{
	return GetInt( m_nTTL );

}

//头部校验和
CString  CIPPacket::GetCheckSum()
{
	return GetInt( m_nCheckSum );

}	
//选项长度
CString  CIPPacket::GetOptLength()
{
	return GetInt( m_nOptLength );
}	

//选项内容
CString  CIPPacket::GetOptions()
{
	if( m_nOptLength > 0)
	{
		CString str;
		str.Format("%s",m_pOptions);
		return str;
	}

	return "空";
}

//数据长度
CString  CIPPacket::GetDLength()
{
	return GetInt( m_nDataLength );
}	
CString  CIPPacket::GetInt(int nNum)
{
	CString str;
	str.Format("%d",nNum);
	return str;
}
CString  CIPPacket::GetBool(bool nBool)
{
	if( nBool )
		return "TRUE";
	return "FALSE";
}

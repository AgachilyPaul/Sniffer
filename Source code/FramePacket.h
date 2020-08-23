// FramePacket.h: interface for the CFramePacket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FRAMEPACKET_H__CBB18FA8_0ABE_4B18_A6E6_6338112A95DF__INCLUDED_)
#define AFX_FRAMEPACKET_H__CBB18FA8_0ABE_4B18_A6E6_6338112A95DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//���ڴ�����·������
class CFramePacket  
{
public:
	CFramePacket();
	virtual ~CFramePacket();
	CFramePacket(const unsigned char *buf,int buflen);
	void		GetMacSrcAddr(char *str);
	CString		GetMacSrcAddr();
	void		GetMacDestAddr(char *str);
	CString		GetMacDestAddr();
	int			GetType();
private:
	int m_nSrcAddr[6];   //ԴMAC��ַ
	int m_nDestAddr[6];  //Ŀ��MAC��ַ
	int m_nType;         //����㱨������:IP,ARP,RARP

};

#endif // !defined(AFX_FRAMEPACKET_H__CBB18FA8_0ABE_4B18_A6E6_6338112A95DF__INCLUDED_)

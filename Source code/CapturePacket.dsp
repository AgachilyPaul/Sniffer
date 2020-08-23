# Microsoft Developer Studio Project File - Name="CapturePacket" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=CapturePacket - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CapturePacket.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CapturePacket.mak" CFG="CapturePacket - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CapturePacket - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 wpcap.lib /nologo /subsystem:windows /machine:I386
# Begin Target

# Name "CapturePacket - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AdapaterSelection.cpp
# End Source File
# Begin Source File

SOURCE=.\ARPPacket.cpp
# End Source File
# Begin Source File

SOURCE=.\CapturePacket.cpp
# End Source File
# Begin Source File

SOURCE=.\CapturePacket.rc
# End Source File
# Begin Source File

SOURCE=.\CapturePacketDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DirDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\FilterDl.cpp
# End Source File
# Begin Source File

SOURCE=.\FramePacket.cpp
# End Source File
# Begin Source File

SOURCE=.\ICMPPacket.cpp
# End Source File
# Begin Source File

SOURCE=.\IPPacket.cpp
# End Source File
# Begin Source File

SOURCE=.\OutputDataDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RARPPacket.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TCPPacket.cpp
# End Source File
# Begin Source File

SOURCE=.\TestDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\UDPPacket.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AdapaterSelection.h
# End Source File
# Begin Source File

SOURCE=.\ARPPacket.h
# End Source File
# Begin Source File

SOURCE=.\CapturePacket.h
# End Source File
# Begin Source File

SOURCE=.\CapturePacketDlg.h
# End Source File
# Begin Source File

SOURCE=.\DirDialog.h
# End Source File
# Begin Source File

SOURCE=.\FilterDl.h
# End Source File
# Begin Source File

SOURCE=.\FramePacket.h
# End Source File
# Begin Source File

SOURCE=.\ICMPPacket.h
# End Source File
# Begin Source File

SOURCE=.\IPPacket.h
# End Source File
# Begin Source File

SOURCE=.\OutputDataDlg.h
# End Source File
# Begin Source File

SOURCE=.\RARPPacket.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TCPPacket.h
# End Source File
# Begin Source File

SOURCE=.\TestDlg.h
# End Source File
# Begin Source File

SOURCE=.\UDPPacket.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\03.ico
# End Source File
# Begin Source File

SOURCE=.\res\16.ico
# End Source File
# Begin Source File

SOURCE=.\res\CapturePacket.ico
# End Source File
# Begin Source File

SOURCE=.\res\CapturePacket.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\app.manifest
# End Source File
# Begin Source File

SOURCE=.\res\GtBase.urf
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project

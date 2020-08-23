; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFilterDl
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CapturePacket.h"

ClassCount=7
Class1=CCapturePacketApp
Class2=CCapturePacketDlg
Class3=CAboutDlg

ResourceCount=8
Resource1=IDD_DIALOG_OUTPUTDATA
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG_NETWORKADAPTER
Resource4=IDD_CAPTUREPACKET_DIALOG
Class4=CAdapaterSelection
Class5=CDirDlg
Resource5=IDD_DIALOG_FILTER
Class6=COutputDataDlg
Resource6=IDD_ABOUTBOX
Resource7=IDR_MENU_MAIN
Class7=CFilterDl
Resource8=IDR_MENU_SYSTEMTRAY

[CLS:CCapturePacketApp]
Type=0
HeaderFile=CapturePacket.h
ImplementationFile=CapturePacket.cpp
Filter=N

[CLS:CCapturePacketDlg]
Type=0
HeaderFile=CapturePacketDlg.h
ImplementationFile=CapturePacketDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CCapturePacketDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=CapturePacketDlg.h
ImplementationFile=CapturePacketDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CAPTUREPACKET_DIALOG]
Type=1
Class=CCapturePacketDlg
ControlCount=19
Control1=IDC_LIST_PACKETINFO,SysListView32,1350631425
Control2=IDC_TREE_SINGERPACKET,SysTreeView32,1350631463
Control3=IDC_EDIT_PACKETHEX,edit,1353781444
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_UDPPACKETCOUNT,edit,1350633600
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_TCPPACKETCOUNT,edit,1350633600
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_ARPPACKETCOUNT,edit,1350633600
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT_OTHRERPACKETCOUNT,edit,1350633600
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT_TOTALPACKETCOUNT,edit,1350633600
Control15=IDC_STATIC,button,1342177287
Control16=IDC_EDIT_FILTER,edit,1353781444
Control17=IDC_BUTTON_FILTERTEST,button,1342242816
Control18=IDC_BUTTON_FILTERSAVE,button,1073807360
Control19=IDC_BUTTON_FILTERAPPLY,button,1342242816

[MNU:IDR_MENU_MAIN]
Type=1
Class=CCapturePacketDlg
Command1=ID_MENU_START
Command2=ID_MENU_STOP
Command3=ID_MENU_EXIT
Command4=ID_MENU_NETWORKCONFIGURATION
Command5=ID_MENU_DATAOUTPUT
Command6=ID_MENU_ABOUTAUTHOR
Command7=ID_MENU_HELPDOCUMENT
CommandCount=7

[DLG:IDD_DIALOG_NETWORKADAPTER]
Type=1
Class=CAdapaterSelection
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TREE_NETWORKADAPTERS,SysTreeView32,1350653967

[CLS:CAdapaterSelection]
Type=0
HeaderFile=AdapaterSelection.h
ImplementationFile=AdapaterSelection.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAdapaterSelection

[CLS:CDirDlg]
Type=0
HeaderFile=DirDlg.h
ImplementationFile=DirDlg.cpp
BaseClass=CFileDialog
Filter=D

[DLG:IDD_DIALOG_OUTPUTDATA]
Type=1
Class=COutputDataDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_FILENAME,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_DIRPATH,edit,1350633600
Control7=IDC_BUTTON_SELECTIONDIR,button,1342242816

[CLS:COutputDataDlg]
Type=0
HeaderFile=OutputDataDlg.h
ImplementationFile=OutputDataDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=COutputDataDlg

[DLG:IDD_DIALOG_FILTER]
Type=1
Class=CFilterDl
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TAB_CTR,SysTabControl32,1342182402

[MNU:IDR_MENU_SYSTEMTRAY]
Type=1
Class=?
Command1=IDR_MENU_STSHOW
Command2=IDR_MENU_STEXIT
CommandCount=2

[CLS:CFilterDl]
Type=0
HeaderFile=FilterDl.h
ImplementationFile=FilterDl.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_TAB_CTR


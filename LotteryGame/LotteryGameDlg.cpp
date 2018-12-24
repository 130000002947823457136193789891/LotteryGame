
// LotteryGameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LotteryGame.h"
#include "LotteryGameDlg.h"
#include "afxdialogex.h"
#include <cstdlib>
#include<stdlib.h>
#include <stdio.h>
#include <time.h>
#include<string>
#include<iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLotteryGameDlg 对话框



CLotteryGameDlg::CLotteryGameDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLotteryGameDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLotteryGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m1);
	DDX_Control(pDX, IDC_EDIT2, m2);
	DDX_Control(pDX, IDC_EDIT3, m3);
	DDX_Control(pDX, IDC_EDIT4, m4);
	DDX_Control(pDX, IDC_EDIT5, m5);
	DDX_Control(pDX, IDC_EDIT6, m6);
	DDX_Control(pDX, IDC_EDIT7, m7);
}

BEGIN_MESSAGE_MAP(CLotteryGameDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CLotteryGameDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CLotteryGameDlg 消息处理程序

BOOL CLotteryGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
			UpdateData (FALSE);
	CString s;
	//CWnd *pWnd;
	//pWnd=GetDlgItem(IDC_EDIT9);
//	UpdateData ();
	//CString a;
	//a=m_prize;
	CString a;
	 m1.SetWindowTextA(_T("A0"));
	 m2.SetWindowTextA(_T("A1"));
	 m3.SetWindowTextA(_T("A2"));
	 m4.SetWindowTextA(_T("A3"));
	 m5.SetWindowTextA(_T("A4"));
	 m6.SetWindowTextA(_T("A5"));
	 m7.SetWindowTextA(_T("A6"));


	//pWnd->SetWindowText(s);
		UpdateData (TRUE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLotteryGameDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLotteryGameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLotteryGameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLotteryGameDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
		CLotteryGameDlg  dlg;
	CString csx;
	m1.GetWindowText(csx);
	
	UpdateData (FALSE);
	//m1.SetWindowText(csx);
	//UpdateData ();
    const int size = 7;
	    string player[size];


	if(dlg.DoModal ()==IDOK)
	{
	AfxMessageBox ("hello welcome to lottery game!");
		
    char prize[size];       // 签号
      //存储游戏的最终结果
		int change[8][size];
	//m1.GetDlgItem (0);
       //二维数组 
	CString str1,str2,str3,str4,str5,str6,str7;	
((CEdit*)GetDlgItem(IDC_EDIT1))->GetWindowText(str1);

((CEdit*)GetDlgItem(IDC_EDIT2))->GetWindowText(str2);

((CEdit*)GetDlgItem(IDC_EDIT3))->GetWindowText(str3);

((CEdit*)GetDlgItem(IDC_EDIT4))->GetWindowText(str4);

((CEdit*)GetDlgItem(IDC_EDIT5))->GetWindowText(str5);

((CEdit*)GetDlgItem(IDC_EDIT6))->GetWindowText(str6);

((CEdit*)GetDlgItem(IDC_EDIT7))->GetWindowText(str7);
AfxMessageBox (str1);
AfxMessageBox (str2);
AfxMessageBox (str3);
AfxMessageBox (str4);
AfxMessageBox (str5);
AfxMessageBox (str6);
AfxMessageBox (str7);
CString s;
s=str1+str2+str3+str4+str5+str6+str7;
AfxMessageBox (s);

//一维数组prize[size]来记录size个签
	cout<<"please input player's order:"<<endl;

    for(int i=0; i<size; i++)
    {
        prize[i]=0;
		player[i]=i;
 
    }

	prize[2]=1;        //奖品、公差

	player[0]=str1;player[1]=str2;player[2]=str3;
	player[3]=str4;player[4]=str5;player[5]=str6;
	player[6]=str7;
	UpdateData ();
CString S;
S=str1+str2+str3+str4+str5+str6+str7;
//AfxMessageBox (S);
//抽签游戏的竖线和横线布局
//	cout<<"The setting of internal:"<<endl;
//	for(int i=0;i<8;i++)
//	{
//		for(int j=0;j<size;j++)
//		{
//			change[i][j]=0;
//		}
//	}
	change[0][1]=1;change[0][6]=1;change[1][1]=1;change[1][4]=1;change[2][0]=1;
	change[2][4]=1;change[3][0]=1;change[3][4]=1;change[4][3]=1;change[5][1]=1;
	change[5][4]=1;change[6][0]=1;change[7][1]=1;change[7][6]=1;



	//RandLayout
	static const int maxplayer=50;
	static const int minlevelnum=10;
	static const int maxlevelnum=20;
	int levelNum;
	int playerNum=7;
	srand((unsigned)time(0));
	levelNum=rand()%(maxlevelnum-minlevelnum)+
		minlevelnum;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<size;++j)
		{
			change[i][j]=rand()%2; 
		}
	}
	//AfxMessageBox (str1);
		string map[8][size+1];
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<size+1;j++)
		{
			if(1==change[i][j])
			{
				//cout<<"|---";
				map[i][j]="|---";
			}
			else
				//cout<<"|   ";
				map[i][j]="|    ";
		}
		//cout<<"|"<<endl;
		map[i][7]=="|";
	}
	string a1=map[0][0],a2=map[0][1],a3=map[0][2],a4=map[0][3],a5=map[0][4],a6=map[0][5],a7=map[0][6];
	string b1=map[1][0],b2=map[1][1],b3=map[1][2],b4=map[1][3],b5=map[1][4],b6=map[1][5],b7=map[1][6];
	string c1=map[2][0],c2=map[2][1],c3=map[2][2],c4=map[2][3],c5=map[2][4],c6=map[2][5],c7=map[2][6];
	string d1=map[3][0],d2=map[3][1],d3=map[3][2],d4=map[3][3],d5=map[3][4],d6=map[3][5],d7=map[3][5];
	string e1=map[4][0],e2=map[4][1],e3=map[4][2],e4=map[4][3],e5=map[4][4],e6=map[4][5],e7=map[4][6];
	string f1=map[5][0],f2=map[5][1],f3=map[5][2],f4=map[5][3],f5=map[5][4],f6=map[5][5],f7=map[5][6];
	string g1=map[6][0],g2=map[6][1],g3=map[6][2],g4=map[6][3],g5=map[6][4],g6=map[6][5],g7=map[6][6];
	string h1=map[7][0],h2=map[7][1],h3=map[7][2],h4=map[7][3],h5=map[7][4],h6=map[7][5],h7=map[7][6];
	a1=a1+a2+a3+a4+a5+a6+a7;
	b1=b1+b2+b3+b4+b5+b6+b7;
	c1=c1+c2+c3+c4+c5+c6+c7;
	d1=d1+d2+d3+d4+d5+d6+d7;
	e1=e1+e2+e3+e4+e5+e6+e7;
	f1=f1+f2+f3+f4+f5+f6+f7;
	g1=g1+g2+g3+g4+g5+g6+g7;
	h1=h1+h2+h3+h4+h5+h6+h7;
	string r=a1+"                                                                         "
		    +b1+"                                                                         "+
			 c1+"                                                                         "+
			 d1+"                                                                        "+
			 e1+"                                                                       "+
			 f1+"                                                                       "+
			 g1+"                                                                        "+
			 h1;
	CString cstr1(r.c_str());


	AfxMessageBox (cstr1);

//	change[7][8]={{0,1,0,0,0,1,0},{0,1,0,0,1,0,0},{1,0,0,0,1,0,0},{1,0,0,0,1,0,0,0},
//	{0,0,0,1,0,0,0},{0,1,0,0,1,0,0},{1,0,0,0,0,0,0},{0,1,0,0,0,1,0}};

//当碰到某一横线跨在
//第 i 条和第 i+1 条竖线上时，交换数据
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<size-1;j++)
		{
			if(change[i][j]==1)
			{
				string t;
				t=player[j];
				player[j]=player[j+1];
				player[j+1]=t;
				
			}
			
		}
	}
	string a,b,c,d,e,f,g;
	a=player[0];b=player[1];c=player[2];
	d=player[3];e=player[4];f=player[5];
	g=player[6];
	string h="奔驰，宝马，恶魔之眼，棕吕，g水，《白金数据》，kindle";
	a=a+"       "+b+"       "+c+"           "+d+"       "+e+"           "+f+"              "+g+"                  "+h;

	CString cstr(a.c_str());
	
	AfxMessageBox (cstr);




//游戏结束后，抽签者会一一对应到最下面一排的签号
//	cout<<"游戏结束后，抽签者会一一对应到最下面一排的签号"<<endl;
//  cout << "prize: ";
//    for(int i=0; i<size; i++)
//    cout << prize[i] << " ";
	
//	cout<<endl;
//    cout << "Player:";
//    for(int i=0; i<size; i++)
//    cout << player[i] << " ";

//	cout<<endl;

	//MessageBox::Show(player[6],"恭喜");
//			m1=player[0];m2=player[1];m3=player[2];
	//m4=player[3];m5=player[4];m6=player[5];
	//m7=player[6];
	//UpdateData (TRUE );
	//string i;
	//i=player[0];
	//CString str;
	//str.Format ("%s",i);

	//m_result.SetWindowTextA(str);
	//AfxMessageBox(str);

		//	CString str10;
	//str10="1元  1000元 500元  1万  50元  谢谢参与 谢谢参与 谢谢参与 ";
	//GetDlgItem(IDC_EDIT2)->SetWindowText(str10);
	//UpdateData ();
	//GetDlgItem(IDC_STATIC2)->SetWindowText("nihao");
	}

	//CString str;
	//str=player[0];
	//m1.SetWindowTextA(str);


//	StringBuffer buf = new StringBuffer() ;
//for(int i=0; i<a.length; i++) {
//buf.append(a[i]) ;
//}

	
	
	UpdateData(TRUE);
}


// LotteryGameDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CLotteryGameDlg �Ի���



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


// CLotteryGameDlg ��Ϣ�������

BOOL CLotteryGameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLotteryGameDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CLotteryGameDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLotteryGameDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		
    char prize[size];       // ǩ��
      //�洢��Ϸ�����ս��
		int change[8][size];
	//m1.GetDlgItem (0);
       //��ά���� 
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

//һά����prize[size]����¼size��ǩ
	cout<<"please input player's order:"<<endl;

    for(int i=0; i<size; i++)
    {
        prize[i]=0;
		player[i]=i;
 
    }

	prize[2]=1;        //��Ʒ������

	player[0]=str1;player[1]=str2;player[2]=str3;
	player[3]=str4;player[4]=str5;player[5]=str6;
	player[6]=str7;
	UpdateData ();
CString S;
S=str1+str2+str3+str4+str5+str6+str7;
//AfxMessageBox (S);
//��ǩ��Ϸ�����ߺͺ��߲���
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

//������ĳһ���߿���
//�� i ���͵� i+1 ��������ʱ����������
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
	string h="���ۣ�������ħ֮�ۣ�������gˮ�����׽����ݡ���kindle";
	a=a+"       "+b+"       "+c+"           "+d+"       "+e+"           "+f+"              "+g+"                  "+h;

	CString cstr(a.c_str());
	
	AfxMessageBox (cstr);




//��Ϸ�����󣬳�ǩ�߻�һһ��Ӧ��������һ�ŵ�ǩ��
//	cout<<"��Ϸ�����󣬳�ǩ�߻�һһ��Ӧ��������һ�ŵ�ǩ��"<<endl;
//  cout << "prize: ";
//    for(int i=0; i<size; i++)
//    cout << prize[i] << " ";
	
//	cout<<endl;
//    cout << "Player:";
//    for(int i=0; i<size; i++)
//    cout << player[i] << " ";

//	cout<<endl;

	//MessageBox::Show(player[6],"��ϲ");
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
	//str10="1Ԫ  1000Ԫ 500Ԫ  1��  50Ԫ  лл���� лл���� лл���� ";
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

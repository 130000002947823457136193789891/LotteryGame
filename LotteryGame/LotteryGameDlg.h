
// LotteryGameDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CLotteryGameDlg �Ի���
class CLotteryGameDlg : public CDialogEx
{
// ����
public:
	CLotteryGameDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LOTTERYGAME_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m1;
	CEdit m2;
	CEdit m3;
	CEdit m4;
	CEdit m5;
	CEdit m6;
	CEdit m7;
	afx_msg void OnBnClickedOk();
};

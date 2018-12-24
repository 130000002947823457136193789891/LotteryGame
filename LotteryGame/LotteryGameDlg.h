
// LotteryGameDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CLotteryGameDlg 对话框
class CLotteryGameDlg : public CDialogEx
{
// 构造
public:
	CLotteryGameDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LOTTERYGAME_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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

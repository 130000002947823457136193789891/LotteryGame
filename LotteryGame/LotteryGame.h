
// LotteryGame.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLotteryGameApp:
// �йش����ʵ�֣������ LotteryGame.cpp
//

class CLotteryGameApp : public CWinApp
{
public:
	CLotteryGameApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLotteryGameApp theApp;
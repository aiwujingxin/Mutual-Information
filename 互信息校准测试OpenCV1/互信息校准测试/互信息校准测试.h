
// ����ϢУ׼����.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C����ϢУ׼����App: 
// �йش����ʵ�֣������ ����ϢУ׼����.cpp
//

class C����ϢУ׼����App : public CWinApp
{
public:
	C����ϢУ׼����App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C����ϢУ׼����App theApp;
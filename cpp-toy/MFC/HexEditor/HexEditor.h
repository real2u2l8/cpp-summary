// HexEditor.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CHexEditorApp:
// �� Ŭ������ ������ ���ؼ��� HexEditor.cpp�� �����Ͻʽÿ�.
//

class CHexEditorApp : public CWinApp
{
public:
	CHexEditorApp();

// �������Դϴ�.
	public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CHexEditorApp theApp;
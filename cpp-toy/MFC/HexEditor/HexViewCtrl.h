#pragma once

// �ʿ��� ����� ���� include
#include <afxwin.h>     // MFC core
#include <afxcmn.h>     // MFC Windows common controls

class CHexViewCtrl
{
public:
	CHexViewCtrl(void);
	~CHexViewCtrl(void);

	void Initialize(CListCtrl* pListCtrl);
	void DisplayFile(const CString& strPath);
	void Clear();

private:
	// �÷� �ʱ�ȭ
	void InitializeColumns();
	void DisplayFileData(const BYTE* pBuffer, ULONGLONG ulFileSize);
	
	// ��� ����
	CListCtrl* m_pListCtrl;
	BYTE* m_pbyBuffer;
	ULONGLONG m_ulFileSize;
};

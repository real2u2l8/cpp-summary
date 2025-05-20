#pragma once

// 필요한 헤더만 직접 include
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
	// 컬럼 초기화
	void InitializeColumns();
	void DisplayFileData(const BYTE* pBuffer, ULONGLONG ulFileSize);
	
	// 멤버 변수
	CListCtrl* m_pListCtrl;
	BYTE* m_pbyBuffer;
	ULONGLONG m_ulFileSize;
};

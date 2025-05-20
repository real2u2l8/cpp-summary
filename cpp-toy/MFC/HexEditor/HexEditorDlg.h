// HexEditorDlg.h : ��� ����
//

#pragma once
#include "HexViewCtrl.h"

// CHexEditorDlg ��ȭ ����
class CHexEditorDlg : public CDialog
{
// �����Դϴ�.
public:
	CHexEditorDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HEXEDITOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;
	CHexViewCtrl m_hexView;  // 16���� �� ��Ʈ��

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonFopen();
};

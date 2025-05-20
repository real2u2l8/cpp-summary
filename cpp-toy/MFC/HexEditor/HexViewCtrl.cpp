#include "stdafx.h"
#include "HexViewCtrl.h"

CHexViewCtrl::CHexViewCtrl(void) : m_pListCtrl(NULL), m_pbyBuffer(NULL), m_ulFileSize(0)
{
}

CHexViewCtrl::~CHexViewCtrl(void)
{
    if (m_pbyBuffer)
        delete[] m_pbyBuffer;
}

void CHexViewCtrl::Initialize(CListCtrl* pListCtrl)
{
    m_pListCtrl = pListCtrl;
    
    // 리스트 컨트롤 스타일 수정
    DWORD dwExStyle = m_pListCtrl->GetExtendedStyle();
    dwExStyle |= LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_SUBITEMIMAGES;
    m_pListCtrl->SetExtendedStyle(dwExStyle);

    // 리스트 컨트롤 기본 스타일 수정
    DWORD dwStyle = ::GetWindowLong(m_pListCtrl->GetSafeHwnd(), GWL_STYLE);
    dwStyle &= ~LVS_TYPEMASK;
    dwStyle |= LVS_REPORT;
    ::SetWindowLong(m_pListCtrl->GetSafeHwnd(), GWL_STYLE, dwStyle);

    InitializeColumns();
}

void CHexViewCtrl::InitializeColumns()
{
    if (!m_pListCtrl) return;

    m_pListCtrl->SetExtendedStyle(m_pListCtrl->GetExtendedStyle() | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
    
    m_pListCtrl->InsertColumn(0, _T("Offset"), LVCFMT_LEFT, 80);
    for (int i = 0; i < 16; i++) {
        CString strCol;
        strCol.Format(_T("%02X"), i);
        m_pListCtrl->InsertColumn(i + 1, strCol, LVCFMT_CENTER, 30);
    }
}

void CHexViewCtrl::Clear()
{
    if (m_pListCtrl)
        m_pListCtrl->DeleteAllItems();
}

void CHexViewCtrl::DisplayFile(const CString& strPath)
{
    CFile file;
    if (!file.Open(strPath, CFile::modeRead))
    {
        AfxMessageBox(_T("파일을 열 수 없습니다."));
        return;
    }

    // 이전 버퍼 해제
    if (m_pbyBuffer)
        delete[] m_pbyBuffer;

    m_ulFileSize = file.GetLength();
    m_pbyBuffer = new BYTE[m_ulFileSize];
    file.Read(m_pbyBuffer, m_ulFileSize);
    file.Close();

    DisplayFileData(m_pbyBuffer, m_ulFileSize);
}

void CHexViewCtrl::DisplayFileData(const BYTE* pBuffer, ULONGLONG ulFileSize)
{
    if (!m_pListCtrl || !pBuffer) return;

    Clear();
    
    for (ULONGLONG ulOffset = 0; ulOffset < ulFileSize; ulOffset += 16)
    {
        CString strOffset;
        strOffset.Format(_T("%08llX"), ulOffset);
        int nItem = m_pListCtrl->InsertItem(m_pListCtrl->GetItemCount(), strOffset);

        for (int nCol = 0; nCol < 16; nCol++) {
            if (ulOffset + nCol < ulFileSize) {
                CString strHex;
                strHex.Format(_T("%02X"), pBuffer[ulOffset + nCol]);
                m_pListCtrl->SetItemText(nItem, nCol + 1, strHex);
            }
        }
    }
}


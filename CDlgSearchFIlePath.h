#pragma once
#include "afxdialogex.h"
#include "StructStu.h"


// CDlgSearchFIlePath 对话框

class CDlgSearchFIlePath : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSearchFIlePath)

public:
	CDlgSearchFIlePath(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgSearchFIlePath();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SEARCH_PATH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTvnSelchangedMfcshelltree1(NMHDR* pNMHDR, LRESULT* pResult);
	CMFCShellTreeCtrl m_shelltree;
	CMFCShellListCtrl m_shelllist;
	afx_msg void OnLvnItemchangedMfcshelllist_lujing(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMClickMfcshelllist_lujing(NMHDR* pNMHDR, LRESULT* pResult);
	CString m_strFilePath;
	CString fileName;
};

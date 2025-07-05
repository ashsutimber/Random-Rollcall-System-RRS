#pragma once
#include "afxdialogex.h"


// m_CDlgSaveYesOrNo 对话框

class m_CDlgSaveYesOrNo : public CDialogEx
{
	DECLARE_DYNAMIC(m_CDlgSaveYesOrNo)

public:
	m_CDlgSaveYesOrNo(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~m_CDlgSaveYesOrNo();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_YES_NO_SAVE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};

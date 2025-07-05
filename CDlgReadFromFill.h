#pragma once
#include "afxdialogex.h"
#include"CDlgSearchFIlePath.h"
#include "StructStu.h"


// CDlgReadFromFill 对话框

class CDlgReadFromFill : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgReadFromFill)

public:
	CDlgReadFromFill(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgReadFromFill();
	linklist head, tail;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_READ_FROM_FILL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
private:
	CDlgSearchFIlePath ReadFilePath;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSearchFill();
	CString m_strReadFileName;
	afx_msg void OnBnClickedButtonReadfile();
	void MyStringToChar(CString str, char* pc);
};

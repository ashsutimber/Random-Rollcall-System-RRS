#pragma once
#include "afxdialogex.h"
#include "StructStu.h"
#include"CDlgReadFromFill.h"

// CDlgLoadFromFill 对话框

class CDlgDataInport : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgDataInport)

public:
	CDlgDataInport(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgDataInport();
	linklist m_lHead, m_lTail;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DATA_INPORT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
private:
	CDlgReadFromFill m_CDlgRead;


public:
	afx_msg void OnBnClickedLoadFromFill();
	afx_msg void OnBnClickedBuildNewData();

	CString m_strFIleNameAndRoad;

};

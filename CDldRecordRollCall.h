#pragma once
#include "afxdialogex.h"
#include "StructStu.h"


// CDldRecordRollCall 对话框

class CDlgRecordRollCall : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgRecordRollCall)

public:
	CDlgRecordRollCall(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgRecordRollCall();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_RECORD_ROLL_CALL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLeave();
	afx_msg void OnBnClickedNo();
	afx_msg void OnBnClickedYes();
	linklist m_selectedNode;
	CString m_strDianDaoStu;
	CString IsPresent;
	void MyStringToChar(CString str, char* pc);
	int flagshifou;
};

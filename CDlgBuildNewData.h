#pragma once
#include "afxdialogex.h"
#include"CDlgSearchFIlePath.h"
#include "StructStu.h"

// CDlgBuildNewData 对话框



class CDlgBuildNewData : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgBuildNewData)
	linklist head, tail;

public:
	CDlgBuildNewData(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgBuildNewData();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BUILD_NEW_DATA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持private:
private:
	CDlgSearchFIlePath SearchPath;

	DECLARE_MESSAGE_MAP()
public:
	//注意注意注意注意
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButtonInsertList();
	//afx_msg void OnLbnSelchangeListNewList();
	void Display();
	CString m_strName;
	CListBox m_ListDisplay;
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonSearchFileRoad();
	CString strFileName;
	CString strFilePath;
	afx_msg void OnLbnSelchangeListNewList();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonLinkFree();
	void MyStringToChar(CString str, char* pc);
	afx_msg void OnBnClickedButtonReadfile();
	afx_msg void OnEnChangeEditSaveFileRoad();
	afx_msg void OnEnChangeEditSaveFileName();
	afx_msg void OnEnChangeEditAddName();
};

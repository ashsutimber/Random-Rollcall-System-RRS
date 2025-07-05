
// RandomRollCallSystemDlg.h: 头文件
//

#pragma once
#include"StructStu.h"
#include"CDlgLoadFromFill.h"

// CRandomRollCallSystemDlg 对话框
class CRandomRollCallSystemDlg : public CDialogEx
{
// 构造
public:
	CRandomRollCallSystemDlg(CWnd* pParent = nullptr);	// 标准构造函数
	linklist head_mingdan, tail_mingdan;
	linklist head_diandao, tail_diandao;
	linklist head_Yidian, tail_Yidian;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RANDOMROLLCALLSYSTEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CDlgDataInport m_DlgData;

public:
	int m_irenshu;
	afx_msg void OnBnClickedButtonInportData();
	afx_msg void OnLbnSelchangeRollCallMen();
	afx_msg void OnBnClickedButtonRecordRollCall();
	CListBox RollCallStu;
	afx_msg void OnBnClickedButtonReadList();
	void SaveTemporaryFile();
	void Display();
	CListBox m_CLBstuList;
	afx_msg void OnLbnSelchangeStudentList();
	afx_msg void OnBnClickedButtonRollCall();
	void DisplayDianDao();
	void DisPlayResult();
	afx_msg void OnDestroy();
	void OpenFile(CString FileName);
	void SaveTempraryYiDianFile();
	int IsPresent;
	afx_msg void OnBnClickedButtonSaveData();
	afx_msg void OnBnClickedButtonReadRollCallList();
	afx_msg void OnBnClickedButtonReadAttendance();
	CString m_strDianDaoListFile;
	void MyStringToChar(CString str, char* pc);
	linklist LinkCat();
	int hadRollCalled;
	int SaveDianDaoFile();
	CListCtrl m_CLBRollCallResult;
	afx_msg void OnLvnItemchangedListDiandaoqingkuang(NMHDR* pNMHDR, LRESULT* pResult);
};

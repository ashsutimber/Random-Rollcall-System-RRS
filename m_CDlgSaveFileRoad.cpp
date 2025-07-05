// m_CDlgSaveFileRoad.cpp: 实现文件
//

#include "pch.h"
#include "RandomRollCallSystem.h"
#include "afxdialogex.h"
#include "CDlgSearchFIlePath.h"


// m_CDlgSaveFileRoad 对话框

IMPLEMENT_DYNAMIC(CDlgSaveFileRoad, CDialogEx)

CDlgSaveFileRoad::CDlgSaveFileRoad(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SAVE_FILE_ROAD, pParent)
	, strFileName(_T(""))
	, strFilePath(_T(""))
{

}

CDlgSaveFileRoad::~CDlgSaveFileRoad()
{
}

void CDlgSaveFileRoad::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SAVE_FILE_NAME, strFileName);
	DDX_Text(pDX, IDC_EDIT_SAVE_FILE_ROAD, strFilePath);
}


BEGIN_MESSAGE_MAP(CDlgSaveFileRoad, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_SAVE_FILE_NAME, &CDlgSaveFileRoad::OnEnChangeEditSaveFileName)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH_FILE_ROAD, &CDlgSaveFileRoad::OnBnClickedButtonSearchFileRoad)
	ON_EN_CHANGE(IDC_EDIT_SAVE_FILE_ROAD, &CDlgSaveFileRoad::OnEnChangeEditSaveFileRoad)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE_PATH, &CDlgSaveFileRoad::OnBnClickedButtonChangePath)
END_MESSAGE_MAP()


// m_CDlgSaveFileRoad 消息处理程序


void CDlgSaveFileRoad::OnEnChangeEditSaveFileName()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CDlgSaveFileRoad::OnBnClickedButtonSearchFileRoad()
{
	SearchPath.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void CDlgSaveFileRoad::OnEnChangeEditSaveFileRoad()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}




void CDlgSaveFileRoad::OnBnClickedButtonChangePath()
{

	strFilePath=SearchPath.m_strFilePath;
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}

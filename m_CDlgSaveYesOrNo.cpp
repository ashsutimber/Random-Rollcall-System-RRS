// m_CDlgSaveYesOrNo.cpp: 实现文件
//

#include "pch.h"
#include "RandomRollCallSystem.h"
#include "afxdialogex.h"
#include "m_CDlgSaveYesOrNo.h"


// m_CDlgSaveYesOrNo 对话框

IMPLEMENT_DYNAMIC(m_CDlgSaveYesOrNo, CDialogEx)

m_CDlgSaveYesOrNo::m_CDlgSaveYesOrNo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_YES_NO_SAVE, pParent)
{

}

m_CDlgSaveYesOrNo::~m_CDlgSaveYesOrNo()
{
}

void m_CDlgSaveYesOrNo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(m_CDlgSaveYesOrNo, CDialogEx)
END_MESSAGE_MAP()


// m_CDlgSaveYesOrNo 消息处理程序

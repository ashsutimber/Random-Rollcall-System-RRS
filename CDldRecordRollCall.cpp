// CDldRecordRollCall.cpp: 实现文件
//

#include "pch.h"
#include "RandomRollCallSystem.h"
#include "afxdialogex.h"
#include "CDldRecordRollCall.h"

// CDldRecordRollCall 对话框

IMPLEMENT_DYNAMIC(CDlgRecordRollCall, CDialogEx)

CDlgRecordRollCall::CDlgRecordRollCall(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_RECORD_ROLL_CALL, pParent)
	, m_strDianDaoStu(_T(""))
{
	flagshifou = 0;
	m_selectedNode = NULL;
}

CDlgRecordRollCall::~CDlgRecordRollCall()
{
}

void CDlgRecordRollCall::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ROLL_CALL_NAME, m_strDianDaoStu);
}


BEGIN_MESSAGE_MAP(CDlgRecordRollCall, CDialogEx)
	ON_BN_CLICKED(LEAVE, &CDlgRecordRollCall::OnBnClickedLeave)
	ON_BN_CLICKED(NO, &CDlgRecordRollCall::OnBnClickedNo)
	ON_BN_CLICKED(YES, &CDlgRecordRollCall::OnBnClickedYes)
END_MESSAGE_MAP()


// CDldRecordRollCall 消息处理程序



void CDlgRecordRollCall::OnBnClickedLeave()
{
	flagshifou = 1;
	if (m_selectedNode != nullptr)
	{
		m_selectedNode->stuData.countqingjia++; // 增加请假次数
		IsPresent=_T("请假");
		MyStringToChar(IsPresent, m_selectedNode->stuData.isPresent);
		//MessageBox(_T("已记录请假"), _T("提示"), MB_ICONINFORMATION);
	}
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CDlgRecordRollCall::OnBnClickedNo()
{
	flagshifou = 1;

	if (m_selectedNode != nullptr)
	{
		m_selectedNode->stuData.countQuedao++; // 增加缺到次数
		IsPresent = _T("缺勤");
		MyStringToChar(IsPresent, m_selectedNode->stuData.isPresent);
		//MessageBox(_T("已记录缺勤"), _T("提示"), MB_ICONINFORMATION);
	}

	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CDlgRecordRollCall::OnBnClickedYes()
{
	flagshifou = 1;

	if (m_selectedNode != nullptr)
	{
		// 按时到课不需要特别记录，可以在这里添加其他逻辑
		IsPresent = _T("按时到课");
		MyStringToChar(IsPresent, m_selectedNode->stuData.isPresent);
		//MessageBox(_T("已记录按时到课"), _T("提示"), MB_ICONINFORMATION);
	}

	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CDlgRecordRollCall::MyStringToChar(CString str, char* pc)
{	// 使用 WideCharToMultiByte 正确处理Unicode转换
	int len = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	if (len >= 256) len = 255;

	WideCharToMultiByte(CP_ACP, 0, str, -1, pc, len, NULL, NULL);
	pc[len] = '\0';

	TRACE(_T("转换结果：%hs\n"), pc);

	// TODO: 在此处添加实现代码.
}

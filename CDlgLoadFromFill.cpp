// CDlgLoadFromFill.cpp: 实现文件
//

#include "pch.h"
#include "RandomRollCallSystem.h"
#include "afxdialogex.h"
#include "CDlgLoadFromFill.h"
#include "CDlgBuildNewData.h"
#include "CDlgReadFromFill.h"
#include "StructStu.h"


// CDlgLoadFromFill 对话框

IMPLEMENT_DYNAMIC(CDlgDataInport, CDialogEx)

CDlgDataInport::CDlgDataInport(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DATA_INPORT, pParent)
{
	m_lHead= m_lTail=NULL;
}

CDlgDataInport::~CDlgDataInport()
{
}

void CDlgDataInport::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgDataInport, CDialogEx)
	ON_BN_CLICKED(ID_LOAD_FROM_FILL, &CDlgDataInport::OnBnClickedLoadFromFill)
	ON_BN_CLICKED(ID_BUILD_NEW_DATA, &CDlgDataInport::OnBnClickedBuildNewData)
END_MESSAGE_MAP()


// CDlgLoadFromFill 消息处理程序


void CDlgDataInport::OnBnClickedLoadFromFill()
{
	m_CDlgRead.DoModal();
	m_lHead = m_CDlgRead.head;
	m_lTail = m_CDlgRead.tail;
	m_strFIleNameAndRoad = m_CDlgRead.m_strReadFileName;
	PathRemoveExtension(m_strFIleNameAndRoad.GetBuffer());//删除后缀便于保存
	m_strFIleNameAndRoad.ReleaseBuffer();
	UpdateData(FALSE);
//	MessageBox(m_strFIleNameAndRoad);
	CDialogEx::OnCancel();
	// TODO: 在此添加控件通知处理程序代码
}
void CDlgDataInport::OnBnClickedBuildNewData()
{
	CDlgBuildNewData m_CDlgBuild;
	m_CDlgBuild.DoModal();
	m_lHead = m_CDlgBuild.head;
	m_lTail = m_CDlgBuild.tail;
	m_strFIleNameAndRoad = m_CDlgBuild.strFilePath + "\\" + m_CDlgBuild.strFileName;
	//MessageBox(m_strFIleNameAndRoad);
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


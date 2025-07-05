// CDlgSearchFIlePath.cpp: 实现文件
//

#include "pch.h"
#include "RandomRollCallSystem.h"
#include "afxdialogex.h"
#include "CDlgSearchFIlePath.h"


// CDlgSearchFIlePath 对话框

IMPLEMENT_DYNAMIC(CDlgSearchFIlePath, CDialogEx)

CDlgSearchFIlePath::CDlgSearchFIlePath(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SEARCH_PATH, pParent)
{

}

CDlgSearchFIlePath::~CDlgSearchFIlePath()
{
}

void CDlgSearchFIlePath::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCSHELLTREE1, m_shelltree);
	DDX_Control(pDX, IDC_MFCSHELLLIST1, m_shelllist);
}


BEGIN_MESSAGE_MAP(CDlgSearchFIlePath, CDialogEx)
	ON_NOTIFY(TVN_SELCHANGED, IDC_MFCSHELLTREE1, &CDlgSearchFIlePath::OnTvnSelchangedMfcshelltree1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_MFCSHELLLIST1, &CDlgSearchFIlePath::OnLvnItemchangedMfcshelllist_lujing)
	ON_NOTIFY(NM_CLICK, IDC_MFCSHELLLIST1, &CDlgSearchFIlePath::OnNMClickMfcshelllist_lujing)
END_MESSAGE_MAP()


// CDlgSearchFIlePath 消息处理程序

//
void CDlgSearchFIlePath::OnTvnSelchangedMfcshelltree1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	CString str_path;
	//将shelltree上选中的路径在shelllist上展示
	m_shelltree.GetItemPath (str_path, pNMTreeView->itemNew.hItem);
	//MessageBox(str_path);
	m_shelllist.DisplayFolder(str_path);
	*pResult = 0;
}

void CDlgSearchFIlePath::OnLvnItemchangedMfcshelllist_lujing(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CDlgSearchFIlePath::OnNMClickMfcshelllist_lujing(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	for (int i = 0; i < m_shelllist.GetItemCount(); i++) {
		if (m_shelllist.GetItemState(i, LVIS_SELECTED) == LVIS_SELECTED) {
			m_shelllist.GetItemPath(fileName, i);
			//MessageBox(fileName);
			m_strFilePath = fileName;

			MessageBox(_T("已选中") + m_strFilePath + _T("。"));
			CDialogEx::OnCancel();
		}
	}
	*pResult = 0;
}

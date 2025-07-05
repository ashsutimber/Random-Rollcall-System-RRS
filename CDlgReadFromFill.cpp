// CDlgReadFromFill.cpp: 实现文件
//

#include "pch.h"
#include "RandomRollCallSystem.h"
#include "afxdialogex.h"
#include "CDlgReadFromFill.h"
#include "CDlgSearchFIlePath.h"


// CDlgReadFromFill 对话框

IMPLEMENT_DYNAMIC(CDlgReadFromFill, CDialogEx)

CDlgReadFromFill::CDlgReadFromFill(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_READ_FROM_FILL, pParent)
	, m_strReadFileName(_T(""))
{
	head = tail = NULL;

}

CDlgReadFromFill::~CDlgReadFromFill()
{
}

void CDlgReadFromFill::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FILENAME, m_strReadFileName);
}


BEGIN_MESSAGE_MAP(CDlgReadFromFill, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH_FILL, &CDlgReadFromFill::OnBnClickedButtonSearchFill)
	ON_BN_CLICKED(IDC_BUTTON_READFILE, &CDlgReadFromFill::OnBnClickedButtonReadfile)
END_MESSAGE_MAP()


// CDlgReadFromFill 消息处理程序




void CDlgReadFromFill::OnBnClickedButtonSearchFill()
{
	ReadFilePath.DoModal(); 
	m_strReadFileName = ReadFilePath.m_strFilePath;
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}



void CDlgReadFromFill::OnBnClickedButtonReadfile()
{
	head = tail = NULL;
	int i, count = 0;
	stuinfo nodedata;
	linklist newStudent;
	char FileName[100];
	FILE* fp;
	fp = NULL;
	MyStringToChar(m_strReadFileName, FileName);
	fopen_s(&fp,FileName , "rb");//r为打开
	if (!fp)
	{
		MessageBox(_T("打开文件"+m_strReadFileName+"失败"), _T("提示"), MB_ICONERROR);
		return;
	}
	fread(&count, sizeof(int), 1, fp);
	for (i = 1; i <= count; i++)
	{
		newStudent = (linklist)malloc(sizeof(linknode));
		fread(&nodedata, sizeof(stuinfo), 1, fp);
		UpdateData(TRUE);
		newStudent->stuData = nodedata;
		newStudent->next = NULL;
		if (!head)head = tail = newStudent;
		else 
		{
			tail->next = newStudent;
			tail = newStudent;
		}
	}
	fclose(fp);
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}




void CDlgReadFromFill::MyStringToChar(CString str, char* pc)
{	// 使用 WideCharToMultiByte 正确处理Unicode转换
	int len = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	if (len >= 256) len = 255;

	WideCharToMultiByte(CP_ACP, 0, str, -1, pc, len, NULL, NULL);
	pc[len] = '\0';

	TRACE(_T("转换结果：%hs\n"), pc);

	// TODO: 在此处添加实现代码.
}

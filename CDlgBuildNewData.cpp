// CDlgBuildNewData.cpp: 实现文件
//

#include "pch.h"
#include "RandomRollCallSystem.h"
#include "afxdialogex.h"
#include "CDlgBuildNewData.h"
#include "StructStu.h"


// CDlgBuildNewData 对话框

IMPLEMENT_DYNAMIC(CDlgBuildNewData, CDialogEx)

CDlgBuildNewData::CDlgBuildNewData(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_BUILD_NEW_DATA, pParent)
	
	, strFileName(_T(""))
	, strFilePath(_T(""))
{
	head = tail = NULL;  // 初始化指针
}

CDlgBuildNewData::~CDlgBuildNewData()
{
	// 清理链表内存
}

void CDlgBuildNewData::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_ADD_NAME, m_strName);
	DDX_Control(pDX, IDC_LIST_NEW_LIST, m_ListDisplay);
	DDX_Text(pDX, IDC_EDIT_SAVE_FILE_NAME, strFileName);
	DDX_Text(pDX, IDC_EDIT_SAVE_FILE_ROAD, strFilePath);
}


BEGIN_MESSAGE_MAP(CDlgBuildNewData, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_INSERT_LIST, &CDlgBuildNewData::OnBnClickedButtonInsertList)
	//ON_LBN_SELCHANGE(IDC_LIST_NEW_LIST, &CDlgBuildNewData::OnLbnSelchangeListNewList)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CDlgBuildNewData::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH_FILE_ROAD, &CDlgBuildNewData::OnBnClickedButtonSearchFileRoad)
	ON_LBN_SELCHANGE(IDC_LIST_NEW_LIST, &CDlgBuildNewData::OnLbnSelchangeListNewList)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CDlgBuildNewData::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_LINK_FREE, &CDlgBuildNewData::OnBnClickedButtonLinkFree)
	ON_BN_CLICKED(IDC_BUTTON_READFILE, &CDlgBuildNewData::OnBnClickedButtonReadfile)
	ON_EN_CHANGE(IDC_EDIT_SAVE_FILE_ROAD, &CDlgBuildNewData::OnEnChangeEditSaveFileRoad)
	ON_EN_CHANGE(IDC_EDIT_SAVE_FILE_NAME, &CDlgBuildNewData::OnEnChangeEditSaveFileName)
	ON_EN_CHANGE(IDC_EDIT_ADD_NAME, &CDlgBuildNewData::OnEnChangeEditAddName)
END_MESSAGE_MAP()


// CDlgBuildNewData 消息处理程序


//void CDlgBuildNewData::OnBnClickedOk()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	CDialogEx::OnOK();
//}
//
//
//void CDlgBuildNewData::OnBnClickedCancel()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	CDialogEx::OnCancel();
//}


void CDlgBuildNewData::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CDlgBuildNewData::OnBnClickedButtonInsertList()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);  // 从控件获取数据
	TRACE(_T("输入的名称：%s\n"), m_strName); // 确认输入正确

	if (m_strName.IsEmpty())
	{
		AfxMessageBox(_T("请输入名称"));
		return;
	}

	linklist q = (linklist)malloc(sizeof(linknode));
	if (!q)
	{
		AfxMessageBox(_T("内存分配失败"));
		return;
	}

	MyStringToChar(m_strName, q->stuData.name);//将CString类型改为C语言风格的char*型，并放入stuData.q->name
	q->stuData.countqingjia = 0;
	q->stuData.countQuedao = 0;
	q->next = NULL;

	if (head == NULL)
		head = tail = q;
	else
	{
		tail->next = q;
		tail = q;
	}

	// 调试输出：打印链表当前内容
	//TRACE(_T("插入后的链表内容：\n"));
	//linklist p = head;
	//while (p) {
	//	TRACE(_T("%s\n"), CString(p->stuData.name));
	//	p = p->next;
	//}
	Display();
	m_strName.Empty();  // 清空输入框
	UpdateData(FALSE);  // 更新控件显示
	//// 添加列表框项数检查
	//int nCount = m_ListDisplay.GetCount();
	//TRACE(_T("列表框当前项数：%d\n"), nCount);
}





void CDlgBuildNewData::Display()
{
	// TODO: 在此处添加实现代码.
	m_ListDisplay.ResetContent();
	linklist p = head;
	int index = 0;
	CString strTemp;
	if (!p)return;
	while (p)
	{
		strTemp.Format(_T("%s"), CString(p->stuData.name));
		m_ListDisplay.InsertString(index, strTemp);
		index++;
		p = p->next;        //指向下一个结点
	}
}


//void CDlgBuildNewData::OnLbnSelchangeListNewList()
//{
//	// 1. 获取当前选中的列表项索引
//	int nSelectedIndex = m_ListDisplay.GetCurSel();
//
//	// 2. 检查是否有效选中
//	if (nSelectedIndex != LB_ERR)
//	{
//		CString strSelectedText;
//		m_ListDisplay.GetText(nSelectedIndex, strSelectedText);
//
//		// 3. 可以在这里添加处理逻辑（例如显示选中内容）
//		AfxMessageBox(_T("选中项: ") + strSelectedText);
//	}
//}

void CDlgBuildNewData::OnBnClickedButtonSave()
{
	int tag = 0;
	linklist p = head;
	if (!p)
	{
		MessageBox(_T("链表为空，保存文件失败"), _T("提示"),MB_ICONERROR);
		return;
	}
	UpdateData(TRUE);
	// TODO: 在此添加控件通知处理程序代码// 检查文件名和路径是否为空
	if (strFilePath.IsEmpty())
	{
		AfxMessageBox(_T("保存路径不能为空"));
		return;
	}
	if (strFileName.IsEmpty())
	{
		AfxMessageBox(_T("文件名不能为空"));
		return;
	}

	// 构造完整的文件路径
	CString strTxtFilePath = strFilePath + _T("\\") + strFileName + _T(".txt");
	CString strDatFilePath = strFilePath + _T("\\") + strFileName + _T(".dat");
	FILE* fp;
	char FilePathtxt[100];
	char FilePathdat[100];
	//将txtFilepath转变为char*型文件
	MyStringToChar(strTxtFilePath, FilePathtxt);
	MyStringToChar(strDatFilePath, FilePathdat);
	// 打开.txt文件用于写入
	fopen_s(&fp, FilePathtxt, "w");

	if (!fp)
	{
		MessageBox(_T("无法创建.txt文件，请检查选中的路径。"), _T("提示"), MB_ICONINFORMATION);
		return;
	}
	fprintf(fp, "点到情况如下（此文件仅用于查看，请勿在此文件中修改信息）：\n\n\n");
	while (p) {
		tag++;
		fprintf(fp, "%d、%s              缺到次数：%d； 请假次数：%d\n\n",tag, p->stuData.name, p->stuData.countQuedao, p->stuData.countqingjia);
		p = p->next;
	}
	fclose(fp);

	MessageBox(_T("保存文件成功,保存为文件"+ strTxtFilePath), _T("提示"), MB_ICONINFORMATION);

	int count = 0;
	p = head;
	fp = NULL;
	fopen_s(&fp, FilePathdat, "wb");//wb为写二进制文件
	if (!fp)
	{
		MessageBox(_T("无法创建.dat文件，请检查选中的路径。"), _T("提示"), MB_ICONINFORMATION);
		return;
	}
	//统计节点数//////////////////////////////////////////////

	while (p)
	{
		count++;
		p = p->next;
	}
	fwrite(&count, sizeof(int), 1, fp);//1是写入的数量，sizeof是该量的大小

	p = head;
	//保存数据文件
	while (p) {
		fwrite(&p->stuData, sizeof(stuinfo), 1, fp);
		p = p->next;
	}
	fclose(fp);

	MessageBox(_T("保存文件成功,保存为文件"+ strDatFilePath), _T("提示"), MB_ICONINFORMATION);
	CDialogEx::OnCancel();

}



void CDlgBuildNewData::OnBnClickedButtonSearchFileRoad()
{
	SearchPath.DoModal();
	strFilePath = SearchPath.m_strFilePath;
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CDlgBuildNewData::OnLbnSelchangeListNewList()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDlgBuildNewData::OnBnClickedButtonDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = m_ListDisplay.GetCurSel();		//m_ListDisplay为列表变量名称
	if (index < 0)return;

	linklist pre, p;
	pre = NULL;
	p = head;
	int count = 0;
	while (p && count < index)     //查找第一个值为x的结点，并用pre保存其前驱位置
	{
		pre = p;
		p = p->next;
		count++;
	}
	if (pre == NULL)              //情况（1）：被删除结点是链表的第一个结点
		head = head->next;
	else if (p == tail) {
		tail = pre;
		pre->next = p->next;
	}
	else                        //情况（2）：被删除结点不是链表的第一个结点
		pre->next = p->next;
		free(p);                    //释放p结点空间

	Display();
	// TODO: 在此添加控件通知处理程序代码
}


void CDlgBuildNewData::OnBnClickedButtonLinkFree()
{

	linklist p;
	while (head)
	{
		p = head;
		head = head->next;
		free(p);

	}Display();
	// TODO: 在此添加控件通知处理程序代码
}


void CDlgBuildNewData::MyStringToChar(CString str, char* pc)
{	// 使用 WideCharToMultiByte 正确处理Unicode转换
	int len = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	if (len >= 256) len = 255;

	WideCharToMultiByte(CP_ACP, 0, str, -1, pc, len, NULL, NULL);
	pc[len] = '\0';

	TRACE(_T("转换结果：%hs\n"), pc);

	// TODO: 在此处添加实现代码.
}


void CDlgBuildNewData::OnBnClickedButtonReadfile()
{

	SearchPath.DoModal();
	strFilePath = SearchPath.m_strFilePath;
	PathRemoveFileSpec(strFilePath.GetBuffer());
	strFileName = SearchPath.fileName;	
	strFileName = PathFindFileName(strFileName);//通过PathfindFileName获得含后缀的文件名
	PathRemoveExtension(strFileName.GetBuffer());
	UpdateData(FALSE);
	head = tail = NULL;
	int i, count = 0;
	stuinfo nodedata;
	linklist newStudent;
	char FileName[100];
	FILE* fp;
	fp = NULL;
	MyStringToChar(SearchPath.m_strFilePath, FileName);
	fopen_s(&fp, FileName, "rb");//r为打开
	if (!fp)
	{
		MessageBox(_T("打开文件" + SearchPath.m_strFilePath + "失败"), _T("提示"), MB_ICONERROR);
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
	Display();

	// TODO: 在此添加控件通知处理程序代码
}


void CDlgBuildNewData::OnEnChangeEditSaveFileRoad()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CDlgBuildNewData::OnEnChangeEditSaveFileName()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CDlgBuildNewData::OnEnChangeEditAddName()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

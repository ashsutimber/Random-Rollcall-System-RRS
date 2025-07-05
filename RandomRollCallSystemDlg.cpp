
// RandomRollCallSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "RandomRollCallSystem.h"
#include "RandomRollCallSystemDlg.h"
#include "afxdialogex.h"
#include "CDlgLoadFromFill.h"
#include "CDldRecordRollCall.h"
#include "m_CDlgSaveYesOrNo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRandomRollCallSystemDlg 对话框



CRandomRollCallSystemDlg::CRandomRollCallSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RANDOMROLLCALLSYSTEM_DIALOG, pParent)
	, m_irenshu(3)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	tail_mingdan = tail_mingdan = tail_Yidian=NULL;
	head_diandao = head_diandao =  head_Yidian=NULL;
}

void CRandomRollCallSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RENSHU, m_irenshu);
	DDX_Control(pDX, IDC_ROLL_CALL_MEN, RollCallStu);
	DDX_Control(pDX, IDC_STUDENT_LIST, m_CLBstuList);
	DDX_Control(pDX, IDC_LIST_DianDaoQingKuang, m_CLBRollCallResult);
}

BEGIN_MESSAGE_MAP(CRandomRollCallSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_INPORT_DATA, &CRandomRollCallSystemDlg::OnBnClickedButtonInportData)
	ON_LBN_SELCHANGE(IDC_ROLL_CALL_MEN, &CRandomRollCallSystemDlg::OnLbnSelchangeRollCallMen)
	ON_BN_CLICKED(IDC_BUTTON_RECORD_ROLL_CALL, &CRandomRollCallSystemDlg::OnBnClickedButtonRecordRollCall)
	ON_BN_CLICKED(IDC_BUTTON_READ_LIST, &CRandomRollCallSystemDlg::OnBnClickedButtonReadList)
	ON_LBN_SELCHANGE(IDC_STUDENT_LIST, &CRandomRollCallSystemDlg::OnLbnSelchangeStudentList)
	ON_BN_CLICKED(IDC_BUTTON_ROLL_CALL, &CRandomRollCallSystemDlg::OnBnClickedButtonRollCall)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_SAVE_DATA, &CRandomRollCallSystemDlg::OnBnClickedButtonSaveData)
	ON_BN_CLICKED(IDC_BUTTON_READ_ROLL_CALL_LIST, &CRandomRollCallSystemDlg::OnBnClickedButtonReadRollCallList)
	ON_BN_CLICKED(IDC_BUTTON_READ_ATTENDANCE, &CRandomRollCallSystemDlg::OnBnClickedButtonReadAttendance)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_DianDaoQingKuang, &CRandomRollCallSystemDlg::OnLvnItemchangedListDiandaoqingkuang)
END_MESSAGE_MAP()


// CRandomRollCallSystemDlg 消息处理程序

BOOL CRandomRollCallSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	hadRollCalled = 0;

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CString BiaoTou[] = {_T("序号"), _T("姓名"),_T("出席情况")};
	for (int i=0; i < 3; i++) {
		if(i==0)
			m_CLBRollCallResult.InsertColumn(i, BiaoTou[i], LVCFMT_LEFT, 80);
		else if(i==1)
			m_CLBRollCallResult.InsertColumn(i, BiaoTou[i], LVCFMT_LEFT, 100);
		else
			m_CLBRollCallResult.InsertColumn(i, BiaoTou[i], LVCFMT_LEFT, 134);

	}
	m_CLBRollCallResult.SetExtendedStyle(m_CLBRollCallResult.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CRandomRollCallSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRandomRollCallSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRandomRollCallSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRandomRollCallSystemDlg::OnBnClickedButtonInportData()
{
	m_DlgData.DoModal();
	head_mingdan = m_DlgData.m_lHead;
	tail_mingdan = m_DlgData.m_lTail;
	head_diandao = NULL;
	tail_diandao = NULL;
	head_Yidian = NULL;
	tail_Yidian = NULL;
	SaveTemporaryFile();
	Display();
	DisplayDianDao();
	DisPlayResult();
	//m_DlgData.
	// TODO: 在此添加控件通知处理程序代码
}



void CRandomRollCallSystemDlg::OnLbnSelchangeRollCallMen()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CRandomRollCallSystemDlg::OnBnClickedButtonRecordRollCall()
{
	int index = RollCallStu.GetCurSel();		//m_ListDisplay为列表变量名称
	if (index < 0)return;
	linklist p, pre;
	p = pre = head_diandao;
	int count = 0;
	while (p && count < index)     //查找第一个值为x的结点，并用pre保存其前驱位置
	{
		pre = p;
		p = p->next;
		count++;
	}

	CDlgRecordRollCall m_DlgRecordAttendance;
	m_DlgRecordAttendance.m_selectedNode = p;
	UpdateData(TRUE);
	m_DlgRecordAttendance.m_strDianDaoStu = p->stuData.name;
	m_DlgRecordAttendance.DoModal();
	if (m_DlgRecordAttendance.flagshifou == 0) {
		MessageBox(_T("您还没有记录该同学的出勤情况，请重新记录。"), _T("提示"), MB_ICONINFORMATION);
		return;
	}
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	//将已经点到的同学移除
	if (!head_Yidian)
		head_Yidian = tail_Yidian = p;
	else
	{
		tail_Yidian->next = p;
		tail_Yidian = p;
	}
	if (p == head_diandao)
		head_diandao = p->next;
	else if(p==tail_diandao)
	{
		pre->next = p->next;
		tail_diandao = pre;
	}
	else pre->next = p->next;
	tail_Yidian->next = NULL;
	SaveTempraryYiDianFile();
	hadRollCalled = 1;
	DisplayDianDao();
	DisPlayResult();
}


void CRandomRollCallSystemDlg::OnBnClickedButtonReadList()
{
	//SaveTemporaryFile();
	CString FilePath = _T("D:\\list.txt");
	OpenFile(FilePath);
	// TODO: 在此添加控件通知处理程序代码
}


void CRandomRollCallSystemDlg::SaveTemporaryFile()
{
	int count = 0;
	int tag = 1;
	FILE* fp = NULL;
	linklist p = head_mingdan;
	if (!p)
	{
		//MessageBox(_T("链表为空，保存文件失败"), _T("提示"), MB_ICONERROR);
		return;
	}
	UpdateData(TRUE); fopen_s(&fp, "D:\\list.txt", "w");//list.txt为临时文件

	if (!fp)
	{
		//MessageBox(_T("无法创建.txt文件"), _T("提示"), MB_ICONINFORMATION);
		return;
	}
	fprintf(fp, "读取的学生名单如下：\n\n\n");

	while (p) {
		
		fprintf(fp, "%d、%s\n\n",tag, p->stuData.name);
		p = p->next;
		tag++;
	}
	fprintf(fp, "\n\n注：在此名单中修改无法修改软件中读取的名单。\n");

	fclose(fp);

	//MessageBox(_T("保存文件成功,保存为文件list.txt"), _T("提示"), MB_ICONINFORMATION);
	p = head_mingdan;
	fp = NULL;
	fopen_s(&fp, "D:\\list.dat", "wb");//wb为写二进制文件
	if (!fp)
	{
		//MessageBox(_T("无法创建.dat文件。"), _T("提示"), MB_ICONINFORMATION);
		return;
	}
	//统计节点数//////////////////////////////////////////////

	while (p)
	{
		count++;
		p = p->next;
	}
	fwrite(&count, sizeof(int), 1, fp);//1是写入的数量，sizeof是该量的大小

	p = head_mingdan;
	//保存数据文件
	while (p) {
		fwrite(&p->stuData, sizeof(stuinfo), 1, fp);
		p = p->next;
	}
	fclose(fp);

	//MessageBox(_T("保存文件成功,保存为文件list.dat" ), _T("提示"), MB_ICONINFORMATION);

	// TODO: 在此处添加实现代码.
}


void CRandomRollCallSystemDlg::Display()
{
	m_CLBstuList.ResetContent();
	linklist p = head_mingdan;
	int index = 0;
	CString strTemp;
	if (!p)return;
	while (p)
	{
		strTemp.Format(_T("%s"), CString(p->stuData.name));
		m_CLBstuList.InsertString(index, strTemp);
		index++;
		p = p->next;        //指向下一个结点
	}
	// TODO: 在此处添加实现代码.
}


void CRandomRollCallSystemDlg::OnLbnSelchangeStudentList()
{
	Display();
	// TODO: 在此添加控件通知处理程序代码
}


void CRandomRollCallSystemDlg::OnBnClickedButtonRollCall()
{
	int i,j;
	int count = 0;
	linklist p = head_mingdan;
	linklist pre=p;
	while (p) {
		count++;
		p = p->next;
	}
	int ChouQuN;
	p = head_mingdan;
	srand((unsigned)time(NULL));
	UpdateData(TRUE);
	if (count <= m_irenshu) {//判断是否完成所有人点到
		if (!head_mingdan)	{
				MessageBox(_T("已全部完成点名。"),_T("提示"),MB_ICONINFORMATION);
				return;
			}
			if (!head_diandao)
		
		{
			head_diandao = head_mingdan;
			tail_diandao = tail_mingdan;
			head_mingdan = NULL;
			tail_mingdan = NULL;
		}
		else {
			tail_diandao->next = head_mingdan;
			tail_diandao = head_mingdan;
			head_mingdan = NULL;
			tail_mingdan = NULL;

		}
	}
	else
	{
		for (i = 1; i <= m_irenshu; i++)
		{
			p = head_mingdan;
			ChouQuN = rand() % count + 1;
			for (j = 1; j < ChouQuN; j++) {
				pre = p;
				p = p->next;
			}
			if (!head_diandao)
				head_diandao = tail_diandao = p;
			else
			{
				tail_diandao->next = p;
				tail_diandao = p;
			}
			if (p == head_mingdan)
				head_mingdan = p->next;
			else pre->next = p->next;
			tail_diandao->next = NULL;
			count--;
		}
	}
	Display();
	DisplayDianDao();
	// TODO: 在此添加控件通知处理程序代码
}


void CRandomRollCallSystemDlg::DisplayDianDao()
{
	RollCallStu.ResetContent();
	linklist p = head_diandao;
	int index = 0;
	CString strTemp;
	if (!p)return;
	while (p)
	{
		strTemp.Format(_T("%s"), CString(p->stuData.name));
		RollCallStu.InsertString(index, strTemp);
		index++;
		p = p->next;        //指向下一个结点
	}

	// TODO: 在此处添加实现代码.
}



void CRandomRollCallSystemDlg::DisPlayResult()
{
	m_CLBRollCallResult.DeleteAllItems();
	int i=0;
	linklist p = head_Yidian;
	CString Name;
	CString Xuhao;
	CString IsPresent;
	if (!p)return;
	while (p)
	{
		Xuhao.Format(_T("%d"), i + 1);
		Name.Format(_T("%s"), CString(p->stuData.name));
		IsPresent.Format(_T("%s"), CString(p->stuData.isPresent));
		m_CLBRollCallResult.InsertItem(i, Xuhao);
		m_CLBRollCallResult.SetItemText(i, 1, Name);
		m_CLBRollCallResult.SetItemText(i, 2, IsPresent);
		i++;
		p = p->next;        //指向下一个结点
	}


	// TODO: 在此处添加实现代码.
}


void CRandomRollCallSystemDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	m_CDlgSaveYesOrNo Close;
	if (Close.DoModal() == IDOK) {
		SaveDianDaoFile();
	}
	// TODO: 在此处添加消息处理程序代码
}


void CRandomRollCallSystemDlg::OpenFile(CString FileName)
{
		// 使用 ShellExecute 打开记事本并加载文件
		HINSTANCE hInstance = ShellExecute(NULL,                   // 父窗口句柄（无父窗口设为NULL）
			_T("open"),             // 操作类型（"open"表示打开）
			_T("notepad.exe"),      // 要执行的程序（记事本）
			FileName,               // 文件路径（作为参数传给记事本）
			NULL,                   // 工作目录（NULL表示当前目录）
			SW_SHOW                 // 窗口显示方式（SW_SHOW正常显示）
		);

		// 检查执行结果
		if ((int)hInstance <= 32)
		{
			// 错误处理
			DWORD error = GetLastError();
			AfxMessageBox(_T("无法用记事本打开文件！") );
		}

	// TODO: 在此处添加实现代码.
}


void CRandomRollCallSystemDlg::SaveTempraryYiDianFile()
{
	int count = 0;
	FILE* fp = NULL;
	linklist p = head_Yidian;
	if (!p)
	{
		//MessageBox(_T("链表为空，保存文件失败"), _T("提示"), MB_ICONERROR);
		return;
	}
	UpdateData(TRUE); fopen_s(&fp, "D:\\listYiDian.txt", "w");//listYiDian.txt为临时文件

	if (!fp)
	{
		//MessageBox(_T("无法创建.txt文件"), _T("提示"), MB_ICONINFORMATION);
		return;
	}
	fprintf(fp, "已点到名单如下（此文件仅用于查看，请勿在此文件中修改信息）：\n\n\n");
	while (p) {
		fprintf(fp, "%s       %s                累计请假次数:%d次；  累计缺勤次数:%d次\n\n", p->stuData.name, p->stuData.isPresent,p->stuData.countqingjia,p->stuData.countQuedao);
		p = p->next;
	}
	fclose(fp);

	//MessageBox(_T("保存文件成功,保存为文件D:\\listYiDian.txt"), _T("提示"), MB_ICONINFORMATION);
	p = head_mingdan;
	fp = NULL;
	fopen_s(&fp, "D:\\listYiDiam.dat", "wb");//wb为写二进制文件
	if (!fp)
	{
		//MessageBox(_T("无法创建.dat文件。"), _T("提示"), MB_ICONINFORMATION);
		return;
	}
	//统计节点数//////////////////////////////////////////////

	while (p)
	{
		count++;
		p = p->next;
	}
	fwrite(&count, sizeof(int), 1, fp);//1是写入的数量，sizeof是该量的大小

	p = head_Yidian;
	//保存数据文件
	while (p) {
		fwrite(&p->stuData, sizeof(stuinfo), 1, fp);
		p = p->next;
	}
	fclose(fp);

	//MessageBox(_T("保存文件成功,保存为文件listYiDian.dat" ), _T("提示"), MB_ICONINFORMATION);

	// TODO: 在此处添加实现代码.
}


void CRandomRollCallSystemDlg::OnBnClickedButtonSaveData()
{
	if(SaveDianDaoFile())
		MessageBox(_T("保存成功！"), _T("提示"), MB_ICONINFORMATION);

	// TODO: 在此添加控件通知处理程序代码
}


void CRandomRollCallSystemDlg::OnBnClickedButtonReadRollCallList()
{
	if (hadRollCalled == 0) {
		MessageBox(_T("您还没有点到呢。"), _T("提示"), MB_ICONINFORMATION);
		return;
	}
	OpenFile(_T("D:\\listYiDian.txt"));
	 //TODO: 在此添加控件通知处理程序代码
}


void CRandomRollCallSystemDlg::OnBnClickedButtonReadAttendance()
{
	SaveDianDaoFile();
	
	if (m_strDianDaoListFile.IsEmpty()) {
		MessageBox(_T("请先读取数据或保存"), _T("提示"), MB_ICONINFORMATION);
		return;
	}
	CString txtf= m_strDianDaoListFile+_T(".txt");
	OpenFile(txtf);

	// TODO: 在此添加控件通知处理程序代码
}


void CRandomRollCallSystemDlg::MyStringToChar(CString str, char* pc)
{
	int len = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
	if (len >= 256) len = 255;

	WideCharToMultiByte(CP_ACP, 0, str, -1, pc, len, NULL, NULL);
	pc[len] = '\0';

	TRACE(_T("转换结果：%hs\n"), pc);

	// TODO: 在此处添加实现代码.
}


linklist CRandomRollCallSystemDlg::LinkCat()//将名单链表点到链表和已点链表连接成一个链表
{
	linklist head = NULL;
	linklist tail = NULL;
	linklist p = head_mingdan;
	while (p) {
		linklist q = (linklist)malloc(sizeof(linknode));
		q->stuData = p->stuData;
		q->next = p->next;
		if (!q)
		{
			AfxMessageBox(_T("内存分配失败"));
			return NULL;
		}
		if (head == NULL)
			head = tail = q;
		else
		{
			tail->next = q;
			tail = q;
		}
		p = p->next;
	}
	p = head_diandao;
	while (p) {
		linklist q = (linklist)malloc(sizeof(linknode));
		q->stuData = p->stuData;
		q->next = p->next;
		if (!q)
		{
			AfxMessageBox(_T("内存分配失败"));
			return NULL;
		}
		if (head == NULL)
			head = tail = q;
		else
		{
			tail->next = q;
			tail = q;
		}
		p = p->next;
	}
	p = head_Yidian;
	while (p) {
		linklist q = (linklist)malloc(sizeof(linknode));
		q->stuData = p->stuData;
		q->next = p->next;
		if (!q)
		{
			AfxMessageBox(_T("内存分配失败"));
			return NULL;
		}
		if (head == NULL)
			head = tail = q;
		else
		{
			tail->next = q;
			tail = q;
		}
		p = p->next;
	}
	// TODO: 在此处添加实现代码.
	return head;
}


int CRandomRollCallSystemDlg::SaveDianDaoFile()
{
	int tag = 0;
	m_strDianDaoListFile = m_DlgData.m_strFIleNameAndRoad;
	linklist head = LinkCat();
	linklist p = head;
	char txtFileName[100];
	char datFileName[100];
	CString datf;
	CString txtf;

	if (!p)
	{
		//MessageBox(_T("链表为空，保存文件失败"), _T("提示"), MB_ICONERROR);
		return 0;
	}
	UpdateData(TRUE);
	// TODO: 在此添加控件通知处理程序代码
	// 检查文件名和路径是否为空
	if (m_strDianDaoListFile.IsEmpty())
	{
		//AfxMessageBox(_T("文件名不能为空"));
		return 0;
	}
	UpdateData(TRUE);
	txtf = m_strDianDaoListFile + _T(".txt");
	datf = m_strDianDaoListFile + _T(".dat");
	//MessageBox(txtf);
	//MessageBox(datf);

	MyStringToChar(txtf, txtFileName);
	MyStringToChar(datf, datFileName);
	// 构造完整的文件路径
	FILE* fp;
	// 打开.txt文件用于写入
	fopen_s(&fp, txtFileName, "w");

	if (!fp)
	{
		//MessageBox(_T("无法创建.txt文件，请检查选中的路径。"), _T("提示"), MB_ICONERROR);
		return 0;
	}
	fprintf(fp, "点到情况如下（此文件仅用于查看，请勿在此文件中修改信息）：\n\n\n");
	while (p) {
		tag++;
		fprintf(fp, "%d、%s              缺到次数：%d； 请假次数：%d\n\n",tag, p->stuData.name, p->stuData.countQuedao, p->stuData.countqingjia);
		p = p->next;
	}
	fclose(fp);
	//MessageBox(_T("保存文件成功,保存为文件" + (CString)txtFileName), _T("提示"), MB_ICONINFORMATION);

	int count = 0;
	p = head;
	fp = NULL;
	fopen_s(&fp, datFileName, "wb");//wb为写二进制文件
	if (!fp)
	{
		//MessageBox(_T("无法创建.dat文件"), _T("提示"), MB_ICONERROR);
		return 0;
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
	return 1;

	// TODO: 在此处添加实现代码.
}


void CRandomRollCallSystemDlg::OnLvnItemchangedListDiandaoqingkuang(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}

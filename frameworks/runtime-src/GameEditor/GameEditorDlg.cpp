
// GameEditorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "GameEditor.h"
#include "GameEditorDlg.h"
#include "afxdialogex.h"

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


// CGameEditorDlg 对话框



CGameEditorDlg::CGameEditorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GAMEEDITOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGameEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC_COCOS2DX, m_nPicCocos2dx);
}

BEGIN_MESSAGE_MAP(CGameEditorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CGameEditorDlg 消息处理程序

BOOL CGameEditorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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
	m_nPicCocos2dx.createGLWin();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CGameEditorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGameEditorDlg::OnPaint()
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
HCURSOR CGameEditorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


bool CGameEditorDlg::isPointInPictureWin(CPoint& pt)
{
	CRect rc;
	m_nPicCocos2dx.GetWindowRect(&rc);
	ScreenToClient(&rc);

	if (pt.x >= rc.left && pt.x <= rc.right && pt.y >= rc.top && pt.y <= rc.bottom) return true;
	return false;
}

CPoint CGameEditorDlg::getPicturePoint(CPoint& pt)
{
	CRect rc;
	m_nPicCocos2dx.GetWindowRect(&rc);
	ScreenToClient(&rc);

	CPoint picPt;
	picPt.x = pt.x - rc.left;
	picPt.y = pt.y - rc.top;

	return picPt;
}


void CGameEditorDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (isPointInPictureWin(point)) {
		CPoint pt = getPicturePoint(point);
		SendMessageA(m_nPicCocos2dx.GetSafeHwnd(), WM_LBUTTONDOWN, MK_LBUTTON, pt.y << 16 | pt.x);
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CGameEditorDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (isPointInPictureWin(point)) {
		CPoint pt = getPicturePoint(point);
		SendMessageA(m_nPicCocos2dx.GetSafeHwnd(), WM_LBUTTONUP, MK_LBUTTON, pt.y << 16 | pt.x);
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CGameEditorDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (isPointInPictureWin(point)) {
		CPoint pt = getPicturePoint(point);
		SendMessageA(m_nPicCocos2dx.GetSafeHwnd(), WM_MOUSEMOVE, MK_LBUTTON, pt.y << 16 | pt.x);
	}
	CDialogEx::OnMouseMove(nFlags, point);
}

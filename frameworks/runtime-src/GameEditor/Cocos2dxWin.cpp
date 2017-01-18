// Cocos2dxWin.cpp : implementation file
//

#include "stdafx.h"
#include "GameEditor.h"
#include "Cocos2dxWin.h"
#include "cocos2d.h"
#include "CAppFrameWork.h"
#include "CCocosApp.h"
USING_NS_CC;

#include "platform/desktop/CCGLViewImpl-desktop.h" 


// CCocos2dxWin

IMPLEMENT_DYNAMIC(CCocos2dxWin, CWnd)

CCocos2dxWin::CCocos2dxWin()
{
	m_pFrameWork = NULL;
	//AllocConsole();
	//freopen("CONOUT$", "w", stdout);
}

CCocos2dxWin::~CCocos2dxWin()
{
}

BOOL CCocos2dxWin::createGLWin()
{
	app = new CCocosApp();
	m_pFrameWork = new CAppFrameWork();
	m_pFrameWork->InitApp(app);
	HWND hWnd = GetSafeHwnd();
	app->CreateWnd(hWnd);
	m_pFrameWork->applicationDidFinishLaunching();
	/*CRect rc;
	GetClientRect(&rc);

	cocos2d::Application::getInstance()->initInstance(GetSafeHwnd(), "", rc.right - rc.left, rc.bottom - rc.top);
	HWND hWnd = GetSafeHwnd();
	cocos2d::Application::getInstance()->run(hWnd);

	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();

	_fnMouseFunc = static_cast<GLViewImpl*>(glview)->getMouseBtnFunc();
	_fnCursorFunc = static_cast<GLViewImpl*>(glview)->getCursorFunc();

	this->MoveWindow(rc.left, rc.top, rc.right, rc.bottom);*/

	SetTimer(1, 1, NULL);


	return TRUE;
}

BEGIN_MESSAGE_MAP(CCocos2dxWin, CWnd)
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CCocos2dxWin message handlers
void CCocos2dxWin::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值  
	app->Run();


	CWnd::OnTimer(nIDEvent);
}

LRESULT CCocos2dxWin::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (1 == app->WindowProc(message, wParam, lParam))
		return 1;
	return CWnd::WindowProc(message, wParam, lParam);
}

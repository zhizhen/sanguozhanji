#pragma once

//#include "AppDelegate.h"
//#include "glfw3.h"
#include "CAppFrameWork.h"
#include "CCocosApp.h"


// CCocos2dxWin

class CCocos2dxWin : public CWnd
{
	DECLARE_DYNAMIC(CCocos2dxWin)
private:
	CAppFrameWork* m_pFrameWork;
public:
	CCocos2dxWin();
	virtual ~CCocos2dxWin();

	BOOL createGLWin();

protected:
	CCocosApp*	app;
	bool		m_bCreated;

	GLFWmousebuttonfun _fnMouseFunc;
	GLFWcursorposfun _fnCursorFunc;

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
};



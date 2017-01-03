#pragma once

#include "cocos2d.h";
#include <map>

#define NULL 0

USING_NS_CC;

class CAppBase
{
public:
	CAppBase();
	virtual ~CAppBase();

	// 初始化
	virtual void Init();
	// 销毁
	virtual void Destory();
	// 切入后台
	virtual void BGStart();
	// 切回前台
	virtual void BGEnd();
	// 每帧更新逻辑
	virtual void UpdateFunc(float dt);

	virtual void CreateWnd(HWND hwnd);
	virtual void initGLContextAttrs();
	virtual void Run();
	void Resize(int width, int height);
	LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

protected:
	std::string m_InitViewName;
	int m_InitW;
	int m_InitH;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	HWND m_InitHwnd;
#endif
};

extern CAppBase* gApp;
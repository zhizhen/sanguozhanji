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

	// ��ʼ��
	virtual void Init();
	// ����
	virtual void Destory();
	// �����̨
	virtual void BGStart();
	// �л�ǰ̨
	virtual void BGEnd();
	// ÿ֡�����߼�
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
#include "CGameApp.h"

CGameApp::CGameApp()
{
	isBackgroud = false;

#ifdef _WIN32
#ifdef _DEBUG
	//fopen_s(&logFile, "MEM-LOG.TXT", "w");
	//if (logFile)
	//	_CrtSetAllocHook(myAllocHook);
#endif
#endif
}


CGameApp::~CGameApp()
{
}

void CGameApp::Init()
{
	CCLOG(">>>>>>>>>>>>>>>>>CGameApp::Init");
	CAppBase::Init();

}

void CGameApp::Destory()
{
	CAppBase::Destory();
}

void CGameApp::UpdateFunc(float dt)
{
	CAppBase::UpdateFunc(dt);
}

void CGameApp::BGStart()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	if (isBackgroud == false)
#endif
	{
		CAppBase::BGStart();
		isBackgroud == true;
	}
}

void CGameApp::BGEnd()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	if (isBackgroud == true)
#endif
	{
		CAppBase::BGEnd();
		isBackgroud == false;
	}
}

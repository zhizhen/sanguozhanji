#include "CAppFrameWork.h"
#include "CAppBase.h"

CAppFrameWork::CAppFrameWork()
{
	m_pAppBase = NULL;
}

CAppFrameWork::~CAppFrameWork()
{
	Destory();
}

void CAppFrameWork::Destory()
{
	if (m_pAppBase)
	{
		m_pAppBase->Destory();
		delete m_pAppBase;
		m_pAppBase = NULL;
	}
}

void CAppFrameWork::InitApp(CAppBase* pAppBase)
{
	m_pAppBase = pAppBase;
	gApp = m_pAppBase;
}


bool CAppFrameWork::applicationDidFinishLaunching()
{
	if (m_pAppBase)
	{
		m_pAppBase->Init();
	}
	return true;
}

void CAppFrameWork::applicationDidEnterBackground()
{
	if (m_pAppBase)
	{
		m_pAppBase->BGStart();
	}
}

void CAppFrameWork::applicationWillEnterForeground()
{
	if (m_pAppBase)
	{
		m_pAppBase->BGEnd();
	}
}
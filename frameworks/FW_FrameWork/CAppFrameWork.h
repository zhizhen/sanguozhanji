#pragma once

#include "cocos2d.h"
class CAppBase;

class CAppFrameWork : private cocos2d::CCApplication
{
public:
	CAppFrameWork();

	virtual ~CAppFrameWork();

	virtual void Destory();
	void InitApp(CAppBase* pAppBase);


	virtual bool applicationDidFinishLaunching();

	virtual void applicationDidEnterBackground();

	virtual void applicationWillEnterForeground();

private:
	CAppBase* m_pAppBase;
};
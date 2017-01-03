#pragma once

#include "cocos2d.h"
#include "CAppBase.h"

class CCocosApp : public CAppBase
{
private:
public:
	CCocosApp();
	virtual ~CCocosApp();

	void Init();
	void Destory();
	void UpdateFunc(float dt);
};
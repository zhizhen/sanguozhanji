#pragma once
#include "CAppBase.h"

class CGameApp : public CAppBase
{
public:
	CGameApp();
	virtual ~CGameApp();

	// ��ʼ��
	void Init();
	void Destory();

	void UpdateFunc(float dt);

	void BGStart();
	void BGEnd();

private:
	bool isBackgroud;
};


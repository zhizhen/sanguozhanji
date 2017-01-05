#pragma once
#include "CAppBase.h"

class CGameApp : public CAppBase
{
public:
	CGameApp();
	virtual ~CGameApp();

	// ≥ı ºªØ
	void Init();
	void Destory();

	void UpdateFunc(float dt);

	void BGStart();
	void BGEnd();

private:
	bool isBackgroud;
};


#include "CAppBaseScene.h"
#include "CAppBase.h"
#include "CLayerManager.h"

CAppBaseScene::CAppBaseScene()
{
	CCScene::init();
}

void CAppBaseScene::InitGameLayer()
{
	this->scheduleUpdateWithPriority(Scheduler::PRIORITY_SYSTEM);
	stLayerMgr.Init(this);
}

void CAppBaseScene::update(float dt)
{
	CCScene::update(dt);
	gApp->UpdateFunc(dt);
}
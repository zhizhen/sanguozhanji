#pragma once

#include "cocos2d.h"

USING_NS_CC;

class CAppBaseScene : public Scene
{
public:
	CAppBaseScene();

	void InitGameLayer();

private:
	void update(float dt);
};
#pragma once

#include "cocos2d.h"

USING_NS_CC;

class CTouchLayer : public Layer
{
public:
	CTouchLayer();
	virtual ~CTouchLayer();

	virtual bool init();

	void BindAppBase();

	CREATE_FUNC(CTouchLayer);

};
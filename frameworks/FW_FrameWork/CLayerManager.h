#pragma once
#include "cocos2d.h"
#include "CTouchLayer.h"

USING_NS_CC;

enum RENDER_LAYER
{
	MAP_LAYER,			//地图渲染层级，最底层的层级
	MAPOBJECT_LAYER,	//地图元素层级
	NORMAL_LAYER,
	FLYOBJECT_LAYER,
	FLYCHAR_LAYER,
	UI_LAYER,
	TOP_LAYER,
	MAX_LAYER_NUM
};

#define stLayerMgr CLayerManager::instance()

class CLayerManager
{
public:
	static CLayerManager& instance() { static CLayerManager layer_mgr; return layer_mgr; }
	static CLayerManager* getInstance() { return &instance(); }
	~CLayerManager();

	void Init(Scene* aAttachScene);
	void Destroy();
	void AddToLayer(int layer_index, Node* obj, int zOrder = 0);
	void RemoveFromLayer(int layer_index, Node* obj);

	Layer* GetLayer(int layer_index);
private:
	CLayerManager();
	void SetDefaultLayer();

private:
	Scene* m_pAttachScene;
	CTouchLayer* m_LayerObjectStack[MAX_LAYER_NUM];
	int m_LayerOrder[MAX_LAYER_NUM];
};
#include "CLayerManager.h"

CLayerManager::CLayerManager()
{

}

CLayerManager::~CLayerManager()
{
	Destroy();
}

void CLayerManager::Destroy()
{
	for (int i = 0; i < MAX_LAYER_NUM; ++i)
	{
		if (m_LayerObjectStack[i])
		{
			m_LayerObjectStack[i]->removeAllChildren();
			// 从场景移除
			m_LayerObjectStack[i]->release();
			m_LayerObjectStack[i] = NULL;
		}
	}
}

void CLayerManager::Init(Scene* pAttachScene)
{
	m_pAttachScene = pAttachScene;

	for (int i = 0; i < MAX_LAYER_NUM; ++i)
	{
		m_LayerObjectStack[i] = NULL;
	}
	SetDefaultLayer();
}

void CLayerManager::AddToLayer(int layer_index, Node* obj, int zOrder)
{
	assert(layer_index >= 0 && layer_index < MAX_LAYER_NUM);
	Layer* pLayer = GetLayer(layer_index);
	pLayer->addChild(obj, zOrder);
}

void CLayerManager::RemoveFromLayer(int layer_index, Node* obj)
{
	CCAssert(m_LayerObjectStack[layer_index] != NULL, "[Debug]CLayerManager RemoveToLayer -- Layer is NULL");
	m_LayerObjectStack[layer_index]->removeChild(obj);
}

void CLayerManager::SetDefaultLayer()
{
	//设置层级的渲染次序
	int render_order = 0;
	m_LayerOrder[MAP_LAYER] = render_order++;
	m_LayerOrder[MAPOBJECT_LAYER] = render_order++;
	m_LayerOrder[NORMAL_LAYER] = render_order++;
	m_LayerOrder[FLYOBJECT_LAYER] = render_order++;
	m_LayerOrder[FLYCHAR_LAYER] = render_order++;
	m_LayerOrder[UI_LAYER] = render_order++;
	m_LayerOrder[TOP_LAYER] = render_order++;

	assert(render_order == MAX_LAYER_NUM);
}

Layer* CLayerManager::GetLayer(int layer_index)
{
	if (m_LayerObjectStack[layer_index] == NULL)
	{
		m_LayerObjectStack[layer_index] = CTouchLayer::create();
		m_LayerObjectStack[layer_index]->retain();
		if (layer_index == MAP_LAYER)
		{
			m_LayerObjectStack[layer_index]->BindAppBase();
		}

		m_pAttachScene->addChild(m_LayerObjectStack[layer_index], m_LayerOrder[layer_index]);
	}
	return m_LayerObjectStack[layer_index];
}
#include "stdafx.h"
#include "CCocosApp.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "audio/include/SimpleAudioEngine.h"
#include "cocos2d.h"
#include "scripting/lua-bindings/manual/lua_module_register.h"

CCocosApp::CCocosApp()
{

}

CCocosApp::~CCocosApp()
{

}

void CCocosApp::Init()
{
	// register lua module
	auto engine = LuaEngine::getInstance();
	ScriptEngineManager::getInstance()->setScriptEngine(engine);
	lua_State* L = engine->getLuaStack()->getLuaState();
	lua_module_register(L);

	CAppBase::Init();
}

void CCocosApp::Destory()
{

}

void CCocosApp::UpdateFunc(float dt)
{

}
#include "CAppBase.h"
#include "cocos2d.h"
#include "CAppBaseScene.h"
#include "CMyEGLView.h"


static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

extern CAppBase* gApp = NULL;
CAppBase::CAppBase()
{
	m_InitW = 960;
	m_InitH = 640;

#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	m_InitViewName = "GameWin";
	m_InitHwnd = NULL;
#endif
}

CAppBase::~CAppBase()
{

}

void CAppBase::Init()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#endif

	// initialize director
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();

	if (!glview) {
		if (m_InitHwnd == NULL)
		{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
			glview = GLViewImpl::createWithRect("GameEditor", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
			glview = GLViewImpl::create("GameEditor");
#endif
		}
		else
		{
			// mfc´°¿Ú´´½¨
			glview = CMyEGLView::createWithRect("test", Rect(0, 0, designResolutionSize.width, designResolutionSize.height), m_InitHwnd);
		}

		director->setOpenGLView(glview);


		// turn on display FPS
		director->setDisplayStats(true);

		// set FPS. the default value is 1.0/60 if you don't call this
		director->setAnimationInterval(1.0f / 60);

		// Set the design resolution
		glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
		auto frameSize = glview->getFrameSize();
		// if the frame's height is larger than the height of medium size.
		if (frameSize.height > mediumResolutionSize.height)
		{
			director->setContentScaleFactor(MIN(largeResolutionSize.height / designResolutionSize.height, largeResolutionSize.width / designResolutionSize.width));
		}
		// if the frame's height is larger than the height of small size.
		else if (frameSize.height > smallResolutionSize.height)
		{
			director->setContentScaleFactor(MIN(mediumResolutionSize.height / designResolutionSize.height, mediumResolutionSize.width / designResolutionSize.width));
		}
		// if the frame's height is smaller than the height of medium size.
		else
		{
			director->setContentScaleFactor(MIN(smallResolutionSize.height / designResolutionSize.height, smallResolutionSize.width / designResolutionSize.width));
		}

		//register_all_packages();

		// create a scene. it's an autorelease object
		CAppBaseScene* pBaseScene = new CAppBaseScene();
		pBaseScene->InitGameLayer();

		//auto scene = HelloWorld::createScene();

		// run
		director->runWithScene(pBaseScene);
		pBaseScene->release();
	}
}



void CAppBase::CreateWnd(HWND hwnd)
{
	if (!m_InitHwnd)
	{
		m_InitHwnd = hwnd;

		initGLContextAttrs();

		//auto director = Director::getInstance();
		//auto glview = director->getOpenGLView();
		//if (glview)
		//{
		//	 Retain glview to avoid glview being released in the while loop
		//	glview->retain();
		//}
	}
}

void CAppBase::initGLContextAttrs()
{    //set OpenGL context attributions,now can only set six attributions:
	 //red,green,blue,alpha,depth,stencil
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

	GLView::setGLContextAttrs(glContextAttrs);
}


LRESULT CAppBase::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (CMyEGLView* view = dynamic_cast<CMyEGLView*>(glview)) {
		return view->WindowProc(message, wParam, lParam);
	}
	return 0;
}


void CAppBase::Run()
{
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
		return;
	}
	//
	director->mainLoop();
}

void CAppBase::Resize(int width, int height)
{
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (glview)
	{
		glview->setFrameSize((float)width, (float)height);
		// Set the design resolution
		glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::FIXED_WIDTH);
	}
}

void CAppBase::Destory()
{

}

void CAppBase::BGStart()
{

}

void CAppBase::BGEnd()
{

}

void CAppBase::UpdateFunc(float dt)
{

}
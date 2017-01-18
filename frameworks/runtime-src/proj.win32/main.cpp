#include "main.h"
//#include "SimulatorWin.h"
#include <shellapi.h>
#include "cocos2d.h"
#include "CGameApp.h"
#include "CAppFrameWork.h"

USING_NS_CC;

#ifdef _DEBUG
inline void EnableMemLeakCheck()
{
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
}
#endif


int WINAPI _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

#if _DEBUG
	EnableMemLeakCheck();
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONIN$", "w", stdout);
	freopen("CONIN$", "w", stderr);
#endif

	// create the application instance
	//AppDelegate app;
	CGameApp* myApp = new CGameApp();
	CAppFrameWork myFrameWork;
	myFrameWork.InitApp(myApp);

    //auto simulator = SimulatorWin::getInstance();
    //return simulator->run();
	return Application::getInstance()->run();
}

// EngineBuildCamke.cpp : Defines the entry point for the application.
//

#include "EngineBuildCamke.h"
#include <Windows.h>
#include "Engine/Win/Window.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) 
{
	Window wnd(800,600,"Fuck");
		

	MSG msg;

	bool gResult;
	while((gResult = GetMessage(&msg,nullptr,0,0)) >0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		
	}

	if(gResult == -1)
	{
		return -1;
	}

	return msg.wParam;
}

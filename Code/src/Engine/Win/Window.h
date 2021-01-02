#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include <Windows.h>
class Window
{

	
private:
	class WindowClass
	{
	public:
		static const char* GetName() noexcept;
		static HINSTANCE GetInstance() noexcept;
	private:
		WindowClass() noexcept;
		~WindowClass();
		WindowClass(const WindowClass&) = delete;
		WindowClass& operator=(const WindowClass&) = delete;
		static constexpr const char* wndClassName = "Caffrey Engine";
		static WindowClass wndClass;
		HINSTANCE hInst;
				
	};

public:
	Window(int width, int height, const char* name) ;
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	void SetTitle(const std::string ttitle);

	int GetWidth(){return width;}
	int GetHeight(){return height;}
	HWND GetHandlw(){return hWnd;}
private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	static LRESULT CALLBACK HandleMsgTrunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;
private:
	int width;
	int height;
	HWND hWnd;
public:
	Keyboard kbd;
	Mouse mouse;

	HWND GetHandle() { return hWnd;}
public:
	static Window& GetWindow();

};


inline Window& Window::GetWindow()
{
	static Window Isntance(800,600,"fuck");
	return Isntance;
}

#define CHWND_EXCEPT(hr) Window::Exception(__LINE__,__FILE__,hr);
#define CHWND_LAST_XCEPT(hr) Window::Exception(__LINE__,__FILE__,GetLastError());
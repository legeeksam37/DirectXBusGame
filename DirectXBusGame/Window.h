#pragma once
#include <Windows.h>


class Window
{
public:
	Window();
	bool init();
	bool broadcast();
	bool release();
	bool isRun();
	//methods that gives the size of the window
	RECT getClientWindowRect();
	void setHWND(HWND hwnd);
	//EVENTS
	virtual void onCreate();
	virtual void onUpdate();
	virtual void onDestroy();
	~Window();

protected:
	HWND m_hwnd;
	bool m_is_run;

};



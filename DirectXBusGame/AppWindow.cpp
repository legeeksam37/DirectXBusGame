#include "AppWindow.h"



AppWindow::AppWindow()
{
}


AppWindow::~AppWindow()
{
}

void AppWindow::onCreate()
{
	Window::onCreate();
	//intialize the graphics engine
	GraphicsEngine::get()->init();
	m_swap_chain = GraphicsEngine::get()->createSwapChain();
	//initilaize with size and hanlde of our window
	RECT rc = this->getClientWindowRect();
	m_swap_chain->init(this->m_hwnd, rc.right-rc.left, rc.bottom-rc.top);
}

void AppWindow::onUpdate()
{
	Window::onUpdate();
	GraphicsEngine::get()->get_immediate_dc()->clearRenderTargetColor(this->m_swap_chain, 1, 0, 0, 1);

	m_swap_chain->present(true);
}

void AppWindow::onDestroy()
{
	Window::onDestroy();
	m_swap_chain->release();
	GraphicsEngine::get()->release();


}
#include "DeviceContext.h"
#include "SwapChain.h"

DeviceContext::DeviceContext(ID3D11DeviceContext* device_context):m_device_context(device_context)
{
	//this->m_device_context = device_context;

}

bool DeviceContext::clearRenderTargetColor(SwapChain* swapCHain, float red, float green, float blue, float alpha)
{
	//vector of the four channel of the colors
	FLOAT clear_color[] = {red, green, blue, alpha};
	m_device_context->ClearRenderTargetView(swapCHain->m_render_target_view,clear_color);

	return true;
}

bool DeviceContext::release()
{
	m_device_context->Release();
	delete this; 
	return true;
}

DeviceContext::~DeviceContext()
{
}

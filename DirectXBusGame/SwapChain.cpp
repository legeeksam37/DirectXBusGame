#include "SwapChain.h"
#include "GraphicsEngine.h"

SwapChain::SwapChain()
{
}

bool SwapChain::init(HWND hwnd, UINT width, UINT height)
{

	//pointer to the direct x device so let's get it 

	ID3D11Device*device = GraphicsEngine::get()->m_d3d_device;
	
	DXGI_SWAP_CHAIN_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.BufferCount = 1;
	desc.BufferDesc.Width = width;
	desc.BufferDesc.Height = height;
	//pixel format of our frame buffer of our swapchain 8 bits (1byte) for each of our color panel of our pixel
	desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	//the refresh rate in hertz (60/sec)
	desc.BufferDesc.RefreshRate.Numerator = 60;
	desc.BufferDesc.RefreshRate.Denominator = 1;
	//we use the swap chain as a render target
	desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	desc.OutputWindow = hwnd;
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.Windowed = TRUE;

	//create the swapchain for the window indicated by HWND parameter
	HRESULT  hr = GraphicsEngine::get()->m_dxgi_factory->CreateSwapChain(device, &desc, &m_swap_chain);
	if (FAILED(hr)) {
		return false; 
	}

	//get the back buffer
	//to be usable it has to be converted into a target view
	ID3D11Texture2D* buffer = NULL;
	hr = m_swap_chain->GetBuffer(0,__uuidof(ID3D11Texture2D),(void**)&buffer);

	if (FAILED(hr)) {
	
		return false;
	}
	
	hr = device->CreateRenderTargetView(buffer,NULL, &m_render_target_view);
	buffer->Release();

	if (FAILED(hr)) {

		return false;
	}

	return true;
}

bool SwapChain::present(bool vsynch)
{
	m_swap_chain->Present(vsynch, NULL);
	 
	return true;
}

bool SwapChain::release()
{
	m_swap_chain->Release();
	delete this;
	return true;
}

SwapChain::~SwapChain()
{
}

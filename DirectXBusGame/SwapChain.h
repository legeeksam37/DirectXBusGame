#pragma once
#include <d3d11.h>

class DeviceContext;

class SwapChain
{

public:
	SwapChain();
	bool init(HWND hwnd, UINT width, UINT height);

	bool present(bool vsynch);

	bool release();
	~SwapChain();

private:
	//An IDXGISwapChain interface implements one or more surfaces for storing rendered data before presenting it to an output.
	IDXGISwapChain* m_swap_chain; 
	//contain the output value of the render target view
	ID3D11RenderTargetView* m_render_target_view;
	ID3D10DepthStencilView* m_dsv;
	friend class DeviceContext; 

};


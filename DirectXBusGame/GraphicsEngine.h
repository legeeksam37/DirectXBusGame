#pragma once
#include <d3d11.h>

class SwapChain;
class DeviceContext;


class GraphicsEngine
{
public:
	GraphicsEngine();
	//initialize the DX11 API
	bool init();
	//Relkease all the ressources loaded
	bool release();
	~GraphicsEngine();
	static GraphicsEngine* get();
	SwapChain* createSwapChain();
	DeviceContext* get_immediate_dc();
private:
	DeviceContext* m_imm_device_context;
	ID3D11Device* m_d3d_device;
	D3D_FEATURE_LEVEL m_feature_level;
	ID3D11DeviceContext* m_imm_context;
	IDXGIDevice* m_dxgi_device;
	IDXGIDevice* m_dxgi_adapter;
	IDXGIFactory* m_dxgi_factory;
	friend class SwapChain; 
};


#include "GraphicsEngine.h"
#include "SwapChain.h"
#include "DeviceContext.h"

GraphicsEngine::GraphicsEngine()
{
}

bool GraphicsEngine::init()
{
	//driver type that allows directX to execute the function from the best that uses the gpu to the worst with CPU and slow

	D3D_DRIVER_TYPE drivers_types[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE

	};

	UINT num_driver_types = ARRAYSIZE(drivers_types);

	//the higher the lvl is, the more feature whe have
	//feature level of Dx11 we use

	D3D_FEATURE_LEVEL feature_level[] =
	{
		D3D_FEATURE_LEVEL_11_0
	};

	UINT num_feature_level = ARRAYSIZE(feature_level);

	HRESULT res = 0;

	
	

	for (UINT driver_type_index = 0; driver_type_index < num_driver_types;)
	{
	 res = D3D11CreateDevice(NULL, drivers_types[driver_type_index],NULL, NULL, feature_level, num_feature_level, D3D11_SDK_VERSION, &m_d3d_device, &m_feature_level, &m_imm_context);

		++driver_type_index;
	}

	if (FAILED(res)) {
		return false;
	}

	m_imm_device_context =new DeviceContext(m_imm_context);			//instanciation with immediate context

	m_d3d_device->QueryInterface(__uuidof(IDXGIDevice), (void**)&m_dxgi_device);
	m_dxgi_device->GetParent(__uuidof(IDXGIAdapter), (void**)&m_dxgi_adapter);
	m_dxgi_adapter->GetParent(__uuidof(IDXGIFactory), (void**)&m_dxgi_factory);
	
	return true;

	
}

bool GraphicsEngine::release()
{
	m_dxgi_device->Release();
	m_dxgi_adapter->Release();
	m_dxgi_factory->Release();
	m_imm_device_context->release();
	m_d3d_device->Release();
	return true;
}

GraphicsEngine::~GraphicsEngine()
{
}



SwapChain* GraphicsEngine::createSwapChain()
{



	return new SwapChain();
}

DeviceContext* GraphicsEngine::get_immediate_dc()
{
	return this->m_imm_device_context;
}


//singleton method
GraphicsEngine* GraphicsEngine::get()
{

	static GraphicsEngine engine;
	return &engine;
}
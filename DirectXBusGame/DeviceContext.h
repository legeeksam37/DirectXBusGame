#pragma once
#include "d3d11.h"

class SwapChain;

class DeviceContext
{

public:
	DeviceContext(ID3D11DeviceContext* device_context);
	//rendering commande
	bool clearRenderTargetColor(SwapChain* swapCHain, float red, float green, float blue, float alpha);
	bool release();
	~DeviceContext();

private:
	ID3D11DeviceContext* m_device_context;
};


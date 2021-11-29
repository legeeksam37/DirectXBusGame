#pragma once
#include "d3d11.h"
#include "VertexBuffer.h"

class SwapChain;
class VertexBuffer;

class DeviceContext
{

public:
	DeviceContext(ID3D11DeviceContext* device_context);
	//rendering commande
	bool clearRenderTargetColor(SwapChain* swapCHain, float red, float green, float blue, float alpha);
	void setVertexBuffer(VertexBuffer* vb);

	bool release();
	~DeviceContext();

private:
	ID3D11DeviceContext* m_device_context;
};


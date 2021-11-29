#pragma once
#include "GraphicsEngine.h"
#include <d3d11.h>
#include "DeviceContext.h"


class DeviceContext;
class VertexBuffer


{

public:
	VertexBuffer();
	bool load(void* list_verticies, UINT size_vertex, UINT size_list, void* shader_byte_code, UINT size_bute_shader);
	bool release();
	~VertexBuffer();

private:
	UINT m_size_vetex; // in bytes
	UINT m_size_list;

	//output buffer

	ID3D11Buffer* m_output_buffer;
	//output object of layout input layout
	ID3D11InputLayout* input_layout;
	friend class DeviceContext;

};


#include "VertexBuffer.h"

VertexBuffer::VertexBuffer() :m_output_buffer(0), input_layout(0)
{
}

bool VertexBuffer::load(void * list_verticies, UINT size_vertex, UINT size_list, void *  shader_byte_code, UINT size_bute_shader)
{

	//the load method can be used multiples times to load different list of verticies, let's relase our two ressources so that we can create new ones
	if (m_output_buffer)m_output_buffer->Release();
	if (input_layout)input_layout->Release();


	//descritive object with some data relative to our buffer
	D3D11_BUFFER_DESC buff_desc = {};
	//first attribute to set is usage to set if the buffer is accesible by cpu or gpu
	buff_desc.Usage = D3D11_USAGE_DEFAULT;
	//size in byte of out Buffer (product between the size of the vertex and number of verticies in the list
	buff_desc.ByteWidth = size_vertex*size_list;
	//we tell to direct x how to bind this buffer to the pipeline
	buff_desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	buff_desc.CPUAccessFlags = 0;
	buff_desc.MiscFlags = 0;
	//initial object
	D3D11_SUBRESOURCE_DATA init_data = {};
	//pass the pointer to the memory where the list of verticies is located
	init_data.pSysMem = list_verticies;
	m_size_vetex = size_vertex;
	m_size_list = size_list;

	if (FAILED(GraphicsEngine::get()->m_d3d_device->CreateBuffer(&buff_desc, &init_data, &m_output_buffer))) {
		return false;
		}


	//informatiosn of attributes that compose our vertex type
	D3D11_INPUT_ELEMENT_DESC  layout[] =
	{
//semantic name - semantic index - format - input slot -aligned byte offset - input slot class - instance data step rate
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};
	//number of attributes
	UINT size_layout = ARRAYSIZE(layout);

	if (FAILED(GraphicsEngine::get()->m_d3d_device->CreateInputLayout(layout, size_layout, shader_byte_code, size_bute_shader, &input_layout))) {
		return false;
	}

	return true;
}

bool VertexBuffer::release()
{
	m_output_buffer->Release();
	input_layout->Release();
	delete this;
	return true;
} 

VertexBuffer::~VertexBuffer()
{
}

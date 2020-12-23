#include "pch.h"
#include "Buffers.h"
#include "OpenGLBuffers.h"

VertexBuffer* VertexBuffer::Create()
{
	return new OpenGLVertexBuffer();
}
IndexBuffer* IndexBuffer::Create()
{
	return new OpenGLIndexBuffer();
}
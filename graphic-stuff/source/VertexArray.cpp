#include "pch.h"
#include "VertexArray.h"
#include "OpenGLVertexArray.h"


VertexArray* VertexArray::Create()
{
	return new OpenGLVertexArray();
}
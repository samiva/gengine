#include "pch.h"
#include "OpenGLBuffers.h"

OpenGLVertexBuffer::OpenGLVertexBuffer()
{
	glCreateBuffers(1, &m_rendererId);
}

void OpenGLVertexBuffer::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_rendererId);
}

void OpenGLVertexBuffer::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void OpenGLVertexBuffer::setData(void * data, size_t size)
{
	glNamedBufferStorage(m_rendererId, static_cast<GLsizeiptr>(size), data, 0);
}

void OpenGLVertexBuffer::setLayout(Layout& layout)
{
	m_layout = layout;
}

/***************************
* IndexBuffer
*******************************/
OpenGLIndexBuffer::OpenGLIndexBuffer()
{
	glCreateBuffers(1, &m_rendererId);
}

void OpenGLIndexBuffer::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererId);
}

void OpenGLIndexBuffer::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void OpenGLIndexBuffer::setData(void * data, size_t size, unsigned int count)
{
	glNamedBufferStorage(m_rendererId, static_cast<GLsizeiptr>(size), data, 0);
	m_count = count;
}

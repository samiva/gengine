#include "pch.h"
#include "OpenGLVertexArray.h"
#include "Buffers.h"
#include "OpenGLBuffers.h"

OpenGLVertexArray::OpenGLVertexArray()
{
	glCreateVertexArrays(1, &m_rendererId);
}

void OpenGLVertexArray::bind()
{
	glBindVertexArray(m_rendererId);
	//for (auto i : m_attribPointers) {
	//	glEnableVertexAttribArray(i);
	//}
}

void OpenGLVertexArray::unbind()
{
	for (auto i : m_attribPointers) {
		glDisableVertexAttribArray(i);
	}
	glBindVertexArray(0);
}

void OpenGLVertexArray::addVertexBuffer(VertexBuffer* vb)
{
	unsigned char offset{ 0 };
	glBindVertexArray(m_rendererId);
	vb->bind();
	auto members = vb->getLayout().getMembers();
	for (auto& elem : members) {
		glVertexAttribPointer(elem.index, elem.count, elem.type, elem.normalized, vb->getLayout().getStride(), reinterpret_cast<void*>(offset));
		glEnableVertexAttribArray(elem.index);
		offset += elem.count*Layout::GetSize(elem.type);
		m_attribPointers.push_back(elem.index);
	}
}

void OpenGLVertexArray::addIndexBuffer(IndexBuffer* ib)
{
	glBindVertexArray(m_rendererId);
	ib->bind();
	m_indexBuffer = ScopedPtr<IndexBuffer>(ib);
}

const IndexBuffer* OpenGLVertexArray::getIndexBuffer() const
{
	return m_indexBuffer.get();
}


#ifndef __OPENGLVERTEXARRAY_h__
#define __OPENGLVERTEXARRAY_h__
#include "pch.h"
#include "Base.h"
#include "VertexArray.h"

class OpenGLVertexArray : public VertexArray
{

public:
	OpenGLVertexArray();
	virtual ~OpenGLVertexArray() {}
	virtual void bind() override;
	virtual void unbind() override;
	virtual void addVertexBuffer(VertexBuffer* vb) override;
	virtual void addIndexBuffer(IndexBuffer* ib) override;
	virtual const IndexBuffer* getIndexBuffer() const override;

private:
	GLuint m_rendererId;
	std::vector<GLuint> m_attribPointers;
	ScopedPtr<IndexBuffer> m_indexBuffer;

};
#endif // __OPENGLVERTEXARRAY_h__

#ifndef __VERTEXARRAY_H__
#define __VERTEXARRAY_H__
#include "Base.h"
#include "glew.h"
#include "Buffers.h"


class VertexArray {
public:
	static VertexArray* Create();
public:

	virtual ~VertexArray() { }

	virtual void bind() = 0;
	virtual void unbind() = 0;
	virtual void addVertexBuffer(VertexBuffer* vb) = 0;
	virtual void addIndexBuffer(IndexBuffer* ib) = 0;

	virtual const IndexBuffer* getIndexBuffer() const = 0;

};
#endif // !__VERTEXARRAY_H__
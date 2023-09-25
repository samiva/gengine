#ifndef __BUFFERS_H__
#define __BUFFERS_H__
#include "pch.h"
#include "Base.h"
#include "glew.h"

// #TODO: Remove opengl types
class Layout {
	struct LayoutMember
	{
		GLuint index;
		GLint count;
		GLenum type;
		GLboolean normalized;
	};
public:
	static int GetSize(GLenum type) {
		switch (type) {
		case GL_FLOAT:
			return sizeof(float);
		default:
			return 0;
		}

	}

public:
	
	void addMember(int typeSize, int count, GLenum type) {
		m_stride += count * typeSize;
		m_members.push_back({ indexCount, count, type, GL_FALSE });
		indexCount++;
	}

	unsigned int getStride() { return m_stride; }
	const std::vector<LayoutMember>& getMembers() { return m_members; }

private:
	unsigned int indexCount = 0;
	unsigned int m_stride = 0;
	std::vector<LayoutMember> m_members;

};



class VertexBuffer {
public:
	static VertexBuffer* Create();
public:
	virtual ~VertexBuffer() = default;
	virtual void bind()=0;
	virtual void unbind()=0;
	virtual void setData(void* data, size_t size)=0;
	virtual void setLayout(Layout& layout) = 0;
	virtual Layout& getLayout()  = 0;
};

class IndexBuffer {

public:
public:
	static IndexBuffer* Create();
	virtual ~IndexBuffer() = default;

	virtual void bind()=0;
	virtual void unbind()=0;
	virtual void setData(void* data, size_t size, unsigned int count)=0;

	virtual GLuint getCount() const = 0;
};

#endif // !__BUFFERS_H__


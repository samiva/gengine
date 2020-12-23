#ifndef __OPENGLBUFFERS_h__
#define __OPENGLBUFFERS_h__
#include "pch.h"
#include "Buffers.h"
#include "glew.h"

class OpenGLVertexBuffer : public VertexBuffer  {
public:
	OpenGLVertexBuffer();
	virtual void bind() override;
	virtual void unbind() override;
	virtual void setData(void* data, size_t size) override;
	virtual Layout& getLayout() override { return m_layout; }

	virtual void setLayout(Layout&) override;

private:
	Layout m_layout;
	GLuint m_rendererId;
};

class OpenGLIndexBuffer : public IndexBuffer {

public:
	OpenGLIndexBuffer();

	virtual void bind();
	virtual void unbind();
	virtual void setData(void* data, size_t size, unsigned int count);

	virtual GLuint getCount() const { return m_count; }

private:
	GLuint m_rendererId;
	GLuint m_count;
};

#endif // __OPENGLBUFFERS_h__

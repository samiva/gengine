#include "pch.h"
#include "OpenGLRenderer.h"
#include "OpenGLVertexArray.h"
#include "OpenGLBuffers.h"

void OpenGLRenderer::draw(VertexArray* va)
{

	glDrawElements(GL_TRIANGLES, va->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);
}

// #TODO: Can this be improved?
void OpenGLRenderer::clear(ClearFlags flags)
{
	uint32_t bits{ 0 };
	bits |= ((static_cast<std::underlying_type<ClearFlags>::type>(flags & ClearFlags::Color)) != 0) ? GL_COLOR_BUFFER_BIT : 0;
	bits |= ((static_cast<std::underlying_type<ClearFlags>::type>(flags & ClearFlags::Depth)) != 0) ? GL_DEPTH_BUFFER_BIT : 0;
	bits |= ((static_cast<std::underlying_type<ClearFlags>::type>(flags & ClearFlags::Stencil)) != 0) ? GL_STENCIL_BUFFER_BIT : 0;
	glClear(bits);
}

void OpenGLRenderer::setClearColor(const glm::vec4& color)
{
	glClearColor(color.r, color.g, color.b, color.a);
}

void OpenGLRenderer::setViewPort(int x, int y, int width, int height)
{
	glViewport(x, y, width, height);
}

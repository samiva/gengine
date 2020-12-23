#ifndef __OPENGLRENDERER_H__
#define __OPENGLRENDERER_H__
#include "pch.h"
#include "RendererAPI.h"
class OpenGLRenderer : public RendererAPI
{
	// Inherited via Renderer3D
	virtual void draw(VertexArray* va) override;
	virtual void clear(ClearFlags flags) override;
	virtual void setClearColor(const glm::vec4& color) override;
	virtual void setViewPort(int x, int y, int widt, int height) override;
};
#endif // !__OPENGLRENDERER_H__

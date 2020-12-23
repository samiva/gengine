#ifndef __RENDERERAPI_H__
#define __RENDERERAPI_H__
#include "pch.h"
#include "VertexArray.h"
#include "ShaderProgram.h"
#include "glm.hpp"


// #TODO: Maybe enum class?
//extern const uint8_t ColorBufferBit;
//extern const uint8_t DepthBufferBit;
//extern const uint8_t StencilBufferBit;
enum class ClearFlags : uint8_t {
	Color = 1 << 0,
	Depth = 1 << 1,
	Stencil = 1 << 2
};

 ClearFlags operator |(ClearFlags lhs,ClearFlags rhs);

 ClearFlags operator &(ClearFlags lhs, ClearFlags rhs);

// #TODO: Other apis
class RendererAPI {
public:
	enum class RenderAPI {
		None, OpenGL
	};

public:
	virtual void draw(VertexArray* va) = 0;

	 
	virtual void clear(ClearFlags flags) = 0;
	virtual void setClearColor(const glm::vec4& color) = 0;
	virtual void setViewPort(int x, int y, int widt, int height) = 0;

	static RenderAPI getAPI() { return s_api; }

private:
	static RenderAPI s_api;

};
#endif // !__RENDERERAPI_H__
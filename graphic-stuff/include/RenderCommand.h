#ifndef __RENDERCOMMAND_H__
#define __RENDERCOMMAND_H__
#include "pch.h"
#include "Base.h"
#include "RendererAPI.h"
#include "VertexArray.h"
#include "OpenGLRenderer.h"

class RenderCommand {
public:
	static void Clear(ClearFlags flags) {
		s_api->clear(flags);
	}

	static void setClearColor(float r, float g, float b, float a) {
		s_api->setClearColor( {r,g,b,a} );
	}
	static void Draw(VertexArray* va) {
		s_api->draw(va);
	}

	static void ResizeViewPort(uint32_t width, uint32_t height)
	{
		s_api->setViewPort(0, 0, width, height);
	}

	static void Shutdown() {
		delete s_api;
	}
private:
	static RendererAPI* s_api;
};



#endif // !__RENDERCOMMAND_H__

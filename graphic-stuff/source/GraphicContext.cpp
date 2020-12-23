#include "pch.h"
#include "GraphicContext.h"
#include "RendererAPI.h"
#include "OpenGLGraphicContext.h"
#include "SDL.h"

ScopedPtr<GraphicContext> GraphicContext::Create(void* window) {
	if (RendererAPI::getAPI() == RendererAPI::RenderAPI::OpenGL) {
		return CreateScopedPtr<OpenGLGraphicContext>(static_cast<SDL_Window*>(window));
	}
	
	return nullptr;
}
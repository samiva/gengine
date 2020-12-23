#include "pch.h"
#include "OpenGLGraphicContext.h"
#include "SDL.h"
#include "glew.h"

OpenGLGraphicContext::OpenGLGraphicContext(SDL_Window * window)
	:m_window(window)
{}

OpenGLGraphicContext::~OpenGLGraphicContext()
{
	shutDown();
}

bool OpenGLGraphicContext::init()
{

	SDL_GLContext ctx = SDL_GL_CreateContext(m_window);
	if (ctx == nullptr) {
		std::cerr << "Failed to create context" << std::endl;
		return false;
	}

	SDL_GL_MakeCurrent(m_window, ctx);

	if (glewInit() != GLEW_OK) {
		std::cerr << "Unable to init glew" << std::endl;
		return false;
	}

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	return true;
}

void OpenGLGraphicContext::swapBuffer()
{
	SDL_GL_SwapWindow(m_window);
}

void OpenGLGraphicContext::shutDown()
{
	auto ctx = SDL_GL_GetCurrentContext();	
	SDL_GL_DeleteContext(ctx);
	SDL_DestroyWindow(m_window);
}

#ifndef __OPENGLGRAPHICCONTEXT_H__
#define __OPENGLGRAPHICCONTEXT_H__
#include "pch.h"
#include "GraphicContext.h"
#include "SDL.h"
class OpenGLGraphicContext : public GraphicContext {
public:

	OpenGLGraphicContext(SDL_Window* window);
	virtual ~OpenGLGraphicContext();

	// Inherited via GraphicContext
	virtual bool init() override;

	virtual void swapBuffer() override;

	virtual void shutDown() override;
private:
	SDL_Window* m_window;

};
#endif // !__OPENGLGRAPHICCONTEXT_H__

#ifndef __GRAPHICCONTEXT_H__
#define __GRAPHICCONTEXT_H__
#include "pch.h"
#include "Base.h"
#include "Window.h"

class GraphicContext {
public:
	static ScopedPtr<GraphicContext> Create(void* window);
public:
	virtual ~GraphicContext() {}
	virtual bool init() = 0;
	virtual void swapBuffer() = 0;
	virtual void shutDown() = 0;
};
#endif // !__GRAPHICCONTEXT_H__

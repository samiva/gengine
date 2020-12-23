#ifndef __WINDOWOPENGL_H__
#define __WINDOWOPENGL_H__
#include "pch.h"
#include "Base.h"
#include "Window.h"
#include "SDL.h"
#include "OpenGLGraphicContext.h"
#include "Event.h"


class WindowsWindow : public Window {
public:
	
	WindowsWindow(WindowProps& props);
	// Inherited via Window
	virtual bool init() override;
	virtual void onUpdate() override;
	virtual void shutdown() override;

	virtual const std::string & getTitle() const override { return m_props.title; }

	virtual int getWidth() const override { return m_props.width; }

	virtual int getHeight() const override { return m_props.height; }

	virtual void setEventCallbackFn(const EventCallbackFn&) override;

private:

	ScopedPtr<GraphicContext> m_context;
	WindowProps m_props;

	EventCallbackFn EventCallback;
};
#endif // !__WINDOWOPENGL_H__
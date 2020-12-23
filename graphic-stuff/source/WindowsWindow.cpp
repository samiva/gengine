#include "pch.h"
#include "WindowsWindow.h"
#include "WindowEvent.h"



bool WindowsWindow::init()
{
	SDL_Window* window = SDL_CreateWindow(m_props.title.c_str(), m_props.x, m_props.y, m_props.width, m_props.height, SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
	if (window == nullptr) {
		std::cerr << "Failed to create window" << std::endl;
		return false;
	}

	// Create context 
	m_context = GraphicContext::Create(window);
	if (!m_context->init()) {
		std::cerr << "Failed to initialize context" << std::endl;
		return false;
	}

	return true;
}

WindowsWindow::WindowsWindow(WindowProps& props)
	:m_props(props)
{
}

void WindowsWindow::onUpdate()
{
	SDL_Event ev;
	SDL_PollEvent(&ev);
	switch (ev.type) {
	case SDL_EventType::SDL_QUIT:
	{
		WindowCloseEvent event;
		EventCallback(event);
	}
		break;
	case SDL_EventType::SDL_WINDOWEVENT:
	{
		switch (ev.window.event)
		{
		case SDL_WINDOWEVENT_RESIZED:
			{
				m_props.width = ev.window.data1;
				m_props.height = ev.window.data2;
				WindowResizeEvent event(ev.window.data1, ev.window.data2);
				EventCallback(event);
			}
			break;
		default:
			break;
		}
	}
	break;
	default:
		break;
	}
	m_context->swapBuffer();
}

void WindowsWindow::shutdown()
{
}

void WindowsWindow::setEventCallbackFn(const EventCallbackFn& callback)
{
	EventCallback = callback;
}
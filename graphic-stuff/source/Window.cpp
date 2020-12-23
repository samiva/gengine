#include "pch.h"
#include "Window.h"
#include "WindowsWindow.h"

ScopedPtr<Window> Window::Create(WindowProps& props) {
	auto win = CreateScopedPtr<WindowsWindow>(props);

	win->init();
	return win;
}
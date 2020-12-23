#ifndef __WINDOW_H__
#define __WINDOW_H__
#include "pch.h"
#include "Base.h"
#include "Event.h"

struct WindowProps {
	std::string title;
	int x;
	int y;
	int width;
	int height;
	//uint32_t flags;
};

class Window {
public:
	using EventCallbackFn = std::function<void(Event&)>;
	static ScopedPtr<Window> Create(WindowProps& props);
public:
	virtual ~Window() {}

	virtual bool init() = 0;
	virtual void onUpdate() = 0;
	virtual void shutdown() = 0;

	virtual const std::string& getTitle() const = 0;
	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;
	virtual void setEventCallbackFn(const EventCallbackFn&) = 0;

};
#endif // !__WINDOW_H__

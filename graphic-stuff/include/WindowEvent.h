#ifndef __WINDOWEVENT_h__
#define __WINDOWEVENT_h__
#include "pch.h"
#include "Event.h"
class WindowResizeEvent : public Event
{
public:
	WindowResizeEvent(uint32_t width, uint32_t height) : m_width(width), m_height(height) {}
	uint32_t getWidth() const { return m_width; }
	uint32_t getHeight() const { return m_height; }

	static EventType GetStaticType() { return EventType::WindowResize; }
	virtual EventType getType() const override { return GetStaticType(); }

private:
	uint32_t m_width;
	uint32_t m_height;
};

class WindowCloseEvent : public Event {
public:
	static EventType GetStaticType() { return EventType::WindowClose; }
	virtual EventType getType() const override { return GetStaticType(); }
};
#endif // __WINDOWEVENT_h__

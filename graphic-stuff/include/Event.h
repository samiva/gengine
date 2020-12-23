#ifndef __EVENT_h__
#define __EVENT_h__
#include "pch.h"

enum class EventType {
	None = 0,
	KeyPress, KeyRelease,
	WindowResize, WindowClose,
	MouseMove
};

class Event {
public:
	virtual ~Event() {}
	virtual EventType getType() const = 0;
	bool handled=false;
};

class EventDispatcher {
public: 
	EventDispatcher(Event& e):m_event(e)
	{
	}

	template<typename T, typename F>
	bool dispatch(const F& func) {
		if (m_event.getType() == T::GetStaticType()) {
			m_event.handled = func(static_cast<T&>(m_event));
				return true;
		}
		return false;
	}
protected:
	Event& m_event;
};
#endif // __EVENT_h__

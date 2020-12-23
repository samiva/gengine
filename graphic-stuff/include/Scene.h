#ifndef __SCENE_h__
#define __SCENE_h__
#include "pch.h"
class Event;

class Scene {
public:
	virtual bool init() = 0;
	virtual void update(float dt) = 0;
	virtual void onEvent(Event& e) = 0;
	virtual void onEnd() = 0;
};
#endif // __SCENE_h__

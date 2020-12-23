#ifndef __APPLICATION_h__
#define __APPLICATION_h__
#include "pch.h"
#include "Base.h"
#include "WindowEvent.h"
#include "Window.h"
#include "Scene.h"
#include "StreamRedirector.h"

class Application {
public:
	Application(const std::string& name = "Test");
	virtual ~Application();

	void pushScene(Scene* scene);
	void onEvent(Event& e);
	bool init();
	void run();
	void update(float dt);
	void shutdown();
	bool onWindowClose(WindowCloseEvent& e);
	bool onWindowResize(WindowResizeEvent& e);
private:
	// Currently one scene at a time
	ScopedPtr<Scene> m_scene;
	ScopedPtr<Window> m_window;
	bool m_running = true;
};

/**
 * This need to be implemented 
 *
 * @return Application*
 */
 Application* CreateApp();
#endif // __APPLICATION_h__

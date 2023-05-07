#include "pch.h"
#include "Application.h"
#include "Event.h"
#include "WindowEvent.h"
#include "Scene.h"
#include "SDL.h"
#include "ImageHandler.h"
#include "glew.h"
#include "Renderer3D.h"
#include "Logger.h"
#include "ObjLoader.h"

void GLAPIENTRY
MessageCallback(GLenum source,
	GLenum type,
	GLuint id,
	GLenum severity,
	GLsizei length,
	const GLchar* message,
	const void* userParam)
{
	FILE* errfile = fopen("Error.txt", "a");
	fprintf(errfile, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
		(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
		type, severity, message);
	fclose(errfile);
}

Application::Application(const std::string& name /*= "Test"*/)
{
	
}

Application::~Application()
{

}

bool Application::init()
{
	FILE* f = fopen("error.txt", "w");
	fclose(f);

	SDL_version vers;
	SDL_VERSION(&vers);
	printf("Compiled version %d.%d.%d\n", vers.major, vers.minor, vers.patch);

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
		std::cerr << "Failed to initialize SDL" << std::endl;
		return false;
	}

	Logger::Init("log.txt");
	ImageHandler::Init();

	WindowProps props{ "test", 100,100, 800,600 };
	m_window = Window::Create(props);
	m_window->setEventCallbackFn(std::bind(&Application::onEvent, this, std::placeholders::_1));
	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(MessageCallback, 0);

	std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;

	m_scene->init();

	return true;
}

void Application::pushScene(Scene* scene)
{
	m_scene = ScopedPtr<Scene>(scene);
}

void Application::onEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.dispatch<WindowCloseEvent>(std::bind(&Application::onWindowClose, this, std::placeholders::_1));
	dispatcher.dispatch<WindowResizeEvent>(std::bind(&Application::onWindowResize, this, std::placeholders::_1));
	if (!e.handled) {
		m_scene->onEvent(e);
	}
}

void Application::run()
{
	uint32_t prevticks = SDL_GetTicks();
	while (m_running)
	{
		uint32_t currTicks = SDL_GetTicks();
		update(static_cast<float>(currTicks-prevticks));
		prevticks = currTicks;
		m_window->onUpdate();
	}
}

void Application::update(float dt)
{
	m_scene->update(dt);
}

void Application::shutdown()
{
	m_scene->onEnd();
	Renderer3D::Shutdown();
	Logger::Shutdown();
}

bool Application::onWindowClose(WindowCloseEvent& e)
{
	m_running = false;
	return true;
}

bool Application::onWindowResize(WindowResizeEvent& e)
{
	return false;
}
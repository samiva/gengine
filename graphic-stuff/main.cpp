#include "pch.h"
#include "SDL.h"
#include "StreamRedirector.h"
#include "glew.h"
#include "VertexArray.h"
#include "ShaderProgram.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

#include "WindowsWindow.h"

#include "Buffers.h"
#include "Renderer3D.h"
#include "RenderCommand.h"
#include "Texture.h"
#include "Framebuffer.h"
#include "ImageHandler.h"
#include "SDL_image.h"
#include "Camera3D.h"
#include "WindowEvent.h"
#include "Application.h"
#include "LoggerAPI.h"

//void GLAPIENTRY
//MessageCallback(GLenum source,
//	GLenum type,
//	GLuint id,
//	GLenum severity,
//	GLsizei length,
//	const GLchar* message,
//	const void* userParam)
//{
//	FILE* errfile = fopen("Error.txt", "a");
//	fprintf(errfile, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
//		(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
//		type, severity, message);
//	fclose(errfile);
//}
const int Width = 800;
const int Height = 600;
 bool myexit = false;

bool onWindowClose(WindowCloseEvent& e);
bool onWindowResize(WindowResizeEvent& e);

bool init() {
	//FILE* f = fopen("error.txt", "w");
	//fclose(f);
	//SDL_version vers;
	//SDL_VERSION(&vers);
	//printf("Compiled version %d.%d.%d\n", vers.major, vers.minor, vers.patch);

	//if (SDL_Init(SDL_VIDEO_OPENGL | SDL_INIT_EVENTS) != 0) {
	//	std::cerr << "Failed to initialize SDL" << std::endl;
	//	return false;
	//}

	//ImageHandler::Init();

	return true;
}

void onEvent(Event& e) {
	EventDispatcher dispatcher(e);
	dispatcher.dispatch<WindowCloseEvent>(std::bind(onWindowClose, std::placeholders::_1));
}

int main(int argc, char *argv[]) {
	
	//StreamRedirector sredirector;
	LoggerAPI logger("log.txt");
	logger.writeInfoString("hello");
	init();

	
	auto app = CreateApp();
	if (!app->init()){ 
		std::cerr << "App initialization failed" << std::endl;
		return 1;
	}
	app->run();
	app->shutdown();
	delete app;
	return 0;
}

  bool onWindowClose(WindowCloseEvent& e) {
	myexit = true;
	return true;
}
bool onWindowResize(WindowResizeEvent& e)
{
	Renderer3D::OnResize(e.getWidth(), e.getHeight());
	return false;
}
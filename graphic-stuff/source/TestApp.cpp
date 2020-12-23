#include "pch.h"
#include "TestApp.h"
#include "TestScene.h"

TestApp::TestApp()
{
	pushScene(new TestScene);
}

Application* CreateApp() {
	return new TestApp;
}

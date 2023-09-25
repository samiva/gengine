#include "pch.h"
#include "TestScene.h"
#include "Buffers.h"
#include "ext/matrix_transform.hpp"
#include "Renderer3D.h"
#include "RenderCommand.h"
#include "ObjLoader.h"

bool TestScene::init()
{
	float triangle[] = { 0.0f, 1.0f, 0.0f,	1.0f,0.0f,0.0f,
						-1.0f,0.0f, 0.0f,		0.0f,1.0f,0.0f,
						1.0f, 0.0f,0.0f,		0.0f,0.0f,1.0f };
	unsigned int indices[] = { 0,1,2 };

	// Quad
	float quad[] = {	-1.0, 1.0, 0.0f,		0.0f,1.0f,
						-1.0, -1.0, 0.0f,		0.0f,0.0f,
						1.0,-1.0, 0.0f,		1.0f,0.0f,
						1.0, 1.0,0.0f,		1.0f,1.0f };
	unsigned int quadIndices[] = {0,1,2,
								  0,2,3};

	m_meshCube = ScopedPtr<Mesh>(ObjLoader("/Models/cube.obj").toMesh());

	m_material = CreateScopedPtr<Material>(new ShaderProgram("FlatColorShader"));
	
	m_material->setValue("U_color", glm::vec4(1.0f,0.1f,0.1f,1.0f));
	m_camera = CreateSharedPtr<Camera3D>();
	RenderCommand::setClearColor(0.0f, 0.0f, .4f, 1.0f);
	
	return true;
}

void TestScene::onEvent(Event& e)
{
}

void TestScene::update(float dt)
{
	
	// Renderer3D::Submit(mesh, mat, T); 
	glm::vec3 pos{ 0.0f,0.0f,5.0f };
	m_rotY += .1f*dt;
	auto T = glm::translate(glm::mat4(1.0f), pos)*glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), { 1,0,0 })
		* glm::rotate(glm::mat4(1.0f),  glm::radians(m_rotY), glm::vec3(0, 1, 0));
	RenderCommand::Clear(ClearFlags::Depth|ClearFlags::Color);
	Renderer3D::BeginScene(*m_camera);
	Renderer3D::Submit(m_meshCube->getVertexArray(), *m_material, T);
	Renderer3D::EndScene();
}

void TestScene::onEnd()
{
}
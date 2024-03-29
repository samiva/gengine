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

	auto vaTri = VertexArray::Create();

	auto vb = VertexBuffer::Create();
	vb->setData(static_cast<void*>(triangle), sizeof(triangle));
	Layout layout;
	layout.addMember<float>(3);
	layout.addMember<float>(3);
	vb->setLayout(layout);
	vaTri->addVertexBuffer(vb);
	auto ib = IndexBuffer::Create();
	ib->setData(static_cast<void*>(indices), sizeof(indices), sizeof(indices) / sizeof(indices[0]));
	vaTri->addIndexBuffer(ib);
	m_meshTri = ScopedPtr<Mesh>(Mesh::Create());
	m_meshTri->setVertexArray(vaTri);
	
	
	m_meshCube = ScopedPtr<Mesh>(ObjLoader("../Res/Models/cube.obj").toMesh());

	m_vaScreenQuad = ScopedPtr<VertexArray>( VertexArray::Create());
	auto vbsq = VertexBuffer::Create();

	vbsq->setData(static_cast<void*>(quad), sizeof(quad));
	Layout l;
	l.addMember<float>(3);
	l.addMember<float>(2);
	vbsq->setLayout(l);

	auto ibsq = IndexBuffer::Create();
	ibsq->setData(static_cast<void*>(quadIndices), sizeof(quadIndices), sizeof(quadIndices) / sizeof(quadIndices[0]));
	m_vaScreenQuad->addIndexBuffer(ibsq);

	m_triangleShader = CreateSharedPtr<ShaderProgram>("Shader");
	m_screenShader = CreateSharedPtr<ShaderProgram>("QuadShader");

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
	Renderer3D::Submit(m_meshCube->getVertexArray(), *m_triangleShader, T);
	Renderer3D::EndScene();
}

void TestScene::onEnd()
{
}
#include "pch.h"
#include "Renderer3D.h"
#include "RenderCommand.h"
Renderer3D::RendererData Renderer3D::s_data;

void Renderer3D::BeginScene(Camera3D& camera)
{
	// Store camera viewProjection to renderer data
	Renderer3D::s_data.viewProjectionMatrix = camera.getViewProjection();
}

void Renderer3D::EndScene()
{

}

void Renderer3D::Submit(VertexArray* va,  ShaderProgram& shader)
{
	shader.bind();
	GLint loc = shader.getUniformLocation("texture0");
	glUniform1i(loc, 0);
	va->bind();
	RenderCommand::Draw(va);
}

void Renderer3D::Submit(VertexArray* va,  ShaderProgram& shader, glm::mat4 M)
{
	auto mvp = s_data.viewProjectionMatrix*M;
	shader.bind();
	shader.setUniformMatrix("_mvp", mvp);
	va->bind();
	RenderCommand::Draw(va);
}

void Renderer3D::Submit(VertexArray* va, Material& mat, glm::mat4& T)
{
	auto mvp = s_data.viewProjectionMatrix*T;
	mat.bind();
	
}
void Renderer3D::OnResize(uint32_t width, uint32_t height)
{
	RenderCommand::ResizeViewPort(width,height);
}

void Renderer3D::Shutdown()
{
	RenderCommand::Shutdown();
}
#ifndef __TESTSCENE_h__
#define __TESTSCENE_h__
#include "pch.h"
#include "Base.h"
#include "Scene.h"
#include "VertexArray.h"
#include "ShaderProgram.h"
#include "Framebuffer.h"
#include "Camera3D.h"
#include "Mesh.h"

class TestScene : public Scene
{

public:

	virtual bool init() override;
	virtual void onEvent(Event& e) override;
	virtual void update(float dt) override;
	virtual void onEnd() override;

private:
	ScopedPtr<VertexArray>  m_vaScreenQuad;
	ScopedPtr<Mesh> m_meshTri;
	ScopedPtr<Mesh> m_meshCube;
	SharedPtr<ShaderProgram> m_triangleShader, m_screenShader;
	SharedPtr<Framebuffer> m_fbo;
	SharedPtr<Camera3D> m_camera;

	float m_rotY = 0.0f;
};
#endif // __TESTSCENE_h__

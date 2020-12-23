#ifndef __RENDERER3D_H__
#define __RENDERER3D_H__
#include "pch.h"
#include "VertexArray.h"
#include "ShaderProgram.h"
#include "glm.hpp"
#include "Camera3D.h"
#include "Material.h"

class Renderer3D {
public:
	static void BeginScene(Camera3D& camera);
	static void EndScene();
	static void Submit(VertexArray* va,  ShaderProgram& shader);
	static void Submit(VertexArray* va, Material& mat, glm::mat4& T);
	static void Submit(VertexArray* va,  ShaderProgram& shader, glm::mat4 T);
	static void OnResize(uint32_t width, uint32_t height);
	static void Shutdown();
private:
	struct RendererData {
		glm::mat4 viewProjectionMatrix;
	};

	static RendererData s_data;
};

#endif // !__RENDERER3D_H__


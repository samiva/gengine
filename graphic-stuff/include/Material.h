#ifndef __MATERIAL_h__
#define __MATERIAL_h__
#include "pch.h" 
#include "ShaderProgram.h"
#include <map>
#include "glm.hpp"
#include "gtc/type_ptr.hpp"

class Material {
public:
	Material(ShaderProgram* shader) 
		: m_shader(shader) {}

	void setValue(std::string u_name, const glm::mat4& value) {
		m_shader->bind();
		m_shader->setUniformMatrix(u_name, value);
	}

	void setValue(std::string u_name, const glm::vec4& value) {
		m_shader->bind();
		m_shader->setUniformVector(u_name, value);
	}

	void setValue(std::string u_name, const glm::vec3& value) {
		m_shader->bind();
		m_shader->setUniformVector(u_name, value);
	}

	void bind() {
		m_shader->bind();
	}

	void unbind() {
		m_shader->unbind();
	}
	

private:
	ShaderProgram* m_shader;
};

#endif // __MATERIAL_h__

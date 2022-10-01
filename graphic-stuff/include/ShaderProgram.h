#ifndef __SHADERPROGRAM_H__
#define __SHADERPROGRAM_H__

#include "pch.h"
#include "glew.h"

#include "glm.hpp"

struct ShaderInfo{
	std::string path;
	GLenum type;
};

class ShaderProgram {
public:
	ShaderProgram() = default;
	ShaderProgram(std::string vshaderPath, std::string fshaderPath);
	ShaderProgram(std::string shaderName);
	~ShaderProgram();
	void createProgram(std::string shaderName);
	void createProgram(std::string vshaderPath, std::string fshaderPath);

	inline const GLuint getShaderProgram() { return m_program; }
	inline const GLuint getPositionAttribLoc() { return 0; }
	inline const GLuint getColorAttribLoc() { return 1; }
	inline const GLuint getNormalAttribLoc() { return 2; }

	void bind();
	void unbind();

	inline const std::string &modelViewProjectionMatrix() { return m_modelviewProjection; }
	inline const std::string &modelMatrix() { return m_model; }
	inline const std::string &viewMatrix() { return m_view; }
	inline const std::string &color() { return m_color; }
	inline const std::string &lightPosition() { return m_lightPosition; }
	
	void setUniformMatrix(const std::string& name, const glm::mat4& mat);
	void setUniformVector(const std::string& name, const glm::vec4& vec);
	void setUniformVector(const std::string& name, const glm::vec3& vec);
	void setUniformVector(const std::string& name, const glm::vec2& vec);
	
	GLint getUniformLocation(const std::string& name);
private:	
	GLuint m_program;
	std::string m_modelviewProjection;
	std::string m_model;
	std::string m_view;
	std::string m_color;
	std::string m_lightPosition;


	GLuint createShader(const std::string& src, GLenum type);
	void loadSource(const std::string& path, std::string& src);
	void shaderError(GLint shader);
	void programError();
};
#endif // !__SHADERPROGRAM_H__
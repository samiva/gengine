#include "pch.h"
#include "ShaderProgram.h"
#include<gtc/type_ptr.hpp>

using glm::value_ptr;

ShaderProgram::ShaderProgram(std::string vshaderPath, std::string fshaderPath)
{
	createProgram(vshaderPath, fshaderPath);
}

ShaderProgram::ShaderProgram(std::string shaderName)
{
	std::string vshaderPath = "../Res/Shader/" + shaderName + ".vs";
	std::string fshadePath = "../Res/Shader/" + shaderName + ".fs";
	createProgram(vshaderPath, fshadePath);
}
ShaderProgram::~ShaderProgram()
{
}

void ShaderProgram::createProgram(std::string shaderName)
{
	std::string vshaderPath = "../Res/Shader/" + shaderName + ".vs";
	std::string fshadePath = "../Res/Shader/" + shaderName + ".fs";
	createProgram(vshaderPath, fshadePath);
}

void ShaderProgram::createProgram(std::string vshaderPath, std::string fshaderPath)
{
	m_program = glCreateProgram();
	GLuint vshader = createShader(vshaderPath, GL_VERTEX_SHADER);
	glAttachShader(m_program, vshader);

	GLuint fshader = createShader(fshaderPath, GL_FRAGMENT_SHADER);
	glAttachShader(m_program, fshader);

	// Link the shader program
	glLinkProgram(m_program);
	GLint linked;
	glGetProgramiv(m_program, GL_LINK_STATUS, &linked);
	if (linked != GL_TRUE) {
		programError();
	}

	glValidateProgram(m_program);
	GLint valid;
	glGetProgramiv(m_program, GL_VALIDATE_STATUS, &valid);
	if(valid!= GL_TRUE) {
		programError();
	}
}


void ShaderProgram::bind()
{
	glUseProgram(m_program);
}

void ShaderProgram::unbind()
{
	glUseProgram(0);
}

void ShaderProgram::setUniformMatrix(const std::string & name, const glm::mat4 & mat)
{
	GLint loc = getUniformLocation(name);
	if (loc != -1)
		glUniformMatrix4fv(loc, 1, GL_FALSE, value_ptr(mat));
}

void ShaderProgram::setUniformVector(const std::string & name, const glm::vec4 & vec)
{
	GLint loc = getUniformLocation(name);
	if (loc != -1)
		glUniform4fv(loc, 1, value_ptr(vec));
}

void ShaderProgram::setUniformVector(const std::string & name, const glm::vec3 & vec)
{
	GLint loc = getUniformLocation(name);
	if (loc != -1)
		glUniform3fv(loc,1, value_ptr(vec));
}

void ShaderProgram::setUniformVector(const std::string & name, const glm::vec2 & vec)
{
	GLint loc = getUniformLocation(name);
	if (loc != -1)
		glUniform2fv(loc, 1, value_ptr(vec));
}

GLint ShaderProgram::getUniformLocation(const std::string & name)
{
	GLint i = glGetUniformLocation(m_program, name.c_str());;
	//std::cout <<"SHADER UNIFORM: "<< name << " : " << i << std::endl;
	return glGetUniformLocation(m_program, name.c_str());
}

GLuint ShaderProgram::createShader(const std::string& path, GLenum shaderType)
{
	std::string src;
	loadSource(path, src);
	const GLchar* shadersrc = src.c_str();
	const GLint length = static_cast<GLint>(src.length());

	GLuint shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shadersrc, &length);
	glCompileShader(shader);
	GLint compiled;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
	if (compiled != GL_TRUE) {
		shaderError(shader);
	}

	return shader;
}

void ShaderProgram::loadSource(const std::string& path, std::string& src)
{
	std::ifstream ifs(path.c_str(), std::ifstream::binary);
	
	if (!ifs.is_open()) {
		char buff[1024];
		strerror_s(buff,errno);
		std::cerr << "Open file fail: " << buff<<std::endl;
		return;
	}
	ifs.seekg(0, ifs.end);
	size_t sz = ifs.tellg();
	ifs.seekg(0, ifs.beg);

	src.resize(sz);
	ifs.read(&src[0], src.size());
}

void ShaderProgram::shaderError(GLint shader)
{
	GLsizei maxlen = 0;
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxlen);
	std::string estr;
	estr.resize(maxlen);
	GLsizei len = 0;
	glGetShaderInfoLog(shader, maxlen, &len, &estr[0]);
	std::cerr << "Shader error: " << estr << std::endl;
}
void ShaderProgram::programError()
{
	GLsizei maxlen = 0;
	glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &maxlen);
	std::string estr;
	estr.resize(maxlen);

	GLsizei len = 0;
	glGetProgramInfoLog(m_program, maxlen, &len, &estr[0]);
	std::cerr << "Shader program error: " << estr << std::endl;
}

#include "pch.h"
#include "OpenGLTexture2D.h"
#include "ImageHandler.h"

OpenGLTexture2D::OpenGLTexture2D(const std::string& filePath)
	:m_internalFormat(GL_RGBA8), m_baseFormat(GL_RGBA)
{
	auto img = ImageHandler::LoadImage(filePath);
	m_width = img.width;
	m_height = img.height;
	glCreateTextures(GL_TEXTURE_2D, 1, &m_rendererId);
	glTextureStorage2D(m_rendererId, 1, m_internalFormat, m_width, m_height);
	glTextureParameteri(m_rendererId, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTextureParameteri(m_rendererId, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	// Set texture image
	glTextureSubImage2D(m_rendererId, 0, 0, 0, m_width, m_height, m_baseFormat, GL_UNSIGNED_INT_8_8_8_8, img.data);

}

OpenGLTexture2D::OpenGLTexture2D(uint32_t width, uint32_t height)
	:m_width(width), m_height(height), m_internalFormat(GL_RGBA8), m_baseFormat(GL_RGBA)
{
	glCreateTextures(GL_TEXTURE_2D, 1, &m_rendererId);
	glTextureStorage2D(m_rendererId, 1,m_internalFormat,m_width, m_height);
	glTextureParameteri(m_rendererId, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTextureParameteri(m_rendererId, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

OpenGLTexture2D::~OpenGLTexture2D()
{
	glDeleteTextures(1, &m_rendererId);
}

void OpenGLTexture2D::bind(uint32_t slot)
{
	glBindTextureUnit(slot, m_rendererId);
}

void OpenGLTexture2D::setData(void* data)
{
	// #NOTE: width and height must be image's width and height.	
	glTextureSubImage2D(m_rendererId, 0, 0, 0, m_width, m_height, m_baseFormat, GL_UNSIGNED_INT_8_8_8_8, data);
}

// #NOTE: ImageDescriptor is a quick fix to get the width and height of the image. For testing...
void OpenGLTexture2D::setData(const ImageDescriptor& desc)
{
	glTextureSubImage2D(m_rendererId, 0, 0, 0, desc.width, desc.height, m_baseFormat, GL_UNSIGNED_INT_8_8_8_8, desc.data);
}
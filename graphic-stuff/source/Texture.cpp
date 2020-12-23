#include "pch.h"
#include "Texture.h"
#include "OpenGLTexture2D.h"

SharedPtr<Texture2D> Texture2D::Create(const std::string& fileName)
{
	return CreateSharedPtr<OpenGLTexture2D>(fileName);
}

SharedPtr<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
{
	return CreateSharedPtr<OpenGLTexture2D>(width, height);
}
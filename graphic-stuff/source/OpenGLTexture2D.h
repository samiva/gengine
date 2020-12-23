#ifndef __OPENGLTEXTURE_h__
#define __OPENGLTEXTURE_h__
#include "pch.h"
#include "Texture.h"

#include "glew.h"

class OpenGLTexture2D : public Texture2D
{
public:

	/**
	 *
	 *
	 * @param filePath to image file.
	 */
	OpenGLTexture2D(const std::string& filePath);



	/**
	 *
	 *
	 * @param width
	 * @param height
	 */
	OpenGLTexture2D(uint32_t width, uint32_t height);

	virtual ~OpenGLTexture2D();

	virtual void bind(uint32_t slot = 0) override;

	virtual uint32_t getWidth() override { return m_width; }

	virtual uint32_t getHeight() override { return m_height; }
	virtual uint32_t getRendererId() override { return m_rendererId; }
	virtual void setData(void* data) override;


	virtual void setData(const ImageDescriptor& desc) override;

private:
	uint32_t m_rendererId;
	uint32_t m_width;
	uint32_t m_height;
	GLenum m_internalFormat, m_baseFormat;
};
#endif // __OPENGLTEXTURE_h__
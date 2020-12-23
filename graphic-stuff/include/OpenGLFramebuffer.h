#ifndef __OPENGLFRAMEBUFFER_h__
#define __OPENGLFRAMEBUFFER_h__
#include "pch.h"
#include "Framebuffer.h"
class OpenGLFramebuffer : public Framebuffer
{
public:
	OpenGLFramebuffer(const FramebufferSpecification& spec);
	~OpenGLFramebuffer();

	virtual void bind() override;

	virtual void unbind() override;

	virtual void invalidate() override;

	virtual uint32_t getRenderId() override { return m_rendererID; }

	virtual uint32_t getColorAttachmentId() override { return m_colorAttachmentId; }

	virtual uint32_t getDepthStencilAttachmentId() override { return m_depthStencilAttachmenId; }

	virtual void bindColorAttachmentTexture(uint32_t slot = 0) override;

private:
	uint32_t m_rendererID;
	uint32_t m_colorAttachmentId;
	uint32_t m_depthStencilAttachmenId;
	FramebufferSpecification m_spec;
};

#endif // __OPENGLFRAMEBUFFER_h__

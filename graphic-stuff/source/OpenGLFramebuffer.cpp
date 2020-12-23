#include "pch.h"
#include "OpenGLFramebuffer.h"

OpenGLFramebuffer::OpenGLFramebuffer(const FramebufferSpecification& spec)
	: m_spec(spec)
{
	invalidate();
}

OpenGLFramebuffer::~OpenGLFramebuffer()
{
	glDeleteTextures(1, &m_colorAttachmentId);
	glDeleteTextures(1, &m_depthStencilAttachmenId);
	glDeleteFramebuffers(1, &m_rendererID);
}
void OpenGLFramebuffer::bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_rendererID);
}

void OpenGLFramebuffer::unbind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void OpenGLFramebuffer::invalidate()
{
	if (glIsFramebuffer(m_rendererID)==GL_TRUE && glCheckNamedFramebufferStatus(m_rendererID,GL_FRAMEBUFFER)==GL_FRAMEBUFFER_COMPLETE) {
		glDeleteTextures(1, &m_colorAttachmentId);
		glDeleteTextures(1, &m_depthStencilAttachmenId);
		glDeleteFramebuffers(1, &m_rendererID);
	}
	glCreateFramebuffers(1, &m_rendererID);
	// Color attachment
	glCreateTextures(GL_TEXTURE_2D, 1, &m_colorAttachmentId);
	glTextureStorage2D(m_colorAttachmentId, 1, GL_RGBA8, m_spec.width, m_spec.height);
	glNamedFramebufferTexture(m_rendererID, GL_COLOR_ATTACHMENT0, m_colorAttachmentId, 0);

	// Depth and stencil attachment
	glCreateTextures(GL_TEXTURE_2D, 1, &m_depthStencilAttachmenId);
	glTextureStorage2D(m_depthStencilAttachmenId, 1, GL_DEPTH24_STENCIL8, m_spec.width, m_spec.height);
	glNamedFramebufferTexture(m_rendererID, GL_DEPTH_STENCIL_ATTACHMENT, m_depthStencilAttachmenId, 0);
	
	// Check if everything  is okay

	if (glCheckNamedFramebufferStatus(m_rendererID,GL_FRAMEBUFFER)!=GL_FRAMEBUFFER_COMPLETE)
	{
		std::cerr << "Error: framebuffer configure failed!!!" << std::endl;
	}
	else {
		std::cout << "framebuffer complete " << m_rendererID << std::endl;
	}
}

void OpenGLFramebuffer::bindColorAttachmentTexture(uint32_t slot)
{
	glBindTextureUnit(slot, m_colorAttachmentId);
}
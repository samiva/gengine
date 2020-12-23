#include "pch.h"
#include "Framebuffer.h"
#include "OpenGLFramebuffer.h"

SharedPtr<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec) {
	return CreateSharedPtr<OpenGLFramebuffer>(spec);
}

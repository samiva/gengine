#ifndef __FRAMEBUFFER_h__
#define __FRAMEBUFFER_h__
#include "pch.h"
#include "Base.h"
#include "glew.h"

struct FramebufferSpecification {
	uint32_t width;
	uint32_t height;
	bool swapBuffer = false;
};

class Framebuffer {
public:
	static SharedPtr<Framebuffer> Create(const FramebufferSpecification& spec = {800,600});
public:
	virtual ~Framebuffer() {}

	virtual void bind() = 0;
	virtual void unbind() = 0;

	virtual void invalidate() = 0;
	virtual uint32_t getRenderId() = 0;
	virtual uint32_t getColorAttachmentId() = 0;
	virtual uint32_t getDepthStencilAttachmentId() = 0;
	/**
	 * #TODO: Rethink in the future.
	 * Bind color attachment texture to texture slot and
	 * use it for sampling.
	 *
	 * @param slot: Number of slot where to bind.
	 */
	 virtual void bindColorAttachmentTexture(uint32_t slot = 0) = 0;
};
#endif // __FRAMEBUFFER_h__

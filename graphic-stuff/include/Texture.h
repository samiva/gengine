#ifndef __TEXTURE_h__
#define __TEXTURE_h__
#include "pch.h"
#include "Base.h"
#include "ImageDescriptor.h"

class Texture {
public:
public:
	virtual ~Texture() {}
	/**
	 * Binds texture to specified slot.
	 *
	 * @param slot
	 */
	virtual void bind(uint32_t slot = 0) = 0;
	//virtual void unbind() = 0;
	virtual void setData(void* data) = 0;
	virtual void setData(const ImageDescriptor& desc) = 0;
	virtual uint32_t getWidth() = 0;
	virtual uint32_t getHeight() = 0;
	virtual uint32_t getRendererId() = 0;
};

class Texture2D : public Texture
{
public:
	virtual ~Texture2D() {}
	static SharedPtr<Texture2D> Create(const std::string& fileName);
	static SharedPtr<Texture2D> Create(uint32_t width, uint32_t height);

};

#endif // __TEXTURE_h__

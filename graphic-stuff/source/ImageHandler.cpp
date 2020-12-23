#include "pch.h"
#include "ImageHandler.h"
#include "SDL_image.h"

// https://www.libsdl.org/projects/SDL_image/docs/SDL_image.pdf

void ImageHandler::Init()
{
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}
ImageDescriptor ImageHandler::LoadImage(const std::string& filePath)
{
	SDL_Surface* orig_img = IMG_Load(filePath.c_str());
	auto p = SDL_GetBasePath();

	if (orig_img == nullptr) {
		const char* err=IMG_GetError();
		std::cerr << "ERROR: Image load failed!!!" << std::endl;
		return ImageDescriptor{};
	}
	SDL_Surface * img;
	SDL_PixelFormat *fmt = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
	img = SDL_ConvertSurface(orig_img, fmt, 0);
	SDL_FreeFormat(fmt);
	if (img == nullptr) {
		std::cerr << "Error: Image cannot be converted to target format!!!" << std::endl;
	}
	SDL_FreeSurface(orig_img);

	// I'm not sure if this works at all
	void* pixels = std::malloc(img->pitch*img->h);
	if (SDL_MUSTLOCK(img))
		SDL_LockSurface(img);

	// std::memcpy(pixels, img->pixels, img->pitch*img->h);

	// Flip image
	for(int y =0;y<img->h;++y) {
		uint32_t* s_ptr = reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(img->pixels)+ ((y)*img->pitch));
		uint32_t* d_ptr = reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(pixels) + ((img->h - 1 - y)*img->pitch));
		std::memcpy(d_ptr,s_ptr, img->pitch);
	}

	if (SDL_MUSTLOCK(img))
		SDL_UnlockSurface(img);
	SDL_FreeSurface(img);
	ImageDescriptor imgDesc{ pixels, img->w,img->h };
	return imgDesc;
}

void ImageHandler::Shutdown()
{
	IMG_Quit();
}
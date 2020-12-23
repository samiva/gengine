#ifndef __IMAGEHANDLER_h__
#define __IMAGEHANDLER_h__
#include "pch.h"
#include "ImageDescriptor.h"

class ImageHandler {
public:
	static void Init();
	static ImageDescriptor LoadImage(const std::string& filePath);
	static void Shutdown();
};
#endif // __IMAGEHANDLER_h__
 

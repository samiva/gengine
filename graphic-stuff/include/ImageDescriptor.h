#ifndef __IMAGEDESCRIPTOR_h__
#define __IMAGEDESCRIPTOR_h__
#include "pch.h"
struct ImageDescriptor {
	void* data;
	int width = 0;
	int height = 0;
	int channels = 3;
};

#endif // __IMAGEDESCRIPTOR_h__

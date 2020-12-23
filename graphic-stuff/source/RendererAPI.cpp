#include "pch.h"
#include "RendererAPI.h"

//const uint8_t ColorBufferBit=1<<0;
//const uint8_t DepthBufferBit=1<<1;
//const uint8_t StencilBufferBit=1<<2;


RendererAPI::RenderAPI RendererAPI::s_api = RendererAPI::RenderAPI::OpenGL;

ClearFlags operator|(ClearFlags lhs, ClearFlags rhs)
{
	using underlying = std::underlying_type<ClearFlags>::type;
	return static_cast<ClearFlags>(
		static_cast<underlying>(lhs) |
		static_cast<underlying>(rhs));
}

ClearFlags operator&(ClearFlags lhs, ClearFlags rhs)
{
	using underlying = std::underlying_type<ClearFlags>::type;
	return static_cast<ClearFlags>(
		static_cast<underlying>(lhs) &
		static_cast<underlying>(rhs));
}
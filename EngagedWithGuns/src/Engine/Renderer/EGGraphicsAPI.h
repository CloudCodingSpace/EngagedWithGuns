#pragma once

#include <GLFW/glfw3.h>

namespace EG
{
	enum EGGraphicsAPI
	{
		EG_GRAPHICS_API_OPENGL,
		EG_GRAPHICS_API_VULKAN
	};

	static EGGraphicsAPI n_API = EG_GRAPHICS_API_OPENGL;

	static inline void GetGraphicsAPI() {
		glfwInit();
		if (glfwVulkanSupported())
		{
			n_API = EG_GRAPHICS_API_VULKAN;
		}
	}
}
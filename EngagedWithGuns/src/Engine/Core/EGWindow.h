#pragma once

#include <stdexcept>
#include <string>
#include <cstdint>

#include <vulkan/vulkan.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stb/stb_image.h>

#include "../Renderer/EGGraphicsAPI.h"

namespace EG
{
	struct EGWindowSpec
	{
		uint32_t width;
		uint32_t height;
		std::string title;
		std::string iconPath;
		bool fullscreen;
		bool vSync;
		bool IsHiddenWhileCreation;
		bool resizable;
	};

	class EGWindow
	{
	public:
		EGWindow(EG::EGWindowSpec spec);
		~EGWindow();

		void Show();
		void Update();
		bool IsCloseButtonPressed();

		const EG::EGWindowSpec* GetSpec() { return reinterpret_cast<const EG::EGWindowSpec*>(&m_Spec); }
		GLFWwindow* GetHandle() { return m_Hnd; }
	private:
		EG::EGWindowSpec m_Spec;
		GLFWwindow* m_Hnd;
	private:
		static void framebuffsizecallback(GLFWwindow* window, int w, int h);
	};
}
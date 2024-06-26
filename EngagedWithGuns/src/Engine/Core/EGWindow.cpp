#include "EGWindow.h"

namespace EG
{
	EGWindow::EGWindow(EG::EGWindowSpec spec) : m_Spec { spec }, m_Hnd { nullptr }
	{
		if (!glfwInit())
			throw std::runtime_error("Failed to initialize GLFW!");

		if (!spec.resizable)
			glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		if (spec.IsHiddenWhileCreation)
			glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

		if (n_API == EG_GRAPHICS_API_OPENGL)
		{
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		}
		else
		{
			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		}

		m_Hnd = glfwCreateWindow((int) spec.width, (int) spec.height, spec.title.c_str(), spec.fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
		if (!m_Hnd)
			throw std::runtime_error("Failed to create the window!");

		if (spec.vSync)
		{
			glfwSwapInterval(1);
		}

		if (!spec.iconPath.empty()) 
		{
			int channels;
			GLFWimage image[1];
			image->pixels = stbi_load(spec.iconPath.c_str(), &image->width, &image->height, &channels, 4);
			glfwSetWindowIcon(m_Hnd, 1, image);
		}

		glfwMakeContextCurrent(m_Hnd);
		glfwSetWindowUserPointer(m_Hnd, this);
		glfwSetFramebufferSizeCallback(m_Hnd, framebuffsizecallback);

		if (n_API == EG_GRAPHICS_API_OPENGL)
		{
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
				throw std::runtime_error("Failed to initialize OpenGL!");
		}
	}

	EGWindow::~EGWindow()
	{
		glfwDestroyWindow(m_Hnd);
		glfwTerminate();
	}

	void EGWindow::Show()
	{
		glfwShowWindow(m_Hnd);
	}

	void EGWindow::Update()
	{
		glfwSwapBuffers(m_Hnd);
		glfwPollEvents();
	}

	bool EGWindow::IsCloseButtonPressed()
	{
		return glfwWindowShouldClose(m_Hnd);
	}

	void EGWindow::framebuffsizecallback(GLFWwindow* window, int w, int h)
	{
		EG::EGWindow* win = (EG::EGWindow*)glfwGetWindowUserPointer(window);
		win->m_Spec.width = w;
		win->m_Spec.height = h;

		if (n_API == EG_GRAPHICS_API_OPENGL)
		{
			glViewport(0, 0, w, h);
		}
	}
}
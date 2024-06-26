#include "EGEngine.h"

namespace EG
{
	EGEngine::EGEngine(uint32_t width, uint32_t height, const std::string& title, bool IsFullscreen, bool vSync, bool IsHiddenInInit, bool IsResizable, const std::string& iconPath)
	{
		EG::EGWindowSpec spec{};
		spec.width = width;
		spec.height = height;
		spec.title = title;
		spec.IsHiddenWhileCreation = IsHiddenInInit;
		spec.fullscreen = IsFullscreen;
		spec.iconPath = iconPath;
		spec.vSync = vSync;
		spec.resizable = IsResizable;

		m_Window = std::make_shared<EG::EGWindow>(spec);
	}

	void EGEngine::Run()
	{
		if (n_API == EG_GRAPHICS_API_OPENGL)
		{
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glEnable(GL_DEPTH_TEST);
		}
		m_Window->Show();

		while (!m_Window->IsCloseButtonPressed())
		{
			if (n_API == EG_GRAPHICS_API_OPENGL)
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			OnUpdate();
			Render();
			m_Window->Update();
		}
	}

	void EGEngine::OnUpdate()
	{

	}

	void EGEngine::Render()
	{

	}
}
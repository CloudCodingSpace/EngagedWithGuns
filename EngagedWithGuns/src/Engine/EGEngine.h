#pragma once

#include <cstdint>
#include <string>
#include <memory>

#include "Core/EGWindow.h"

#define EG_STD_WIDTH   800
#define EG_STD_HEIGHT  600

namespace EG
{
	class EGEngine
	{
	public:
		EGEngine(uint32_t width, uint32_t height, const std::string& title, bool IsFullscreen = false, bool vSync = false, bool IsHiddenInInit = true, bool IsResizable = false, const std::string& iconPath = "");

		void Run();
	private:
		std::shared_ptr<EG::EGWindow> m_Window;
	private:
		void OnUpdate();
		void Render();
	private:
		// Static members
	};
}
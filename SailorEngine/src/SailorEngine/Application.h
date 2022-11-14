#pragma once

#include "Core.h"

namespace SailorEngine
{
	class SAILORENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


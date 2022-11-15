#include "Application.h"

#include "SailorEngine/Log.h"
#include "SailorEngine/Events/ApplicationEvent.h"

namespace SailorEngine
{
	Application::Application()
	{
	}
	
	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		SE_LOG_TRACE(e);
		
		while (true);
	}
}
#pragma once

#ifdef SL_PLATFORM_WINDOWS

extern SailorEngine::Application* SailorEngine::CreateApplication();

int main(int argc, char** argv)
{
	SailorEngine::Log::Init();
	SL_LOG_CORE_WARN("Init log !");
	SL_LOG_INFO("Hello ! Var={0}", 123);
	
	auto app = SailorEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif

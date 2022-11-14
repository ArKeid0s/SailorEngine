#pragma once

#ifdef SL_PLATFORM_WINDOWS

extern SailorEngine::Application* SailorEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = SailorEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif

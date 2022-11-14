#include <SailorEngine.h>

class Sandbox : public SailorEngine::Application
{
public:
	Sandbox()
	{
		
	}

	~Sandbox()
	{
		
	}
};

SailorEngine::Application* SailorEngine::CreateApplication()
{
	return new Sandbox();
}
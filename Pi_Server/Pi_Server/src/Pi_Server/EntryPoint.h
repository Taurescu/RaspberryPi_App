#pragma once

#ifdef PIS_PLATFORM_WINDOWS

extern PIS::Server* PIS::CreateServer();

int main(int argc, char **argv)
{
	PIS::Log::Init();

	PIS_WARN("SERVER");
	PIS_INFO("TESTING");

	auto app = PIS::CreateServer();
	app->Run();
	delete app;

	return 0;
}

#endif

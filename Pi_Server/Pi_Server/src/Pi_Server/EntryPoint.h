#pragma once
#include <vector>

#ifdef PIS_PLATFORM_WINDOWS

extern PIS::Server* PIS::CreateServer();

int main(int argc, char **argv)
{
	PIS::Log::Init();

	PIS_WARN("Initialized Log!");
	int b = 6;
	int* a = &b;
	PIS_INFO("Hello! {}", (void*)a);
	APP_ERROR("NO VAR");


	auto app = PIS::CreateServer();
	app->Run();
	delete app;

	return 0;
}

#endif

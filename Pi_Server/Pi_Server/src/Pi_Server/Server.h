#pragma once
#include "Core.h"

namespace PIS {

	class PIS_API Server
	{
	public:
		Server();
		virtual ~Server();

		void Run();
	};

	//To be defined in client
	Server* CreateServer();
}

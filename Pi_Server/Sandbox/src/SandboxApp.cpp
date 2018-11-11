#include "TCP.h"

class Sandbox : public PIS::Server
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

PIS::Server* PIS::CreateServer()
{
	return new Sandbox();
}
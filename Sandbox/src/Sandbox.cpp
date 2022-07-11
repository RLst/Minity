#include "Sandbox.h"

#include <stdio.h>

Sandbox::Sandbox()
{
}

Sandbox::~Sandbox()
{
}

MinityEngine::Core* MinityEngine::CreateCore()
{
	return new Sandbox();
}
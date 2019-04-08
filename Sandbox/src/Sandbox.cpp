#include "Sandbox.h"

#include <stdio.h>

Sandbox::Sandbox()
{
}

Sandbox::~Sandbox()
{
}

Minity::Core* Minity::CreateCore()
{
	return new Sandbox();
}
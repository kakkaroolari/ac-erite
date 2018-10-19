#include "Tracer.h"
#include <stdio.h>
#include <windows.h>


Tracer::Tracer()
{
}


Tracer::~Tracer()
{
}

// Do more overloads if needed
void Tracer::_trace(const char* input, int p)
{
	char* msgbuf = new char[100];
	const char* prefix = "[ERITE] ";
	strcpy(msgbuf, prefix);
	sprintf_s(msgbuf + strlen(prefix), 100 - strlen(prefix), input, p);
	OutputDebugString(msgbuf);
}

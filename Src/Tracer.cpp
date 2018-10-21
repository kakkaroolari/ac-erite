#include "Tracer.h"
#include <stdio.h>
#include <windows.h>


const char *Tracer::_prefix = "[ERITE] ";
const int Tracer::MaxLen = 200;
const size_t Tracer::Begin = strlen(_prefix);
const size_t Tracer::End = MaxLen - Begin;


Tracer::Tracer()
{
}


Tracer::~Tracer()
{
}

// Do more overloads if needed
void Tracer::_trace(const char* input, int p)
{
	char msgbuf[MaxLen] = { 0 };
	_formatInternal(msgbuf);
	sprintf_s(msgbuf + Begin, End, input, p);
	OutputDebugString(msgbuf);
}

void Tracer::_trace(const char* input, const char* p)
{
	char msgbuf[MaxLen] = { 0 };
	_formatInternal(msgbuf);
	sprintf_s(msgbuf + Begin, End, input, p);
	OutputDebugString(msgbuf);
}

void Tracer::_formatInternal(char* msgbuf)
{
	strcpy(msgbuf, _prefix);
}

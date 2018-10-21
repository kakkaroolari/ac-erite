#pragma once
class Tracer
{
public:
	Tracer();
	~Tracer();

public:
	static void _trace(const char* input, int p);
	static void _trace(const char* input, const char* p);

private:
	static const char* _prefix;
	static void _formatInternal(char*);
	static const int MaxLen;
	static const size_t Begin;
	static const size_t End;

};


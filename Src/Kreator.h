#ifndef _KREATOR_H_
#define _KREATOR_H_

#include <string>

class Kreator
{
public:
	Kreator();
	~Kreator();

	void ReadAndExecuteSpec(std::string jsonFile);
};
#endif _KREATOR_H_


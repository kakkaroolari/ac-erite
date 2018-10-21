#include "Kreator.h"
#include "json.hpp"
#include <fstream>
#include "Tracer.h"

using namespace std;

Kreator::Kreator()
{
}


Kreator::~Kreator()
{
}


void Kreator::ReadAndExecuteSpec(std::string jsonFile)
{
	// read a JSON file
	try {
		std::ifstream i(jsonFile);
		nlohmann::json j;
		i >> j;
		Tracer::_trace("json size: %d", static_cast<int>(j.size()));
	}
	catch (exception& e) {
		Tracer::_trace("ReadAndExecuteSpec ex: %s", e.what());
	}
}

#ifndef TCP1_INCLUDED
#include "Python.h"
#define TCP1_INCLUDED
#include <string>
#include <fstream>
#include <stdlib.h>

class TCP1 {
public:
	void start();
	void stop();
	void sendMessage(std::string);
	std::string getMessage();
};

#endif

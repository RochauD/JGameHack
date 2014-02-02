#ifndef TCP2_INCLUDED
#include "Python.h"
#define TCP2_INCLUDED
#include <string>
#include <fstream>
#include <stdlib.h>

class TCP2 {
public:
	void start();
	void stop();
	void sendMessage(std::string);
	std::string getMessage();
};

#endif

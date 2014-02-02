#include "TCP1.h"

void TCP1::start() {
	Py_Initialize();
  PyRun_SimpleString(
"MY_PORT=4446\n"
"OTHER_IP='127.0.0.1'\n"
"OTHER_PORT=4447\n"
"from socket import *\n"
"s1=socket(AF_INET, SOCK_STREAM)\n"
"s1.bind(('',MY_PORT))\n"
"s1.listen(1)\n"
"print 'Listening for connections.. '\n"
"q1,addr=s1.accept()\n"
"s2=socket(AF_INET, SOCK_STREAM)\n"
"s2.connect((OTHER_IP,OTHER_PORT))\n");
}

void TCP1::stop() {
	PyRun_SimpleString(
"s1.close()\n"
"s2.close()\n");
  Py_Finalize();
}





void TCP1::sendMessage(std::string s) {
	/*PyRun_SimpleString("q1.send(\"\"\"");
	PyRun_SimpleString(s.c_str());
	PyRun_SimpleString("\"\"\")\n");*/
	std::string s0 = "q1.send(\"\"\"";
	std::string s1 = "\"\"\")\n";
	PyRun_SimpleString((s0+s+s1).c_str());
}

std::string TCP1::getMessage() {
	std::string s;
	PyRun_SimpleString("d = open('storage_tcp1.txt','w')\n"
		"d.write(s2.recv(1024))\n"
		"d.close()\n");
	std::ifstream infile;
	infile.open("storage_tcp1.txt");
	getline(infile, s);
	return s;
}



#include <iostream>

int main() {
	TCP1 server = TCP1();
	server.start();
	std::cout << "\nI'm sending: 'Alpha'";
	server.sendMessage("Alpha");
	std::cout << "\nI got: "<<server.getMessage();
	std::cout << "\nI'm sending: 'Beta'";
	server.sendMessage("Beta");
	std::cout << "I got: " << server.getMessage();
	server.stop();
}

#include "TCP2.h"

void TCP2::start() {
	Py_Initialize();
PyRun_SimpleString("OTHER_PORT=4446\n"
	"OTHER_IP='127.0.0.1'\n"
	"MY_PORT=4447\n"
	"from socket import *\n"
	"s2=socket(AF_INET, SOCK_STREAM)\n"
	"s2.connect((OTHER_IP,OTHER_PORT))\n"
	"s1=socket(AF_INET, SOCK_STREAM)\n"
	"s1.bind(('',MY_PORT))\n"
	"s1.listen(1)\n"
	"print 'Listening for connections.. '\n"
	"q1,addr=s1.accept()\n");
}

void TCP2::stop() {
	PyRun_SimpleString(
"s1.close()\n"
"s2.close()\n");
  Py_Finalize();
}


void TCP2::sendMessage(std::string s) {
	std::string s0 = "q1.send(\"\"\"";
	std::string s1 = "\"\"\")\n";
	PyRun_SimpleString((s0+s+s1).c_str());
	/*PyRun_SimpleString("q1.send(\"\"\"");
	PyRun_SimpleString(s.c_str());
	PyRun_SimpleString("\"\"\")\n");*/
}

std::string TCP2::getMessage() {
	std::string s;
	PyRun_SimpleString("d = open('storage_tcp2.txt','w')\n"
		"d.write(s2.recv(1024))\n"
		"d.close()\n");
	std::ifstream infile;
	infile.open("storage_tcp2.txt");
	getline(infile, s);
	return s;
}

#include <iostream>

int main() {
	TCP2 server = TCP2();
	server.start();
	std::cout << "I got: " << server.getMessage();
	std::cout << "\nI'm sending: 'First Message'";
	server.sendMessage("First Message");
	std::cout << "\nI got: "<<server.getMessage();
	std::cout << "\nI'm sending: 'Second Message'";
	server.sendMessage("Second Message");
	server.stop();
}

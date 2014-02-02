#include "Python.h"

int
main(int argc, char *argv[])
{
  Py_SetProgramName(argv[0]);  /* optional but recommended */
  Py_Initialize();

/*PyRun_SimpleString("host1='127.0.0.1'");
  Py_Finalize();
PyRun_SimpleString("port2=4446");
  Py_Finalize();
PyRun_SimpleString("from socket import *");
  Py_Finalize();
PyRun_SimpleString("host2='127.0.0.1'");
  Py_Finalize();
PyRun_SimpleString("port1=4447");
  Py_Finalize();
PyRun_SimpleString("s2=socket(AF_INET, SOCK_STREAM)");
  Py_Finalize();
PyRun_SimpleString("s2.connect(('',port2))");
  Py_Finalize();
PyRun_SimpleString("s1=socket(AF_INET, SOCK_STREAM)");
  Py_Finalize();
PyRun_SimpleString("s1.bind(('',port1))");
  Py_Finalize();
PyRun_SimpleString("s1.listen(1)");
  Py_Finalize();
PyRun_SimpleString("print 'Listening for connections.. '");
  Py_Finalize();
PyRun_SimpleString("q1,addr=s1.accept()");
  Py_Finalize();
PyRun_SimpleString("while True:");
  Py_Finalize();
PyRun_SimpleString("	msg=s2.recv(1024)");
  Py_Finalize();
PyRun_SimpleString("	print 'Message from server : ' + msg");
  Py_Finalize();
PyRun_SimpleString("	data=raw_input('Enter data to be send: ')");
  Py_Finalize();
PyRun_SimpleString("	q1.send(data)");
  Py_Finalize();
PyRun_SimpleString("s1.close()");
  Py_Finalize();
PyRun_SimpleString("s2.close()");
  Py_Finalize();*/
PyRun_SimpleString("host1='127.0.0.1'\nport2=4446\nfrom socket import *\nhost2='127.0.0.1'\nport1=4447\ns2=socket(AF_INET, SOCK_STREAM)\ns2.connect(('',port2))\ns1=socket(AF_INET, SOCK_STREAM)\ns1.bind(('',port1))\ns1.listen(1)\nprint 'Listening for connections.. '\nq1,addr=s1.accept()\nwhile True:\n    msg=s2.recv(1024)\n    print 'Message from server : ' + msg\n    data=raw_input('Enter data to be send: ')\n    q1.send(data)\ns1.close()\ns2.close()\n");
  Py_Finalize();
  return 0;
}
#include "Python.h"

int
main(int argc, char *argv[])
{
  Py_SetProgramName(argv[0]);  /* optional but recommended */
  Py_Initialize();
  //PyRun_SimpleString("host1=\"127.0.0.1\"#t the server address to variable host1\nport1=4446# Sets the variable port1 to 4444\nfrom socket import * # Imports socket module\n\ns1=socket(AF_INET, SOCK_STREAM)\n\ns1.bind((\"\",port1))# Binds the socket. Note that the input to \n# the bind function is a tuple\ns1.listen(1)\n\n\nprint \"Listening for connections.. \"\n\nq1,addr=s1.accept() # Accepts incoming request from client and returns\n# socket and address to variables q and addr\n\n\nhost2=\"127.0.0.1\"            # Set the server address to variable host2\n \nport2=4447               # Sets the variable port2 to 4444\n\n \ns2=socket(AF_INET, SOCK_STREAM)      # Creates a socket\n \ns2.connect((host2,port2))          # Connect to server address\n \n\nwhile True:\n  data=raw_input(\"Enter data to be send: \") # Data to be send is stored in variable data from\n # user\n    q1.send(data) # Sends data to client\n\n    msg=s2.recv(1024)            # Receives data upto 1024 bytes and stores in variables msg\n   \n print \"Message from server : \" + msg\n \n\ns1.close() \ns2.close()                            # Closes the socket \n# End of code");
/*  PyRun_SimpleString("host1=\"127.0.0.1\"");
  Py_Finalize();
PyRun_SimpleString("port1=4446");
  Py_Finalize();
PyRun_SimpleString("from socket import *");
  Py_Finalize();
PyRun_SimpleString("s1=socket(AF_INET, SOCK_STREAM)");
  Py_Finalize();
PyRun_SimpleString("s1.bind((\"\",port1))");
  Py_Finalize();
PyRun_SimpleString("s1.listen(1)");
  Py_Finalize();
PyRun_SimpleString("print \"Listening for connections.. \"");
  Py_Finalize();
PyRun_SimpleString("q1,addr=s1.accept()");
  Py_Finalize();
PyRun_SimpleString("host2=\"127.0.0.1\"");
  Py_Finalize();
PyRun_SimpleString("port2=4447");
  Py_Finalize();
PyRun_SimpleString("s2=socket(AF_INET, SOCK_STREAM)");
  Py_Finalize();
PyRun_SimpleString("s2.connect((host2,port2))");
  Py_Finalize();
PyRun_SimpleString("while True:");
  Py_Finalize();
PyRun_SimpleString("    data=raw_input(\"Enter data to be send: \")");
  Py_Finalize();
PyRun_SimpleString("    q1.send(data)");
  Py_Finalize();
PyRun_SimpleString("    msg=s2.recv(1024)");
  Py_Finalize();
PyRun_SimpleString("    print \"Message from server : \" + msg");
  Py_Finalize();
PyRun_SimpleString("s1.close()");
  Py_Finalize();
PyRun_SimpleString("s2.close()");*/
  PyRun_SimpleString("host1='127.0.0.1'\nport1=4446\nfrom socket import *\ns1=socket(AF_INET, SOCK_STREAM)\ns1.bind(('',port1))\ns1.listen(1)\nprint 'Listening for connections.. '\nq1,addr=s1.accept()\nhost2='127.0.0.1'\nport2=4447\ns2=socket(AF_INET, SOCK_STREAM)\ns2.connect((host2,port2))\nwhile True:\n    data=raw_input('Enter data to be send: ')\n    q1.send(data)\n    msg=s2.recv(1024)\n    print 'Message from server : ' + msg\ns1.close()\ns2.close()\n");
  Py_Finalize();
  return 0;
}


/*#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}*/
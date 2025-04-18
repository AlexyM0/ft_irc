#ifndef SERVER_H
#define SERVER_H

#pragma once

#include <iostream>

class Server
{
     public:

           Server(int ac, char **av);
           ~Server();

            void inputCheck();

           class Error: public std::exception
		{
			public:
				virtual const char* what() const throw();
				Error(std::string const &msg);
				virtual ~Error() throw() {};
			private:
				std::string _msg;
		};

     private:

            std::string _portStr;
            int         _port;
            std::string _password;

};

#endif
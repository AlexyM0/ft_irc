#include "Server.hpp"


int main(int ac, char **av)
{
    try
    {
        Server serv(ac, av);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}
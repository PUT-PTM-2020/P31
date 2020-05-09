#include <iostream>
#include "../Inc/Level.hpp"

int main()
{
    Level l(true,true);
    std::string name = "C:\\Users\\dello\\Desktop\\testy\\leveltest.txt";
    l.save(name);
    return 0;
}
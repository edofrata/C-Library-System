#include "library.hpp"
#include <iostream>

int main()
{
    Utilities util;

    util.file_reader();

    while(!util.exit){
        util.start();
    }
    
}
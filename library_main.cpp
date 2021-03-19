#include "library.hpp"
#include <iostream>

int main()
{

    Utilities util;

    util.file_reader();
    // util.start();

// --------------------------- TEST ------------------------------------------
    printf("Sorted array: \n");
    for(int i =0; i < util.book_data.size() ; i ++){

        std::cout<< i << "   " << util.book_data[i].get_title() << std::endl; 

    }

//    std::cout << "\n\n THE SIZE IS: " << n << std::endl;


}
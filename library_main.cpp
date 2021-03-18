#include "library.hpp"
#include <iostream>

int main()
{

    Utilities util;

    util.file_reader();
    util.start();

    // --------------------------- TEST ------------------------------------------
    std::cout << "Title:             " << util.book_data.at(419).get_title() << std::endl;
    std::cout << "Author's:          " << util.book_data.at(419).get_authors() << std::endl;
    std::cout << "ISBN:              " << util.book_data.at(419).get_isbn() << std::endl;
    std::cout << "Quantity:          " << util.book_data.at(419).get_quantity() << std::endl;
    std::cout << "Size of the deque: " << util.book_data.size() << std::endl;
}
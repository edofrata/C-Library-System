#include "library.hpp"
#include <iostream>

int main()
{

    Data data;

    data.file_reader();
    data.start();
    std::cout << "Title:             " <<  data.book_data.at(0).get_title() << std::endl;
    std::cout << "Author's:          " << data.book_data.at(0).get_authors() << std::endl;
    std::cout << "ISBN:              " << data.book_data.at(0).get_isbn() << std::endl;
    std::cout << "Quantity:          " << data.book_data.at(0).get_quantity() << std::endl;
    std::cout << "Size of the deque: " << data.book_data.size() << std::endl;
}
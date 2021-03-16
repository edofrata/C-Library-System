// defining the header file if not defined
#ifndef _LIBRARY_H_
#define _LIBRARY_H_

// defining standard library
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

// declaring the classes needed
class Book
{

private:
    // declaring variables
    std::string title, authors, isbn; 
    int quantity;

public:
    // constructor
    Book(std::string title_, std::string authors_, std::string isbn_,  int quantity_)
    {

        title = title_;
        authors = authors_;
        isbn = isbn_;
        quantity = quantity_;

    }

    Book(){};
// ------------------ GETTER METHODS ---------------------
// method which returns the title
    std::string get_title() { return title; }

// method which returns the author(s)
    std::string get_authors() { return authors; }

// method which returns the ISBN
    std::string get_isbn() { return isbn; }

// method which returns the quantity
    int get_quantity() { return quantity; }
// --------------------------------------------------------

// reading file method
    void file_reader();
    std::vector<std::string> string_splitter(std::string line, std::string delimeter);
};

#endif
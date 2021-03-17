// defining the header file if not defined
#ifndef _LIBRARY_H_
#define _LIBRARY_H_

// defining standard library
#include <iostream>
#include <string>
#include <vector>
#include <deque>

// declaring the classes needed
class Book
{

private:
    // declaring variables
    std::string title, authors, isbn;
    int quantity;

public:
    // constructor
    Book(std::string title_, std::string authors_, std::string isbn_, int quantity_)
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
};

class Data
{

public:
    // reading file method
    void file_reader();
    void start();
    std::vector<std::string> string_splitter(std::string line, std::string delimeter);
    // deque of objects which will store all the books
    std::deque<Book> book_data;

protected:
// ----------------- SETTER METHODS --------------------------
    // Setting the new book
    void set_newBook(std::string title, std::string authors, std::string isbn, int quantity)
    {
        book_data.push_back(Book (title, authors, isbn, quantity));
    }
    // incresing quantity of the book

    void set_quantityBook(int index, int quantity)
    {
        book_data.at(index).get_quantity() + quantity;
    }
    // Removing the book
    void set_decrementBook(int index, int quantity)
    {
         book_data.at(index).get_quantity() - quantity;
    }
// ----------------------------------------------------------   
};

#endif
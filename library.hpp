// defining the header file if not defined
#ifndef _LIBRARY_H_
#define _LIBRARY_H_

// defining standard library
#include <iostream>
#include <random>  
#include <string>
#include <vector>
#include <deque>
#include <chrono>
#include <regex>

// declaring the classes needed
class Book
{

private:
    // declaring variables
    std::string title, authors, isbn;
    

public:

    int quantity;
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

    // void setQty(int num);
    // --------------------------------------------------------
};

class Utilities
{

public:
    void file_reader();                   // reading file method
    void start();                         //where the main menu is
    void print_books();                    //printing all the books


// -------------------- Book Methods ------------------------
    void adding_newBook(); //method which adds a new book to the data structure
    void increase_Books(); //method which increases the Books quantity
    void decreasement_Books(); //method which decreases the books quantity
    void searching_book(); //searching for a book
// ----------------------------------------------------------

// ------------------ ALGORITHM TECHNIQUES-----------------------------
    // partition method
    int partition(std::deque<Book>& data, int left, int right, int index);
    // Sorting method
    void quick_sorting(std::deque<Book*>& data, long int left, long int right, unsigned int index);
    // searching method
    std::deque<Book*> search(std::deque<Book*> &data, std::string word);
    
    // sorting method encapsulated with shuffling
    std::deque<Book*> encapsulated_sorting(std::deque<Book*>& data);
   
// ---------------------------------------------------------------------
    std::string toLowerCase(std::string); //ToLowerCase method which will be needed when searching for a string
    std::vector<std::string> string_splitter(std::string line, std::string delimiter);
    // deque of objects which will store all the books
    std::deque<Book*> book_data;
     std::deque<Book*> titles_found; //WHere the found books will finish
    int total;
    bool exit = false;
    

 
protected:
   
    // ----------------- SETTER METHODS --------------------------
    // Setting the new book
    void set_newBook(std::string title, std::string authors, std::string isbn, int quantity)
    {
        Book* book = new Book(title, authors, isbn, quantity);
        book_data.push_back(book);
    }
    // incresing quantity of the book

    int set_quantityBook(std::deque<Book*>& data, int index, int &quantity)
    {
        int total = (*data.at(index)).get_quantity() + quantity;
        
        (*data.at(index)).quantity = total;

        return total;
    }

    // Removing the book
    int set_decrementBook(std::deque<Book*>& data,int index, int &quantity)
    {
        total = (*data.at(index)).get_quantity() - quantity;
        
        (*data.at(index)).quantity = total;

        return total;
    }
    // ----------------------------------------------------------
};

#endif

    //   Book* book = new Book(data[0], data[1], data[2], stoi(data[3]));
                        // book_data.push_back(book));

                        // while(index > max_size || index < 0 )
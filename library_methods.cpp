#include "library.hpp"

#include <fstream>
#include <limits>
#include <algorithm>

// ------------------------ Main menu a new Book Method -----------------------
void Utilities::start()
{

    int choice;
    std::cout << "\n---------------------------------------" << std::endl;
    std::cout << "|   Welcome to the Library System!    |" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "| Adding    New Book      --------> 1 |" << std::endl;
    std::cout << "| Increase  Book Quantity --------> 2 |" << std::endl;
    std::cout << "| Decrement Book Quantity --------> 3 |" << std::endl;
    std::cout << "| Search    Book Title    --------> 4 |" << std::endl;
    std::cout << "| Exit                    --------> 0 |" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "\nPlease insert your choice:> ";

    std::cin >> choice;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nWRONG FROMAT!" << std::endl;
        start();
    }

    switch (choice)
    {

    case 0:
        std::cout << "\nSUCCESSFULLY EXITED!" << std::endl;
        std::exit(1);
        break;
    case 1:
        // adding new Book method
        adding_newBook();
        break;
    case 2:
        // Increasing Books Quantity method

        break;
    case 3:
        // Decreasing Book Quantity

        break;
    case 4:
        // searching title method

    default:
        std::cout << "\nTHERE IS NO SUCH CHOICE! PLEASE, TRY AGAIN!" << std::endl;
        start();
        break;
    }
}
// ----------------------------------------------------------------------------

// --------------------------- Adding a new Book Method -----------------------
void Utilities::adding_newBook()
{

    std::string title, authors, isbn;
    int quantity;

    // -------------- Title request -----------------
    std::cout << "\nPlease insert the name of the Book:> ";
    std::cin.ignore();
    std::getline(std::cin, title);
    // ---------------------------------------------
    // -------------- Autor(s) request -------------
    std::cout << "\nPlease insert the author(s):> ";
    std::getline(std::cin, authors);
    // ---------------------------------------------
    // -------------- ISBN request -----------------
    std::cout << "\nPlease insert the ISBN:> ";
    std::cin >> isbn;
    // ---------------------------------------------
    do
    {
        // -------------- Quantity request -------------
        std::cout << "\nPlease insert quantity:> ";
        std::cin >> quantity;
        // ---------------------------------------------
    } while (std::cin.fail());
    // adding the book to the data structure
    set_newBook(title, authors, isbn, quantity);

    int re_choice;
    std::cout << "BOOK ADDED!" << std::endl;

    do
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nWould you like to add another Book?" << std::endl;
        std::cout << "\n--------------" << std::endl;
        std::cout << "| Yes ----> 1 |" << std::endl;
        std::cout << "| No -----> 0 |" << std::endl;
        std::cout << "---------------" << std::endl;
        std::cout << "\nPlease insert you choice:> ";
        std::cin >> re_choice;

    } while (std::cin.fail());

    switch (re_choice)
    {

    case 0:
        start();
        break;

    case 1:
        adding_newBook();
        break;
    }
}
// -----------------------------------------------------------------
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// -------------------------ALL METHODS ----------------------------

// ------------------ Splitting the string -------------------------
std::vector<std::string> Utilities::string_splitter(std::string line, std::string delimeter)
{
    std::vector<std::string> vector_strings;
    std::string word;
    size_t pos = 0;

    while ((pos = line.find(delimeter)) != std::string::npos)
    {
        word = line.substr(0, pos);

        vector_strings.push_back(word);

        line.erase(0, pos + delimeter.length());
    }

    // adding to the vector the string passed
    vector_strings.push_back(line);
    return vector_strings;
}
// -----------------------------------------------------------------------

// ------------------------- File reader ---------------------------------
void Utilities::file_reader()
{

    std::string file;
    std::string line;

    // --------------Asking for the file desired ---------------------
    std::cout << "\nTo exit type ====> 0" << std::endl;
    std::cout << "Please insert the file desired:> ";
    std::cin >> file;
    std::ifstream library(file);
    // ---------------------------------------------------------------
    while (true)
    {
        if (file == "0")
        {
            std::cout << "\nSuccessfully Exited!" << std::endl;
            std::exit(1);
        }
        else
        {
            if (library.is_open())
            {
                while (std::getline(library, line))
                {
                    line.c_str();
                    if (line != "")
                    {
                        // splitting the data by the tab which in ASCII is (9)
                        std::vector<std::string> data = string_splitter(line, std::string(1, 9));
                        //    Creating the object
                        book_data.push_back(Book(data[0], data[1], data[2], stoi(data[3])));
                        book_data.shrink_to_fit();
                    }
                }
                std::cout << "\nSUCCESSFULLY IMPORTED!" << std::endl;
                library.close();

                break;
            }
            else if (library.fail())
            {
                std::cout << "\nFILE NOT FOUND! PLEASE TRY AGAIN!" << std::endl;
                file_reader();
                break;
            }
        }
    }
    
// shuffle of vector, in case the data structure is already sorted, in order to not affect the quick sort performance
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle (book_data.begin(), book_data.end(), std::default_random_engine(seed));
// sorting the entire data structure
    quick_sorting(book_data, 0, book_data.size() - 1);
    
}
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// ----------------toLowerCase method -------------------------
std::string Utilities::toLowerCase(std::string word)
{
#include <algorithm>
#include <cctype>


    std::transform(word.begin(), word.end(), word.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return word;
}
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// --------------------------- QUICK SORTING ALGORITHM -------------------------------

// ------ Placing the last element as pivot, which places smaller to left and greater to right (of pivot) -----------------
template <class T>
int Utilities::partition(T &data, int left, int right) {
    Utilities util;
    int pivot = left + (right - left) / 2; //getting the pivot location

    std::string pivot_word = util.toLowerCase(data[pivot].get_title()); //retrieving the pivot word

    int i = left, j = right;

// creating a holder
    Book temp;

    while(i <= j) {
        // while the left word is less than the pivot word will increase i
        while(util.toLowerCase(data[i].get_title()) < pivot_word) {

            i++;
        }
        // when it exits it will check the right node if is greater than the pivot word
        while(util.toLowerCase(data[j].get_title()) > pivot_word) {

            j--;
        }
// finally it check if i is less or equal to j and if it is will swap them 
        if(i <= j) {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

// -------------------- Sorting the Data structure Method -----------------
template <class T>
void Utilities::quick_sorting(T &data, int left, int right) {

// when the left node(first index) will be greater than the right node (last one)
// it will finish the sorting
    if(left < right) {

        int pivot= partition(data, left, right);

        quick_sorting(data, left, pivot- 1);

        quick_sorting(data, pivot, right);
    }
}
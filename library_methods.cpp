#include "library.hpp"

#include <fstream>
#include <limits>
// ------------------ Splitting the string -------------------------
std::vector<std::string> Data::string_splitter(std::string line, std::string delimeter)
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

// ------------------------- File reader ---------------------------------
void Data::file_reader()
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
                std::cout << "\nSuccessfully Imported!" << std::endl;
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
}

void Data::start()
{

    int choice;

    std::cout << "\nAdding New Book ----------------> 1" << std::endl;
    std::cout << "Increase Book Quantity ---------> 2" << std::endl;
    std::cout << "Decrement Book Quantity --------> 3" << std::endl;
    std::cout << "Exit ---------------------------> 0" << std::endl;
    std::cout << "\nPlease insert your choice:> ";

    std::cin >> choice;

    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nWRONG FROMAT!" << std::endl;
        start();
    } 

    switch (choice)
    {

    case 0:
        std::cout << "\nSuccessfully Exited!" << std::endl;
        std::exit(1);
        break;
    case 1:
        // adding new Book method

        break;
    case 2:
        // Increasing Books Quantity method

        break;

    case 3:
        // Decreasing Book Quantity

        break;
    }
}

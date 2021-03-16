#include "library.hpp"

// ------------------ Splitting the string -------------------------
std::vector<std::string> Book::string_splitter(std::string line, std::string delimeter)
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
void Book::file_reader()
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
                        Book Book(data[0], data[1], data[2], stoi(data[3]));

                        std::cout << "Title: " << data[2] << std::endl;
                    }
                }
                std::cout << "\nSuccessfully Imported!" << std::endl;
                library.close();

                break;
            }
            else if (library.fail())
            {
                std::cout << "File not found! Please Try Again!" << std::endl;
                file_reader();
                break;
            }
        }
    }
}

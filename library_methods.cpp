#include "library.hpp"

// ------------------ Splitting the string -------------------------
std::vector<std::string> Book::string_splitter(std::string line, std::string delimeter)
{
    std::vector<std::string> vector_strings;
    std::string word;
    size_t index = 0;

    do
    {
        word = line.substr(0, index);

        vector_strings.push_back(word);

        line.erase(0, index + delimeter.length());
    } while ((index = line.find(delimeter)) != std::string::npos);

    // adding to the vector the string passed
    vector_strings.push_back(line);
    return vector_strings;
}
// ------------------------- File reader ---------------------------------
void Book::file_reader()
{

    std::string file;
    std::string line;
    bool new_file = false;

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
            if (library.is_open() || new_file)
            {
                while (std::getline(library, line))
                {
                    line.c_str();
                    if (line != "")
                    {
                // splitting the data by the tab which in ASCII is (9)
                        std::vector<std::string> data = string_splitter(line, std::string(1, 9));
                //    Creating the object
                        Book Book(data[0], data[1], data[2], std::stoul(data[3]));
                    }
                }
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

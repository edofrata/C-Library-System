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
        exit = true;
        std::exit(1);
        break;
    case 1:
        // adding new Book method
        adding_newBook();
        break;
    case 2:
        // Increasing Books Quantity method
        increase_Books();
        break;
    case 3:
        // Decreasing Book Quantity
        decreasement_Books();
        break;
    case 4:
        // searching title method
        searching_book();
    default:
        std::cout << "\nTHERE IS NO SUCH CHOICE! PLEASE, TRY AGAIN!" << std::endl;
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
// --------------------------- Increase Book quantity Method -----------------------
void Utilities::increase_Books(){
    int quantity;
    int index;
    print_books();


    std::cout << "\nTo go back type ====> 0" << std::endl;
    std::cout << "\nPlease insert the Book index:> ";
    std::cin >> index;
  if(index == 0){
        start();
    }else{
    std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
    std::cout <<"\nYou have chosen: " << std::endl;
    std::cout << "Title: " << book_data.at(index - 1).get_title() << std::endl;
    std::cout << "Author(s): " << book_data.at(index - 1).get_authors() << std::endl;
    std::cout << "ISBN: " << book_data.at(index - 1).get_isbn() << std::endl;
    std::cout << "Quantity: " << book_data.at(index - 1).get_quantity() << std::endl;

    std::cout << "Please Insert The incresement:> ";
    std::cin >> quantity;

    set_quantityBook(index - 1, quantity);

    std::cout << book_data.at(index - 1).get_title() << " " << "Has Been incremented of: " << quantity << std::endl;
    std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
    std::cout <<"\nAfter Increment: " << std::endl;
    std::cout << "Title: " << book_data.at(index - 1).get_title() << std::endl;
    std::cout << "Author(s): " << book_data.at(index - 1).get_authors() << std::endl;
    std::cout << "ISBN: " << book_data.at(index - 1).get_isbn() << std::endl;
    std::cout << "Quantity: " << book_data.at(index - 1).get_quantity() << std::endl;

    }
}
// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// --------------------------- DECREASE Book quantity Method -----------------------
void Utilities::decreasement_Books(){

    int quantity;
    int index;
    print_books();

    std::cout << "\nTo go back type ====> 0" << std::endl;
    std::cout << "\nPlease insert the Book index:> ";
    std::cin >> index;

    if(index == 0){
        start();
    }else{
    std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
    std::cout <<"\nYou have chosen: " << std::endl;
    std::cout << "Title: " << book_data.at(index - 1).get_title() << std::endl;
    std::cout << "Author(s): " << book_data.at(index - 1).get_authors() << std::endl;
    std::cout << "ISBN: " << book_data.at(index - 1).get_isbn() << std::endl;
    std::cout << "Quantity: " << book_data.at(index - 1).get_quantity() << std::endl;

    std::cout << "Please Insert The incresement:> ";
    std::cin >> quantity;

    set_decrementBook(index - 1, quantity);

    if(total <=0){

        book_data.erase(book_data.begin() + (index - 1));
        std::cout << "Has been Deleted " << std::endl;
        print_books();

    }else{

    std::cout << book_data.at(index - 1).get_title() << " " << "Has Been incremented of: " << quantity << std::endl;
    std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
    std::cout <<"\nAfter Increment: " << std::endl;
    std::cout << "Title: " << book_data.at(index - 1).get_title() << std::endl;
    std::cout << "Author(s): " << book_data.at(index - 1).get_authors() << std::endl;
    std::cout << "ISBN: " << book_data.at(index - 1).get_isbn() << std::endl;
    std::cout << "Quantity: " << book_data.at(index - 1).get_quantity() << std::endl;

        }
    }
}

//------------------------------ searching book -----------------------------
void Utilities::searching_book(){

    std::string book_title;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle (book_data.begin(), book_data.end(), std::default_random_engine(seed));
    quick_sorting(book_data, 0, book_data.size() - 1, 0);

    std::cout << "\nTo exit type ====> 0" << std::endl;
    std::cout<< "\nWhich book would you like to search?" << std::endl;
    std::cout << "Please insert the word:> ";
    std::cin.ignore();
    std::getline(std::cin, book_title);


    if(book_title.empty()){
        
        std::cout << "YOU NEED TO INSERT A WORD!" << std::endl;
    }else if(book_title == "0"){
        start();
    }
//    calling the search, which will evaluate the rest
    search(book_data,book_title);
    start();
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
    quick_sorting(book_data, 0, book_data.size() - 1, 0);

  

}

void Utilities::print_books(){


    for(int i = 0; i < book_data.size(); i ++){

     std::cout << "| " << i + 1 << "| " << book_data.at(i).get_title() << std::endl;

    }

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
int Utilities::partition(std::deque<Book> &data, int left, int right, int index) {
     Utilities util;
    int pivot = left + (right - left) / 2; //getting the pivot location

    std::string pivot_word = toLowerCase(string_splitter(data[pivot].get_title(), " ")[index]); //retrieving the pivot word

    int i = left, j = right;

// creating a holder
    Book temp;

    while(i <= j) {
        // while the left word is less than the pivot word will increase i
        while(toLowerCase(string_splitter(data[i].get_title(), " ")[index]) < pivot_word) { i++; }
        // when it exits it will check the right node if is greater than the pivot word
        while(toLowerCase(string_splitter(data[j].get_title(), " ")[index]) > pivot_word) { j--; }
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
void Utilities::quick_sorting(std::deque<Book> &data, int left, int right, int index) {

// when the left node(first index) will be greater than the right node (last one)
// it will finish the sorting
    if(left < right) {

        int pivot= partition(data, left, right, index);

        quick_sorting(data, left, pivot - 1, index);
        quick_sorting(data, pivot, right, index);
    }
}

// ----------------------------- Searching for a string ------------------
void Utilities::search(std::deque<Book> data, std::string word){
    

    unsigned long int left=0, right= data.size();

    int i = -1;
    while(++i >= 0){
// ---------------------------------------------------------------------
 
        quick_sorting(data, 0, data.size() - 1, i);
        // for(Book d: data){ std::cout << d.get_title() << std::endl; }
// -----------------------------------------------------------------------

        // std::cout << "\nGRANDE CICLO " << i << std::endl;
        bool nextWord = false;

        // ----------------START--------------------
        std::function<bool( int left, int right)> recur = [&]( int l, int r){
            unsigned long long mid = l + (r - l) / 2;
            std::deque<std::string> titles_found;
            
            std::string title = string_splitter(data[mid].get_title(), " ").size() >i? string_splitter(data.at(mid).get_title(), " ")[i]: "";
            nextWord = title != "" ? true : nextWord;

            // std::cout << "\n\nTITLE " << title << std::endl;
            if (toLowerCase(word)< toLowerCase(title) ){
            // needs to cut the right node and go to the left
            // std::cout << "\nVALUE OF R: " << l << std::endl;
                if(r != left && r != mid){
                    r = mid;
                    return recur(l, r);
                }
            }
            else if(toLowerCase(word) > toLowerCase(title)){
            // needs to cut the left node and go to the right
                // std::cout << "\nVALUE OF L: " << l << std::endl;
                if(l != right - 1 && l != mid){ 
                    l = mid;  
                    return recur(l, r);
                }
            }else{

                std::cout << "WORDS FOUND: " << std::endl;
                std::cout   << "\nThe word searched: "  << word         << " "
                            << "\n\nThe words Found: " << "\n\n"<< mid << " " << data[mid].get_title() << std::endl;
                // storing the mid value
                unsigned long long temp_mid = mid;
                // checking if first there are words alike

                while(toLowerCase(word) == toLowerCase(string_splitter(data.at(mid--).get_title(), " ")[i])){

                    std::cout << mid << " "<< data[mid].get_title() << std::endl;
   
                }
//Reassigning the mid value 
                mid = temp_mid;

               while(toLowerCase(word) == toLowerCase(string_splitter(data.at(mid++).get_title(), " ")[i])){
                   
                   std::cout << mid << " "<< data[mid].get_title() << std::endl;

               }
                
                
                    return false;
                
            }
            while(i == 0){
                std::cout << "\nTHE WORD HAS NOT BEEN FOUND! "<< std::endl;
                std::cout << "Would you like to search further?? "<< std::endl;
                std::cout << "Yes -----> 1"<< std::endl;
                std::cout << "No  -----> 0"<< std::endl << std::endl;
                std::cout << "Please insert choice:> ";

                //user input
                std::string choice; std::cin >> choice;
                std::cout << std::endl;

                if(choice == "1"){
                    return true;
                }else if(choice == "0"){
                    return false;
                }else{ std::cout << "Wrong selection! Try again."<< std::endl; }
            }

            if(!nextWord){
                std::cout << "Not found! "<< std::endl;
                return false;
            }
            return true;
        };


        if(!recur(left, right)){ return; }else{

            std::cout << "\nTHE WORD HAS NOT BEEN FOUND" << std::endl;
            return;
        }
    }


}
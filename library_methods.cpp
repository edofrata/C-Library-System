#include "library.hpp"

#include <fstream>
#include <limits>
#include <algorithm>
// #include <unordered_map>
#include <set>
#include <unordered_set>
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
    int quantity; //user input quantity choice
    std::string word; // word to be searched by the user
    std::string final_choice; // the final choice if no wrod has been found
    encapsulated_sorting(book_data); // the sorting and shuffling data structure
    int index; //index input in order to get the bok from the data structure 
    
    std::cout << "\nTo go back type ====> 0" << std::endl;
    std::cout << "\nPlease insert the word of the Book:> ";
    std::cin >> word;

  if(word == "0"){
        start();
    }else{
            search(&book_data, word);
            unsigned int max_size = (*titles_found).size();
    if(max_size > 0){
            std::cout << "\nPlease Insert the book:> ";
            std::cin >> index;

        while(index > max_size || index <= 0 ){
            std::cout << "THERE IS NOT SUCH INDEX!" << std::endl;
            std::cout << "\nPlease Insert the book:> ";
            std::cin >> index;
        }

        std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"  << std::endl;
        std::cout <<"\nYOU HAVE CHOSEN: " << std::endl;
        std::cout << "Title:      " << (*titles_found).at(index - 1).get_title()    << std::endl;
        std::cout << "Author(s):  " << (*titles_found).at(index - 1).get_authors()  << std::endl;
        std::cout << "ISBN:       " << (*titles_found).at(index - 1).get_isbn()     << std::endl;
        std::cout << "Quantity:   " << (*titles_found).at(index - 1).get_quantity() << std::endl;
        std::cout << "\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
        // checking if the quantity inserted increses
        std::cout << "\nPlease Insert The incresement:> ";
        std::cin >> quantity;
    while(quantity < 0){
            std::cout << "\nTHIS IS THE INCREMENT SECTION" << std::endl;
            std::cout << "\nPlease Insert The incresement:> ";
            std::cin >> quantity;

    }

    set_quantityBook((*titles_found), index - 1, quantity);

    std::cout << "\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
    std::cout << (*titles_found).at(index).get_title() << " " << "Has Been incremented of: " << quantity << std::endl;
    std::cout <<"\nAFTER INCREMENT: " << std::endl;
    std::cout << "Title:      " << (*titles_found).at(index - 1).get_title()    << std::endl;
    std::cout << "Author(s):  " << (*titles_found).at(index - 1).get_authors()  << std::endl;
    std::cout << "ISBN:       " << (*titles_found).at(index - 1).get_isbn()     << std::endl;
    std::cout << "Quantity:   " << (*titles_found).at(index - 1).get_quantity() << std::endl;
    std::cout << "\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;

    }else{

        std::cout << "No Books were found!" << std::endl;
        std::cout << "\nWould you like to retry?" << std::endl;
        std::cout << "\nYes ---> 1" << std::endl;
        std::cout << "No   ---> 0" << std::endl;
        

        while(final_choice != "0" &&  final_choice !=  "1"){
        
        std::cout << "Please Insert Your choice:> ";
        std::cin >> final_choice;
                
                if(final_choice != "0" &&  final_choice != "1")
                std::cout << "\nWRONG INPUT!" << std::endl;
        }

        if(final_choice == "0"){
            start();
        }else{
            increase_Books();
        }
    }

    }
}
// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// --------------------------- DECREASE Book quantity Method -----------------------
void Utilities::decreasement_Books(){

   int quantity; //user input quantity choice
    std::string word; // word to be searched by the user
    std::string final_choice; // the final choice if no wrod has been found
    encapsulated_sorting(book_data); // the sorting and shuffling data structure
    int index; //index input in order to get the bok from the data structure 
   
    std::cout << "\nTo go back type ====> 0" << std::endl;
    std::cout << "\nPlease insert the Book index:> ";
    std::cin >> word;

    if(word == "0"){
        start();
    }else{

            search(&book_data, word);
            unsigned int max_size = (*titles_found).size();

    if(max_size > 0){

            std::cout << "\nPlease Insert the book:> ";
            std::cin >> index;
            
        while(index > max_size || index <= 0 ){
            std::cout << "THERE IS NOT SUCH INDEX!" << std::endl;
            std::cout << "\nPlease Insert the book:> ";
            std::cin >> index;
        }

    std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
    std::cout <<"\nYou have chosen: " << std::endl;
    std::cout << "Title:      " << (*titles_found).at(index - 1).get_title()    << std::endl;
    std::cout << "Author(s):  " << (*titles_found).at(index - 1).get_authors()  << std::endl;
    std::cout << "ISBN:       " << (*titles_found).at(index - 1).get_isbn()     << std::endl;
    std::cout << "Quantity:   " << (*titles_found).at(index - 1).get_quantity() << std::endl;
    std::cout << "\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;

    std::cout << "Please Insert The decresement:> ";
    std::cin >> quantity;

     while(quantity < 0){
            std::cout << "\nNO NEED TO INSERT A NEGATIVE NUMBER!" << std::endl;
            std::cout << "\nPlease Insert The incresement:> ";
            std::cin >> quantity;

    }

    set_decrementBook((*titles_found), index - 1, quantity);

    if(total <=0){

        book_data.erase(book_data.begin() + (index - 1));
        std::cout << "Has been Deleted " << std::endl;

    }else{

    std::cout << book_data.at(index - 1).get_title() << " " << "Has Been decremented of: " << quantity << std::endl;
    std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
    std::cout <<"\nAfter decrement:   " << std::endl;
    std::cout << "Title:      " << (*titles_found).at(index - 1).get_title()    << std::endl;
    std::cout << "Author(s):  " << (*titles_found).at(index - 1).get_authors()  << std::endl;
    std::cout << "ISBN:       " << (*titles_found).at(index - 1).get_isbn()     << std::endl;
    std::cout << "Quantity:   " << (*titles_found).at(index - 1).get_quantity() << std::endl;

        }
    }else{

        std::cout << "No Books were found!" << std::endl;
        std::cout << "\nWould you like to retry?" << std::endl;
        std::cout << "\nYes ---> 1" << std::endl;
        std::cout << "No   ---> 0" << std::endl;
        

        while(final_choice != "0" &&  final_choice !=  "1"){
        
        std::cout << "Please Insert Your choice:> ";
        std::cin >> final_choice;
                
                if(final_choice != "0" &&  final_choice != "1")
                std::cout << "\nWRONG INPUT!" << std::endl;
        }

        if(final_choice == "0"){
            start();
        }else{
            decreasement_Books();
        }


         }
    }
}
//------------------------------ searching book -----------------------------
void Utilities::searching_book(){

    std::string book_title;

    
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
    search(&book_data,book_title);
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
    std::cout << "\nWELCOME TO THE LIBRARY SYSTEM!" << std::endl;
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

    encapsulated_sorting(book_data);
}

// ---------------------- ENCAPSULATED SORTING -------------------------
std::deque<Book> Utilities::encapsulated_sorting(std::deque<Book>& data){
    
// shuffle of vector, in case the data structure is already sorted, in order to not affect the quick sort performance
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle (data.begin(), data.end(), std::default_random_engine(seed));
// sorting the entire data structure
    quick_sorting(data, 0, data.size() - 1, 0);

    return data;
}
// ----------------------------------------------------------------------

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

// // |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||


void Utilities::quick_sorting(std::deque<Book>& data, long int left, long int right, unsigned int index){
    std::string pivot;

    //--------------------------- Recursive Functiomn -----------------------------------
    std::function<void(std::deque<Book>& data, long int l, long int r)> quick_sort = [&](std::deque<Book>& data, long int left, long int right){
        pivot = "";
        long int pivot_index = (left + right) / 2 ;
        long int i = left, j = right;
        
        

        std::vector<std::string> pivot_word = string_splitter(data[pivot_index].get_title(), " ");   // vector for pivot words
         if(index < pivot_word.size() ){
                for (std::vector<std::string>::const_iterator iterator_pivot = pivot_word.begin()+ index; iterator_pivot != pivot_word.end(); ++iterator_pivot) 
                    { pivot += " " + *iterator_pivot; }
                }    
        // -------- creating a holder for partioning word ----------
        while (i <= j) {
            // creating a holder for object
            Book* temp = new Book(data[i]);   
            i--;
            j++;
            std::string right_word, left_word;
            // -------------- STARTING LEFT SIDE CHECK ------------------------
            do
            {
                left_word = "";
                std::vector<std::string>* vector_leftWord = new std::vector<std::string>(string_splitter(data[++i].get_title(), " "));   
                if(index < (*vector_leftWord).size()){
                for (std::vector<std::string>::const_iterator iterator_left = (*vector_leftWord).begin()+ index; iterator_left != (*vector_leftWord).end(); ++iterator_left) 
                    { left_word += " " + *iterator_left; }
                }

                 delete vector_leftWord; //releasing memory
            } while (toLowerCase(left_word)  < toLowerCase(pivot));

            //------------------ STARTING RIGHT SIDE CHECK --------------------
            do
            {
                right_word = "";
                std::vector<std::string>* vector_rightWord = new std::vector<std::string>(string_splitter(data[--j].get_title(), " "));     // vector for right words
                 if(index < (*vector_rightWord).size()){
                for (std::vector<std::string>::const_iterator iterator_right = (*vector_rightWord).begin()+ index; iterator_right != (*vector_rightWord).end(); ++iterator_right) 
                    { right_word += " " + *iterator_right; }

                 }
                 
                  delete vector_rightWord; //realising memory
            } while (toLowerCase(right_word) > toLowerCase(pivot));

            if (i <= j) 
            { 
                (*temp) = data[i];
                data[i] = data[j];
                data[j] = *temp;
                i++; 
                j--;
               
            } 
            delete temp; //releasing memory as I do not need the holder anymore
        }
        // ---------- Recall to the quick sorting --------
        if (left < j ){ quick_sort(data, left, j );}
        if (i < right){ quick_sort(data, i, right); }
    };
    quick_sort(data,left,right);
    
}
// ------------------------------------------------------------------------
// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// -----------------BINARY SEARCH TREE IMPLEMENTATION----------------------
std::deque<Book> Utilities::search(std::deque<Book>* data, std::string word){
 

    unsigned long int left=0, right= (*data).size();
    // std::unordered_map<std::string, Book> books_found; //Unordered hash map which will hold the books found
    (*titles_found).clear(); //clearing from the old list
    

    int i = -1, next_index = 0, count_cycles;
    while(++i >= 0 && next_index != -1){
        next_index = -1;

// ------- shuffling the data structure in case the list given is already in order -----------
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle (book_data.begin(), book_data.end(), std::default_random_engine(seed));
// -------------------------------------------------------------------------------------------
        quick_sorting((*data), 0, (*data).size() - 1, i);

        // ----------------START--------------------
        std::function<bool( int left, int right)> binary_search = [&]( int l, int r){

            unsigned long int mid = l + (r - l) / 2;
            std::string title = string_splitter((*data)[mid].get_title(), " ").size() > i ? string_splitter((*data).at(mid).get_title(), " ")[i]: "";
            next_index = title != "" ? i : next_index;

            if (toLowerCase(word)< toLowerCase(title) ){
            // needs to cut the right node and go to the left
                if(r != left && r != mid){
                    r = mid;
                    return binary_search(l, r);
                }
            }
            else if(toLowerCase(word) > toLowerCase(title)){
            // needs to cut the left node and go to the right

                if(l != right - 1 && l != mid){ 
                    l = mid;  
                    return binary_search(l, r);
                }
            }else{
                // storing the mid value0
                unsigned long int* temp_mid = new unsigned long int(mid);
          
                if(toLowerCase(word) == toLowerCase(title)){
                    std::cout   << "\nThe word searched: " << word  << " "
                                << "\n\nThe words Found: " << std::endl;

                // checking if first there are words alike
                while(toLowerCase(word) == toLowerCase(string_splitter((*data).at(mid).get_title(), " ")[i])){
                    (*titles_found).push_front((*data)[mid]);
                    // making sure that it does not go out of bounds
                    if(mid > 0){ --mid; }
                    else       { break; }            
                }
                
                
                // checking the word if equal by incrementing after mid
                while(toLowerCase(word) == toLowerCase(string_splitter((*data).at(++(*temp_mid)).get_title(), " ")[i]) ){
                   (*titles_found).push_back((*data)[*temp_mid]);

                }


// ----------------------------------------------- TEST AREA ------------------------------------------------------------
                // int counter_ = 0;
                // for(unsigned int i= mid; i<= (*temp_mid); i++){

                //         std::string isbn = (*data)[i].get_isbn();
                //         if(books_found.find(isbn) == books_found.end()){
                //             titles_found[counter_] = (*data)[i];
                //             counter_++;
                //         }

                //     }
                // --------------------- Creating a set in order to eliminate all the duplicates ---------------
                // std::set<Book> book_duplicates;
                // for(unsigned int i = 0; i < titles_found.size(); ++i ){ 
                //     book_duplicates.insert(titles_found[i]);
                //      } 
                // // assigning the values back
                // titles_found.assign(book_duplicates.begin(), book_duplicates.end());
 // ---------------------------------------------------------------------------------------------------------------------


                delete temp_mid;//releasing memory 
                int counter = 1;
                std::cout  << "LIST PRINTED OUT: " << std::endl;
                for(auto book : (*titles_found)){ std::cout << counter << " " << book.get_title() << std::endl; counter++; }
                
                count_cycles = i == 0 ? (*titles_found).size() : count_cycles;
                return true;
                
             }
            
            }
            
            return false;
        };


        if(!binary_search(left,right) && i == 0){
            std::cout << "\nTHE WORD HAS NOT BEEN FOUND! " << std::endl;
            std::cout << "Would you like to search further? "<< std::endl;
            std::cout << "Yes -----> 1"<< std::endl;
            std::cout << "No  -----> 0"<< std::endl << std::endl;

            std::string choice = "";
            while(choice != "1" && choice != "0"){
                std::cout << "Please insert choice:> ";
                std::cin >> choice; // user input 

                if(choice != "1" && choice != "0"){

                    std::cout << "WRONG INPUT!, TRY AGAIN!" << std::endl; // in case the input is wrong
                    
                }
            }
            if(choice == "0"){ break; }
        }else if((*titles_found).size() > 0){
            
            if(next_index == 0 && i == 0){
            
                std::cout << "\r\n" << "\nHAVE YOU FOUND THE BOOK?" << std::endl;
                std::cout << "Yes                         ----> 1";
                std::cout<< "\nNo, Make a further search   ----> 0";
                //----------------- USER INPUT --------------------------
                std::string choice = "";
                while(choice != "1" && choice != "0"){  
                   
                    std::cout << "\nPlease insert your choice:> ";  
                    std::cin >> choice; 

                    if(choice != "1" && choice != "0")
                    std::cout << "\nWRONG INPUT, TRY AGAIN!" <<std::endl;  
                }
                if( choice == "1" ){ return (*titles_found); }
            }else if( next_index == -1 ){
                if((*titles_found).size() > count_cycles){

                    std::cout << "\nI HAVE FOUND " << std::to_string((*titles_found).size() - count_cycles) << " MORE" << std::endl;

                }else{ std::cout << "\nNOT MORE WORDS WERE FOUND!"; }
                break;
            }
        }else if(next_index == -1){
            
            std::cout << "I HAVEN'T FOUND SUCH BOOK WITH THAT WORD!";
            break;
        }
    }
    return (*titles_found);
  
}



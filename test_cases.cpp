#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "library_methods.cpp"

TEST_CASE("Checking if the getter/setter methods work fine", "[get_title, get_authors, get_isbn, get_quantity]")
{

    Utilities util;
    std::deque<Book *> test;

    Book *book1 = new Book("This is a test", "Edoardo Fratantonio;John;", "98765432", 23);
    test.push_back(book1);

    Book *book2 = new Book("The Lord of the Rings", "Peter Jackson", "96426272", 10);
    test.push_back(book2);

    Book *book3 = new Book("Harry Potter", "JK ROWLING;", "9365352728", 15);
    test.push_back(book3);

    Book *book4 = new Book("This is a post test", "Edoardo Frata;John Belly;", "9345625212", 12);
    test.push_back(book4);

    CHECK((*test.at(0)).get_title() == "This is a test");
    CHECK((*test.at(0)).get_authors() == "Edoardo Fratantonio;John;");
    CHECK((*test.at(0)).get_isbn() == "98765432");
    CHECK((*test.at(0)).get_quantity() == 23);

    SECTION("testing out the rest of the objects randomly")
    {

        CHECK((*test.at(2)).get_title() == "Harry Potter");
        CHECK((*test.at(1)).get_authors() == "Peter Jackson");
        CHECK((*test.at(3)).get_isbn() == "9345625212");
        CHECK((*test.at(1)).get_quantity() == 10);
        CHECK((*test.at(3)).get_title() == "This is a post test");
        CHECK((*test.at(2)).get_isbn() == "9365352728");
        CHECK((*test.at(3)).get_quantity() == 12);
    }

    SECTION("testing out the setter method of adding a new book")
    {

        util.set_newBook(test, "Test of new book", "Delila More;John Dude", "936543234", 34);

        REQUIRE((*test.at(4)).get_authors() == "Delila More;John Dude");
        REQUIRE((*test.at(4)).get_quantity() == 34);
    }
    SECTION("testing out the setter method of increasing a book")
    {

        int *quantity = new int(10);
        util.set_quantityBook(test, 2, (*quantity));
        REQUIRE((*test.at(2)).get_quantity() == 25);

        delete quantity;
    }

    SECTION("testing out the setter method of decreasing a book")
    {

        int *quantity_decreasing = new int(2);
        util.set_decrementBook(test, 3, (*quantity_decreasing));
        REQUIRE((*test.at(3)).get_quantity() == 10);

        delete quantity_decreasing;
    }
}

TEST_CASE("Testing the ToLowerCase method", "[toLowerCase]")
{
    Utilities util;

    REQUIRE(util.toLowerCase("heLLo") == "hello");
    REQUIRE(util.toLowerCase("TEST") == "test");
    REQUIRE(util.toLowerCase("Title") == "title");
    REQUIRE(util.toLowerCase("crash") == "crash");
}

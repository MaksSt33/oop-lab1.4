#include "pch.h"
#include "CppUnitTest.h"
#include "../lab1.4/Book.h"
#include "../lab1.4/Library.h"
#include "../lab1.4/Library.cpp"
#include "../lab1.4/Book.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest14
{
    TEST_CLASS(UnitTestLibrary) {
public:

    TEST_METHOD(TestBookInitialization) {
        Book book;
        bool initialized = book.init("1984", "George Orwell", 1949);
        Assert::IsTrue(initialized);
        Assert::AreEqual(string("1984"), book.getTitle());
        Assert::AreEqual(string("George Orwell"), book.getAuthor());
        Assert::AreEqual(1949, book.getYear());
    }

    TEST_METHOD(TestInvalidBookYear) {
        Book book;
        bool initialized = book.init("Invalid Book", "Author", -100);
        Assert::IsFalse(initialized);
    }

    TEST_METHOD(TestLibraryAddBook) {
        Library library;
        Book book;
        book.init("Brave New World", "Aldous Huxley", 1932);
        library.addBook(book);

        stringstream buffer;
        streambuf* old = cout.rdbuf(buffer.rdbuf());
        library.displayAll();
        cout.rdbuf(old);

        string output = buffer.str();
        Assert::IsTrue(output.find("Brave New World") != string::npos);
    }

    TEST_METHOD(TestLibraryRemoveBook) {
        Library library;
        Book book;
        book.init("To Remove", "Author", 2000);
        library.addBook(book);
        library.removeBook("To Remove");

        stringstream buffer;
        streambuf* old = cout.rdbuf(buffer.rdbuf());
        library.displayAll();
        cout.rdbuf(old);

        string output = buffer.str();
        Assert::IsTrue(output.find("To Remove") == string::npos);
    }
	};
}

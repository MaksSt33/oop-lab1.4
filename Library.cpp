#include "Library.h"

Library::Library() : bookCount(0) {}

void Library::addBook(const Book& book) {
    if (bookCount < MAX_BOOKS) {
        books[bookCount++] = book;
    }
    else {
        cout << "Library is full!" << endl;
    }
}

void Library::removeBook(const string& title) {
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].getTitle() == title) {
            for (int j = i; j < bookCount - 1; ++j) {
                books[j] = books[j + 1];
            }
            --bookCount;
            return;
        }
    }
    cout << "Book not found!" << endl;
}

void Library::findBook(const string& value) const {
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].getTitle() == value || books[i].getAuthor() == value || to_string(books[i].getYear()) == value) {
            books[i].display();
        }
    }
}

void Library::displayAll() const {
    for (int i = 0; i < bookCount; ++i) {
        books[i].display();
    }
}

void Library::sortBooks(int criteria) {
    for (int i = 0; i < bookCount - 1; ++i) {
        for (int j = 0; j < bookCount - i - 1; ++j) {
            bool shouldSwap = false;
            if (criteria == 1 && books[j].getTitle() > books[j + 1].getTitle()) {
                shouldSwap = true;
            }
            else if (criteria == 2 && books[j].getAuthor() > books[j + 1].getAuthor()) {
                shouldSwap = true;
            }
            else if (criteria == 3 && books[j].getYear() > books[j + 1].getYear()) {
                shouldSwap = true;
            }
            if (shouldSwap) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
    cout << "Books sorted successfully!" << endl;
}
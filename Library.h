#pragma once
#include "Book.h"

class Library {
private:
    Book books[MAX_BOOKS];
    int bookCount;

public:
    Library();
    void addBook(const Book& book);
    void removeBook(const string& title);
    void findBook(const string& value) const;
    void displayAll() const;
    void sortBooks(int criteria);
};
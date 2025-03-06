#pragma once
#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;

class Book {
private:
    string title;
    string author;
    int year;

public:
    Book();
    bool init(const string& t, const string& a, int y);
    void read();
    void display() const;
    string getTitle() const;
    string getAuthor() const;
    int getYear() const;
    void setTitle(const string& t);
    void setAuthor(const string& a);
    bool setYear(int y);
    string toString() const;
};
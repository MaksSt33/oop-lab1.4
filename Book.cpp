#include "Book.h"

Book::Book() : title(""), author(""), year(0) {}

string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }

void Book::setTitle(const string& t) { title = t; }
void Book::setAuthor(const string& a) { author = a; }

bool Book::setYear(int y) {
    if (y > 0) {
        year = y;
        return true;
    }
    cout << "Invalid year!" << endl;
    return false;
}

bool Book::init(const string& t, const string& a, int y) {
    setTitle(t);
    setAuthor(a);
    return setYear(y);
}

void Book::read() {
    string t, a;
    int y;
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, t);
    cout << "Enter author: ";
    getline(cin, a);
    do {
        cout << "Enter year: ";
        cin >> y;
    } while (!setYear(y));
    init(t, a, y);
}

void Book::display() const {
    cout << "Title: " << title << ", Author: " << author << ", Year: " << year << endl;
}

string Book::toString() const {
    return "Title: " + title + ", Author: " + author + ", Year: " + to_string(year);
}

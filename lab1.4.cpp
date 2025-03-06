#include "Library.h"

void menu() {
    Library library;
    int choice;
    do {
        cout << "\n1. Add Book\n2. Remove Book\n3. Find Book\n4. Display All\n5. Sort Books\n6. Exit\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            Book book;
            book.read();
            library.addBook(book);
        }
        else if (choice == 2) {
            string title;
            cout << "Enter title to remove: ";
            cin.ignore();
            getline(cin, title);
            library.removeBook(title);
        }
        else if (choice == 3) {
            string value;
            cout << "Enter title, author, or year to find: ";
            cin.ignore();
            getline(cin, value);
            library.findBook(value);
        }
        else if (choice == 4) {
            library.displayAll();
        }
        else if (choice == 5) {
            int criteria;
            cout << "Sort by:\n1. Title\n2. Author\n3. Year\nChoose: ";
            cin >> criteria;
            library.sortBooks(criteria);
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}

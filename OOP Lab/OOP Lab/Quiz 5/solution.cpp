#include <iostream>
#include <cstring>
using namespace std;

class Book {
    char* title;
    char* author;
    int unique_id;

public:
    Book() {
        title = nullptr;
        author = nullptr;
        unique_id = 0;
    }

    Book(const char* t, const char* a, int id) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
        author = new char[strlen(a) + 1];
        strcpy(author, a);
        unique_id = id;
    }

    ~Book() {
        delete[] title;
        delete[] author;
    }

    Book(const Book& other) {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);
        author = new char[strlen(other.author) + 1];
        strcpy(author, other.author);
        unique_id = other.unique_id;
    }

    Book& operator=(const Book& other) {
        if (this != &other) {
            delete[] title;
            delete[] author;
            title = new char[strlen(other.title) + 1];
            strcpy(title, other.title);
            author = new char[strlen(other.author) + 1];
            strcpy(author, other.author);
            unique_id = other.unique_id;
        }
        return *this;
    }

    void print() const {
        cout << "[ID: " << unique_id << "] " << title << " by " << author << endl;
    }
};

class Library {
    char* name;
    Book* books;
    int size;

public:
    Library(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        books = nullptr;
        size = 0;
    }

    ~Library() {
        delete[] name;
        delete[] books;
    }

    void addBook(const char* title, const char* author, int id) {
        Book* temp = new Book[size + 1];
        for (int i = 0; i < size; ++i) {
            temp[i] = books[i];
        }
        temp[size] = Book(title, author, id);
        delete[] books;
        books = temp;
        size++;
    }

    void displayAll() const {
        cout << "Library Name: " << name << endl;
        cout << "Books Available: " << endl;
        for (int i = 0; i < size; ++i) {
            cout << (i + 1) << ". ";
            books[i].print();
        }
    }
};

int main() {
    Library lib("Central Library");
    lib.addBook("C++ Basics", "Bjarne Stroustrup", 101);
    lib.addBook("Data Structures", "Mark Weiss", 102);
    lib.displayAll();

    return 0;
}

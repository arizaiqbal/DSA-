#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int id;

public:
    Book() { 
        id = -1; 
    } 

    Book(int bookId) {
         id = bookId;
     }

    int getId() { 
        return id; 
    }
};

class Library {
private:
    Book **books;       
    int *sizes;         
    string *categories; 
    int rows;           

public:
    Library(int r) {
        rows = r;
        books = new Book*[rows];
        sizes = new int[rows];
        categories = new string[rows];
    }

    void input() {
        for (int i = 0; i < rows; i++) {
            cout << "Enter name of category " << i+1 << ": ";
            cin >> categories[i];

            cout << "Enter number of books in " << categories[i] << ": ";
            cin >> sizes[i];

            books[i] = new Book[sizes[i]];

            cout << "Enter book IDs for " << categories[i] << ": ";
            for (int j = 0; j < sizes[i]; j++) {
                int id;
                cin >> id;
                books[i][j] = Book(id); 
            }
        }
    }

    void display() {
        cout << "Library Collection:" << endl;
        for (int i = 0; i < rows; i++) {
          cout << categories[i] << " : ";
            for (int j = 0; j < sizes[i]; j++) {
                cout << books[i][j].getId() << " ";
            }
            cout << endl;
        }
    }

    void searchBook(int id) {
    bool found = false;
        for (int i = 0; i < rows; i++) {
           for (int j = 0; j < sizes[i]; j++) {
                if (books[i][j].getId() == id) {
                    cout << "Book with ID " << id << " is available in category: " << categories[i] << endl;
                       found = true;
                       return;
                }
            }
        }
        if (!found) {
        cout << "Book with ID " << id << " is not available in the library." << endl;
        }
    }

    ~Library() {
        for (int i = 0; i < rows; i++) {
            delete[] books[i];
        }


        delete[] books;
        delete[] sizes;
        delete[] categories;
    }
};

int main() {
    int categories;
    cout << "Enter number of categories: ";
         cin >> categories;

    Library lib(categories);
        lib.input();

    lib.display();

    int id;
    cout << "Enter book ID to search: ";
     cin >> id;
    lib.searchBook(id);

    return 0;
}

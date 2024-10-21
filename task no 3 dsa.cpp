
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;




class Publication {
public:
    virtual void display() const = 0;
    virtual string getTitle() const = 0;
    virtual ~Publication() = default;
};

class Book : public Publication {
private:
    string title;
    string author;
    int pages;

public:
    Book(const string& title, const string& author, int pages)
        : title(title), author(author), pages(pages) {}

    void display() const override {
        cout << "Book: " << title << " by " << author << " (" << pages << " pages)\n";
    }

    string getTitle() const override {
        return title;
    }

    int getPages() const {
        return pages;
    }
};

class Newspaper : public Publication {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper(const string& name, const string& date, const string& edition)
        : name(name), date(date), edition(edition) {}

    void display() const override {
        cout << "Newspaper: " << name << ", Date: " << date << ", Edition: " << edition << "\n";
    }

    string getTitle() const override {
        return name;
    }

    string getEdition() const {
        return edition;
    }
};


class Library {
private:
    vector<Book> books;
    vector<Newspaper> newspapers;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void addNewspaper(const Newspaper& newspaper) {
        newspapers.push_back(newspaper);
    }

    void displayCollection() const {
        for (const auto& book : books) {
            book.display();
        }
        for (const auto& newspaper : newspapers) {
            newspaper.display();
        }
    }

    void sortBooksByPages() {
        sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
            return a.getPages() < b.getPages();
            });
    }

    void sortNewspapersByEdition() {
        sort(newspapers.begin(), newspapers.end(), [](const Newspaper& a, const Newspaper& b) {
            return a.getEdition() < b.getEdition();
            });
    }

    Book* searchBookByTitle(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                return &book;
            }
        }
        return nullptr;
    }

    Newspaper* searchNewspaperByName(const string& name) {
        for (auto& newspaper : newspapers) {
            if (newspaper.getTitle() == name) {
                return &newspaper;
            }
        }
        return nullptr;
    }
};

int main() {
  
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

   
    Library library;

    
    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    
    cout << "Before Sorting:\n";
    library.displayCollection();


    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    
    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << "Found Book:" << endl;
        foundBook->display();
    }
    else {
        cout << "Book not found." << endl;
    }

   
    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) {
        cout << "Found Newspaper" << endl;
        foundNewspaper->display();
    }
    else {
        cout << "Newspaper not found." << endl;
    }

    return 0;
}

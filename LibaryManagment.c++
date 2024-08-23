#include <bits/stdc++.h>
using namespace std;

// Define structures for Book and User
struct Book
{
    int bookId;
    string title;
    string author;
    bool isAvailable;
};

struct User
{
    int userId;
    string username;
    string password;
};

// Function declarations
void displayMenu();
void addBook(Book books[], int &bookCount);
void displayBooks(const Book books[], int bookCount);
void addUser(User users[], int &userCount);
void displayUsers(const User users[], int userCount);

void displayMenu()
{
    cout << "\n===== Library Management System =====" << endl;
    cout << "1. Add Book" << endl;
    cout << "2. Display Books" << endl;
    cout << "3. Add User" << endl;
    cout << "4. Display Users" << endl;
    cout << "5. Exit" << endl;
}

void addBook(Book books[], int &bookCount)
{
    if (bookCount < 100)
    {
        Book newBook;
        cout << "Enter Book ID: ";
        cin >> newBook.bookId;
        cout << "Enter Title: ";
        cin.ignore(); // to clear the newline character from the buffer
        getline(cin, newBook.title);
        cout << "Enter Author: ";
        getline(cin, newBook.author);
        newBook.isAvailable = true;

        books[bookCount++] = newBook;
        cout << "Book added successfully." << endl;
    }
    else
    {
        cout << "Maximum book limit reached." << endl;
    }
}

void displayBooks(const Book books[], int bookCount)
{
    cout << "\n===== Book List =====" << endl;
    cout << setw(5) << "ID" << setw(20) << "Title" << setw(20) << "Author" << setw(15) << "Availability" << endl;
    for (int i = 0; i < bookCount; ++i)
    {
        cout << setw(5) << books[i].bookId << setw(20) << books[i].title << setw(20) << books[i].author;
        if (books[i].isAvailable)
        {
            cout << setw(15) << "Available";
        }
        else
        {
            cout << setw(15) << "Not Available";
        }
        cout << endl;
    }
}

void addUser(User users[], int &userCount)
{
    if (userCount < 50)
    {
        User newUser;
        cout << "Enter User ID: ";
        cin >> newUser.userId;
        cout << "Enter Username: ";
        cin.ignore();
        getline(cin, newUser.username);
        cout << "Enter Password: ";
        getline(cin, newUser.password);

        users[userCount++] = newUser;
        cout << "User added successfully." << endl;
    }
    else
    {
        cout << "Maximum user limit reached." << endl;
    }
}

void displayUsers(const User users[], int userCount)
{
    cout << "\n===== User List =====" << endl;
    cout << setw(5) << "ID" << setw(20) << "Username" << setw(20) << "Password" << endl;
    for (int i = 0; i < userCount; ++i)
    {
        cout << setw(5) << users[i].userId << setw(20) << users[i].username << setw(20) << users[i].password << endl;
    }
}

int main()
{
    const int MAX_BOOKS = 100;
    const int MAX_USERS = 50;
    Book books[MAX_BOOKS];
    User users[MAX_USERS];
    int bookCount = 0;
    int userCount = 0;

    int choice;
    do
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook(books, bookCount);
            break;
        case 2:
            displayBooks(books, bookCount);
            break;
        case 3:
            addUser(users, userCount);
            break;
        case 4:
            displayUsers(users, userCount);
            break;
        case 5:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

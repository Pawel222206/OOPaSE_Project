#include <iostream>		// input/output
#include <string>		// string variable support
#include <vector>		// vector support
#include <Windows.h>	// acceses Windows API
#include <cstdlib>		// several general purpose functions
using namespace std;	// removes the requairement for "std::" clutter

#include "Book.h";
#include "Database.h";
#include "Account.h";
#include "Userbase.h";

int OpeningMenu();
int UserMenu();
int AdminMenu();

int main()
{
    Database* database = new Database();    // setting up the Book Database
    Book* book1 = new Book("01", "The Unified Modeling Language User Guide", "Booch G., Rumbaugh J., Jacobson I.");
    database->add(book1);
    Book* book2 = new Book("02", "Design Patterns: Elements of Reusable Object-Oriented Software", "Gamma E., Helms R., Johnson R., Vlissides J.");
    database->add(book2);
    Book* book3 = new Book("03", "Testing object-oriented systems", "Binder R.");
    database->add(book3);
    Book* book4 = new Book("04", "Professional C++, Third Edition", "Gregoire M.");
    database->add(book4);

    Userbase* userbase = new Userbase();    // setting up the User Accounts
    Account* account1 = new Account("Pawel", "123");
    userbase->addAccount(account1);
    Account* account2 = new Account("Asia", "kot321");
    userbase->addAccount(account2);
    
    // Program proper
    int adminPassword = 1234;   // set administration access password
    int in_adminPassword = 0;   // input varaivle for administration access password
    int adminActivity = 0;  // defines activity chosen in AdminMenu

    string in_exit;
    string in_borrowCode;

    while (true)    // Looping of the whole program
    {
        int accessType = OpeningMenu();  // Main menu

        if (accessType == 1) // GUEST access
        {
            cout << "Welcome guest!" << endl << endl;

            database->getAll(); // Provides a full catalogue of books in the library

            // exit - This should be a function ...but breaking loop from inside is easy
            cout << endl << "If you wish to close the program, write exit. If you want to return to main manu, write anything (except exit)." << endl;
            cin >> in_exit; string exit = "exit";
            if (in_exit == exit) { break; }
            else { Sleep(100); }    // sleep needed so we don't go throu several menues with a single input
        }
        else if (accessType == 2) // USER access
        {
            cout << "Welcome patron!" << endl << endl;

            int userActivity = UserMenu();  // User menu
            if (userActivity == 1)  // Logging in
            {
                cout << "Logging in:" << endl; // taking username and password as input from user
                cout << "Please enter your username: ";
                string in_username;
                cin >> in_username;
                cout << "Please enter your password: ";
                string in_password;
                cin >> in_password;

                if (userbase->loginAccount(in_username, in_password) == true)   // checking if the logging attempt was succesfull (also porvides user's borrowing history)
                {
                    database->getAll();
                    
                    while (true)    // looping, to allow for a log out
                    {
                        cout << endl << "If you wish to borrow a book, write its code." << endl;
                        cin >> in_borrowCode;
                        database->borrowBook_B(in_borrowCode);
                        userbase->borrowBook_A(in_borrowCode, in_username);

                        // log out
                        cout << endl << "If you wish to go back to main menu, write exit. If you want to borrow another book, write anything (except exit)." << endl;
                        cin >> in_exit; string exit = "exit";
                        if (in_exit == exit) { break; }
                        else { Sleep(100); }
                    }
                }
            }
            else if (userActivity == 2) // Registering
            {
                cout << "Sign in:" << endl; // taking username and password as input from user
                cout << "Please enter your username: ";
                string in_username;
                cin >> in_username;
                cout << "Please enter your password: ";
                string in_password;
                cin >> in_password;

                Account* newAccount = new Account(in_username, in_password);    // creating the account
                userbase->addAccount(newAccount);

                cout << "Account created succesfully" << endl << "Login: " << newAccount->getLogin() << endl << "Password: " << newAccount->getPassword();

                // exit
                cout << endl << "If you wish to close the program, write exit. If you want to return to main manu, write anything (except exit)." << endl;
                cin >> in_exit; string exit = "exit";
                if (in_exit == exit) { break; }
                else { Sleep(100); }
            }
        }
        else if (accessType == 3) // ADMIN access
        {
            cout << "Welcome Librarian!" << endl << endl << "Please provide password: ";
            cin >> in_adminPassword;
            if (in_adminPassword == adminPassword)
            {
                while (true)    // looping, to allow for a log out
                {
                    adminActivity = AdminMenu();    // Admin menu
                    if (adminActivity == 1) // Borrowing history
                    {
                        userbase->getHistory();

                        // log out
                        cout << endl << "If you wish to go back to main menu, write exit. If you want to return to admin menu, write anything (exept exit)." << endl;
                        cin >> in_exit; string exit = "exit";
                        if (in_exit == exit) { break; }
                        else { Sleep(100); }
                    }
                    else if (adminActivity == 2)    // Book's state manager
                    {
                        cout << "Book's state manager" << endl;
                        database->getAll();

                        cout << "To change state of the book simply enter it's code: " << endl;
                        string in_code;
                        cin >> in_code;
                        database->updateState(in_code);

                        // log out
                        cout << endl << "If you wish to go back to main menu, write exit. If you want to return to admin menu, write anything (exept exit)." << endl;
                        cin >> in_exit; string exit = "exit";
                        if (in_exit == exit) { break; }
                        else { Sleep(100); }
                    }
                }
            }
            else // wrong password
            {
                cout << "Wrong password, calling police :)" << endl;
                Sleep(1000);
                break;
            }
        }
        else // Error
        {
            cout << "Huh?";
            break;
        }
    }
    return 0;
}

// This menus are very rought, just to have some fun interface
int OpeningMenu()
{
    int menuState = 0;  // variable describing state of the menu: 0 - top, 1 - middle, 2 - bot, 3 - out
    int accesType = 0;  // variable carrying the resoult: 1- guest, 2 - user, 3 - admin

    system("cls"); // resets the screen
    cout << "Library:" << endl << "[>] Guest" << endl << "[ ] User" << endl << "[ ] Administrator" << endl;
    while (menuState < 3)
    {
        if (GetAsyncKeyState(VK_UP))    // if up arrow pressed
        {
            if (menuState == 1) // if "cursor" is in the middle
            {
                system("cls"); // resets the screen
                cout << "Library:" << endl << "[>] Guest" << endl << "[ ] User" << endl << "[ ] Administrator" << endl;
                menuState = 0;  // set "cursor" to top
                Sleep(100); // wait 0.1 seconds, to not get multiple inputs from one press
            }
            else
            {
                if (menuState == 2) // if select is at the bottom
                {
                    system("cls");
                    cout << "Library:" << endl << "[ ] Guest" << endl << "[>] User" << endl << "[ ] Administrator" << endl;
                    menuState = 1;
                    Sleep(100);
                }
            }
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            if (menuState == 0)
            {
                system("cls");
                cout << "Library:" << endl << "[ ] Guest" << endl << "[>] User" << endl << "[ ] Administrator" << endl;
                menuState = 1;
                Sleep(100);
            }
            else
            {
                if (menuState == 1)
                {
                    system("cls");
                    cout << "Library:" << endl << "[ ] Guest" << endl << "[ ] User" << endl << "[>] Administrator" << endl;
                    menuState = 2;
                    Sleep(100);
                }
            }
        }

        // Actions
        if (GetAsyncKeyState(VK_RIGHT))  // right arrow key becouse enter does not reset properly
        {
            switch (menuState)
            {
            case 0:
                menuState = 3;
                accesType = 1;
                break;
            case 1:
                menuState = 3;
                accesType = 2;
                break;
            case 2:
                menuState = 3;
                accesType = 3;
                break;
            default:    // incorrect value
                cout << "What? How?";
                break;
            }
        }
        Sleep(100);
    }
    system("cls");
    return accesType;
}

int UserMenu()
{
    int menuState = 0;
    int userActivity = 0;

    system("cls");
    cout << "[>] Sign in" << endl << "[ ] Create account" << endl;
    while (menuState < 2)
    {
        if (GetAsyncKeyState(VK_UP))
        {
                system("cls");
                cout << "[>] Sign in" << endl << "[ ] Create account" << endl;
                menuState = 0;
                Sleep(100);
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
                system("cls");
                cout << "[ ] Sign in" << endl << "[>] Create account" << endl;
                menuState = 1;
                Sleep(100);
        }

        // Actions
        if (GetAsyncKeyState(VK_RIGHT))
        {
            switch (menuState) {
            case 0:
                menuState = 2;
                userActivity = 1;
                break;
            case 1:
                menuState = 2;
                userActivity = 2;
                break;
            default:
                cout << "What? How?";
                break;
            }
        }
        Sleep(100);
    }
    system("cls");
    return userActivity;
}

int AdminMenu()
{
    int menuState = 0;
    int adminActivity = 0;

    system("cls");
    cout << "[>] Borrowing history" << endl << "[ ] Book's state manager" << endl;
    while (menuState < 2)
    {
        if (GetAsyncKeyState(VK_UP))
        {
            system("cls");
            cout << "[>] Borrowing history" << endl << "[ ] Book's state manager" << endl;
            menuState = 0;
            Sleep(100);
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            system("cls");
            cout << "[ ] Borrowing history" << endl << "[>] Book's state manager" << endl;
            menuState = 1;
            Sleep(100);
        }

        // Actions
        if (GetAsyncKeyState(VK_RIGHT))
        {
            switch (menuState) {
            case 0:
                menuState = 3;
                adminActivity = 1;
                break;
            case 1:
                menuState = 3;
                adminActivity = 2;
                break;
            default:    // incorrect value
                cout << "What? How?";
                break;
            }
        }
        Sleep(100);
    }
    system("cls");
    return adminActivity;
}
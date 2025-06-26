#include <iostream>		// input/output (cin/cout)
//#include <fstream>	// external files support
//#include <string>		// string variable support
#include <vector>		// vector variable support (Database)
//#include <map>		// map variable support
//#include <thread>		// thread variable support
//#include <mutex>		// mutex - constrainst
//#include <future>		// future - asynchronus programing
#include <Windows.h>	// acceses Windows API (menuing)
#include <cstdlib>		// several general purpose functions (menuing)
using namespace std;	// removes the requairement for "std::" clutter

#include "Book.h";
#include "Database.h";

int OpeningMenu();
int UserMenu();
int AdminMenu();

// main - test your might for template how to use method in other method

int main()
{
    /* TESTING BOOK.H
    Book* book1 = new Book();   // default constructor
    cout << book1->getCode() << book1->getState() << book1->getName() << book1->getAuthor() << endl;

    Book* book2 = new Book("0001", "Opowiesc Wigilijna", "Dickens");
    cout << book2->getCode() << book2->getState() << book2->getName() << book2->getAuthor() << endl;
    book2->getAll();

    delete book1;   // default destructor
    */

    //Simulating books - idealy I would store them in a .txt to have a memory but whatever
    Database* database = new Database();    // start by creating a database
    
    Book* book0 = new Book();   // construct book
    database->add(book0);   // add book to database, could be done cleaner but whatever
    Book* book1 = new Book("01", "The Unified Modeling Language User Guide", "Booch G., Rumbaugh J., Jacobson I.");
    database->add(book1);
    Book* book2 = new Book("02", "Design Patterns: Elements of Reusable Object-Oriented Software", "Gamma E., Helms R., Johnson R., Vlissides J.");
    database->add(book2);
    Book* book3 = new Book("03", "Testing object-oriented systems", "Binder R.");
    database->add(book3);
    Book* book4 = new Book("04", "Professional C++, Third Edition", "Gregoire M.");
    database->add(book4);
    book4->updateState("04");
    
    //database->getAll();   // test
    //delete database;
    
    // Program proper
    int accesType = 0;  // defines acces type chosen in OpeningMenu
    int adminPassword = 1234;   // set administration acces password
    int in_adminPassword = 0;   // input varaivle for administration acces password
    int adminActivity = 0;  // defines activity chosen in AdminMenu
    int userActivity = 0;  // defines activity chosen in UserMenu
    string in_exit;

    while (true)    // looping so you can ~log out
    {

        accesType = OpeningMenu();  // the function working the opening menu

        if (accesType == 1) // GUEST acces
        {
            cout << "Welcome guest!" << endl;
            database->getAll();

            // What is worse, a function using goto ripping the program back to start or another layer of if's?
            cout << endl << "If you wish to close the program, write exit. If you want to return to main manu, write anything (exept exit)." << endl;
            cin >> in_exit;
            string exit = "exit";   // This if is an atrocity
            if (in_exit == exit)
            {
                break;
            }
            else
            {
                Sleep(100);
            }
        }
        else if (accesType == 2) // USER acces
        {
            cout << "Welcome user" << endl;
            userActivity = UserMenu();

            if (userActivity == 1)
            {
                cout << "Sign in - PLACEHOLDER" << endl;
                break;
            }
            else if (userActivity == 2)
            {
                cout << "Create account - PLACEHOLDER" << endl;
                break;
            }
        }
        else if (accesType == 3) // ADMIN acces
        {
            cout << "Welcome admin!" << endl << "Please provide password: ";
            cin >> in_adminPassword;
            if (in_adminPassword == adminPassword)
            {
                while (true)    // looping so you can ~log out
                {
                    adminActivity = AdminMenu();

                    if (adminActivity == 1)
                    {
                        cout << "Borrowing history - database as PLACEHOLDER" << endl;  // it'll be the same but with diffrent database?
                        database->getAll();
                        Sleep(2000);
                        break;
                    }
                    else if (adminActivity == 2)
                    {
                        cout << "Book's state manager" << endl;
                        database->getAll();

                        cout << "To change state of the book simply enter it's code: " << endl;
                        string in_code;
                        cin >> in_code;
                        database->updateState(in_code);

                        // What is worse, a function using goto ripping the program back to start or another layer of if's?
                        cout << endl << "If you wish to go back to main menu, write exit. If you want to return to admin menu, write anything (exept exit)." << endl;
                        cin >> in_exit;
                        string exit = "exit";   // This if is an atrocity
                        if (in_exit == exit)
                        {
                            break;
                        }
                        else
                        {
                            Sleep(100);
                        }
                    }
                }
            }
            else
            {
                cout << "Wrong password, calling police :)" << endl;
                break;
            }
        }
        else
        {
            cout << "Huh?";
            break;
        }

    }

    return 0;
}

int OpeningMenu()
{
    int menuState = 0;  // variable describing state of the menu: 0 - top, 1 - middle, 2 - bot, 3 - out
    int accesType = 0;

    // Start menu
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
        if (GetAsyncKeyState(VK_RIGHT)) {
            switch (menuState) {
            case 0: // Guest acces
                menuState = 3;  // will stop the menu loop after completing this instruction
                //cout << "Guest" << endl;
                accesType = 1;
                break;
            case 1:
                menuState = 3;
                //cout << "User" << endl;
                accesType = 2;
                break;
            case 2:
                menuState = 3;
                //cout << "Admin" << endl;
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
    int menuState = 0;  // variable describing state of the menu: 0 - top, 1 - middle, 2 - bot, 3 - out
    int userActivity = 0;

    // Start menu
    system("cls");
    cout << "[>] Sign in" << endl << "[ ] Create account" << endl;
    while (menuState < 2)
    {
        if (GetAsyncKeyState(VK_UP))    // if up arrow pressed
        {
                system("cls"); // resets the screen
                cout << "[>] Sign in" << endl << "[ ] Create account" << endl;
                menuState = 0;  // set "cursor" to top
                Sleep(100); // wait 0.1 seconds, to not get multiple inputs from one press
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
                system("cls");
                cout << "[ ] Sign in" << endl << "[>] Create account" << endl;
                menuState = 1;
                Sleep(100);
        }

        // Actions
        if (GetAsyncKeyState(VK_RIGHT)) // right arrow key becouse enter does not reset properly
        {
            switch (menuState) {
            case 0: // Guest acces
                menuState = 2;  // will stop the menu loop after completing this instruction
                //cout << "Guest" << endl;
                userActivity = 1;
                break;
            case 1:
                menuState = 2;
                //cout << "User" << endl;
                userActivity = 2;
                break;
            default:    // incorrect value
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
    int menuState = 0;  // variable describing state of the menu: 0 - top, 1 - middle, 2 - bot, 3 - out
    int adminActivity = 0;

    // Start menu
    system("cls");
    cout << "[>] Borrowing history" << endl << "[ ] Book's state manager" << endl;
    while (menuState < 2)
    {
        if (GetAsyncKeyState(VK_UP))    // if up arrow pressed
        {
            system("cls"); // resets the screen
            cout << "[>] Borrowing history" << endl << "[ ] Book's state manager" << endl;
            menuState = 0;  // set "cursor" to top
            Sleep(100); // wait 0.1 seconds, to not get multiple inputs from one press
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            system("cls");
            cout << "[ ] Borrowing history" << endl << "[>] Book's state manager" << endl;
            menuState = 1;
            Sleep(100);
        }

        // Actions
        if (GetAsyncKeyState(VK_RIGHT)) // right arrow key becouse enter does not reset properly
        {
            switch (menuState) {
            case 0: // Guest acces
                menuState = 3;  // will stop the menu loop after completing this instruction
                //cout << "Guest" << endl;
                adminActivity = 1;
                break;
            case 1:
                menuState = 3;
                //cout << "User" << endl;
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
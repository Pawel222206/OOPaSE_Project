#include <iostream>		// input/output
//#include <fstream>	// external files support
//#include <string>		// string variable support
//#include <vector>		// vector variable support
//#include <map>		// map variable support
//#include <thread>		// thread variable support
//#include <mutex>		// mutex - constrainst
//#include <future>		// future - asynchronus programing
#include <Windows.h>	// acceses Windows API
#include <cstdlib>		// several general purpose functions
using namespace std;	// removes the requairement for "std::" clutter

int OpeningMenu();
int UserMenu();
int AdminMenu();

int main()
{
    int accesType = 0;  // defines acces type chosen in OpeningMenu
    int adminPassword = 1234;   // set administration acces password
    int in_adminPassword = 0;   // input varaivle for administration acces password
    int adminActivity = 0;  // defines activity chosen in AdminMenu
    int userActivity = 0;

    accesType = OpeningMenu();  // the function working the opening menu

    if (accesType == 1) // GUEST acces
    {
        cout << "Welcome guest" << endl;
        cout << "Go to database - PLACEHOLDER" << endl;
    }
    else if (accesType == 2) // USER acces
    {
        cout << "Welcome user" << endl;
        userActivity = UserMenu();

        if (userActivity == 1)
        {
            cout << "Sign in - PLACEHOLDER" << endl;
        }
        else if (userActivity == 2)
        {
            cout << "Create account - PLACEHOLDER" << endl;
        }
    }
    else if (accesType == 3) // ADMIN acces
    {
        cout << "Please provide admin password" << endl;
        cin >> in_adminPassword;
        if (in_adminPassword == adminPassword)
        {
            cout << "Welcome admin";
            adminActivity = AdminMenu();

            if (adminActivity == 1)
            {
                cout << "Borrowing history - PLACEHOLDER" << endl;
            }
            else if (adminActivity == 2)
            {
                cout << "Book's state manager - PLACEHOLDER" << endl;
            }
        }
        else
        {
            cout << "Wrong admin password" << endl;
        }
    }
    else
    {
        cout << "Huh?";
    }

    return 0;
}

int OpeningMenu()
{
    int menuState = 0;  // variable describing state of the menu: 0 - top, 1 - middle, 2 - bot, 3 - out
    int accesType = 0;

    // Start menu
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
        if (GetAsyncKeyState(VK_RETURN)) {
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
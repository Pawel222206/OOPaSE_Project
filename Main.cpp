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

void OpeningMenu()
{
    int menuState = 0;  // variable describing state of the menu: 0 - top, 1 - middle, 2 - bot, 3 - out
    int menuExit = 0;   // variable breaking out of the main manu loop

    // Start menu
    cout << "Library:" << endl << "[>] Sign in" << endl << "[ ] Register" << endl << "[ ] Exit" << endl;
    while (menuExit == 0)
    {
        if (GetAsyncKeyState(VK_UP))    // if up arrow pressed
        {
            if (menuState == 1) // if "cursor" is in the middle
            {
                system("cls"); // resets the screen
                cout << "Library:" << endl << "[>] Sign in" << endl << "[ ] Register" << endl << "[ ] Exit" << endl;
                menuState = 0;  // set "cursor" to top
                Sleep(100); // wait 0.1 seconds, to not get multiple inputs from one press
            }
            else 
            {
                if (menuState == 2) // if select is at the bottom
                {
                    system("cls");
                    cout << "Library:" << endl << "[ ] Sign in" << endl << "[>] Register" << endl << "[ ] Exit" << endl;
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
                cout << "Library:" << endl << "[ ] Sign in" << endl << "[>] Register" << endl << "[ ] Exit" << endl;
                menuState = 1;
                Sleep(100);
            }
            else 
            {
                if (menuState == 1) 
                {
                    system("cls");
                    cout << "Library:" << endl << "[ ] Sign in" << endl << "[ ] Register" << endl << "[>] Exit" << endl;
                    menuState = 2;
                    Sleep(100);
                }
            }
        }

        // Actions
        if (GetAsyncKeyState(VK_RETURN)) {
            switch (menuState) {
            case 0: // Logging in
                cout << "Logging in" << endl;
                break;
            case 1:
                cout << "Registering" << endl;
                break;
            case 2:
                cout << "Exit";
                menuExit = 1;
                break;
            default:    // incorrect value
                cout << "What? How?";
                break;
            }
        }
        Sleep(100);
    }
}

int main() {
    
    OpeningMenu();
    cout << "Done";
    return 0;
}
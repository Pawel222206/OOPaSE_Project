//#include <iostream>
//#include <string>
//#include <Windows.h>
//#include <cstdlib>
//using namespace std;
//
////int main() {
//    //VALUES
//    int menumax = 0;
//    int menuvalue = 1;
//    int back = 0;
//
//    //MENU START
//    cout << "[----MENU----]" << endl;
//    cout << "[>>] START" << endl;
//    cout << "[] SETTINGS" << endl;
//    cout << "[] EXIT" << endl;
//    cout << "[------------]" << endl;
//
//    //MENU + APPLICATION
//    while (true)
//    {
//        if (GetAsyncKeyState(VK_UP)) {
//            if (menumax == 1) {
//                system("cls");
//                cout << "[----MENU----]" << endl;
//                cout << "[>>] START" << endl;
//                cout << "[] SETTINGS" << endl;
//                cout << "[] EXIT" << endl;
//                cout << "[------------]" << endl;
//                menumax = 0;
//                menuvalue = 1;
//                Sleep(100);
//            }
//            else {
//                if (menumax == 2) {
//                    system("cls");
//                    cout << "[----MENU----]" << endl;
//                    cout << "[] START" << endl;
//                    cout << "[>>] SETTINGS" << endl;
//                    cout << "[] EXIT" << endl;
//                    cout << "[------------]" << endl;
//                    menumax = 1;
//                    menuvalue = 2;
//                    Sleep(100);
//                }
//            }
//        }
//        if (GetAsyncKeyState(VK_DOWN)) {
//            if (menumax == 0) {
//                system("cls");
//                cout << "[----MENU----]" << endl;
//                cout << "[] START" << endl;
//                cout << "[>>] SETTINGS" << endl;
//                cout << "[] EXIT" << endl;
//                cout << "[------------]" << endl;
//                menumax = 1;
//                menuvalue = 2;
//                Sleep(100);
//            }
//            else {
//                if (menumax == 1) {
//                    system("cls");
//                    cout << "[----MENU----]" << endl;
//                    cout << "[] START" << endl;
//                    cout << "[] SETTINGS" << endl;
//                    cout << "[>>] EXIT" << endl;
//                    cout << "[------------]" << endl;
//                    menumax = 2;
//                    menuvalue = 3;
//                    Sleep(100);
//                }
//            }
//
//        }
//        //IF USER HAS CHOSEN FROM MENU.
//        if (GetAsyncKeyState(VK_RETURN)) {
//            switch (menuvalue) {
//                //STARTING APPLICATION
//            case 1:
//                cout << "DONE" << endl;
//                break;
//                //SETTINGS
//            case 2:/*
//                while(back==0){
//                    system("cls");
//                    cout<<"[----SETTINGS----]"<<endl;
//                    cout<<"[] START"<<endl;
//                    cout<<"[]"<<endl;
//                    cout<<"[] BACK"<<endl;
//                    cout<<"[------------]"<<endl;
//                }
//                back = 0; */
//                break;
//                //EXIT APPLICATION
//            case 3:
//                return 0;
//                break;
//                //INCORRECT VALUE
//            default:
//                cout << "ERROR";
//                break;
//
//            }
//        }
//        Sleep(100);
//
//    }
//    return 0;
//}
#include <iostream>
#include <string>
#define MAX 1500
// Maximum 1500 contacts

using namespace std;

void showMenu() {
    cout << "================================" << endl;
    cout << "1. Add contacts" << endl;
    cout << "2. Show contacts" << endl;
    cout << "3. Delete contacts" << endl;
    cout << "4. Find contacts" << endl;
    cout << "5. Edit contacts" << endl;
    cout << "6. Clear contacts" << endl;
    cout << "0. Exit" << endl;
    cout << "================================" << endl;
}

struct Person {
    string P_Name;
    int P_Gender; // 1 for male, 2 for female
    int P_Age;
    string P_Phone;
    string P_Email;
};

struct AddressBook {
    struct Person personArray[MAX];
    int P_Size;
};

int main() {
    int select = 0;

    while(true) {
        showMenu();

        cin >> select;

        switch(select) {
            case 1: // Add contacts
                break;
            case 2: // Show contacts
                break;
            case 3: // Delete contacts
                break;
            case 4: // Find contacts
                break;
            case 5: // Edit contacts
                break;
            case 6: // Clear contacts
                break;
            case 0: // Exit
                cout << "See you next time!" << endl;
                return 0;
            default:
                break;
        }    
    }
    

    return 0;
}
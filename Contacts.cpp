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

void AddPerson(AddressBook * book) {
    if(book->P_Size == MAX) {
        cout << "Contacts is FULL!" << endl;
        return;
    }
    else {
        string name;
        cout << "Enter name: " << endl;
        cin >> name;
        book->personArray[book->P_Size].P_Name = name;

        int gender = 0;
        cout << "Enter 1 for male, 2 for female" << endl;
        cout << "Enter gender:" << endl;
        
        while(true) {
            cin >> gender;
            if(gender == 1||gender == 2) {
                book->personArray[book->P_Size].P_Gender = gender;
                break;
            }
            cout << "ERROR! Please enter again." << endl;
        }

        int age = 0;
        cout << "Enter age: " << endl;
        
        while(true) {
            cin >> age;
            if(age > 0 && age < 200) {
                book->personArray[book->P_Size].P_Age = age;
                break;
            }
            cout << "ERROR! Please enter again." << endl;
            // control + c to terminate
        }

        string phone;
        cout << "Enter phone number: " << endl;
        cin >> phone;
        book->personArray[book->P_Size].P_Phone = phone;

        string email;
        cout << "Enter email: " << endl;
        cin >> email;
        book->personArray[book->P_Size].P_Email = email;

        book->P_Size++;

        system("pause");
        system("cls");
    }
}

int main() {
    int select = 0;
    AddressBook book;
    book.P_Size = 0;

    while(true) {
        showMenu();

        cin >> select;

        switch(select) {
            case 1: // Add contacts
                AddPerson(&book);
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
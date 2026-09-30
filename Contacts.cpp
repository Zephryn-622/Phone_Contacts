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

void pauseClear() {
    cout << endl;
    cout << "Press ENTER to continue..." << endl;

    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();

    system("clear");
}

struct Person {
    string P_Name;
    int P_Gender; // 1 for male, 2 for female
    int P_Age; // age in between 0 and 200
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
        // Name
        string name;
        cout << "Enter name: ";
        cin >> name;
        book->personArray[book->P_Size].P_Name = name;

        // Gender
        int gender = 0;
        cout << "Enter gender (1 for male, 2 for female): ";
        
        while(true) {
            cout << "Enter gender: ";
            cin >> gender;
            if(gender == 1||gender == 2) {
                book->personArray[book->P_Size].P_Gender = gender;
                break;
            }
            cout << "ERROR! Please enter again." << endl;
            // control + c to terminate
        }

        // Age
        int age = 0;
        
        while(true) {
            cout << "Enter age: ";
            cin >> age;
            if(age > 0 && age < 200) {
                book->personArray[book->P_Size].P_Age = age;
                break;
            }
            cout << "ERROR! Please enter again." << endl;
            // control + c to terminate
        }

        // Phone number
        string phone;
        cout << "Enter phone number: ";
        cin >> phone;
        book->personArray[book->P_Size].P_Phone = phone;

        // Email
        string email;
        cout << "Enter email: ";
        cin >> email;
        book->personArray[book->P_Size].P_Email = email;

        // Increase contact count
        book->P_Size++;

        cout << endl;
        cout << "Added successful" << endl;
        
        pauseClear();
    }
}

void ShowPerson(AddressBook * book) {
    if(book->P_Size == 0){
        cout << "No contacts in system." << endl;
    }
    else {
        for(int i = 0; i < book->P_Size; i++) {
            cout << "Name: " << book->personArray[i].P_Name << endl;

            if(book->personArray[i].P_Gender == 1) {
                cout << "Gender: Male" << endl;
            }
            else {
                cout << "Gender: Female" << endl;
            }

            cout << "Gender: " << book->personArray[i].P_Gender << endl;
            cout << "Age: " << book->personArray[i].P_Age << endl;
            cout << "Phone number: " << book->personArray[i].P_Phone << endl;
            cout << "E-mail: " << book->personArray[i].P_Email << endl;
            cout << endl;
        }
        pauseClear();
    }
    
}

int main() {
    int select = 0;
    AddressBook book;
    book.P_Size = 0;

    while(true) {
        showMenu();

        cin >> select;
        cout << endl;

        switch(select) {
            case 1: // Add contacts
                AddPerson(&book);
                break;
            case 2: // Show contacts
                ShowPerson(&book);
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
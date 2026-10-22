#include <iostream>
#include <string>
#define MAX 1500
// Maximum 1500 contacts

using namespace std;

// Show all selection in menu
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

// Pause and clear screen
void pauseClear() {
    cout << endl;
    cout << "Press ENTER to continue..." << endl;

    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.get();

    system("clear");
}

// Structure of contacts
struct Person {
    string P_Name;
    int P_Gender; // 1 for male, 2 for female
    int P_Age; // age in between 0 and 200
    string P_Phone;
    string P_Email;
};

// Structure of address book
struct AddressBook {
    struct Person personArray[MAX];
    int P_Size;
};

// 1. Add contact function
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

// 2. Show contact function
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

// Determine contact existence function
int PersonExist(AddressBook * book, string name) {
    for(int i = 0; i < book->P_Size; i++) {
        if(book->personArray[i].P_Name == name) {
            // contact found
            return i;
        }
    }
    // contact not found
    return -1; 
}

// 3. Delete contact function
void DeletePerson(AddressBook * book) {
    cout << "Enter contact name to be deleted: ";
    string name;
    cin >> name;

    int deletePerson = PersonExist(book, name);
    

    // -1 is not found, other is found 
    if(deletePerson != -1) {
        for(int i = deletePerson; i < book->P_Size; i++) {
            book->personArray[i] = book->personArray[i + 1];
        }
        book->P_Size--;
        cout << endl;
        cout << "Deleted successful" << endl;
    }
    else {
        cout << endl;
        cout << "Contact not found." << endl;
    }
    pauseClear();
}

// 4. Find contact function
void FindPerson(AddressBook * book) {
    cout << "Enter contact name want to found: ";
    string name;
    cin >> name;

    int findPerson = PersonExist(book, name);

    // -1 is not found, other is found
    if(findPerson != -1) {
        cout << endl;
        cout << "Contact name: " << book->personArray[findPerson].P_Name << endl;
        cout << "Contact gender: " << book->personArray[findPerson].P_Gender << endl;
        cout << "Contact age: " << book->personArray[findPerson].P_Age << endl;
        cout << "Contact phone number: " << book->personArray[findPerson].P_Phone << endl;
        cout << "Contact email: " << book->personArray[findPerson].P_Email << endl;
    }else {
        cout << endl;
        cout << "Contact not found." << endl;
    }
    pauseClear();
}

// 5. Edit contact function
void EditPerson(AddressBook * book) {
    cout << "Enter contact name want to edit: ";
    string name;
    cin >> name;

    int editPerson = PersonExist(book, name);

    // -1 is not found, other is found
    if(editPerson != -1) {
        cout << endl;

        cout << "Name changed: ";
        string name;
        cin >> name;
        book->personArray[editPerson].P_Name = name;

        int gender = 0;
        while(true) {
            cout << "Gender changed (1 for male, 2 for female): ";
            cin >> gender;
            if(gender == 1||gender == 2) {
                book->personArray[editPerson].P_Gender = gender;
                break;
            }
            cout << "ERROR! Please enter again." << endl;
            // control + c to terminate
        }

        int age = 0;
        while(true) {
            cout << "Enter age: ";
            cin >> age;
            if(age > 0 && age < 200) {
                book->personArray[editPerson].P_Age = age;
                break;
            }
            cout << "ERROR! Please enter again." << endl;
            // control + c to terminate
        }

        cout << "Phone number changed: ";
        string phone;
        cin >> phone;
        book->personArray[editPerson].P_Phone = phone;

        cout << "Email changed: ";
        string email;
        cin >> email;
        book->personArray[editPerson].P_Email = email;

        cout << endl;
        cout << "Changed successfully." << endl;
    }else {
        cout << endl;
        cout << "Contact not found." << endl;
    }

    pauseClear();
}

// 6. Clear contact
void ClearPerson(AddressBook * book) {
    char select;

    // Enter yes or no to clear all contacts
    while(true){
        cout << "Confirm clear all contacts? (Y/N)" << endl;
        cin >> select;

        if(select == 'Y' || select == 'y'){
            book->P_Size = 0;
            cout << endl;
            cout << "All contacts cleared." << endl;
            break;
        }else if(select == 'N' || select == 'n'){
            break;
        }else{
            cout << endl;
            cout << "ERROR! Please enter again.\n" << endl;
            cout << endl;
        }
    }
    pauseClear();
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
                DeletePerson(&book);
                break;
            case 4: // Find contacts
                FindPerson(&book);
                break;
            case 5: // Edit contacts
                EditPerson(&book);
                break;
            case 6: // Clear contacts
                ClearPerson(&book);
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
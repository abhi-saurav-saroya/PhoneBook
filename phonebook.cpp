#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class PhoneBook {
    private:
        string firstName;
        string lastName;
        unsigned long long contact[5];

    public:
        void addContact();
        void displayContact();
        void updateContact();
        void deleteContact();
        void searchContact();
        void sortContacts();
        void saveToFile();
        void loadFromFile();
        void menu();
        // void inline clearScreen() {
        //     #ifdef _WIN32
        //         system("cls");
        //     #else
        //         system("clear");
        //     #endif
        // }
};

void PhoneBook::menu() {
    int choice;
    do {
        cout << "Phone Book Menu:\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Update Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Search Contact\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        if(!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            continue;
        }

        cin >> choice;

        switch(choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContact();
                break;
            case 3:
                updateContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                searchContact();
                break;
            case 6:
                cout << "Exiting Phone Book. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 6);
}

void PhoneBook::addContact() {
    cout << "\t1. Add New Contact\n";
    cout << "\t2. Add to existing Contact\n";
    int subChoice;
    cin >> subChoice;

    if(subChoice == 1) {
        cout << "Enter first name: ";
        cin >> firstName;
        cout << "Enter last name: ";
        cin >> lastName;
        cout << "Enter contact number: ";

        if(!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid contact number. Please enter digits only." << endl;
            return;
        }
        cin >> contact[0];

        ofstream file("phonebook.txt", ios::app);
        file << firstName << " " << lastName << " " << contact << endl;
        file.close();
    }

    else if(subChoice == 2) {
        cout << "Feature under development." << endl;
        return;
    } 
    
    else {
        cout << "Invalid choice." << endl;
        return;
    }

    cout << "Contact added successfully!" << endl;
}

void PhoneBook::searchContact() {
    cout << "1. Search by First Name\n";
    cout << "2. Search by Last Name\n";
    cout << "3. Search by Contact Number\n";
    int searchChoice;

    if(!cin) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input." << endl;
        return;
    }
    cin >> searchChoice;

    string fName;
    string lName;
    unsigned long long cNumber;

    if(searchChoice == 1) {
        cout << "Enter first name: ";
        cin >> fName;
    } 
    else if(searchChoice == 2) {
        cout << "Enter last name: ";
        cin >> lName;
    } 
    else if(searchChoice == 3) {
        while(1) {
            cout << "Enter contact number: ";
            if(!cin) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input. Please enter a number between 1 and 6." << endl;
                continue;
            }
            cin >> cNumber;
            break;
        }
    } 
    else {
        cout << "Invalid choice." << endl;
    }

    ifstream file("phonebook.txt");
    string fNameFile, lNameFile;
    unsigned long long cNumberFile;
    while(file >> fNameFile >> lNameFile >> cNumberFile) {
        if(searchChoice == 1 && fName == fNameFile) {
            cout << "First Name: " << fNameFile << endl;
            cout << "Last Name: " << lNameFile << endl;
            cout << "Contact Number: " << cNumberFile << endl;
        }
        else if(searchChoice == 2 && lName == lNameFile) {
            cout << "First Name: " << fNameFile << endl;
            cout << "Last Name: " << lNameFile << endl;
            cout << "Contact Number: " << cNumberFile << endl;
        }
        else if(searchChoice == 3 && cNumber == cNumberFile) {
            cout << "First Name: " << fNameFile << endl;
            cout << "Last Name: " << lNameFile << endl;
            cout << "Contact Number: " << cNumberFile << endl;
        }
    }
    file.close();
}

void PhoneBook::displayContact() {
    cout << "Feature under development." << endl;
}

int main() {
    PhoneBook pb;
    pb.menu();
    return 0;
}
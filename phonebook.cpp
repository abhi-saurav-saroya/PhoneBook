#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<limits>
using namespace std;

struct Contact {
    string firstName;
    string lastName;
    vector<unsigned long long> numbers;
};

class PhoneBook {
    private:
        vector<Contact> contacts;

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
        bool nameExists(const string& first, const string& last);
        bool numberExists(unsigned long long number);
        Contact* findContact(const string& first, const string& last);
        Contact* findContact(unsigned long long number);
};

string toLower(const string& s) {
    string result = s;
    for (char& ch : result) {
        ch = tolower(ch);
    }
    return result;
}

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

        cin >> choice;
        if(!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 6." << endl << endl;
            continue;
        }

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

bool PhoneBook::nameExists(const string& first, const string& last) {
    for (const Contact& c : contacts) {
        if (c.firstName == first && c.lastName == last)
            return true;
    }
    return false;
}

bool PhoneBook::numberExists(unsigned long long number) {
    for (const Contact& c : contacts) {
        for (unsigned long long num : c.numbers) {
            if (num == number)
                return true;
        }
    }
    return false;
}

Contact* PhoneBook::findContact(const string& first, const string& last) {
    for (Contact& c : contacts) {
        bool firstMatch = first.empty() || toLower(c.firstName) == toLower(first);
        bool lastMatch  = last.empty() || toLower(c.lastName) == toLower(last);
        if (firstMatch && lastMatch) {
            return &c;
        }
    }
    return nullptr;
}

Contact* PhoneBook::findContact(unsigned long long number) {
    for (Contact& c : contacts) {
        for (unsigned long long num : c.numbers) {
            if (num == number) {
                return &c;
            }
        }
    }
    return nullptr;
}

void PhoneBook::addContact() {
    int subChoice;

    while(1) {
        cout << endl;
        cout << "\t1. Add New Contact\n";
        cout << "\t2. Add to existing Contact\n";
        cout << "Enter your choice: ";

        cin >> subChoice;
        if(!cin || subChoice < 1 || subChoice > 2) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input." << endl;
            continue;
        }
        break;
    }

    if(subChoice == 1) {
        cout << endl;
        cout << "Enter first name: ";
        string firstName, lastName;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, firstName);
        cout << "Enter last name: ";
        cin >> lastName;
        cout << "Enter contact number: ";

        unsigned long long cNumber;
        cin >> cNumber;
        if(!cin) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid contact number. Please enter digits only." << endl;
            return;
        }

        if(nameExists(firstName, lastName)) {
            cout << "Contact with this name already exists." << endl;
            return;
        }

        if(numberExists(cNumber)) {
            cout << "This phone number already exists." << endl;
            return;
        }

        Contact c;
        c.firstName = firstName;
        c.lastName = lastName;
        c.numbers.push_back(cNumber);
        contacts.push_back(c);
    }

    else if(subChoice == 2) {
        cout << endl;
        string firstName, lastName;
        unsigned long long cNumber;

        cout << "Enter first name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, firstName);
        cout << "Enter last name: ";
        cin >> lastName;

        Contact* existingContact = findContact(firstName, lastName);

        if (!existingContact) {
            cout << "Contact not found." << endl;
            return;
        }

        while(1) {
            cout << "Enter new contact number: ";
            cin >> cNumber;
            if(!cin) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid contact number. Please enter digits only." << endl;
                return;
            }
            break;
        }
        
        if(numberExists(cNumber)) {
            cout << "This phone number already exists." << endl;
            return;
        }

        existingContact->numbers.push_back(cNumber);
    }

    cout << "Contact added successfully!" << endl;
}

void PhoneBook::searchContact() {
    cout << endl;
    cout << "\t1. Search by First Name\n";
    cout << "\t2. Search by Last Name\n";
    cout << "\t3. Search by Contact Number\n";
    int searchChoice;

    while(1) {
        cout << "Enter your choice: ";
        cin >> searchChoice;
        if(!cin || searchChoice < 1 || searchChoice > 3) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            continue;
        }
        break;
    }

    string fName;
    string lName;
    unsigned long long cNumber;

    if(searchChoice == 1) {
        cout << endl;
        cout << "Enter first name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, fName);

        Contact* c = findContact(fName, "");
        if (!c) {
            cout << "No contact found with first name \"" << fName << "\".\n";
        } else {
            cout << "Contact found:\n";
            cout << "First Name: " << c->firstName << "\n";
            cout << "Last Name: " << c->lastName << "\n";
            cout << "Numbers: ";
            for (auto num : c->numbers) {
                cout << num << " ";
            }
            cout << endl;
        }
    } 

    else if(searchChoice == 2) {
        cout << endl;
        cout << "Enter last name: ";
        cin >> lName;

        Contact* c = findContact("", lName);
        if (!c) {
            cout << "No contact found with last name \"" << lName << "\".\n";
        } else {
            cout << "Contact found:\n";
            cout << "First Name: " << c->firstName << "\n";
            cout << "Last Name: " << c->lastName << "\n";
            cout << "Numbers: ";
            for (auto num : c->numbers) {
                cout << num << " ";
            }
            cout << endl;
        }
    } 

    else if(searchChoice == 3) {
        while(1) {
            cout << endl;
            cout << "Enter contact number: ";
            cin >> cNumber;
            if(!cin) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid contact number." << endl;
                continue;
            }
            break;
        }

        Contact* c = findContact(cNumber);
        if (!c) {
            cout << "No contact found with contact number \"" << cNumber << "\".\n";
        } else {
            cout << "Contact found:\n";
            cout << "First Name: " << c->firstName << "\n";
            cout << "Last Name: " << c->lastName << "\n";
            cout << "Numbers: ";
            for (auto num : c->numbers) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

}

void PhoneBook::displayContact() {
    cout << endl;
    cout << "Feature under development." << endl;
}

void PhoneBook::updateContact() {
    cout << endl;
    cout << "Feature under development." << endl;
}

void PhoneBook::deleteContact() {
    cout << endl;
    string fName, lName;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter the First Name and Last Name of the contact to delete." << endl;
    cin >> fName >> lName;

    vector<Contact>::iterator it;
    for (it = contacts.begin(); it != contacts.end(); ++it) {
        if (toLower(it->firstName) == toLower(fName) && toLower(it->lastName) == toLower(lName)) {
            contacts.erase(it);
            cout << "All contact numbers of this contact deleted successfully." << endl;
            return;
        }
    }
    cout << "Contact not found." << endl;
}

void PhoneBook::sortContacts() {
    cout << endl;
    cout << "Feature under development." << endl;
}

void PhoneBook::saveToFile() {
    cout << endl;
    cout << "Feature under development." << endl;
}

void PhoneBook::loadFromFile() {
    cout << endl;
    cout << "Feature under development." << endl;
}

int main() {
    PhoneBook pb;
    pb.menu();
    return 0;
}
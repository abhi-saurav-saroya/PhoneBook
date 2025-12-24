# C++ Contact Manager Application

A console-based contact manager application implemented entirely in C++ using object-oriented and generic programming features. This program allows users to manage contacts efficiently, including adding, updating, deleting, searching, displaying, and saving contacts in sorted manner to a file for permanent backup.

## Features

- **Add Contact:**  
  - Add a completely new contact with first name, last name, and one or more phone numbers.  
  - Add additional numbers to an existing contact.  
  - Validates that contact names and numbers are unique.

- **Display Contacts:**  
  - Lists all contacts in alphabetical order by first name and then last name.  
  - Displays all associated phone numbers.

- **Update Contact:**  
  - Update first name, last name, or individual phone numbers.  
  - Ensures updated names or numbers remain unique within the contact list.

- **Delete Contact:**  
  - Delete a contact completely by specifying first and last names.

- **Search Contact:**  
  - Search contacts by first name, last name, or phone number.  
  - Case-insensitive search for names.

- **Persistent Storage:**  
  - Automatically saves all contacts to a file (`contacts.txt`) on exit.  
  - Loads contacts from file when the program starts.

## Object-Oriented Programming (OOP) Features

- **Class and Encapsulation:**  
  - `PhoneBook` class encapsulates all contact management operations.  
  - Private members: `contacts` vector storing all `Contact` objects.  
  - Public member functions: `addContact()`, `displayContact()`, `updateContact()`, `deleteContact()`, `searchContact()`, `sortContacts()`, `saveToFile()`, `loadFromFile()`, `menu()`, `nameExists()`, `numberExists()`, `findContact()`.

- **Structs for Data Representation:**  
  - `Contact` struct stores individual contact details: `firstName`, `lastName`, and a vector of phone numbers.

- **Constructors and Destructors:**  
  - Destructor of `PhoneBook` ensures contacts are saved to file automatically upon program exit.

- **Method Organization and Modularity:**  
  - Each functionality (add, update, delete, search, display) is implemented as a separate method for clarity and reusability.

## Generic Programming and Standard Library Usage

- **`<algorithm>` library:**  
  - Used for sorting contacts alphabetically by first and last names (`sortContacts()` method).

- **`<sstream>` library:**  
  - Used for parsing saved contact data from file (`loadFromFile()` method).

- **Other Standard Libraries:**  
  - `<iostream>` for console input/output.  
  - `<string>` for string operations.  
  - `<vector>` for dynamic storage of contacts and numbers.  
  - `<fstream>` for file handling.  
  - `<limits>` for robust input handling.

## Input Handling

- All inputs are validated for correctness (numeric, non-empty, and within constraints).  
- Invalid inputs are handled gracefully without crashing the program using `cin.clear()` and `cin.ignore()`.  
- Case-insensitive search ensures more flexible name matching.  
- Duplicate names or numbers are prevented.

## File Handling

- Contacts are automatically loaded from `contacts.txt` at program start.  
- Updates and additions are saved back to the file upon program exit.  
- Each line in the file represents a contact with first name, last name, and all associated numbers separated by spaces.

## How to Compile and Run

1. Open a terminal or command prompt.  
2. Navigate to the folder containing `contact_manager.cpp`.  
3. Compile the program with a C++ compiler:

```bash
g++ phonebook.cpp -o phonebook
```
4. Run the program:
```bash
# Linux / Mac
./phonebook

# Windows
phonebook.exe
```

## Requirements

1. C++ Compiler
2. Standard C++ library headers: `<iostream>`, `<string>`, `<vector>`, `<fstream>`, `<sstream>`, `<algorithm>`, `<limits>`.
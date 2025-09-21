// COMSC-210 | Lab 11 | Mamadou Sissoko
// IDE used: Visual Studio Code

#include <iostream>
#include <string>
using namespace std;

// constants
const int MAX_PATIENTS = 100; // max allowed patients

// A struct to represent a hospital patient
// Each patient has a name, age, a dynamic list of medications, and a count of medications
struct Patient {
    string name;
    int age;
    string* medications;
    int numMeds;
}

// Function prototypes
void inputPatients(Patient* patients, int size);

// inputPatients() prompts user to enter patient info including medications
// arguments: pointer to array of Patient structs, size of the array
// returns: nothing, fills patient array with input data
void inputPatients(Patient* patients, int size) {
    for (int i = 0; i < size; i++) {
        cout << "\n--- Enter info for Patient #" << (i + 1) << " ---\n";

        cin.ignore(); // clear leftover newline
        cout << "Name: ";
        getline(cin, patients[i].name);

        // Validate age input
        cout << "Age: ";
        while (!(cin >> patients[i].age) || patients[i].age <= 0) {
            cout << "Invalid age. Please enter a positive number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        // Validate number of medications input
        cout << "How many medications is " << patients[i].name << " taking? ";
        while (!(cin >> patients[i].numMeds) || patients[i].numMeds < 0) {
            cout << "Invalid number. Please enter 0 or a positive number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        // Allocate medication array if needed
        if (patients[i].numMeds > 0) {
            patients[i].medications = new string[patients[i].numMeds];
            cin.ignore(); // clear newline before getline loop
            for (int j = 0; j < patients[i].numMeds; j++) {
                cout << "Enter medication #" << (j + 1) << ": ";
                getline(cin, patients[i].medications[j]);
            }
        } else {
            patients[i].medications = nullptr;
        }
    }
}

int main() {
    int numPatients;

    cout << "Enter the number of patients to record (max " << MAX_PATIENTS << "): ";
    while (!(cin >> numPatients) || numPatients <= 0 || numPatients > MAX_PATIENTS) {
        cout << "Invalid number. Please enter a number between 1 and " << MAX_PATIENTS << ": ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    // Create a dynamic array of Patient structs
    Patient* patients = new Patient[numPatients];

    // Input patient data
    inputPatients(patients, numPatients);

    // Free dynamic memory
    for (int i = 0; i < numPatients; i++) {
        delete[] patients[i].medications;
    }
    delete[] patients;

    return 0;
}

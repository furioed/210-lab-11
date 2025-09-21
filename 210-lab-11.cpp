// COMSC-210 | Lab 11 | Mamadou Sissoko
// IDE used: Visual Studio Code

#include <iostream>
#include <string>
using namespace std;

// constants
const int MAX_PATIENTS = 100;

// A struct to represent a hospital patient
// Each patient has a name, age, a dynamic list of medications, and a count of medications
struct Patient {
    string name;
    int age;
    string* medications;
    int numMeds;
};

// Function prototypes
void inputPatients(Patient* patients, int size);
void displayPatients(const Patient* patients, int size);
void cleanup(Patient* patients, int size);

// inputPatients() prompts user to enter patient info including medications
// arguments: pointer to array of Patient structs, size of the array
// returns: nothing, fills patient array with input data
void inputPatients(Patient* patients, int size) {
    for (int i = 0; i < size; i++) {
        cout << "\n--- Enter info for Patient #" << (i + 1) << " ---\n";

        cin.ignore();
        cout << "Name: ";
        getline(cin, patients[i].name);

        cout << "Age: ";
        while (!(cin >> patients[i].age) || patients[i].age <= 0) {
            cout << "Invalid age. Please enter a positive number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "How many medications is " << patients[i].name << " taking? ";
        while (!(cin >> patients[i].numMeds) || patients[i].numMeds < 0) {
            cout << "Invalid number. Please enter 0 or a positive number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        if (patients[i].numMeds > 0) {
            patients[i].medications = new string[patients[i].numMeds];
            cin.ignore();
            for (int j = 0; j < patients[i].numMeds; j++) {
                cout << "Enter medication #" << (j + 1) << ": ";
                getline(cin, patients[i].medications[j]);
            }
        } else {
            patients[i].medications = nullptr;
        }
    }
}

// displayPatients() prints all patient info to console
// arguments: pointer to array of Patient structs, size of the array
// returns: nothing
void displayPatients(const Patient* patients, int size) {
    cout << "\n===== HOSPITAL PATIENT RECORDS =====\n";
    for (int i = 0; i < size; i++) {
        cout << "\nPatient #" << (i + 1) << "\n";
        cout << "Name: " << patients[i].name << "\n";
        cout << "Age: " << patients[i].age << "\n";
        cout << "Medications: ";
        if (patients[i].numMeds == 0) {
            cout << "None";
        } else {
            for (int j = 0; j < patients[i].numMeds; j++) {
                cout << patients[i].medications[j];
                if (j < patients[i].numMeds - 1) cout << ", ";
            }
        }
        cout << "\n";
    }
}

// cleanup() frees all dynamically allocated memory
// arguments: pointer to array of Patient structs, size of the array
// returns: nothing
void cleanup(Patient* patients, int size) {
    for (int i = 0; i < size; i++) {
        delete[] patients[i].medications;
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

    // create dynamic array of patients
    Patient* patients = new Patient[numPatients];

    // input phase
    inputPatients(patients, numPatients);

    // display phase
    displayPatients(patients, numPatients);

    // cleanup phase
    cleanup(patients, numPatients);
    delete[] patients;

    return 0;
}

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

// main() initializes dynamic array of Patient structs
int main() {
    int numPatients;

    // Prompt user for number of patients
    cout << "Enter the number of patients to record (max " << MAX_PATIENTS << "): ";
    while (!(cin >> numPatients) || numPatients <= 0 || numPatients > MAX_PATIENTS) {
        cout << "Invalid number. Please enter a number between 1 and " << MAX_PATIENTS << ": ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    // Create a dynamic array of Patient structs
    Patient* patients = new Patient[numPatients];

    cout << numPatients << " patient records allocated successfully.\n";

    // Free dynamically allocated memory
    delete[] patients;

    return 0;
}

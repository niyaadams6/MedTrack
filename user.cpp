#include <string>
#include <iostream>
#include <vector>
#include <sstream>

#include "user.h"

using namespace std;
#include "medication.h"

User :: User(){
    username = "default";
    age = 0;

}

User :: User(string _username , int _age){
    username = _username;
    age = _age;
}

void User:: displayProfile(){
    cout << "Name: " << username << " Age: "<< age << endl;
}
 void User:: displayUserInfo(){
    cout << endl << "Name: " << username  << endl << "Age: "<< age  << endl<< "Email: "<< email  << endl<< "Phone #: "<< phone_number << endl;
}

User::~User() {
    for (Medication* med : Meds) {
        delete med;
    }
    Meds.clear();
}

User& User:: operator=(const User& other) { // copy assighment opp
    if (this != &other) { // protect against self-assignment
        username = other.username;
        age = other.age;
        filename = other.filename;
        login = other.login;

        // Clear old meds
        for (auto m : Meds) {
            delete m;
        }
        Meds.clear();

        // Deep copy new meds
        for (auto m : other.Meds) {
            Meds.push_back(new Medication(*m));
        }
    }
    return *this;
}

User :: User(const User& other) {
    username = other.username;
    age = other.age;
    filename = other.filename;
    login = other.login;
    // Deep copy for Meds vector
    for (auto m : other.Meds) {
        Meds.push_back(new Medication(*m));
    }
}

void User::startSession(){
    login = true;
}

void User::addAllergy(string alle){
    allergies.push_back(alle);
}

void User:: addMeds(Medication& med){
    Meds.push_back(new Medication(med));
};




void User::displayMedications() const {
    for (int i = 0; i < Meds.size(); i++) {
        cout << i << ". " << Meds[i]->getName() << " - " << (Meds[i]->getStatus() ? "Taken" : "Not taken") << endl;
    }
}

void User::markDose(int index) {
    if (index >= 0 && index < Meds.size()) {
        Meds[index]->markAsTaken(); // mark as taken
        cout << Meds[index]->getName() << " has been marked as taken!\n";
    } else {
        cout << "Invalid medication selection.\n";
    }
}

void User:: resetAllMeds(){
    for (int i = 0; i < Meds.size(); i++) {
        Meds[i]->resetForNewDay();
    }
}

void User :: setFilename(string _file){
    filename = _file;
}

#include <fstream> // for file streams

void User::saveToFile() const {
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        //cout << "Failed to open file for saving.\n";
        return;
    }

    outFile << username << endl;
    outFile << age << endl;
    outFile << email << endl;
    outFile << phone_number << endl;

    outFile << "Allergies:" << endl;
    for (const string& allergy : allergies) {
        outFile << allergy << endl;
    }

    outFile << "Medications:" << endl;
    for (Medication* med : Meds) {
        outFile << med->getName() << "," 
                << med->getDosage() << ","  // <<<< ADD DOSAGE HERE
                << med->getFrequency() << ","
                << (med->getStatus() ? "Taken" : "Not taken") 
                << endl;
    }

    outFile.close();
    //cout << "Data saved successfully!\n";
}




void User::loadFromFile() {
    ifstream inFile(filename);

    if (!inFile.is_open()) {
        cout << "Failed to open file for loading.\n";
        return;
    }

    getline(inFile, username);

    inFile >> age;
    inFile.ignore(); // throw away leftover newline

    getline(inFile, email);

    inFile >> phone_number;
    inFile.ignore(); // again, throw away leftover newline

    string line;
    getline(inFile, line); // "Allergies:"
    allergies.clear();

    while (getline(inFile, line)) {
        if (line == "Medications:") break;
        allergies.push_back(line);
    }

    Meds.clear();
    while (getline(inFile, line)) {
        stringstream ss(line);
        string name, dosage, freqStr, takenStr;

        getline(ss, name, ',');
        getline(ss, dosage, ',');
        getline(ss, freqStr, ',');
        getline(ss, takenStr);

        int frequency = stoi(freqStr);
        bool taken = (takenStr == "Taken");

        Medication* med = new Medication(name, dosage, frequency);
        if (taken) {
            med->markAsTaken();
        }

        Meds.push_back(med);
    }

    inFile.close();
    cout << "Data loaded successfully!\n";
}

string User::getFilename() const {
    return filename;
}

void User::setemail(string _email){
    email = _email;
}
void User::setphone(int _phone){
    phone_number = _phone;
}
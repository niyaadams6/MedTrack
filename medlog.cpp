#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "medlog.h"

using namespace std;

Medlog::Medlog(){
    currentUser = nullptr;

}

void Medlog ::addUser(User& person){
    users.push_back(new User(person));
}

void Medlog::display_all_users(){
    for(unsigned int i = 0; i < users.size(); i++){

        cout << i << ". ";
        users.at(i)-> displayProfile();
    }
}

Medlog::~Medlog() {
    for (User* u : users) {
        delete u;   // Free each dynamically allocated User
    }
    users.clear();  // clears the vector
}


void Medlog::selectUser( int person) {
    if (person >= 0 && person < static_cast<int>(users.size())) {
        currentUser = users.at(person); 
    } else {
        cout << "Invalid selection.\n";
    }
}

User* Medlog::getCurrentUser() const {
    return currentUser;
}

void Medlog::deleteUser(int index) {
    if (index >= 0 && index < users.size()) {
        delete users[index];
        users.erase(users.begin() + index);
    } else {
        cout << "Invalid user index.\n";
    }
}

void Medlog::deleteAllUsers() {
    for (User* user : users) {
        delete user;
    }
    users.clear();
}


void Medlog::saveAllUsers() {
    ofstream outFile("users.txt");
    if (!outFile.is_open()) {
        //cout << "Could not open master users file for saving!\n";
        return;
    }

    for (User* user : users) {
        outFile << user->getFilename() << endl;
        user->saveToFile(); // Also save each user's personal file
    }

    outFile.close();
}

void Medlog::loadAllUsers() {
    ifstream inFile("users.txt");
    if (!inFile.is_open()) {
        //cout << "No existing users to load.\n";
        return;
    }

    string filename;
    while (getline(inFile, filename)) {
        User* newUser = new User("", 0); // create user with just filename
        newUser->setFilename(filename); // set filename
        newUser->loadFromFile(); // load real user info
        users.push_back(newUser); // add back to Medlog
    }

    inFile.close();
}

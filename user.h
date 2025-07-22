#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

//#include "medication.h"

class Medication;


class User{
    private:
        string username;
        int age; 
        string email; 
        int phone_number;
        
        vector<string>allergies;
        vector<Medication*> Meds;
        string filename;
        bool login;

    public:

        User();
        User(string _username , int _age);
        void displayProfile();
        void displayUserInfo();
        void displayMedications() const;
        void startSession();
        void addAllergy(string alle);
        void addMeds(Medication& med);
        ~User(); // destructor 
        User& operator=(const User& other);
        User(const User& other);
        void markDose(int index);
        void resetAllMeds();
        void setFilename(string _file);
        void saveToFile() const;
        void loadFromFile();
        string getFilename() const;
        void setemail(string _email);
        void setphone(int _phone);
    

    
};



#endif
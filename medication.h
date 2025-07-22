#ifndef MEDICATION_H
#define MEDICATION_H

#include <string>
#include <iostream>
#include <vector>

#include "user.h"

class Medication{
    private:
        string name;
        string dosage;
        int frequency_per_day;
        bool taken_today;
        vector<string>avoidDoing;
        vector<string> sideEffects;
    
    public:
        Medication();
        Medication(string _name,string  _dosage, int _frequency_per_day);
        void markAsTaken();
        void resetForNewDay();
        void display();
        void addSideEffects(string effects);
        void addAvoid(string action);
        bool getStatus();
        string getName();
        string getDosage();
        int getFrequency();

        void setName(string _name);
        void setDosage(string _dosage);
        void setFrequency(int _frequency_per_day);

        //needs copy constructor 


};

using namespace std;

#endif
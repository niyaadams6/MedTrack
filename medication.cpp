#include <string>
#include <iostream>
#include <vector>

#include "medication.h"

using namespace std;

Medication :: Medication(){
    name = "noName";
    dosage = "??";
    frequency_per_day = 0;
    taken_today = false;
}

Medication :: Medication(string _name ,string  _dosage, int _frequency_per_day){
    name = _name;
    dosage = _dosage;
    frequency_per_day = _frequency_per_day;
    taken_today = false;
}

//needs copy constructor 

void Medication :: markAsTaken(){
    taken_today = true;
}

void Medication :: resetForNewDay(){
    taken_today = false;
}

void Medication:: display(){
    cout << dosage << " of " << name << " needs be taken " << frequency_per_day << " a day." << endl;
}

void Medication:: addSideEffects(string effects){
    sideEffects.push_back(effects);
}

void Medication:: addAvoid(string action){
    avoidDoing.push_back(action);
}

bool Medication:: getStatus(){
    return taken_today;
}

string Medication:: getName(){
    return name;
}

string Medication:: getDosage(){
    return dosage;
}

int Medication:: getFrequency(){
    return frequency_per_day;
}

void Medication:: setName(string _name){
    name = _name;
}
void Medication :: setDosage(string _dosage){
    dosage = _dosage;
}
void Medication :: setFrequency(int _frequency_per_day){
    frequency_per_day = _frequency_per_day;
}
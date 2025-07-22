#ifndef MEDLOG_H
#define MEDLOG_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "user.h"


class Medlog{

    private:
        vector<User*> users;
        User* currentUser;
    
    public: 
        Medlog();
        void addUser(User& person);
        void display_all_users();
        void selectUser(  int person);
        ~Medlog();
        User* getCurrentUser() const;
        void deleteUser(int index);
        void deleteAllUsers();
        void saveAllUsers();
        void loadAllUsers();

        


};

#endif
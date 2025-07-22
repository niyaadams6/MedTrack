#include <iostream>
#include "medlog.h"
#include "user.h"
#include "medication.h"

using namespace std;

void catArt(int choice) {
    switch (choice) {
        case 1:
            cout << "  /\\_/\\   " << endl;
            cout << " ( o.o )  Meow! Loading your profile..." << endl;
            cout << "  > ^ <   " << endl;
            break;
        case 2:
            cout << "  /\\_/\\   " << endl;
            cout << " ( ^.^ )  New friend created!" << endl;
            cout << "  > ^ <   " << endl;
            break;
        case 3:
            cout << "  /\\_/\\   " << endl;
            cout << " ( -_- )  User removed..." << endl;
            cout << "  > ^ <   " << endl;
            break;
        case 4:
            cout << "  /\\_/\\   " << endl;
            cout << " ( x_x )  All users cleared!" << endl;
            cout << "  > ^ <   " << endl;
            break;
        case 5:
            cout << "  /\\_/\\   " << endl;
            cout << " ( ^_^ )  See you later!" << endl;
            cout << "  > ^ <   " << endl;
            break;
        default:
            cout << "  /\\_/\\   " << endl;
            cout << " ( o_o )  Unknown option... meow?" << endl;
            cout << "  > ^ <   " << endl;
            break;
    }
}
// Function to display the main menu
// and options to the user

void displayMenu() {
    cout << "  /\\_/\\    Welcome to MeowMedLog!" << endl;
    cout << " ( o.o )   Let's track your meds!" << endl;
    //cout << "  > ^ <    " << endl;
    //cout << endl;
    cout << "+-----------------------------+" << endl;
    cout << "|  1. Load user profile       |" << endl;
    cout << "|  2. Create user profile     |" << endl;
    cout << "|  3. Delete user             |" << endl;
    cout << "|  4. Delete all users        |" << endl;
    cout << "|  5. Exit                    |" << endl;
    cout << "+-----------------------------+" << endl;
    //cout << endl;
}



int main() {
    int choice;
    Medlog medSystem;
    Medlog newlog;
    string _name, _dosage, _filename, _username;
    int _frequency_per_day, _age;
    medSystem.loadAllUsers();
    string email;
    int phone_number;

    do {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        catArt(choice);

        switch (choice) {
            case 1: { // Load User Profile
                cout << "Select a user to load:\n";
                medSystem.display_all_users();
                int index;
                cin >> index;
                medSystem.selectUser(index);
                cout << "Loading user profile...\n";
                
                int choice2 = 0;
                do {
                    
                    cout << "\n User Menu \n";
                    cout << "1. Add medication\n";
                    cout << "2. View medication list\n";
                    cout << "3. Mark dose as taken\n";
                    cout << "4. Reset for new day\n";
                    cout << "5. Save\n";
                    cout << "6. Add/Renew Information\n";
                    cout << "7. View user Information\n";
                    cout << "8. Return to main menu\n";

                    cout << "Enter your choice: ";
                    cin >> choice2;

                    switch (choice2) {
                        case 1: { // Add medication
                            Medication newMed;
                            cout << "New medication's name: ";
                            cin >> _name;
                            cout << "New medication's dosage: ";
                            cin >> _dosage;
                            cout << "How many times is this medication taken a day? ";
                            cin >> _frequency_per_day;
                            newMed.setName(_name);
                            newMed.setDosage(_dosage);
                            newMed.setFrequency(_frequency_per_day);
                            medSystem.getCurrentUser()->addMeds(newMed);
                            break;
                        }
                        case 2: { // View medication list
                            medSystem.getCurrentUser()->displayMedications();
                            break;
                        }
                        case 3: { // Mark dose as taken
                            if (medSystem.getCurrentUser() != nullptr) {
                                medSystem.getCurrentUser()->displayMedications();
                                cout << "Select a medication to mark as taken: ";
                                int medChoice;
                                cin >> medChoice;
                                medSystem.getCurrentUser()->markDose(medChoice);
                            } else {
                                cout << "No user selected!\n";
                            }
                            break;
                        }
                        case 4: { // Reset meds for new day
                            medSystem.getCurrentUser()->resetAllMeds();
                            break;
                        }
                        case 5: { // Save to file
                            cout << "What's your user's filename? ";
                            cin >> _filename;
                            medSystem.getCurrentUser()->setFilename(_filename);
                            if (medSystem.getCurrentUser() != nullptr) {
                                medSystem.getCurrentUser()->saveToFile();
                            } else {
                                cout << "No user selected.\n";
                            }
                            break;
                        }
                        case 6: { // Add info to user
                            cout << "Enter your email: ";
                            cin >> email;
                            medSystem.getCurrentUser()->setemail(email);
                            cout << "Enter your phone number: ";
                            cin >> phone_number;
                            medSystem.getCurrentUser()->setphone(phone_number);
                            cout << "Enter your allergies (type 'done' when finished): ";
                            string allergy;
                            while (true) {
                                cin >> allergy;
                                if (allergy == "done") break;
                                medSystem.getCurrentUser()->addAllergy(allergy);
                            }
                            break;
                            
                        }
                        case 7: { // View user profile
                            medSystem.getCurrentUser()->displayUserInfo();
                            break;
                        }
                        case 8: { // Return to main menu
                            cout << "Returning to main menu...\n";
                            break;
                        }
                        default:
                            cout << "Invalid option. Try again!\n";
                    }

                } while (choice2 != 8);
                break;
            }
            case 2: { // Create User Profile
                cout << "Enter new username: ";
                cin >> _username;
                cout << "Enter age: ";
                cin >> _age;

                User* newUser = new User(_username, _age);
                medSystem.addUser(*newUser);
                cout << "User profile created!\n";
                break;
            }
            case 3: { // Delete a user
                cout << "Select the user to delete:\n";
                medSystem.display_all_users();
                int deleteIndex;
                cin >> deleteIndex;
                medSystem.deleteUser(deleteIndex);
                cout << "User deleted!\n";
                break;
            }
            case 4: { // Delete all users
                medSystem.deleteAllUsers();
                cout << "All users deleted!\n";
                break;
            }
            case 5: { // Exit
                cout << "Exiting... Meow!\n";
                break;
            }
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5.\n";
        }

        cout << "\n";

    } while (choice != 5);
    medSystem.saveAllUsers();
    return 0;
}

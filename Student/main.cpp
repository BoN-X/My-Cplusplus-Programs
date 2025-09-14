#include <iostream>
#include "student_manager.h"

void printMenu() {
    std::cout << "=== Student Management System ===\n"
              << "1. Add student\n"
              << "2. Display all\n"
              << "3. Find student by ID\n"
              << "4. Remove student\n"
              << "5. Sort by total score\n"
              << "6. Save to file\n"
              << "7. Load from file\n"
              << "8. Connect to database\n"
              << "9. Load from database\n"
              << "10. Save to database\n"
              << "0. Exit\n"
              << "Select an option: ";
}

int main() {
    StudentManager manager;
    int choice;
    std::string id, name;
    do {
        printMenu();
        std::cin >> choice;
        switch(choice) {
            case 1: {
                std::cout << "Enter ID: "; std::cin >> id;
                std::cout << "Enter name: "; std::cin >> name;
                Student s(id, name);
                double score;
                std::cout << "Enter scores (end with -1): ";
                while (std::cin >> score && score != -1) s.addScore(score);
                manager.addStudent(s);
                break;
            }
            case 2: manager.displayAll(); break;
            case 3: {
                std::cout << "Enter ID: "; std::cin >> id;
                if (auto* s = manager.findStudentById(id)) {
                    std::cout << "Found: " << s->getId() << " " << s->getName() << "\n";                    
                } else {
                    std::cout << "Not Found.\n";
                }
                break;
            }
            case 4: {
                std::cout << "Enter ID: "; std::cin >> id;
                std::cout << (manager.removeStudentById(id) ? "Removed.\n" : "Not found.\n");
                break;
            }
            case 5:
                manager.sortByTotalScoreDescending();
                manager.displayAll();
                break;
            case 6:
                manager.saveToFile("data.txt");
                std::cout << "Save to file.\n";
                break;
            case 7:
                manager.loadFromFile("data.txt");
                std::cout << "Loaded from file.\n";
                break;
            case 8: {
                std::string uri;
                std::cout << "Enter DB URI: "; std::cin >> uri;
                manager.connectDatabase(uri);
                break;
            }
            case 9:
                manager.loadFromDatabase();
                std::cout << "Loaded from DB.\n";
                break;
            case 10:
                manager.saveToDatabase();
                std::cout << "Saved to DB.\n";
                break;
            case 0:
                std::cout << "Exiting....\n";
            default:
                std::cout << "Invalid option.\n";
        }
    } while (choice != 0);
    return 0;
}
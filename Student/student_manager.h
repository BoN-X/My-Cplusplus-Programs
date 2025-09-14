#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H

#include "student.h"
#include <vector>
#include <string>

class StudentManager {
private:
    std::vector<Student> students;
public:
    //In-memory operations    
    void addStudent(const Student& student);
    bool removeStudentById(const std::string& id);
    Student* findStudentById(const std::string& id);
    void displayAll() const;
    void sortByTotalScoreDescending();

    //File persistence(stubs)
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;

    //Database operations(stubs)
    void connectDatabase(const std::string& uri);
    void loadFromDatabase();
    void saveToDatabase();
};

#endif
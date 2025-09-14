#include "student_manager.h"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>

void StudentManager::addStudent(const Student& student) {
    students.push_back(student);
}

bool StudentManager::removeStudentById(const std::string& id) {
    auto it = std::remove_if(students.begin(), students.end(),
        [&](const Student& s){ return s.getId() == id;});
    if (it != students.end()) {
        students.erase(it, students.end());
        return true;
    }
    return false;
}

Student* StudentManager::findStudentById(const std::string& id) {
    for (auto& s : students) {
        if (s.getId() == id) return &s;
    }
    return nullptr;
}

void StudentManager::displayAll() const {
    std::cout << "ID\tName\tScores\tAverage\n";
    for (const auto& s : students) {
        std::cout << s.getId() << "\t"
                  << s.getName() << "\t";
        for (double sc : s.getScores()) std::cout << sc << " ";
        std::cout << "\t" << s.getAverageScore() << "\n";
    }
}

void StudentManager::sortByTotalScoreDescending() {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b){
        double sumA = std::accumulate(a.getScores().begin(), a.getScores().end(), 0.0);
        double sumB = std::accumulate(b.getScores().begin(), b.getScores().end(), 0.0);
        return sumA > sumB;
    });
}

void StudentManager::loadFromFile(const std::string& filename) {
    // TODO: implement file reading
}

void StudentManager::saveToFile(const std::string& filename) const {
    // TODO: implement file writing
}

void StudentManager::connectDatabase(const std::string& uri) {
    // TODO: initialize MySQL connection using Connector/C++
}

void StudentManager::loadFromDatabase() {
    // TODO: fetch data from MySQL and populate students
}

void StudentManager::saveToDatabase() {
    // TODO: write current students data to MySQL
}

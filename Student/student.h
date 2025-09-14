#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
private:
    std::string id;
    std::string name;
    std::vector<double> scores;
public:
    Student(const std::string& id, const std::string& name);

    //Getter and Setter
    const std::string& getId() const;
    const std::string& getName() const;
    void setName(const std::string& name);

    //Score operations
    void addScore(double score);
    const std::vector<double>& getScores() const;
    double getAverageScore() const;
};

#endif
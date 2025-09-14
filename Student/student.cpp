#include "student.h"
#include <numeric>

Student::Student(const std::string& id, const std::string& name)
    : id(id), name(name) {}

const std::string& Student::getId() const {return id;}
const std::string& Student::getName() const {return name;};
void Student::setName(const std::string& name) {this->name = name;}

void Student::addScore(double score) {scores.push_back(score);}
const std::vector<double>& Student::getScores() const {return scores;}

double Student::getAverageScore() const {
    if (scores.empty()) return 0.0;
    double sum = std::accumulate(scores.begin(), scores.end(), 0.0);
    return sum / scores.size();
}
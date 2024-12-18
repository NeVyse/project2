#include "Student.h"
#include <iostream>
#include <numeric>
// Конструктор без параметров
Student::Student() {
    std::cout << "Вызван конструктор по умолчанию для Student" << std::endl;
}
// Конструктор с параметрами
Student::Student(const std::string& surname, const std::string& initials, int groupNumber, const std::vector<int>& grades)
    : surname(surname), initials(initials), groupNumber(groupNumber), grades(grades) {
    std::cout << "Вызван конструктор с параметрами для Student" << std::endl;
}
// Конструктор копирования
Student::Student(const Student& other)
    : surname(other.surname), initials(other.initials), groupNumber(other.groupNumber), grades(other.grades) {
    std::cout << "Вызван конструктор копирования для Student" << std::endl;
}
// Деструктор
Student::~Student() {
    std::cout << "Вызван деструктор для Student" << std::endl;
}
// Методы доступа
std::string Student::getSurname() const { return surname; }
void Student::setSurname(const std::string& surname) { this->surname = surname; }
std::string Student::getInitials() const { return initials; }
void Student::setInitials(const std::string& initials) { this->initials = initials; }
int Student::getGroupNumber() const { return groupNumber; }
void Student::setGroupNumber(int groupNumber) { this->groupNumber = groupNumber; }
std::vector<int> Student::getGrades() const { return grades; }
void Student::setGrades(const std::vector<int>& grades) { this->grades = grades; }
// Вычисление среднего балла
double Student::averageGrade() const {
    if (grades.empty()) return 0.0;
    return static_cast<double>(std::accumulate(grades.begin(), grades.end(), 0)) / grades.size();
}
// Перегрузка операторов ввода/вывода
std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "Фамилия: " << student.surname << ", Инициалы: " << student.initials
       << ", Номер группы: " << student.groupNumber << ", Оценки: ";
    for (int grade : student.grades) {
        os << grade << " ";
    }
    return os;
}
std::istream& operator>>(std::istream& is, Student& student) {
    std::cout << "Введите фамилию: ";
    is >> student.surname;
    std::cout << "Введите инициалы: ";
    is >> student.initials;
    std::cout << "Введите номер группы: ";
    is >> student.groupNumber;
    int numGrades;
    std::cout << "Введите количество оценок: ";
    is >> numGrades;
    student.grades.resize(numGrades);
    for (int i = 0; i < numGrades; ++i) {
        std::cout << "Введите оценку " << (i + 1) << ": ";
        is >> student.grades[i];
    }
    return is;
}

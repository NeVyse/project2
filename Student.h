#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <vector>
class Student {
private:
    std::string surname;
    std::string initials;
    int groupNumber;
    std::vector<int> grades;
public:
    // Конструкторы
    Student();
    Student(const std::string& surname, const std::string& initials, int groupNumber, const std::vector<int>& grades);
    Student(const Student& other);
    // Деструктор
    ~Student();
    // Методы доступа
    std::string getSurname() const;
    void setSurname(const std::string& surname);
    std::string getInitials() const;
    void setInitials(const std::string& initials);
    int getGroupNumber() const;
    void setGroupNumber(int groupNumber);
    std::vector<int> getGrades() const;
    void setGrades(const std::vector<int>& grades);
    // Средний балл
    double averageGrade() const;
    // Перегрузка операторов
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
    friend std::istream& operator>>(std::istream& is, Student& student);
};
#endif

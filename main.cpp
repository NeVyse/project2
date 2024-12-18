#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"
void addStudent(std::vector<Student>& students) {
    Student student;
    std::cin >> student;
    students.push_back(student);
}
void removeStudent(std::vector<Student>& students, int index) {
    if (index < 0 || index >= students.size()) {
        throw std::out_of_range("Некорректный индекс для удаления студента.");
    }
    students.erase(students.begin() + index);
}
void editStudent(std::vector<Student>& students, int index) {
    if (index < 0 || index >= students.size()) {
        throw std::out_of_range("Некорректный индекс для редактирования студента.");
    }
    std::cout << "Редактирование студента с индексом " << index << ":" << std::endl;
    std::cin >> students[index];
}
void displayStudentsWithHighGrades(const std::vector<Student>& students) {
    bool found = false;
    for (const auto& student : students) {
        if (std::all_of(student.getGrades().begin(), student.getGrades().end(), [](int grade) { return grade >= 4; })) {
            std::cout << "Фамилия: " << student.getSurname() << ", Номер группы: " << student.getGroupNumber() << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Нет студентов с оценками 4 и 5." << std::endl;
    }
}
void sortStudentsByAverageGrade(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.averageGrade() < b.averageGrade();
    });
}
int main() {
    std::vector<Student> students;
    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Удалить студента\n";
        std::cout << "3. Редактировать студента\n";
        std::cout << "4. Показать студентов с оценками 4 и 5\n";
        std::cout << "5. Показать всех студентов\n";
        std::cout << "6. Сортировать студентов по среднему баллу\n";
        std::cout << "0. Выйти\n";
        std::cout << "Введите пункт меню: ";
        std::cin >> choice;
        try {
            switch (choice) {
                case 1: {
                    addStudent(students);
                    break;
                }
                case 2: {
                    int index;
                    std::cout << "Введите индекс студента для удаления: ";
                    std::cin >> index;
                    removeStudent(students, index);
                    break;
                }
                case 3: {
                    int index;
                    std::cout << "Введите индекс студента для редактирования: ";
                    std::cin >> index;
                    editStudent(students, index);
                    break;
                }
                case 4: {
                    displayStudentsWithHighGrades(students);
                    break;
                }
                case 5: {
                    for (const auto& student : students) {
                        std::cout << student << std::endl;
                    }
                    break;
                }
                case 6: {
                    sortStudentsByAverageGrade(students);
                    break;
                }
                case 0:
                    break;
                default:
                    std::cout << "Некорректный выбор, попробуйте снова." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
    } while (choice != 0);
    return 0;
}

#include "student.h"

Student::Student() : name(""), number(0), marks(nullptr), size(0) {
    cout << "The constructor without parameters for the Student class is called\n";
}

Student::Student(const string& n, const int& num, const float* m, const int& siz)
    : name(n), number(num), size(siz) {
    marks = new float[size];
    std::copy(m, m + size, marks);
    cout << "The constructor with parameters for the Student class is called\n";
}


Student::Student(const Student& other) : name(other.name), number(other.number), size(other.size) {
    marks = new float[size];
    std::copy(other.marks, other.marks + size, marks);
    cout << "The copy constructor for the Student class is called\n";
}


Student::~Student() {
    delete[] marks;
    cout << "The destructor for the Student class is called\n";
}

string Student::get_name() const{
    return this->name;
}

void Student::set_name(const string& n) {
    this->name = n;
}

int Student::get_number() const{
    return this->number;
}

void Student::set_number(const int& n) {
    this->number = n;
}

const float* Student::get_marks() const { 
    return marks; 
}

void Student::set_marks(const float* m, int siz) {
    delete[] marks;
    size = siz;
    marks = new float[size];
    memcpy(marks, m, size * sizeof(float));
}

int Student::get_size() const { 
    return size; 
}

void Student::set_size(const int& siz) { 
    size = siz; 
}

void Student::display_student() {
    cout << "Name: " << name << "\nNumber of the group: " << number;
    cout << "\nMarks: ";
    for (int i = 0; i < size; i++) cout << marks[i] << ' ';
    cout << endl;
}

void Student::edit_student() {
    int choice;
    cout << "Choose what you want to edit:\n";
    cout << "1. Student name\n";
    cout << "2. Student number of the group\n";
    cout << "3. List of  grades\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            string new_name;
            cout << "Enter the new student name: ";
            cin.ignore();
            getline(cin, new_name);
            set_name(new_name);
            break;
        }
        case 2: {
            int new_number;
            cout << "Enter the new student number of the group: ";
            cin >> new_number;
            set_number(new_number);
            break;
        }
        case 3: {
            int new_size;
            cout << "Enter the number of marks: ";
            cin >> new_size;
            float* new_marks = new float[new_size];
            cout << "Enter the grades: ";
            for (int i = 0; i < new_size; i++) {
                cin >> new_marks[i];
            }

            set_marks(new_marks, new_size);
            delete[] new_marks;
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
    }
}


float Student::get_average_mark() const {
    if (size == 0) return 0.0f;

    float sum = 0.0f;
    for (int i = 0; i < size; i++) {
        sum += marks[i];
    }
    return sum / size;
}
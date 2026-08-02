#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

double calculateAverage(const vector<double>& scores) {
    if (scores.empty()) {
        return 0.0;
    }

    double total = 0.0;

    for (double score : scores) {
        total += score;
    }

    return total / scores.size();
}

bool idExists(const vector<Student>& students, int id) {
    for (const Student& student : students) {
        if (student.id == id) {
            return true;
        }
    }

    return false;
}

void addStudent(vector<Student>& students) {
    Student student;
    int scoreCount;

    cout << "Student name: ";
    getline(cin, student.name);

    cout << "Student ID: ";
    cin >> student.id;

    if (idExists(students, student.id)) {
        cout << "Error: A student with this ID already exists." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "How many scores? ";
    cin >> scoreCount;

    if (scoreCount < 0) {
        cout << "Error: Number of scores cannot be negative." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < scoreCount; i++) {
        double score;
        cout << "Enter score " << i + 1 << ": ";
        cin >> score;
        student.scores.push_back(score);
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    students.push_back(student);
    cout << "Student \"" << student.name << "\" added successfully." << endl;
}

void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available." << endl;
        return;
    }

    cout << left << setw(25) << "Name"
         << setw(15) << "ID"
         << setw(35) << "Scores"
         << setw(10) << "Average" << endl;
    cout << string(85, '-') << endl;

    for (const Student& student : students) {
        string scoreText;

        for (size_t i = 0; i < student.scores.size(); i++) {
            scoreText += to_string(student.scores[i]);
            if (i < student.scores.size() - 1) {
                scoreText += ", ";
            }
        }

        if (scoreText.empty()) {
            scoreText = "None";
        }

        cout << left << setw(25) << student.name
             << setw(15) << student.id
             << setw(35) << scoreText
             << fixed << setprecision(2) << calculateAverage(student.scores) << endl;
    }
}

void displayStudentAverage(const vector<Student>& students) {
    int id;

    cout << "Enter student ID: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (const Student& student : students) {
        if (student.id == id) {
            cout << fixed << setprecision(2)
                 << student.name << "'s average score: "
                 << calculateAverage(student.scores) << endl;
            return;
        }
    }

    cout << "Error: Student ID not found." << endl;
}

void displayMenu() {
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Please enter a number from 1 to 4." << endl;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayStudents(students);
        } else if (choice == 3) {
            displayStudentAverage(students);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Error: Please enter a number from 1 to 4." << endl;
        }
    }

    return 0;
}

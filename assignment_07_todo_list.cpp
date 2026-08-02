#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

void displayMenu() {
    cout << "\n============================" << endl;
    cout << "     TO-DO LIST MENU" << endl;
    cout << "============================" << endl;
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Delete task" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

void addTask(vector<string>& tasks) {
    string task;

    cout << "Enter task: ";
    getline(cin, task);

    if (task.empty()) {
        cout << "Error: Task cannot be empty." << endl;
        return;
    }

    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"" << endl;
}

void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty." << endl;
        return;
    }

    cout << "Your Tasks:" << endl;

    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty." << endl;
        return;
    }

    viewTasks(tasks);

    int taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Invalid task number." << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        cout << "Error: Invalid task number." << endl;
        return;
    }

    string removedTask = tasks[taskNumber - 1];
    tasks.erase(tasks.begin() + taskNumber - 1);
    cout << "Task \"" << removedTask << "\" has been removed." << endl;
}

int main() {
    vector<string> tasks;
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
            addTask(tasks);
        } else if (choice == 2) {
            viewTasks(tasks);
        } else if (choice == 3) {
            deleteTask(tasks);
        } else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Error: Please enter a number from 1 to 4." << endl;
        }
    }

    return 0;
}

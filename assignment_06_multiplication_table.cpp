#include <iostream>
using namespace std;

void printSingleTable(int number) {
    cout << "Multiplication Table for " << number << ":" << endl;

    for (int i = 1; i <= 12; i++) {
        cout << number << " x " << i << " = " << number * i << endl;
    }
}

void printTablesUpTo(int number) {
    for (int i = 1; i <= number; i++) {
        printSingleTable(i);

        if (i < number) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int number;
    int limit;

    cout << "Enter a number for a single multiplication table: ";
    cin >> number;

    if (number <= 0) {
        cout << "Error: Number must be positive." << endl;
        return 0;
    }

    printSingleTable(number);

    cout << "\nEnter N to print tables from 1 to N: ";
    cin >> limit;

    if (limit <= 0) {
        cout << "Error: N must be positive." << endl;
        return 0;
    }

    printTablesUpTo(limit);

    return 0;
}

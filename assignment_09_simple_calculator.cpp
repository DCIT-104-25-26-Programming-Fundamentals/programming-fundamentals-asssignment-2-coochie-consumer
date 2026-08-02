#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

double add(double first, double second) {
    return first + second;
}

double subtract(double first, double second) {
    return first - second;
}

double multiply(double first, double second) {
    return first * second;
}

double divide(double first, double second) {
    return first / second;
}

int calculateModulus(int first, int second) {
    return first % second;
}

double exponentiate(double base, double exponent) {
    return pow(base, exponent);
}

void displayMenu() {
    cout << "\n============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

int main() {
    int choice;

    cout << fixed << setprecision(2);

    while (true) {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Please select a number from 1 to 7." << endl;
            continue;
        }

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "Error: Please select a number from 1 to 7." << endl;
            continue;
        }

        if (choice == 5) {
            int first;
            int second;

            cout << "Enter first number : ";
            cin >> first;
            cout << "Enter second number: ";
            cin >> second;

            if (second == 0) {
                cout << "Error: Cannot perform modulus by zero." << endl;
            } else {
                cout << "Result: " << first << " % " << second << " = " << calculateModulus(first, second) << endl;
            }

            continue;
        }

        double first;
        double second;
        double result;
        char symbol;

        cout << "Enter first number : ";
        cin >> first;
        cout << "Enter second number: ";
        cin >> second;

        if (choice == 1) {
            result = add(first, second);
            symbol = '+';
        } else if (choice == 2) {
            result = subtract(first, second);
            symbol = '-';
        } else if (choice == 3) {
            result = multiply(first, second);
            symbol = '*';
        } else if (choice == 4) {
            if (second == 0) {
                cout << "Error: Cannot divide by zero." << endl;
                continue;
            }
            result = divide(first, second);
            symbol = '/';
        } else {
            result = exponentiate(first, second);
            symbol = '^';
        }

        cout << "Result: " << first << " " << symbol << " " << second << " = " << result << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

void printFibonacci(int terms) {
    long long first = 0;
    long long second = 1;

    cout << "Fibonacci sequence: ";

    for (int i = 0; i < terms; i++) {
        cout << first;
        if (i < terms - 1) {
            cout << " ";
        }

        long long next = first + second;
        first = second;
        second = next;
    }

    cout << endl;
}

bool isFibonacci(long long number) {
    if (number < 0) {
        return false;
    }

    long long first = 0;
    long long second = 1;

    while (first < number) {
        long long next = first + second;
        first = second;
        second = next;
    }

    return first == number;
}

int main() {
    int terms;
    long long number;

    cout << "How many terms? ";
    cin >> terms;

    if (terms <= 0) {
        cout << "Error: Number of terms must be positive." << endl;
    } else {
        printFibonacci(terms);
    }

    cout << "Enter a number to check: ";
    cin >> number;

    if (isFibonacci(number)) {
        cout << number << " is a Fibonacci number." << endl;
    } else {
        cout << number << " is NOT a Fibonacci number." << endl;
    }

    return 0;
}

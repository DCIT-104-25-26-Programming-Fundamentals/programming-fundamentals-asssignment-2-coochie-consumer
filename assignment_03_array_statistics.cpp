#include <iostream>
using namespace std;

double calculateSum(const double numbers[], int size) {
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }

    return sum;
}

double calculateAverage(const double numbers[], int size) {
    return calculateSum(numbers, size) / size;
}

double findMaximum(const double numbers[], int size) {
    double maximum = numbers[0];

    for (int i = 1; i < size; i++) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }

    return maximum;
}

double findMinimum(const double numbers[], int size) {
    double minimum = numbers[0];

    for (int i = 1; i < size; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }

    return minimum;
}

int main() {
    int size;

    cout << "How many numbers? ";
    cin >> size;

    if (size <= 0) {
        cout << "Error: The number of values must be positive." << endl;
        return 0;
    }

    double* numbers = new double[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    cout << "\nResults:" << endl;
    cout << "Sum:     " << calculateSum(numbers, size) << endl;
    cout << "Average: " << calculateAverage(numbers, size) << endl;
    cout << "Maximum: " << findMaximum(numbers, size) << endl;
    cout << "Minimum: " << findMinimum(numbers, size) << endl;

    delete[] numbers;
    return 0;
}

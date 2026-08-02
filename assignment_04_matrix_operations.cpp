#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int columns, const string& name) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Enter " << name << " element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(const int matrix[10][10], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(const int matrix[10][10], int transpose[10][10], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(const int first[10][10], const int second[10][10], int result[10][10], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            result[i][j] = first[i][j] + second[i][j];
        }
    }
}

void multiplyMatrices(const int first[10][10], const int second[10][10], int result[10][10], int rowsA, int columnsA, int columnsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < columnsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < columnsA; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

bool validSize(int rows, int columns) {
    return rows > 0 && rows <= 10 && columns > 0 && columns <= 10;
}

int main() {
    int matrix[10][10] = {};
    int transpose[10][10] = {};
    int rows;
    int columns;

    cout << "PART A - TRANSPOSE" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;

    if (!validSize(rows, columns)) {
        cout << "Error: Matrix dimensions must be between 1 and 10." << endl;
        return 0;
    }

    readMatrix(matrix, rows, columns, "matrix");
    transposeMatrix(matrix, transpose, rows, columns);

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix, rows, columns);
    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transpose, columns, rows);

    int first[10][10] = {};
    int second[10][10] = {};
    int sum[10][10] = {};

    cout << "\nPART B - ADDITION" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;

    if (!validSize(rows, columns)) {
        cout << "Error: Matrix dimensions must be between 1 and 10." << endl;
        return 0;
    }

    readMatrix(first, rows, columns, "first matrix");
    readMatrix(second, rows, columns, "second matrix");
    addMatrices(first, second, sum, rows, columns);

    cout << "\nSum Matrix:" << endl;
    displayMatrix(sum, rows, columns);

    int rowsA;
    int columnsA;
    int rowsB;
    int columnsB;
    int product[10][10] = {};

    cout << "\nPART C - MULTIPLICATION" << endl;
    cout << "Enter rows for matrix A: ";
    cin >> rowsA;
    cout << "Enter columns for matrix A: ";
    cin >> columnsA;
    cout << "Enter rows for matrix B: ";
    cin >> rowsB;
    cout << "Enter columns for matrix B: ";
    cin >> columnsB;

    if (!validSize(rowsA, columnsA) || !validSize(rowsB, columnsB)) {
        cout << "Error: Matrix dimensions must be between 1 and 10." << endl;
        return 0;
    }

    if (columnsA != rowsB) {
        cout << "Error: Columns in matrix A must equal rows in matrix B." << endl;
        return 0;
    }

    readMatrix(first, rowsA, columnsA, "matrix A");
    readMatrix(second, rowsB, columnsB, "matrix B");
    multiplyMatrices(first, second, product, rowsA, columnsA, columnsB);

    cout << "\nProduct Matrix:" << endl;
    displayMatrix(product, rowsA, columnsB);

    return 0;
}

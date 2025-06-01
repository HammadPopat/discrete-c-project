
#include <iostream>
using namespace std;

bool isReflexive(int matrix[10][10], int n) {
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] != 1)
            return false;
    }
    return true;
}

bool isIrreflexive(int matrix[10][10], int n) {
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] == 1)
            return false;
    }
    return true;
}

bool isSymmetric(int matrix[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i])
                return false;
        }
    }
    return true;
}

bool isAntisymmetric(int matrix[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1)
                return false;
        }
    }
    return true;
}

bool isTransitive(int matrix[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                for (int k = 0; k < n; k++) {
                    if (matrix[j][k] == 1 && matrix[i][k] == 0)
                        return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int n;
    int matrix[10][10];

    cout << "Enter the number of elements in the set: ";
    cin >> n;

    cout << "Enter the relation matrix (use 1 for true, 0 for false):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nProperties of the relation:\n";
    cout << "Reflexive: " << (isReflexive(matrix, n) ? "Yes" : "No") << endl;

    cout << "Irreflexive: " << (isIrreflexive(matrix, n) ? "Yes" : "No") << endl;

    cout << "Symmetric: " << (isSymmetric(matrix, n) ? "Yes" : "No") << endl;

    cout << "Antisymmetric: " << (isAntisymmetric(matrix, n) ? "Yes" : "No") << endl;

    cout << "Transitive: " << (isTransitive(matrix, n) ? "Yes" : "No") << endl;

    return 0;
}



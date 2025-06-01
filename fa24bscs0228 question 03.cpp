#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    char set[10];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> set[i];

    char first[100], second[100];
    int totalPairs = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            first[totalPairs] = set[i];
            second[totalPairs] = set[j];
            totalPairs++;
        }
    }

    cout << "\nA x A = { ";
    for (int i = 0; i < totalPairs; i++) {
        cout << "(" << first[i] << "," << second[i] << ") ";
    }
    cout << "}\n";


    int totalRelations = pow(2, totalPairs);
    cout << "\nTotal binary relations: " << totalRelations << "\n";

    cout << "\nBinary Relations:\n";
    for (int i = 0; i < totalRelations; i++) {
        cout << "{ ";
        for (int j = 0; j < totalPairs; j++) {
            if (i & (1 << j)) {
                cout << "(" << first[j] << "," << second[j] << ") ";
            }
        }
        cout << "}\n";
    }

    return 0;
}


#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main() {


    cout << "\nQ1: Multiset Operations\n";
    multiset<int> A = {1, 2, 2, 3};
    multiset<int> B = {2, 3, 4};

    cout << "Union: ";
    multiset<int> uni = A;
    for (int x : B) uni.insert(x);
    for (int x : uni) cout << x << " ";
    cout << endl;

    cout << "Intersection: ";
    multiset<int> inter, copyA = A;
    for (int x : B) {
        if (copyA.find(x) != copyA.end()) {
            inter.insert(x);
            copyA.erase(copyA.find(x));
        }
    }
    for (int x : inter) cout << x << " ";
    cout << endl;

    cout << "Difference (A - B): ";
    multiset<int> diff = A;
    for (int x : B) {
        if (diff.find(x) != diff.end())
            diff.erase(diff.find(x));
    }
    for (int x : diff) cout << x << " ";
    cout << endl;

    cout << "Addition A + B: ";
    for (int x : A) cout << x << " ";
    for (int x : B) cout << x << " ";
    cout << endl;

    cout << "\nQ2: Matrix Relation Properties\n";
    int R[3][3] = {{1, 1, 0}, {0, 1, 1}, {0, 0, 1}};

    bool reflex = true, irreflex = true, sym = true, antisym = true, trans = true;

    for (int i = 0; i < 3; i++) {
        if (R[i][i] != 1) reflex = false;
        if (R[i][i] == 1) irreflex = false;

        for (int j = 0; j < 3; j++) {
            if (R[i][j] != R[j][i]) sym = false;
            if (i != j && R[i][j] && R[j][i]) antisym = false;

            for (int k = 0; k < 3; k++)
                if (R[i][j] && R[j][k] && !R[i][k])
                    trans = false;
        }
    }

    cout << "Reflexive: " << (reflex ? "Yes" : "No") << endl;
    cout << "Irreflexive: " << (irreflex ? "Yes" : "No") << endl;
    cout << "Symmetric: " << (sym ? "Yes" : "No") << endl;
    cout << "Antisymmetric: " << (antisym ? "Yes" : "No") << endl;
    cout << "Transitive: " << (trans ? "Yes" : "No") << endl;

    cout << "\nQ3: Cartesian Product and Relations\n";
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<string> S(n);
    for (int i = 0; i < n; i++) cin >> S[i];

    vector<pair<string, string>> CP;
    for (auto a : S)
        for (auto b : S)
            CP.push_back({a, b});

    cout << "Cartesian Product:\n";
    for (auto p : CP) cout << "(" << p.first << "," << p.second << ") ";
    cout << endl;

    int relCount = pow(2, CP.size());
    cout << "Binary Relations Count: " << relCount << endl;

    cout << "All Relations:\n";
    for (int i = 0; i < relCount; i++) {
        cout << "{ ";
        for (int j = 0; j < CP.size(); j++) {
            if (i & (1 << j)) cout << "(" << CP[j].first << "," << CP[j].second << ") ";
        }
        cout << "}\n";
    }
  

    return 0;
}

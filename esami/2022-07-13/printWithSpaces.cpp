#include <iostream>
using namespace std;

void printSolution(char const *A, bool const *S, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i];
        if (S[i])
            cout << " ";
    }
    cout << endl;
}

void printWithSpacesRec(char const *A, bool *S, int n, int i) {
    if (i == n - 1) {
        printSolution(A, S, n);
    } else {
        S[i] = false;
        printWithSpacesRec(A, S, n, i + 1);
        S[i] = true;
        printWithSpacesRec(A, S, n, i + 1);
    }
}

void printWithSpaces(char const *A, int n) {
    bool *S = new bool[n - 1];
    for (int i = 0; i < n - 1; i++)
        S[i] = false;
    printWithSpacesRec(A, S, n, 0);
}

int main() {
    char A[4] = {'C', 'I', 'A', 'O'};
    int n = sizeof(A) / sizeof(A[0]);

    printWithSpaces(A, n);

    return 0;
}

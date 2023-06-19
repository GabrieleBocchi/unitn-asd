#include <iostream>
using namespace std;

void printSolution(int const *S, int n) {
    for (int i = 0; i < n; i++)
        cout << S[i];
    cout << endl;
}

void printOctalsRec(int n, int *S, int i, int prec) {
    if (i == n) {
        printSolution(S, n);
    } else {
        for (int j = 0; j <= 7; j++) {
            if (prec != j) {
                S[i] = j;
                printOctalsRec(n, S, i + 1, j);
            }
        }
    }
}

void printOctals(int n) {
    int *S = new int[n];
    printOctalsRec(n, S, 0, -1);
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <n>" << endl;
        return -1;
    }

    int n = atoi(argv[1]);

    printOctals(n);

    return 0;
}

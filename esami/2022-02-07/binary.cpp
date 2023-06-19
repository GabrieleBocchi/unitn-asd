#include <iostream>
using namespace std;

void printSolution(bool const *S, int n) {
    for (int i = 0; i < n; i++)
        cout << S[i];
    cout << endl;
}

void binaryRec(int n, int n0, int n1, int remain0, int remain1, bool *S,
               int i) {
    if (i == n) {
        printSolution(S, n);
    } else {
        if (remain0 > 0) {
            S[i] = false;
            binaryRec(n, n0, n1, remain0 - 1, n1, S, i + 1);
        }
        if (remain1 > 0) {
            S[i] = true;
            binaryRec(n, n0, n1, n0, remain1 - 1, S, i + 1);
        }
    }
}

void binary(int n, int n0, int n1) {
    bool *S = new bool[n];
    binaryRec(n, n0, n1, n0, n1, S, 0);
}

int main(int argc, char const *argv[]) {
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <n> <n0> <n1>" << endl;
        return -1;
    }

    int n = atoi(argv[1]);
    int n0 = atoi(argv[2]);
    int n1 = atoi(argv[3]);

    binary(n, n0, n1);

    return 0;
}

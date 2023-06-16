#include <iostream>
using namespace std;

void processSolution(int const *S, int n) {
    cout << "[";
    cout << S[0];
    for (int i = 1; i < n; i++)
        cout << ", " << S[i];
    cout << "]" << endl;
}

void printElegantRec(int n, int *S, int *T, int i) {
    if (i == n)
        processSolution(S, n);
    else {
        for (int j = 1; j <= n; j++) {
            if (T[j - 1] == 0 && (j % (i + 1) == 0 || (i + 1) % j == 0)) {
                S[i] = j;
                T[j - 1] = 1;
                printElegantRec(n, S, T, i + 1);
                T[j - 1] = 0;
            }
        }
    }
}

void printElegant(int n) {
    int *S = new int[n];
    int *T = new int[n];
    printElegantRec(n, S, T, 0);
}

int main(int argc, char const **argv) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <n>" << endl;
        return 1;
    }

    int n = atoi(argv[1]);

    printElegant(n);

    return 0;
}

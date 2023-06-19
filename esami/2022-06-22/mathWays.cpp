#include <iostream>
using namespace std;

void printSolution(int const *S, int i) {
    cout << S[0];
    for (int j = 1; j <= i; j++)
        cout << " -> " << S[j];
    cout << endl;
}

void mathWaysRec(int n, int k, int *S, int i) {
    if (k == n) {
        printSolution(S, i - 1);
    } else if (k > n) {
        return;
    } else {
        S[i] = k + 1;
        mathWaysRec(n, S[i], S, i + 1);
        S[i] = k * 2;
        mathWaysRec(n, S[i], S, i + 1);
        S[i] = k * k;
        mathWaysRec(n, S[i], S, i + 1);
    }
}

void mathWays(int n, int k) {
    int *S = new int[n - k + 1];
    S[0] = k;
    mathWaysRec(n, k, S, 1);
}

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <n> <k>" << endl;
        return -1;
    }

    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    mathWays(n, k);

    return 0;
}

#include <iostream>
using namespace std;

int discordville(int const *D, int const *N, int n) {
    int *DP = new int[n];
    DP[0] = D[0];

    for (int i = 1; i < n; i++) {
        int prec = 0;
        if (i - N[i] > 0)
            prec = DP[i - N[i] - 1];
        DP[i] = max(DP[i - 1], prec + D[i]);
    }

    return DP[n - 1];
}

int main() {
    int D[5] = {3, 4, 5, 7, 1};
    int N[5] = {0, 1, 1, 3, 1};
    int n = sizeof(D) / sizeof(D[0]);

    cout << discordville(D, N, n) << endl;

    return 0;
}

#include <iostream>
using namespace std;

int maxConnections(int const *X, int const *Y, int n) {
    int DP[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        DP[i][0] = 0;
        DP[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (X[i - 1] == Y[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
    return DP[n][n];
}

int main() {
    int X[6] = {1, 3, 6, 7, 5, 9};
    int Y[6] = {1, 8, 3, 7, 8, 9};
    int n = sizeof(X) / sizeof(X[0]);

    cout << maxConnections(X, Y, n) << endl;

    return 0;
}

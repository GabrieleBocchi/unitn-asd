#include <iostream>
using namespace std;

int mcs(int const *T, int const *U, int n, int m) {
    int DP[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        DP[i][0] = 0;
    for (int j = 0; j <= m; j++)
        DP[0][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (T[i - 1] == U[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + T[i - 1];
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
    return DP[n][m];
}

int main() {
    int T[4] = {1, -2, 2, 4};
    int U[3] = {1, 4, 2};
    int n = sizeof(T) / sizeof(T[0]);
    int m = sizeof(U) / sizeof(U[0]);

    cout << mcs(T, U, n, m) << endl;

    return 0;
}

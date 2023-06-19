#include <iostream>
using namespace std;

int lrs(char const *T, int n) {
    int **DP = new int *[n + 1];
    for (int i = 0; i <= n; i++) {
        DP[i] = new int[n + 1];
        DP[i][0] = 0;
        DP[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (T[i - 1] == T[j - 1] && i - 1 != j - 1)
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);

    return DP[n][n];
}

int main() {
    char T[6] = {'A', 'B', 'C', 'A', 'B', 'C'};
    int n = sizeof(T) / sizeof(T[0]);

    cout << lrs(T, n) << endl;

    return 0;
}

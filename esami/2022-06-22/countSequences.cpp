#include <iostream>
using namespace std;

int countSequences(int n, int m) {
    int **DP = new int *[m];
    for (int i = 0; i < m; i++) {
        DP[i] = new int[n];
        DP[i][0] = i + 1;
    }

    for (int j = 1; j < n; j++) {
        for (int i = j; i < m; i++) {
            DP[i][j] = DP[i - 1][j] + DP[((i + 1) / 2) - 1][j - 1];
        }
    }

    return DP[m - 1][n - 1];
}

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <n> <m>" << endl;
        return -1;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    cout << countSequences(n, m) << endl;

    return 0;
}

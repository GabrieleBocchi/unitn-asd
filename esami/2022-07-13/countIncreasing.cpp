#include <iostream>
using namespace std;

int countIncreasing(int const *A, int n, int k) {
    int **DP = new int *[n];
    for (int i = 0; i < n; i++) {
        DP[i] = new int[k];
        DP[i][0] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < k; j++) {
            DP[i][j] = 0;
            for (int m = 0; m <= i - 1; m++)
                if (A[m] < A[i])
                    DP[i][j] += DP[m][j - 1];
        }
    }

    int res = 0;
    for (int i = k - 1; i < n; i++)
        res += DP[i][k - 1];

    return res;
}

int main() {
    int A[5] = {-3, 7, 5, 6, 9};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 3;

    cout << countIncreasing(A, n, k) << endl;

    return 0;
}

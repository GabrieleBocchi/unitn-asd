#include <iostream>
using namespace std;

int countWellBalancedRec(int *DP, int n) {
    if (n <= 1)
        return 1;

    if (DP[n - 1] < 0) {
        if (n % 2 == 1) {
            int res = countWellBalancedRec(DP, (n - 1) / 2);
            DP[n - 1] = res * res;
        } else
            DP[n - 1] = 2 * countWellBalancedRec(DP, (n - 1) / 2) *
                        countWellBalancedRec(DP, ((n - 1) / 2) + 1);
    }

    return DP[n - 1];
}

int countWellBalanced(int n) {
    int *DP = new int[n];
    for (int i = 0; i < n; i++)
        DP[i] = -1;

    return countWellBalancedRec(DP, n);
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <n>" << endl;
        return -1;
    }

    int n = atoi(argv[1]);

    cout << countWellBalanced(n) << endl;

    return 0;
}

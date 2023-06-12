#include <iostream>
using namespace std;

int count(int n, int s) {
    int *DP = new int[n + 1];
    for (int i = 0; i < n; i++) {
        DP[i] = 0;
    }
    DP[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s && i >= j; j++) {
            DP[i] += DP[i - j];
        }
    }
    return DP[n];
}

int main(int argc, char const **argv) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <n> <s>" << endl;
        return 1;
    }

    int n = atoi(argv[1]), s = atoi(argv[2]);

    cout << count(n, s) << endl;

    return 0;
}

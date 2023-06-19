#include <cmath>
#include <iostream>
using namespace std;

int mathWays(int n, int k) {
    int *DP = new int[n - 2];
    DP[0] = 1;

    for (int i = 1; i < n - 2; i++) {
        DP[i] = DP[i - 1];

        if ((i + 3) % 2 == 0 && (i - ((i + 3) / 2)) >= 0)
            DP[i] += DP[i - ((i + 3) / 2)];

        float rad = sqrt(i + 3);
        if (rad == (int)rad)
            DP[i] += DP[(int)rad - 3];
    }

    return DP[n - 3];
}

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <n> <k>" << endl;
        return -1;
    }

    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    cout << mathWays(n, k) << endl;

    return 0;
}

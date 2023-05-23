#include <fstream>
#include <iostream>
using namespace std;

int main() {
    int N, res = 0;
    ifstream in("input.txt");
    in >> N;
    int *arr = new int[N];
    int *DP = new int[N];

    for (int i = 0; i < N; i++) {
        in >> arr[i];
        DP[i] = -1;
    }

    for (int i = N - 1; i >= 0; i--) {
        DP[i] = arr[i];

        for (int j = i + 1; j < N; j++)
            if (arr[i] <= arr[j] && arr[i] + DP[j] > DP[i])
                DP[i] = DP[j] + arr[i];
    }

    for (int i = 0; i < N; i++)
        if (DP[i] > res)
            res = DP[i];

    ofstream out("output.txt");
    out << res;

    in.close();
    out.close();

    return 0;
}

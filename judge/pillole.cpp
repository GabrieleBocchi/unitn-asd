#include <fstream>
#include <iostream>

using namespace std;

int main() {
    int N;
    ifstream in("input.txt");
    in >> N;

    long long int *DP1 = new long long int[N];
    long long int *DP2 = new long long int[N];

    DP2[0] = 0;
    for (int i = 1; i < N; i++)
        DP2[i] = 1;

    for (int i = 1; i < N; i++) {
        for (int j = i - 1; j < N; j++) {
            if (i - j == 1) {
                if (j == 0) {
                    DP1[j] = 1;
                } else {
                    DP1[j] = DP2[j];
                }
            } else {
                DP1[j] = DP2[j] + DP1[j - 1];
            }
        }
        swap(DP1, DP2);
    }

    ofstream out("output.txt");
    if (N == 1)
        out << 1;
    else
        out << DP2[N - 1];

    free(DP1);
    free(DP2);

    in.close();
    out.close();

    return 0;
}

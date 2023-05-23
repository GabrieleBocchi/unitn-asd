#include <fstream>
#include <iostream>
using namespace std;

int main() {
    int C, N;
    ifstream in("input.txt");
    in >> C >> N;
    int *P = new int[N];
    int *V = new int[N];

    int *DP1 = new int[C];
    int *DP2 = new int[C];

    for (int i = 0; i < N; i++) {
        in >> P[i];
        in >> V[i];
    }

    for (int j = 0; j < C; j++)
        if (P[0] <= j + 1)
            DP2[j] = V[0];
        else
            DP2[j] = 0;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < C; j++) {
            if (P[i] < j + 1)
                DP1[j] = max(DP2[j], DP2[j - P[i]] + V[i]);
            else if (P[i] == j + 1)
                DP1[j] = max(DP2[j], V[i]);
            else
                DP1[j] = DP2[j];
        }
        for (int j = 0; j < C; j++)
            DP2[j] = DP1[j];
    }

    ofstream out("output.txt");
    out << DP1[C - 1];

    in.close();
    out.close();

    return 0;
}

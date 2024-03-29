#include <iostream>
using namespace std;

void processSolution(int *S, int n) {
    cout << "{ ";
    for (int i = 0; i < n; i++)
        if (S[i])
            cout << i + 1 << " ";
    cout << "}" << endl;
}

void minCardinalityRec(int n, int *S, int i, int min) {
    if (min == 0)
        processSolution(S, n);
    else if (i == n)
        return;
    else {
        S[i] = 1;
        if (min == -1)
            minCardinalityRec(n, S, i + 1, i);
        else
            minCardinalityRec(n, S, i + 1, min - 1);
        S[i] = 0;
        minCardinalityRec(n, S, i + 1, min);
    }
}

void minCardinality(int n) {
    int *S = new int[n];
    minCardinalityRec(n, S, 0, -1);
}

int main(int argc, char const **argv) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <n>" << endl;
        return 1;
    }

    int n = atoi(argv[1]);

    minCardinality(n);

    return 0;
}

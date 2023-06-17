#include <climits>
#include <iostream>
using namespace std;

int minproduct(int const *A, int n) {
    int res = 1, min = INT_MAX, maxNeg = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (A[i] < min) {
            min = A[i];
        }
        if (A[i] < 0 && A[i] > maxNeg) {
            maxNeg = A[i];
        }
        if (A[i] != 0) {
            res *= A[i];
        }
    }

    if (res > 0) {
        if (maxNeg == INT_MIN) {
            return min;
        } else {
            return res / maxNeg;
        }
    } else {
        return res;
    }
}

int main() {
    int A[6] = {-1, -1, 2, -2, 4, 3};
    int n = sizeof(A) / sizeof(A[0]);

    cout << minproduct(A, n) << endl;

    return 0;
}

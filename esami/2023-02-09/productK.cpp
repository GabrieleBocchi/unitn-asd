#include <iostream>
using namespace std;

int productKRec(int const *A, int n, int m, int i, int prod, bool valid) {
    int res = 0;
    if (valid && prod <= m)
        res++;
    if (prod > m || i >= n)
        return res;

    res += productKRec(A, n, m, i + 1, prod * A[i], true);
    res += productKRec(A, n, m, i + 1, prod, false);

    return res;
}

int productK(int *A, int n, int m) { return productKRec(A, n, m, 0, 1, true); }

int main() {
    int A[4] = {1, 3, 2, 4};
    int n = sizeof(A) / sizeof(A[0]);
    int m = 10;

    cout << productK(A, n, m) << endl;

    return 0;
}

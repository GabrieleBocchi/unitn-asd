#include <fstream>
#include <iostream>
using namespace std;

int findIndexOf(int *arr, int start, int element) {
    for (int i = start;; i++)
        if (arr[i] == element)
            return i;
}

int main() {
    int N, index, mosse = 0, prezzo = 0;
    ifstream in("input.txt");
    in >> N;
    int *arr1 = new int[N];
    int *arr2 = new int[N];

    for (int i = 0; i < N; i++) {
        in >> arr1[i];
        arr2[i] = arr1[i];
    }

    index = 0;
    while (index < N) {
        if (arr1[index] != index + 1) {
            swap(arr1[index], arr1[arr1[index] - 1]);
            mosse++;
        }
        if (arr1[index] == index + 1)
            index++;
    }

    index = 0;
    int swapIndex1, swapIndex2, tmpMosse;
    while (index < N) {
        tmpMosse = 0;
        swapIndex1 = -1;
        while (arr2[index] != index + 1) {
            if (swapIndex1 == -1)
                swapIndex1 = findIndexOf(arr2, index, index + 1);
            swapIndex2 = findIndexOf(arr2, 0, swapIndex1 + 1);
            prezzo = prezzo + arr2[swapIndex1] + arr2[swapIndex2];
            swap(arr2[swapIndex1], arr2[swapIndex2]);
            swapIndex1 = swapIndex2;
            tmpMosse++;
        }
        if (index != 0 && (tmpMosse - 2) * (index + 1) > tmpMosse + 2)
            prezzo = prezzo - ((tmpMosse - 2) * (index + 1) - (tmpMosse + 2));
        index++;
    }

    ofstream out("output.txt");
    out << mosse << " " << prezzo;

    in.close();
    out.close();
    delete[] arr1;
    delete[] arr2;

    return 0;
}

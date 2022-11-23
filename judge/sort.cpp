#include <iostream>
#include <fstream>
using namespace std;

void merge(int *arr, int start, int end, int mid)
{
    int indexL = start, indexR = mid + 1, indexRes = 0;

    int *res = new int[end + 1];

    while (indexL <= mid && indexR <= end)
    {
        if (arr[indexL] < arr[indexR])
        {
            res[indexRes] = arr[indexL];
            indexL++;
        }
        else
        {
            res[indexRes] = arr[indexR];
            indexR++;
        }
        indexRes++;
    }
    while (indexL <= mid)
    {
        res[indexRes] = arr[indexL];
        indexL++;
        indexRes++;
    }
    while (indexR <= end)
    {
        res[indexRes] = arr[indexR];
        indexR++;
        indexRes++;
    }
    for (int i = start; i <= end; i++)
        arr[i] = res[i - start];
    delete[] res;
}

void mergeSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, end, mid);
    }
}

int main()
{
    int N;
    ifstream in("input.txt");
    in >> N;
    int *arr = new int[N];

    for (int i = 0; !in.eof(); i++)
        in >> arr[i];

    mergeSort(arr, 0, N - 1);

    ofstream out("output.txt");
    for (int i = 0; i < N; i++)
        out << arr[i] << " ";
    delete[] arr;

    return 0;
}

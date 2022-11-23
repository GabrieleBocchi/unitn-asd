#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Interval
{
    int start;
    int end;
};

bool compare(Interval a, Interval b)
{
    return a.start < b.start;
}

int main()
{
    int N, min = 0, max = 0, maxEnd = 0;
    ifstream in("input.txt");
    in >> N;
    Interval *arr = new Interval[N];

    for (int i = 0; !in.eof(); i++)
    {
        in >> arr[i].start;
        in >> arr[i].end;
    }

    sort(arr, arr + N, compare);

    for (int i = 1; i < N; i++)
    {
        if (arr[i].start - arr[i - 1].end > max - min)
        {
            if (maxEnd <= arr[i - 1].end)
            {
                min = arr[i - 1].end;
                max = arr[i].start;
            }
            else if (maxEnd > arr[i - 1].end && maxEnd < arr[i].start && arr[i].start - maxEnd > max - min)
            {
                min = maxEnd;
                max = arr[i].start;
            }
        }
        if (arr[i - 1].end > maxEnd)
            maxEnd = arr[i - 1].end;
    }

    ofstream out("output.txt");
    if (min == 0)
        out << 0;
    else
        out << min << " " << max;
    delete[] arr;

    return 0;
}

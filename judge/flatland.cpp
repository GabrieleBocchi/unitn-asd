#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool checkLeft(bool* arr, int start, int end)
{
    if(arr[end] == 1)
        return true;
    for(int i = end - 2; i > start; i = i - 2)
        if(arr[i] == 1 && arr[i + 1] == 0)
            return true;
    return false;
}

bool checkRight(bool* arr, int start, int end)
{
    if(arr[start] == 0)
        return true;
    for(int i = start + 2; i < end; i = i + 2)
        if(arr[i] == 0 && arr[i - 1] == 1)
            return true;
    return false;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N;
    in >> N;
    bool arr[N];

    vector<int> result;
    
    char c;
    for(int i = 0; i < N; i++)
    {
        in >> c;
        if(c == 's')
            arr[i] = true;
        else
            arr[i] = false;
    }
    in.close();

    if(N >= 3)
    {
        if(checkRight(arr, 1, N - 1))
            result.push_back(0);

        for(int i = 2; i < N - 2; i = i + 2)
            if(checkLeft(arr, 0, i - 1) && checkRight(arr, i + 1, N - 1))
                result.push_back(i);

        if(checkLeft(arr, 0, N - 2))
            result.push_back(N - 1);
    }
    else
        result.push_back(0);

    out << result.size() << endl;
    for (int i = 0; i < result.size(); i++)
        out << result[i] << " ";
}
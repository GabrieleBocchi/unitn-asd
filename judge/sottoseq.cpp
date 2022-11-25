#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int element, maxHere = 0, result = 0;
    ifstream in("input.txt");
    in >> element;

    while (!in.eof())
    {
        in >> element;
        maxHere = max(maxHere + element, 0);
        result = max(result, maxHere);
    }

    ofstream out("output.txt");
    out << result;

    in.close();
    out.close();

    return 0;
}

// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<char> vec;

int main()
{

    string in;
    cin >> in;

    // cout << in << endl;

    for (int i = 0; i < in.length(); i++)
    {
        vec.push_back(in[i]);
    }
    char current = vec[0];
    int count = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (current == vec[i])
        {
            count++;
            if (count >= 7)
                break;
        }
        else
        {
            current = vec[i];
            count = 1;
        }
    }
    if (count >= 7)
        cout << "YES";
    else
        cout << "NO";
}
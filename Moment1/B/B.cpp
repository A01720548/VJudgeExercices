// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <vector>
using namespace std;

vector<double> vec;

int main()
{
    int n;
    cin >> n;
    int num;
    int arr[n][2];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> num;
            arr[i][j] = num;
        }
    }
    int a = 1;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][0] == arr[j][1])
            {
                result++;
            }
        }
    }

    cout << result;
}
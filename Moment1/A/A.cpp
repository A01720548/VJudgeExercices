// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>
using namespace std;

vector<double> vec;

int main()
{
    int n;
    cin >> n;
    double num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    int sum = accumulate(vec.begin(), vec.end(), 0);

    int minCoins = 0;
    int coinsSum = 0;
    sort(vec.begin(), vec.end(), greater<int>());

    for (int i = 0; i < vec.size(); i++)
    {
        if (coinsSum <= sum / 2)
        {
            coinsSum += vec[i];
            minCoins++;
        }
        else
            break;
    }

    cout << minCoins;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t, n, k, amountOfSubArrays;
    map <int, int> mapWithOrder;
    int numberOfTestCases, amountOfElements;
    cin >> numberOfTestCases;
    while (numberOfTestCases--) {
        cin >> n;
        cin >> k;
        amountOfSubArrays = 1;
        int array[n];
        int sortedArray[n];
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
            sortedArray[i] = array[i];
        }
        if (n == 1) {
            cout << "YES" << endl; // If array only contains one element
        }
        else {
            sort(sortedArray, sortedArray + n);
            for (int i = 0; i < n; i++)
            {
                mapWithOrder[sortedArray[i]] = (i + 1); // Assign order to element in map
            }
            for (int i = 0; i < n; i++)
            {
                array[i] = mapWithOrder[array[i]]; // Store order in array
            }
            for (int i = 1; i < n; i++)
            {
                if (array[i] - array[i - 1] != 1) amountOfSubArrays++;
            }
            if (amountOfSubArrays <= k) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        mapWithOrder.clear();
    }
}
// g++ main.cpp -o main.exe
// main.exe < in.txt
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Algorithm
void KMPSearch(string txt, string pat)
{
    bool found = false;
    int counter = 0;
    vector<int> indicesFound;
    int M = pat.length();
    int N = txt.length();

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            found = true;
            counter++;
            indicesFound.push_back(i - j + 1);
            // cout << i - j + 1 << " ";
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }

    }
    if (found) {
        cout << counter << endl;
        for (auto i : indicesFound) {
            cout << i << " ";
        }
        cout << endl;
    }
    else cout << "Not Found" << endl;
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s, pattern;
        cin >> s >> pattern;
        KMPSearch(s, pattern);



    }
}
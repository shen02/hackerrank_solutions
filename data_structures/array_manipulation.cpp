#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */
// Reverse prefix array?
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 1, 0);

    for(vector<int> query : queries){
        arr[query[0] - 1] += query[2];
        arr[query[1]] -= query[2];
    }

    long max_value = 0;
    long sum = 0;
    for(int value : arr){
        sum += value;
        max_value = max(sum, max_value);
    }
    
    return max_value;
}
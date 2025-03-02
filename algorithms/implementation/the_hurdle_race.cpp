#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'hurdleRace' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY height
 */

int hurdleRace(int k, vector<int> height) {
    // finds the maximum value within the list; more efficient than sorting
    int maxHeight = *max_element(height.begin(), height.end()); 

    return max({0, maxHeight - k});   
}
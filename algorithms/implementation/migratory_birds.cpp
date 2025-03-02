#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'migratoryBirds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int migratoryBirds(vector<int> arr) {
    map<int, int> occurrences;
    
    for (int id : arr){
        occurrences[id]++; 
    }

    return max_element(occurrences.begin(), occurrences.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second; })->first;
}
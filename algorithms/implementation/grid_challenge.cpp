#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gridChallenge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING_ARRAY grid as parameter.
 */

string gridChallenge(vector<string> grid) {
    vector<string> sortedGrid;
    for(string s : grid){
       sort(s.begin(), s.end());
       sortedGrid.push_back(s);
    }
    
    bool alphabeticalCol = 1;
    
    for(int col = 0; col < sortedGrid.at(0).length(); col++){
        for(int row = 0; row < sortedGrid.size() - 1; row++){
            alphabeticalCol = alphabeticalCol && (sortedGrid.at(row)[col] <= sortedGrid.at(row + 1)[col]);
        }
    }
    
    return alphabeticalCol? "YES" : "NO";
}
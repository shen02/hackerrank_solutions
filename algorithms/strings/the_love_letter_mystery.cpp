#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'theLoveLetterMystery' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int theLoveLetterMystery(string s) {
    int operations = 0;
        
    for(int i = 0; i < s.size() / 2; i++){
        char a = s[i];
        char b = s[s.size() - i - 1];
        
        operations += abs(b-a);
    }
    
    return operations;
}
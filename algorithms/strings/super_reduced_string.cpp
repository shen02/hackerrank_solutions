#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {
    bool hasPair = 1;
    string result = s;
    
    while(hasPair){
        string temp = "";
        hasPair = 0;
        for(int i = 0; i < result.size();){
            if(result[i] != result[i+1]){
                temp += result[i];
                i++;
            }else{
                i+=2;
                hasPair = 1;
            }
        }
        result = temp;
    }
    
    // Could be better
    if(result==""){
        return "Empty String";
    }
    
    return result;
}
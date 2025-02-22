#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) {
    int currSeaLevel = 0;
    int prevSeaLevel = currSeaLevel;
    int valleys = 0;
    
    for(char step : path){
        
        prevSeaLevel = currSeaLevel;
        if(step == 'U'){
            currSeaLevel++;
        }else if(step == 'D'){
            currSeaLevel--;
        }
        
        if(currSeaLevel == 0 && prevSeaLevel < 0){
            valleys++;
        }
    }
    
    return valleys;
}
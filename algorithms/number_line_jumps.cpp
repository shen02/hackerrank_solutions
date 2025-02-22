#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'kangaroo' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER x1
 *  2. INTEGER v1
 *  3. INTEGER x2
 *  4. INTEGER v2
 */

string kangaroo(int x1, int v1, int x2, int v2) {
    return overlapPossible(x1, v1, x2, v2)? "YES" : "NO";
}

// Determine whether the given x-v combination can result in equivalent x
// at an equivalent time.
bool overlapPossible(int x1, int v1, int x2, int v2){
    if(v1 != v2){
        double time = (double)(x2 - x1) / (v1 - v2);
        return ((time > 0) && (time - floor(time) == 0));
    }else{
        return x1 == x2;
    }      
}
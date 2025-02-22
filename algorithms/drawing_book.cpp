#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */

int pageCount(int n, int p) {
    // turns from page 1 = (p - (p % 2)) / 2
    // turns from page n = ((n - p)  + (p % 2)) / 2
    
    return min(((p-(p%2))/2), (((n-p)+(p%2))/2));
}
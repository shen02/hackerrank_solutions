#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */

int cookies(int k, vector<int> A) {
    int operations = 0;
    
    // Create a min-heap with sweetness in ascending order from the top
    priority_queue<int, vector<int>, greater<int>> cookies(A.begin(), A.end());
    
    while(cookies.size() > 1 && cookies.top() < k){
        int least = cookies.top();
        cookies.pop();
        int secondLeast = cookies.top();
        cookies.pop();
        
        cookies.push(least + 2 * secondLeast);
        
        operations++;
    }
    
    return cookies.top() < k? -1 : operations;
}
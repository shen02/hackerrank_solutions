#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */

// Brute force attempt through map & bubble sort;
// Oh gosh I thought this solution was ugly until I saw the hackerrank editorial;
// On a second thought, this one is still considerably worse.
void minimumBribes(vector<int> q) {
    bool swapped = 1;
    int swaps = 0;
    
    bool tooChaotic = 0;
    map<int, int> bribe_o_meter;
    
    while(swapped){
        swapped = 0;
        for(int i = 0; i < q.size() - 1; i++){
            if(q.at(i) > q.at(i + 1)){
                bribe_o_meter[q.at(i)]++;
                swap(q.at(i), q.at(i + 1));
                swapped = 1;
                swaps += 1;
            }
            if(bribe_o_meter[q.at(i+1)] > 2){
                tooChaotic = 1;
                break;
            }
        }
    }
    cout << (tooChaotic? "Too chaotic" : to_string(swaps)) << endl;
}
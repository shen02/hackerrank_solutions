#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    
    // 1. Keep only unique elements (e.g. set)
    // 2. comparative insertion (simultaneous sorting required)
    
    vector<int> playerRanks;
    vector<int> uniqueRankings;
    
    set<int, greater<int>> rankings(ranked.begin(), ranked.end());
    uniqueRankings.assign(rankings.begin(), rankings.end());
    
    stack<int, vector<int>> greaterThanPlayer(uniqueRankings);
    
    for(int score : player){
        while(!greaterThanPlayer.empty() && score >= greaterThanPlayer.top()){
            greaterThanPlayer.pop();
        }
        playerRanks.push_back(greaterThanPlayer.size() + 1);
    }
    
    return playerRanks;
}
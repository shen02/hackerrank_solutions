#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

// Passes all tests but it's so primitive it makes me cry in shame
string isValid(string s) {
    string result = "YES";
    
    // Count the frequency of each letter
    map<char, int> lettersFrequencies;
    for(char c : s){
        lettersFrequencies[c]++;
    }
    
    // Count the frequency of each frequency
    map<int, int> countFrequencies;
    for(pair<char, int> count : lettersFrequencies){
        countFrequencies[count.second]++;
    }
    
    // If all characters already have the same frequency
    if(countFrequencies.size() == 1){
        return "YES";
    }
    // If there are more than 2 distinctive frequencies, hence removing 1 character will not result in all characters
    // having the same frequency.
    if(countFrequencies.size() > 2){
        return "NO";
    }
    
    // Find the frequency with the minimum frequency
    pair<int, int> min = *min_element(countFrequencies.begin(), countFrequencies.end(), [](pair<int, int> a, pair<int, int> b){return a.second < b.second;});
    
    countFrequencies[min.first]--;
    if(min.first > 1)
        countFrequencies[min.first-1]++;

    // Erase all frequency values with a frequency of 0
    for(map<int, int>::iterator i = countFrequencies.begin(); i != countFrequencies.end();){
        if(i->second == 0){
            i = countFrequencies.erase(i);
        }else{
            i++;
        }
    }
    
    if(countFrequencies.size() > 1){
        return "NO";
    }
    
    return result;
}
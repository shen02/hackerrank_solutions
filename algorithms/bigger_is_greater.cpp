#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'biggerIsGreater' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING w as parameter.
 */

// Returns the next lexigraphically largest permutation of the given string w, where the input w is gauranteed to be the largest permutation with the given w[0].
// Invariant: the return will have a different starting character than w
string nextLargestDifferentBeginning(string w);

// Returns the next lexigraphically largest permutation of the given string w
string biggerIsGreater(string w){
    
    string result = "no answer";
    
    for(int i = w.size() - 1; i >= 1; i--){
        // At the first occurrence where the characters are not in descending order
        if(w[i] > w[i-1]){
            result = w.substr(0, i - 1) + nextLargestDifferentBeginning(w.substr(i - 1));
            return result;
        }
    }
    
    return result;
}

string nextLargestDifferentBeginning(string w){
    char firstChar = w[0];
    // Maps a given character in w with its next largest character in w
    // *Inefficient in space/time for all the unused mapped values
    map<char, char> nextLargestChar;
    sort(w.begin(), w.end());
    
    for(int i = 0; i < w.size() - 1; i++){
        nextLargestChar[w[i]] = w[i + 1];
    }
    
    char nextLargest = nextLargestChar[firstChar];
        
    w.erase(w.find(nextLargest), 1); // Not the best approach
    
    return nextLargest + w;
}


// Alternative approach to nextLargestDifferentBeginning using priority queue
// Looks better but buggy (passing 2/5 tests) for some reason; need to double-check. 
string nextLargestDifferentBeginning_Alternative(string w){
    string nextLargestString = "";
    
    // Create a priority queue in ascending order of the given string
    priority_queue<char, vector<char>, greater<char>> orderedChars(w.begin(), w.end());
    
    // Append all chars smaller than w[0] in ascending order  
    while(orderedChars.top() != w[0]){
        char currentChar = orderedChars.top();
        nextLargestString += currentChar;
        orderedChars.pop();
    }
    // Append w[0]
    nextLargestString += orderedChars.top();
    orderedChars.pop();
    
    // Append the next largest char after w[0] to the beginning of the result
    nextLargestString = orderedChars.top() + nextLargestString;
    orderedChars.pop();
    
    // Append the remaining larger characters than w[0] in ascending order
    while(!orderedChars.empty()){
        nextLargestString += orderedChars.top();
        orderedChars.pop();
    }
    
    return nextLargestString;
}
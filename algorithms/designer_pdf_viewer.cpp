#include <bits/stdc++.h>

using namespace std;s

/*
 * Complete the 'designerPdfViewer' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h
 *  2. STRING word
 */

int designerPdfViewer(vector<int> h, string word) {
    const int ascii_adjustment = 97; // The C++ ASCII hex for 'a'
    int max_height = 0; // The height of the "tallest" character in word 
    
    for(char letter : word){
        if(h[letter - ascii_adjustment] > max_height){
            max_height = h[letter - ascii_adjustment];
        }
    }
    
    return word.length() * max_height;
}
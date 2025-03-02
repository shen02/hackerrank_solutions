#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */
 
// Gets the super digit of the given int represented by a string
int getSuperDigit(string superDigit){
    int sum = 0;
    while(superDigit.length() > 1){
        for(char c : superDigit){
            sum += c - '0';
        }
        superDigit = to_string(sum);
        sum = 0;
    }
    return stoi(superDigit);
}

// Recursive solution to getSuperDigit()
int getSuperDigitRecursive(string superDigit){
    if(superDigit.length() == 1){
        return superDigit[0] - '0';
    }else{
        return (superDigit[0] - '0') + getSuperDigitRecursive(superDigit.substr(1));
    }
}

// Get super digit from n, multiple result by k, then get super digit of the
// resulting product (n * k).
int superDigit(string n, int k) {
    return getSuperDigit(to_string(getSuperDigit(n) * k));
}
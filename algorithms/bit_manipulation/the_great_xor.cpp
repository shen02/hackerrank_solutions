#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'theGreatXor' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER x as parameter.
 */

long theGreatXor(long x) {
    /*
    1. a XOR x > x
     I.     a cannot be a 1-bit long where a = x[i] = 1.
     II.    a must have at least n fewer most significant bit x, where n is the length of sequence of continuous 1s in x starting from its most significant bit. 
    2. 0 < a < x     
     I.     a must have at least 1 fewer most significant bit x (see 1.I.)
    */

    return ~x & long(pow(2, floor(log2(x)) + 1) - 1);
}
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    
    if (year == 1918){
        return "26.09.1918";
    }else if (year < 1918){
        return to_string(12 + (year % 4 != 0)) + ".09." + to_string(year);
    }else{
        return to_string(12 + !((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))) + ".09." + to_string(year);
    }
    
}
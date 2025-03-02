#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
 // Returns the minimum number of swaps needed to sort a given array so that 
 // it is equivalent to the given sorted array
int minSwapsSort(vector<int> arr, vector<int> sorted_arr){
    int swaps = 0;
    
    map<int, int> positions;
    for(int i = 0; i < arr.size(); i++){
        positions[arr[i]] = i;
    }
    
    for(int i = 0; i < sorted_arr.size(); i++){
       if(arr[i] != sorted_arr[i]){
            swaps++;
            
            int index = positions[sorted_arr[i]];
            positions[arr[i]] = index;
            positions[arr[index]] = i;
            
            swap(arr[i], arr[index]);
       }
    }
    return swaps;
} 
 // approach using map
int lilysHomework(vector<int> arr) {
    
    // Sorted in ascending order
    vector<int> sorted_asc;
    sorted_asc.assign(arr.begin(), arr.end());
    sort(sorted_asc.begin(), sorted_asc.end());
    
    // Sorted in descending order
    vector<int> sorted_dec;
    sorted_dec.assign(arr.begin(), arr.end());
    sort(sorted_dec.begin(), sorted_dec.end(), greater<int>());
    
    return min(minSwapsSort(arr, sorted_asc), minSwapsSort(arr, sorted_dec));
}


/* Brute force sorting attempt:
 * 
 * The inner loop continuously finds the index to the min/max element, i, within the given list. If the index of the minimum index is acquired, the resulting sorted array will be in ascending order; vice versa. 
 * 
 * The outer loop traverses through indices j where 0 <= j < arr.size() and passes a subarray starting from j to the inner-loop function to acquire the min/max index i. The loop then swaps the elements at indices j + i and j so the min/max element will be at the top of the list. 
 *
 * The function compares the swaps needed for sorting in ascending/descending order and returns the minimum of the two. [not implemented in code below]
 * 
 * The resulting time efficiency is a minimum of O(n^2), which fails 1/2 of the tests.
 */
 
 // Returns the index of the minimum element within the given int array
int min_index(vector<int> arr){
    int index = 0;
    int min = arr.at(0);
    
    for(int i = 1; i < arr.size(); i++){
        if(arr.at(i) < min){
            min = arr.at(i);
            index = i;
        }
    }
    return index;
}

// Returns the index of the maximum element within the given int array
int max_index(vector<int> arr){
    int index = 0;
    int max = arr.at(0);
    
    for(int i = 1; i < arr.size(); i++){
        if(arr.at(i) > max){
            max = arr.at(i);
            index = i;
        }
    }
    return index;
}

// @NOTE: only max-sorting is implemented for time efficiency testing
int lilysHomework_brute(vector<int> arr) {
    int swaps = 0;
   
    for(int i = 0; i < arr.size(); i++){
        vector<int> temp(arr.begin() + i, arr.end());
        if (max_index(temp) != 0) {
            swap(arr.at(i), arr.at(i + max_index(temp)));
            swaps++;
        }
    }

    return swaps;
}
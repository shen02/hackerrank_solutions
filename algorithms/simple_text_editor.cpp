#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;


struct textEditor {
    
    stack<string> ss;
    
    textEditor(){
        ss.push("");
    }

    // Appends w to the end of s
    void append(string w){
        string currStr = ss.top();
        currStr.append(w);
        ss.push(currStr);
    }
    
    // Deletes the last k characters of s
    void delete_chars(int k){
        string currStr = ss.top();
        currStr = currStr.substr(0, currStr.length() - k);
        ss.push(currStr);
    }
    
    // Prints the kth character of s
    void print(int k){
        cout << ss.top().c_str()[k-1] << endl;
    }
    
    // Undo the last operation of type 1 or 2
    void undo(){
        if(!ss.empty()){
            ss.pop();
        }
    }
};

int main() {
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
     
    int q; //Number denoting the number of operations
    cin >> q;
    
    textEditor t = textEditor();
    
    for(int i = 0; i < q; i++){
        int op;
        cin >> op;
        
        switch (op) {
            case 1:{
                string input;
                cin >> input;
                t.append(input);
                break;
            }
            case 2:{
                int k;
                cin >> k;
                t.delete_chars(k);
                break;
            }
            case 3:{
                int k;
                cin >> k;
                t.print(k);
                break;
            }
            case 4:{
                t.undo();
                break;
            }
        }
    }
    return 0;
}
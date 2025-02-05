#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

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

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    string n = first_multiple_input[0];

    int k = stoi(first_multiple_input[1]);

    int result = superDigit(n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

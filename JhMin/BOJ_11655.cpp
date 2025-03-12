#include <bits/stdc++.h>

using namespace std;

string input_strings;

void shift(){
    for(char& i: input_strings){
        if(i < 'A' || i > 'z') continue;
        if(i < 'a'){
            if(i - 'A' >= 13) i -= 13;
            else i += 13;
        }else{
            if(i - 'a' >= 13) i -= 13;
            else i += 13;
        }
    }
}


int main(){
    getline(cin, input_strings);
    shift();
    cout << input_strings << "\n";
    return 0;
}
// g++ -std=c++14 -Wall BOJ_11655.cpp -o BOJ_11655.out
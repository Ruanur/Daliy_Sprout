#include <bits/stdc++.h>

using namespace std;

string get_words;


int main(){
    cin >> get_words;

    stack<char> wordStack;

    int half_num = (get_words.size() % 2 == 0) ? get_words.size() / 2 : get_words.size() / 2 + 1;

    for(int i = 0; i < half_num; i++){
        wordStack.push(get_words[i]);
    }

    if(get_words.size() % 2 != 0){
        wordStack.pop();
    }

    for(int i = half_num; i < get_words.size(); i++){
        if (wordStack.top() != get_words[i]){
            cout << "0" << "\n";
            return 0;
        }
        wordStack.pop();
    }

    cout << "1" << "\n";

    return 0;
}



// g++ -std=c++14 -Wall BOJ_10988.cpp -o BOJ_10988.out
#include <bits/stdc++.h>

using namespace std;

string words;
vector<int> counts;


int main(){
    cin >> words;

    for(int i = 0; i < 26; i++){
        counts.push_back(0);
        for(int j = 0; j < words.size(); j++){
            if(words[j] == 'a' + i) {
                counts[i] = counts[i] + 1;
            }
        }
    }

    for(int i = 0; i < 26; i++){
        cout << counts[i] << " ";
    }
    cout << endl;

    return 0;
}

// g++ -std=c++14 -Wall BOJ_10808.cpp -o BOJ_10808.out

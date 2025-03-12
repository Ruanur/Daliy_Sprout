#include <bits/stdc++.h>

using namespace std;

vector<string> player;
string input_player_temp;
vector<char> result;


int main(){
    int length = 0;
    cin >> length;
    int alphabet['z' - 'a' + 1] = {0};
    for(int i = 0; i < length; i++){
        cin >> input_player_temp;
        player.push_back(input_player_temp);
    }

    for(int i = 0; i < length; i++){
        alphabet[player[i][0] - 'a']++;
    }

    for(int i = 0; i < sizeof(alphabet) / sizeof(int); i++){
        if(alphabet[i] > 4){
            result.push_back('a' + i); // 수정 필요: 특정 인덱스
        }
    }

    string result_string(result.begin(), result.end());

    if(result.size() == 0){
        cout << "PREDAJA" << "\n";
    }
    else{
        cout << result_string << "\n";
    }

}


// g++ -std=c++14 -Wall BOJ_1159.cpp -o BOJ_1159.out
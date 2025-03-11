#include <bits/stdc++.h>

using namespace std;


int tax_a, tax_b, tax_c;
vector<int> in_truck;
vector<int> out_truck;
vector<int> time_line;


int main(){
    cin >> tax_a >> tax_b >> tax_c;

    int temp1 = 0 , temp2 = 0;
    for(int i = 0; i < 3; i++){
        cin >> temp1 >> temp2;
        in_truck.push_back(temp1);
        out_truck.push_back(temp2);
    }


    for(int i = 0; i < *max_element(out_truck.begin(), out_truck.end()); i++){
        time_line.push_back(0);
    }

    for(int index = 0; index < 3; index++){
        for(int i = in_truck[index]; i < out_truck[index]; i++){
            time_line[i]++;
        }
    }

    
    for(int &i: time_line){
        if(i == 1){
            i *= tax_a;
        }

        else if(i == 2){
            i *= tax_b;
        }

        else if(i == 3){
            i *= tax_c;
        }
    }

    int tax_sum = 0;
    for(int i: time_line){
        tax_sum += i;
    }

    cout << tax_sum << "\n";

    return 0;
}


// g++ -std=c++14 -Wall BOJ_2979.cpp -o BOJ_2979.out
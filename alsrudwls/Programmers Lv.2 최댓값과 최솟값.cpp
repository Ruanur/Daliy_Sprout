#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string text_s;
    vector<string> string_arr_int;
    for (int i = 0; i < 4; i++)
    {
        cin >> text_s;
        string_arr_int.push_back(text_s);
    }

    sort(string_arr_int.begin(), string_arr_int.end(), [](const string& a, const string& b)
        {
            return stoi(a) < stoi(b);
        });

    int pointThisarr = 0;
    int vector_size = string_arr_int.size();
    for (int i = 0; i < vector_size; i++)
    {
        pointThisarr = stoi(string_arr_int.back());
        string_arr_int.pop_back();
        std::cout << pointThisarr;
    }


    
}



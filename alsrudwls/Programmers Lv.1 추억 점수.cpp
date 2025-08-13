#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

//pair에는 <이름, 점수>로 저장
//photo에는 이름들이 저장
//photo를 탐색하면서 탐색된 이름이 pair의 이름과 같다면 점수를 추가
vector<int> remainscore(const vector<pair<string, int>>& pairs, const vector<vector<string>>& photo)
{
    map<string, int> mapping;
    for (const auto& p : pairs) 
    {
        mapping[p.first] = p.second;
    }
    int total = 0;

    vector<int> result; // 각 행 합계를 저장할 벡터

    // photo 2차원 벡터 순회
    for (const auto& row : photo) {
        int rowSum = 0;
        for (const auto& cell : row) {
            auto it = mapping.find(cell);
            if (it != mapping.end()) {
                rowSum += it->second;
            }
        }
        result.push_back(rowSum); // 행별 합계를 result에 저장
    }

    return result;
}

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) 
{
    
    vector<pair<string, int>> pairs;

    for (int i = 0; i < name.size(); i++)
    {
        pairs.push_back({ name[i], yearning[i] });
    }

    vector<int> answer = remainscore(pairs, photo);
        
    return answer;
}



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int rows;
    cin >> rows;

    vector<vector<int>> matrix(rows); //삼각형 요소 저장 벡터
    vector<vector<int>> result(rows, vector<int>(rows, 0)); //결과값 출력을 위한 벡터, 삼각형 크기만큼 0으로 초기화 함

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j <= i; ++j) 
        {
            int number;
            cin >> number;
            matrix[i].push_back(number);
        }
    }

    result[0][0] = matrix[0][0];

    for (int i = 1; i < rows; ++i) 
    {
        for (int j = 0; j <= i; ++j) 
        {
            if (j == 0) 
            {
                result[i][j] = result[i - 1][j] + matrix[i][j];
            }
            else if (j == i) 
            {
                result[i][j] = result[i - 1][j - 1] + matrix[i][j];
            }
            else 
            {
                result[i][j] = max(result[i - 1][j - 1], result[i - 1][j]) + matrix[i][j];
            }
        }
    }

    int maxSum = *max_element(result[rows - 1].begin(), result[rows - 1].end());
    cout << maxSum << endl;

    return 0;
}

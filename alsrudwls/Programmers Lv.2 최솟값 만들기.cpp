#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Adding_Result_Multiple(vector<int>& A, vector<int>& B)
{
    int Result = 0;
    for (int i = 0; i < A.size(); i++)
    {
        Result += A[i] * B[i];
    }

    return Result;
}

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int answer = Adding_Result_Multiple(A, B);

    return answer;
}
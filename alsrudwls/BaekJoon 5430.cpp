#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>

/*
선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다. AC는 정수 배열에 연산을 하기 위해 만든 언어이다. 이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.

함수 R은 배열에 있는 수의 순서를 뒤집는 함수이고, D는 첫 번째 수를 버리는 함수이다. 배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.

함수는 조합해서 한 번에 사용할 수 있다. 예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다. 예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 수를 버리는 함수이다.

배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.
*/

using namespace std;

int T;
string p;
int n;
bool isError = false;
deque<int> arr; // 동적 배열 할당
bool isReversed = false; // 배열 뒤집기 상태 표시

void D(deque<int>& arr) // 첫 번째 배열 지우기
{
    if (!arr.empty())
    {
        if (isReversed)
        {
            arr.pop_back();
        }
        else
        {
            arr.pop_front();
        }
    }
    else
    {
        cout << "error" << '\n';
        isError = true;
    }
}

void result(deque<int>& arr)
{
    if (!isError)
    {
        cout << '[';
        while (!arr.empty())
        {
            if (isReversed)
            {
                cout << arr.back();
                arr.pop_back();
            }
            else
            {
                cout << arr.front();
                arr.pop_front();
            }
            if (!arr.empty())
            {
                cout << ',';
            }
        }
        cout << ']' << '\n';
    }
    arr.clear();
    isError = false;
    isReversed = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    cin.ignore(); // 남은 개행 문자 무시

    for (int i = 0; i < T; i++)
    {
        getline(cin, p);
        cin >> n;
        cin.ignore(); // 개행 문자 무시

        string input;
        getline(cin, input);

        // 입력 문자열에서 '['와 ']'를 제거
        input.erase(remove(input.begin(), input.end(), '['), input.end());
        input.erase(remove(input.begin(), input.end(), ']'), input.end());

        // ','를 기준으로 문자열을 분리하여 정수형으로 변환
        stringstream ss(input);
        string token;
        int count = 0;
        while (getline(ss, token, ',') && count < n) //[1,2,3,4] 입력시 1 2 3 4가 배열에 들어가게 된다.
        {
            arr.push_back(stoi(token));
            count++;
        }

        for (char command : p)
        {
            if (command == 'R')
            {
                isReversed = !isReversed; // 뒤집기 상태를 토글, 즉 배열이 뒤집힌 상태라고 인식시킨다.
            }
            else if (command == 'D')
            {
                D(arr);
                if (isError)
                {
                    break;
                }
            }
            else
            {
                cout << "잘못된 명령어" << '\n';
                break;
            }
        }
        result(arr);
    }

    return 0;
}

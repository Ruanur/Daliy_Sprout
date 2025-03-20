#include <iostream>
#include <vector>
using namespace std;

int arr[101][101];
pair<int, int> position;

int Boxout(int n, int w, int num)
{
    int answer = 0;
    int sel = position.second;

    for (int i = position.first; i < n / w + (n % w != 0); i++) {
        if (arr[i][sel] != 0) {
            answer++;
        }
    }
    return answer;
}

int solution(int n, int w, int num) {
    int value = 1;
    bool stop = false;

    cin >> n >> w >> num;

    for (int i = 0; i < n / w + (n % w != 0); i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < w; j++) {
                if (value > n) {
                    stop = true;
                    break;
                }
                arr[i][j] = value++;
                if (arr[i][j] == num) {
                    position = { i, j };
                }
            }
        }
        else {
            for (int j = w - 1; j >= 0; j--) {
                if (value > n) {
                    stop = true;
                    break;
                }
                arr[i][j] = value++;
                if (arr[i][j] == num) {
                    position = { i, j };
                }
            }
        }
        if (stop) break;
    }

    int result = Boxout(n, w, num);

    return result;
}

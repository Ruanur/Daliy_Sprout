#include <iostream>
#include <cmath>

using namespace std;

int calc(int storey) {
    int answer = 0;

    while (storey > 0) {
        int last_digit = storey % 10;
        int next_digit = (storey / 10) % 10; // 다음 자리 확인

        if (last_digit > 5 || (last_digit == 5 && next_digit >= 5)) {
            storey += (10 - last_digit); // 10의 배수로 올림
        }
        else {
            storey -= last_digit; // 10의 배수로 내림
        }

        answer += min(last_digit, 10 - last_digit); // 최소 클릭 횟수 추가
        storey /= 10; // 다음 자리로 이동
    }

    return answer;
}

int solution(int storey) {
    int answer = 0;

    answer = calc(storey);

    return answer;
}
#include <iostream>
using namespace std;

// 분할 정복을 이용한 모듈러 거듭 제곱 함수
long long modular_pow(long long base, long long exp, long long mod) {
    if (exp == 0)
        return 1; // 어떤 수의 0제곱은 1
    long long half = modular_pow(base, exp / 2, mod);
    half = (half * half) % mod; // 절반의 제곱을 mod로 나눈 나머지
    if (exp % 2 != 0)
        half = (half * base) % mod; // 지수가 홀수인 경우 base를 추가로 곱함
    return half;
}

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long result = modular_pow(a, b, c);
    cout << result << endl;

    return 0;
}

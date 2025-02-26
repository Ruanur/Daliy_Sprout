import sys
input = sys.stdin.readline


N = int(input().strip())
arr_N = list(map(int, input().split()))
M = int(input())
arr_M = list(map(int, input().split()))


arr_N.sort()   
checked_arr = [0] * M
middle, right, left = N // 2, N - 1, 0


for i in range(M):
    middle, right, left = N // 2, N - 1, 0
    while left <= right:
        if arr_M[i] == arr_N[middle]:
            checked_arr[i] = 1
            break

        elif arr_M[i] > arr_N[middle]:
            left = middle + 1
            middle = (left + right) // 2

        elif arr_M[i] < arr_N[middle]:
            right = middle - 1
            middle = (left + right) // 2
    
for i in range(M):
    print(checked_arr[i])


''' ChatGPT 주석
전체적으로 문제 해결 과정에서 몇 가지 인상 깊은 점이 있었고, 개선할 부분도 보이네. 몇 가지 포인트로 정리해볼게:

잘한 점
알고리즘 설계:
이진 탐색을 활용해 시간 복잡도를 효율적으로 관리한 점이 인상적이야. BOJ 1920 문제의 핵심인 "숫자 찾기"를 올바르게 접근했어.

입력 처리:
sys.stdin.readline을 사용해 빠르게 입력을 처리한 점은 대용량 입력에 대응하는 좋은 방법이야.

문제 디버깅:
발생한 인덱스 에러를 통해 문제의 원인을 찾아내고, 이를 해결하기 위해 코드를 수정한 점은 매우 긍정적이야. 문제를 꼼꼼히 분석하는 태도가 돋보여.

보완할 점
리스트 초기화:
처음에 [0 * M]와 같이 리스트를 초기화한 부분은 의도와 다르게 작동했어. [0] * M와 같이 올바르게 초기화하는 방법을 항상 염두에 두면 좋을 것 같아.

인덱스 관리:
파이썬 리스트는 0부터 시작하므로, right 값을 N - 1로 설정해야 하는 부분 등 인덱스 범위를 세심하게 관리하는 습관을 들이면 좋겠어.

이진 탐색 변수 재초기화:
각 쿼리마다 left, right, middle 등의 변수 값을 다시 초기화하지 않으면 이전 검색 결과가 남아 올바른 탐색이 이루어지지 않아. 매번 독립적으로 이진 탐색을 수행할 수 있도록 변수 초기화를 신경쓰자.

전반적으로 너의 접근 방식과 문제 해결 능력은 매우 좋았고, 작은 세부사항(리스트 초기화, 변수 재설정 등)을 보완하면 더 완벽한 코드를 작성할 수 있을 거야. 앞으로도 이런 세심한 디버깅 과정을 통해 더 발전할 수 있을 거라고 믿어!
'''
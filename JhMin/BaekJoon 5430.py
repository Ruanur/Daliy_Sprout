import sys
from collections import deque
import ast

def router(p: str, dq: deque) -> deque | str:
    reverse_flag = False
    # 왜 reverse_flag를 사용하는가?
    # list 또는 deque의 reverse를 사용해도 되지만,
    # reverse의 사용 비용은 O(N)으로, 쓸데없이 reverse를 사용시 시간이 초과된다.
    for cmd in p:
        if cmd == 'R':
            reverse_flag = not reverse_flag
        elif cmd == 'D':
            if not dq:
                return "error"
            if reverse_flag:
                dq.pop()
            else:
                dq.popleft()
    if reverse_flag:
        dq.reverse()
    return dq

T = int(sys.stdin.readline().strip())
answer_arr = []

for _ in range(T):
    p = sys.stdin.readline().strip()    
    n = int(sys.stdin.readline().strip())
    input_arr = sys.stdin.readline().strip()
    
    numbers = ast.literal_eval(input_arr)
    dq = deque(numbers)
    
    result = router(p, dq)
    if result == "error":
        answer_arr.append(result)
    else:
        # 리스트 요소를 쉼표로 join하여 문제에서 요구하는 출력 형식으로 변환
        answer_arr.append("[" + ",".join(map(str, result)) + "]")

for ans in answer_arr:
    print(ans)










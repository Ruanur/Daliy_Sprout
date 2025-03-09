import sys
input = sys.stdin.readline

small_man = []
for i in range(9):
    small_man.append(int(input()))
small_man.sort()

left = 0
right = 8

target = sum(small_man) - 100

while left <= right:
    temp = small_man[left] + small_man[right]
    if target > temp:
        left += 1
    elif target < temp:
        right -= 1
    elif target == temp:
        break
    else:
        print("error")

del small_man[right]
del small_man[left]



for i in small_man:
    print(i)

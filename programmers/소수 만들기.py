from itertools import combinations

# 소수 판별 함수
def check(num):
    if num==0 or num==1:
        return False
    else:
        for n in range(2, int(num//2) + 1):
            if num % n == 0:
                return False
        return True
    
def solution(nums):
    answer = 0
    cmb = list(combinations(nums, 3))
    for arr in cmb:
        if check(sum(arr)):
            answer += 1                    
    
    return answer

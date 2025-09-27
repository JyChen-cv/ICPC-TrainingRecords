import math

def check(x, k):
    ls = math.isqrt(x)
    return x - ls >= k

def solve():
    k = int(input())
    l = 1
    r = 15 * 10**18
    while l < r:
        mid = (l + r) // 2
        if check(mid, k):
            r = mid
        else:
            l = mid + 1
    print(l)

times = int(input())
for _ in range(times):
    solve()
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

int n, m;
const int N = 1e5;
int mapp[N + 2];

bool check(int x) {
    int i;
    int cnt = 0;
    for (i = n; i >= 1; i--) {
        if (mapp[i] >= x)
            cnt++;
        else
            break;
    }
    if (cnt >= x) return 1;
    int ls = m;
    for (int j = i; j >= 1; j--) {
        if (mapp[j] + 1 >= x && ls) {
            cnt++;
            ls--;
        }
    }
    return cnt >= x;
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    std::sort(mapp + 1, mapp + n + 1);
    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    std::cout << l << std::endl;
    return 0;
}
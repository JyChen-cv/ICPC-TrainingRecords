#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>

const int N = 10;
int mapp[N + 2];
struct lock {
    int a[6];
    void in() {
        for (int i = 1; i <= 5; i++) {
            std::cin >> a[i];
        }
    }
    void turn(int x, bool dir) {
        // dir==1 -> up
        if (a[x] == 9 && dir == 1)
            a[x] = 0;
        else if (a[x] == 0 && dir == 0)
            a[x] = 9;
        else
            a[x] += (dir ? 1 : -1);
    }
    bool operator<(const lock& t) const {  // 定义map必须有，所以只是为了用map而写
        for (int i = 1; i <= 5; i++) {
            if (a[i] == t.a[i]) continue;
            return a[i] < t.a[i];
        }
    }
};
std::map<lock, int> v;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        lock ls;
        ls.in();
        for (int i = 1; i <= 5; i++) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 1; k <= 9; k++) {
                    lock res = ls;
                    int kk = k;
                    while (kk--) res.turn(i, j);
                    if (v[res] == 0) ans++;
                    v[res] = 1;
                }
            }
        }
        for (int i = 1; i <= 4; i++) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 1; k <= 9; k++) {
                    lock res = ls;
                    int kk = k;
                    while (kk--) {
                        res.turn(i, j);
                        res.turn(i + 1, j);
                    }
                    if (v[res] == 0) ans++;
                    v[res] = 1;
                }
            }
        }
    }
    std::cout << ans / 2 << std::endl;  // 正转9==反转1,map按理说没有影响啊
    return 0;
}
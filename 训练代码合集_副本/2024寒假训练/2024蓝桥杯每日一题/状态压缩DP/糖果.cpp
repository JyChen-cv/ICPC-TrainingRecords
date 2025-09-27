#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

const int N = 20;
int mapp[(1 << N) + 2], res[102];
std::queue<int> q;

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    memset(mapp, 0x3f, sizeof mapp);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int a;
            std::cin >> a;
            res[i] |= (1 << (a - 1));
            mapp[res[i]] = 1;
            q.push(res[i]);
        }
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (mapp[res[i] | x] > mapp[x] + 1) {
                mapp[res[i] | x] = mapp[x] + 1;
                q.push(res[i] | x);
            }
        }
    }
    std::cout << (mapp[(1 << m) - 1] == 0x3f3f3f3f ? -1 : mapp[(1 << m) - 1]) << std::endl;
    return 0;
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1e6;
std::vector<int> bao[N + 2];
int mapp[N + 2], now[N + 2], ans;

void merge(int x, int y) {
    for (int i : bao[x]) {
        if (mapp[i - 1] == y) ans--;
        if (mapp[i + 1] == y) ans--;
    }
    for (int i : bao[x]) {
        mapp[i] = y;
        bao[y].push_back(i);
    }
    bao[x].clear();
}

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
        now[mapp[i]] = mapp[i];
        bao[mapp[i]].push_back(i);
        if (mapp[i] != mapp[i - 1]) ans++;
    }
    for (int i = 1; i <= m; i++) {
        int a;
        std::cin >> a;
        if (a == 1) {
            int x1, x2;
            std::cin >> x1 >> x2;
            if (x1 == x2) continue;
            if (bao[now[x1]].size() > bao[now[x2]].size()) std::swap(now[x1], now[x2]);
            merge(now[x1], now[x2]);
        } else {
            std::cout << ans << std::endl;
        }
    }
    return 0;
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 2e5;
int fa[N + 2];
struct group {
    int f, t, len;
    bool operator<(const group &t) const {
        return len < t.len;
    }
} mapp[N + 2];

int find(int x) {
    if (fa[x] == x)
        return x;
    else
        return fa[x] = find(fa[x]);
}

int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        std::cin >> mapp[i].f >> mapp[i].t >> mapp[i].len;
    }
    std::sort(mapp + 1, mapp + m + 1);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int a = find(mapp[i].f);
        int b = find(mapp[i].t);
        if (a != b) {
            fa[a] = b;
            ans += mapp[i].len;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (find(i) != find(i - 1)) {
            std::cout << "orz" << std::endl;
            return 0;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
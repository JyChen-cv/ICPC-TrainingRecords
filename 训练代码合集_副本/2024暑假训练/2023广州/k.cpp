#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>

const int N = 10;
int mapp[N + 2][N + 2], ans;
int n, m, k;

void dfs(int x) {
    ans = std::min(ans, x);
    if (!x) return;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mapp[i][j]) {
                if (i > 1 && i < n && mapp[i - 1][j] + mapp[i + 1][j] == 1) {
                    mapp[i - 1][j] ^= 1, mapp[i + 1][j] ^= 1;
                    mapp[i][j] = 0;
                    dfs(x - 1);
                    mapp[i][j] = 1;
                    mapp[i - 1][j] ^= 1, mapp[i + 1][j] ^= 1;
                }
                if (j > 1 && j < m && mapp[i][j - 1] + mapp[i][j + 1] == 1) {
                    mapp[i][j - 1] ^= 1, mapp[i][j + 1] ^= 1;
                    mapp[i][j] = 0;
                    dfs(x - 1);
                    mapp[i][j] = 1;
                    mapp[i][j - 1] ^= 1, mapp[i][j + 1] ^= 1;
                }
            }
        }
    }
}

void solve() {
    memset(mapp, 0, sizeof mapp);
    std::cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int a, b;
        std::cin >> a >> b;
        mapp[a][b] = 1;
    }
    ans = k;
    dfs(k);
    std::cout << ans << std::endl;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
1
3 4 5
2 2
1 2
1 4
3 4
1 1

3
3 4 5
2 2
1 2
1 4
3 4
1 1
1 3 3
1 1
1 2
1 3
2 1 1
2 1

*/
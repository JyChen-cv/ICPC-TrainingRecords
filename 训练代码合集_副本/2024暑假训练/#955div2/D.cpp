#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 500;
int mapp[N + 2][N + 2], v[N + 2][N + 2], sum[N + 2][N + 2];

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

void solve() {
    int n, m, k, sub = 0;
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> mapp[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        std::string ls;
        std::cin >> ls;
        for (int j = 1; j <= m; j++) {
            v[i][j] = ls[j - 1] == '0' ? 0 : 1;
            sub += (v[i][j] ? mapp[i][j] : (-mapp[i][j]));
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + v[i][j];
            // std::cout << sum[i][j] << " ";
        }
        // std::cout << std::endl;
    }
    sub = std::abs(sub);
    std::vector<int> res;
    for (int i = 1; i + k - 1 <= n; i++) {
        for (int j = 1; j + k - 1 <= m; j++) {
            int ii = i + k - 1, jj = j + k - 1;
            int nnn = sum[ii][jj] - sum[ii][j - 1] - sum[i - 1][jj] + sum[i - 1][j - 1];
            res.push_back(std::abs(k * k - nnn - nnn));
        }
    }
    int ans = res[0];
    // std::cout << sub << "??" << std::endl;
    // std::cout << ans << " ";
    for (int i = 1; i < (int)res.size(); i++) {
        // std::cout << res[i] << " ";
        ans = gcd(ans, res[i]);
    }
    // std::cout << std::endl;
    // std::cout << res.size() << " " << ans << std::endl;
    if (ans == 0) {
        std::cout << (sub == 0 ? "YES" : "NO") << std::endl;
    } else if (sub % ans == 0)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;
}

signed main() {
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
5 4 4
39 30 0 17
22 42 30 13
10 44 46 35
12 19 9 39
21 0 45 40
1000
1111
0011
0111
1100

*/
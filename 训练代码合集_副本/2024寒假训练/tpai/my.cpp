#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int mod = 1e9 + 7;
const int N = 1e6;
std::vector<int> q[N + 2];
int fa[N * 2 + 2];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void add(int x, int y) {
    int ls1 = find(x);
    int ls2 = find(y);
    if (ls1 == ls2)
        return;
    else
        fa[std::min(ls1, ls2)] = std::max(ls1, ls2);
}

int q_pow(int x, int y) {
    if (y == 0) return 1;
    int mid = q_pow(x, y / 2);
    if (y % 2)
        return mid * mid % mod * x % mod;
    else
        return mid * mid % mod;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::string c;
        std::cin >> c;
        q[i].clear();
        q[i].push_back(0);
        fa[i] = i;
        fa[i + n] = i + n;
        for (int j = 0; j < m; j++) {
            q[i].push_back((c[j] == '0' ? 0 : 1));
        }
    }

    for (int i = 1; i <= m; i++) {  // 考虑i>m/2是不是有点问题？是不是应该用j+n和k/k+n？
        for (int j = 1; j <= n; j++) {
            if (q[j][i] == 1) {
                for (int k = j + 1; k <= n; k++) {
                    if (q[k][i] == 1) {
                        add(j, k);
                        add(j + n, k + n);
                    }
                    if (q[k][m + 1 - i] == 1) {
                        add(j, k + n);
                        add(j + n, k);
                    }
                }
                break;
            }
        }
    }
    std::vector<int> ans;
    int tag = 0;
    for (int i = 1; i <= n; i++) {
        int ls1 = find(i);
        int ls2 = find(i + n);
        // std::cout << ls1 << " " << ls2 << std::endl;
        if (ls1 == ls2) {
            std::cout << 0 << std::endl;
            tag = 1;
            break;
        } else {
            ans.push_back(ls1);
            ans.push_back(ls2);
        }
    }
    if (!tag) {
        std::sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        std::cout << q_pow(2, ans.size() / 2) << std::endl;
    }
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
3 5
01100
10001
00010

1
2 3
001
001

*/
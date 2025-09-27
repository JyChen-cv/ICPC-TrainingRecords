#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
#define lson p << 1
#define rson p << 1 | 1
const int maxn = 1e6 + 5, inf = 1e18, maxm = 4e4 + 5, base = 37;
const int N = 1e6;
const int mod = 1e9 + 7;
// const int mod = 998244353;
// const __int128 mod = 212370440130137957LL;
//  int a[1005][1005];
// bool vis[505][505];
// char s[2005][2005];
int n, m;
int a[maxn];

// string s;

struct Node {
    // int val, id;
    // bool operator<(const Node &u)const{
    //     return val < u.val;//!!!!!!!!!!!!!!!!!!
    // }
    int v, w;
};

struct DSU {
    vector<int> fa;
    DSU(int n) : fa(n) {
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    int find(int x) {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }
    void merge(int x, int y) {
        if (find(x) != find(y)) {
            fa[find(x)] = find(y);
        }
    }
};

// long long ? maxn ? n? m?
void solve() {
    int res = 0;
    cin >> n >> m;
    vector<vector<int>> a(n + 5, vector<int>(m + 5));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;
            cin >> ch;
            a[i][j] = ch - '0';
        }
    }
    DSU d(2 * n + 5);
    for (int j = 1; j <= m / 2; j++) {
        vector<int> vec[2];
        for (int i = 1; i <= n; i++) {
            if (a[i][j]) {
                vec[0].pb(i);
            }
            if (a[i][m - j + 1]) {
                vec[1].pb(i);
            }
        }
        if (vec[0].size() + vec[1].size() >= 3) {
            cout << 0 << '\n';
            return;
        }
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < vec[x].size(); y++) {
                for (int z = y + 1; z < vec[x].size(); z++) {
                    int u = vec[x][y], v = vec[x][z];
                    d.merge(u + n, v);
                    d.merge(u, v + n);
                }
            }
        }
        if (vec[0].size() && vec[1].size()) {
            int u = vec[0][0], v = vec[1][0];
            d.merge(u, v);
            d.merge(u + n, v + n);
        }
    }
    if (m % 2 == 1) {
        int j = (m + 1) / 2;
        vector<int> vec;
        for (int i = 1; i <= n; i++) {
            if (a[i][j]) {
                vec.pb(i);
            }
        }
        if (vec.size() >= 2) {
            cout << 0 << '\n';
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (d.find(i) == d.find(i + n)) {
            cout << 0 << '\n';
            return;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (d.find(i) == i) cnt++;
    }
    cnt /= 2;
    res = 1;
    for (int i = 1; i <= cnt; i++) {
        res = res * 2 % mod;
    }
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cout << fixed << setprecision(9);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

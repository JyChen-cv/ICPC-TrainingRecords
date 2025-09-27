#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define endl '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define ll long long
#define lll __int128
#define ull unsigned long long
#define pii pair<ll, ll>
const int MAX = 1e6 + 10;
const ll mod = 998244353;

lll p, l, k;
ll ans = 0;
map<lll, int> yz;
vector<pair<lll, int>> c;
void dfs(int cur, lll s) {
    if (cur == c.size()) {
        ans++;
        return;
    }
    auto [x, y] = c[cur];
    dfs(cur + 1, s);
    if (y == 0) {
        if (s * x <= l) dfs(cur, s * x);
    } else {
        for (lll i = 0; i < y; i++) {
            s *= x;
            if (s > l) break;
            dfs(cur + 1, s);
        }
    }
}
void solve() {
    ll c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    p = c1, l = c2, k = c3;
    for (lll i = 2; i <= 1e7; i++) {
        if (k % i == 0) {
            yz[i] = 0;
            while (k % i == 0) k /= i;
        }
    }
    if (k != 1) yz[k] = 0;
    for (lll i = 2; i <= 1e7; i++) {
        if (p % i == 0) {
            int cnt = 0;
            while (p % i == 0) p /= i, cnt++;
            if (yz.count(i)) continue;
            yz[i] = cnt;
        }
    }
    if (p != 1) {
        if (not yz.count(p)) yz[p] = 1;
    }
    for (auto [x, y] : yz) c.push_back({x, y});
    dfs(0, 1);
    cout << ans;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << fixed << setprecision(12);
    // init();
    // int _;cin>>_;while (_ --)
    solve();
}
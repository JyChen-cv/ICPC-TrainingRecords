#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int N = 2e5;
int a[N + 2], b[N + 2], c[N + 2], sa[N + 2], sb[N + 2], sc[N + 2];
int n, tot;

int check(int la, int ra, int lb, int rb, int lc, int rc) {
    if (sa[ra] - sa[la - 1] >= tot) {
        if (sb[rb] - sb[lb - 1] >= tot) {
            if (sc[rc] - sc[lc - 1] >= tot) {
                std::cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << std::endl;
                return 1;
            }
        }
    }
    return 0;
}

bool deal(int l, int r, std::pair<int, int> x) {
    int ll = l, rr = r;
    while (ll < rr) {
        int mid = (ll + rr) >> 1;
        if (check(x.first, x.second, l, mid, mid + 1, r)) {
            return 1;
        } else {
            int ls = 0;
            if (sb[mid] - sb[l - 1] < tot) ls = 1;
            if (sc[r] - sc[mid] < tot) {
                if (ls == 0)
                    rr = mid;
                else
                    break;
            } else
                ll = mid + 1;
        }
    }
    ll = l, rr = r;
    while (ll < rr) {
        int mid = (ll + rr) >> 1;
        if (check(x.first, x.second, mid + 1, r, l, mid)) {
            return 1;
        } else {
            int ls = 0;
            if (sc[mid] - sc[l - 1] < tot) ls = 1;
            if (sb[r] - sb[mid] < tot) {
                if (ls == 0)
                    rr = mid;
                else
                    break;
            } else
                ll = mid + 1;
        }
    }
    return 0;
}

void solve() {
    std::cin >> n;
    tot = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        sa[i] = sa[i - 1] + a[i];
        tot += a[i];
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
        sb[i] = sb[i - 1] + b[i];
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> c[i];
        sc[i] = sc[i - 1] + c[i];
    }
    if (tot % 3 == 0)
        tot /= 3;
    else
        tot = tot / 3 + 1;

    int t = 1, sum = 0;
    std::vector<std::pair<int, int> > q;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        while (sum >= tot) {
            if (sum - a[t] < tot) q.push_back({t, i});
            sum -= a[t];
            t++;
        }
    }

    int tag = 0;
    for (auto i : q) {
        // std::cout << i.first << " " << i.second << std::endl;
        if (sb[n] - sb[i.second] >= tot && sc[i.first - 1] - sc[0] >= tot) {
            std::cout << i.first << " " << i.second << " " << i.second + 1 << " " << n << " " << 1 << " " << i.first - 1 << std::endl;
            tag = 1;
        } else if (sb[i.first - 1] - sb[0] >= tot && sc[n] - sc[i.second] >= tot) {
            std::cout << i.first << " " << i.second << " " << 1 << " " << i.first - 1 << " " << i.second + 1 << " " << n << std::endl;
            tag = 1;
        }
        if (tag) break;
        if (deal(1, i.first - 1, i)) {
            tag = 1;
            break;
        } else if (deal(i.second + 1, n, i)) {
            tag = 1;
            break;
        }
    }
    // std::cout << check(5, 5, 1, 4, 6, 10) << std::endl;
    if (!tag) std::cout << -1 << std::endl;
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
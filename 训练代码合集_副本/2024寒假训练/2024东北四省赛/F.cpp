#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define int long long
std::vector<int> factor, cnt, ans;
std::map<int, int> whe;
struct node {
    int x, y;
    bool operator<(const node &t) const {
        return factor[x] * ans[y] > factor[t.x] * ans[t.y];
    }
};
std::priority_queue<node> xu;

int mul(int a, int b, int c) {
    // std::cout << a << " " << b << " ";
    int res = 0;
    for (int t = 60; t >= 0; t--) {
        res <<= 1;
        if (res > c) return 0;
        int ls = (b >> t) & 1;
        if (ls) {
            res += a;
            if (res > c) return 0;
        }
    }
    // std::cout << res << std::endl;
    return 1;
    // a*b <= c
}

signed main() {
    freopen("/Users/chenjiayou/Desktop/2024寒假训练/2024东北四省赛/okok.in", "r", stdin);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int q, m, k;
    std::cin >> q >> m >> k;
    int qq = q, kk = k;
    for (int i = 2; i * i <= kk; i++) {  // ?youshim? meishi
        if (k % i == 0) {
            while (k % i == 0) k /= i;
            whe[i] = 1;
            factor.push_back(i);
            cnt.push_back(1e9);
        }
    }
    if (k != 1) {
        factor.push_back(k);
        cnt.push_back(1e9);
    }
    for (int i = 2; i * i <= qq; i++) {
        if (q % i == 0) {
            int cn = 0;
            while (q % i == 0) {
                cn++;
                q /= i;
            }
            if (whe[i])
                continue;
            else {
                factor.push_back(i);
                cnt.push_back(cn);
            }
        }
    }
    if (q != 1 && !whe[q]) {
        factor.push_back(q);
        cnt.push_back(1);
    }

    ans.push_back(1);
    for (int i = 0; i < (int)factor.size(); i++) {
        // std::cout << factor[i] << " " << cnt[i] << std::endl;
        xu.push(node{i, 0});
    }

    // int llala = 0;
    while (xu.size()) {
        int x = xu.top().x;
        int y = xu.top().y;
        // llala = std::max(llala, (int)xu.size());
        xu.pop();
        if (ans[ans.size() - 1] != factor[x] * ans[y]) ans.push_back(factor[x] * ans[y]);
        // std::cout << x << " " << y << " " << ans.size() << " " << ans[ans.size() - 1] << std::endl;
        if (mul(factor[x], ans[y + 1], m) && cnt[x]) {
            // mul(factor[x], ans[y + 1], m)
            // if (factor[x] * ans[y + 1] <= ans[ans.size() - 1]) continue;
            xu.push((node){x, y + 1});
            cnt[x]--;
        }
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        // std::cout << ans[i] << " ";
    }
    // std::cout << llala << std::endl;
    std::cout << ans.size() << std::endl;

    return 0;
}
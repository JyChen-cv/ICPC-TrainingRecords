#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define int long long
std::vector<int> factor, ans, xu2;
struct node {
    int x, y;
    bool operator<(const node &t) const {
        return factor[x] * ans[y] > factor[t.x] * ans[t.y];
    }
};
std::priority_queue<node> xu;

bool mul(int a, int b, int c) {
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
    // freopen("/Users/chenjiayou/Desktop/2024寒假训练/2024东北四省赛/okok.in", "r", stdin);
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int q, m, k;
    std::cin >> q >> m >> k;
    int qq = q, kk = k;
    for (int i = 2; i * i <= kk; i++) {  // ?youshim? meishi
        if (k % i == 0) {
            while (k % i == 0) k /= i;
            factor.push_back(i);
        }
    }
    if (k != 1) {
        factor.push_back(k);
    }
    for (int i = 1; i * i <= qq; i++) {
        if (q % i == 0) {
            if (i != 1) xu2.push_back(i);
            if (i * i != q) xu2.push_back(qq / i);
        }
    }
    std::sort(xu2.begin(), xu2.end());

    ans.push_back(1);
    for (int i = 0; i < (int)factor.size(); i++) {
        // std::cout << factor[i] << std::endl;
        if (factor[i] <= m) xu.push(node{i, 0});
    }

    int zhi = 0;
    while (xu.size()) {
        int x = xu.top().x;
        int y = xu.top().y;
        xu.pop();
        int ls = factor[x] * ans[y];
        // std::cout << ls << " " << zhi << " " << xu2[zhi] << std::endl;
        while (zhi < (int)xu2.size() && xu2[zhi] <= ls) {
            ans.push_back(xu2[zhi]);
            zhi++;
        }
        if (ans[ans.size() - 1] != ls) {
            ans.push_back(ls);
        }
        // std::cout << x << " " << y << " " << ans.size() << " " << ans[ans.size() - 1] << std::endl;
        if (mul(factor[x], ans[y + 1], m)) {
            // mul(factor[x], ans[y + 1], m)
            // if (factor[x] * ans[y + 1] <= ans[ans.size() - 1]) continue;
            xu.push((node){x, y + 1});
        }
    }
    while (zhi < (int)xu2.size()) {
        if (xu2[zhi] > m) break;
        ans.push_back(xu2[zhi++]);
    }
    // std::cout << zhi << " " << xu2.size() << std::endl;
    // for (int i = 0; i < (int)ans.size(); i++) {
    //     std::cout << ans[i] << " ";
    // }
    // for (int i = 0; i < (int)xu2.size(); i++) {
    //     std::cout << xu2[i] << " ";
    // }
    // 6618496174290
    std::cout << ans.size() << std::endl;

    return 0;
}
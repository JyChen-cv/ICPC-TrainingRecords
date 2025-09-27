#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

#define int long long
const int N = 5e5;
int mapp[N + 2];
struct node {
    int v;
    node(int x) {
        v = x;
    }
    bool operator<(const node &t) const {
        return v < t.v;
    }
};  // ??? 直接用int也没啥不行的吧
int n, m, sum1, sum2;
std::multiset<node> pre, pos;

int calc() {
    int median = pos.begin()->v;
    return (sum2 - median * (int)pos.size() + median * (int)pre.size() - sum1);
}

inline std::multiset<node>::iterator lst(std::multiset<node> &x) {
    std::multiset<node>::iterator res = x.end();  // 注意pre不能为空
    res--;
    return res;
}
void adj() {
    if (pos.size() >= pre.size() + 2) {
        sum1 += pos.begin()->v;
        sum2 -= pos.begin()->v;
        pre.insert(pos.begin()->v);
        pos.erase(pos.begin());
        return;
    }
    if (pos.size() >= pre.size()) return;
    sum1 -= lst(pre)->v;
    sum2 += lst(pre)->v;
    pos.insert(lst(pre)->v);
    pre.erase(lst(pre));
}

void solve() {
    pre.clear(), pos.clear(), sum1 = 0, sum2 = 0;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
        mapp[i] -= i;
    }

    //   要维护pos始终比pre长
    int ans = 0;
    for (int h = 1, t = 1; h <= n; h++) {
        node ls1(mapp[h]);
        if (mapp[h] >= pos.begin()->v) {
            pos.insert(mapp[h]);
            sum2 += mapp[h];
        } else {
            pre.insert(mapp[h]);
            sum1 += mapp[h];
        }
        adj();
        while (calc() > m && t <= h) {
            node ls2(mapp[t]);
            if ((pos.begin()->v) <= ls2.v) {
                sum2 -= mapp[t];
                pos.erase(pos.find(ls2));
                adj();
            } else {
                sum1 -= mapp[t];
                pre.erase(pre.find(ls2));
                adj();
            }
            t++;
        }
        // std::cout << t << " " << h << " " << pre.size() << " " << pos.size() << " " << pos.begin()->v << " " << calc() << " " << sum1 << " " << sum2 << std::endl;
        ans = std::max(ans, h - t + 1);
    }
    std::cout << ans << std::endl;
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
// 真实比赛不是在打CF，任何考虑到的正确的思路都应该拿纸简单记录一下
// 然后，每次代码简化，思路简化都应该小心，避免自己被绕进去简化错误，最后原本正确的也想不到了

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

typedef long long ll;
const int N = 2e6;
int g[N + 2];
std::string a;
ll f[N + 2];

int get(int x, char v) {
    if (x <= 0) return 0;
    if (a[x] == v)
        return x;
    else
        return get(g[x] - 1, v);
}
int main() {
    freopen("/Users/chenjiayou/Downloads/game/game4.in", "r", stdin);
    int n;
    ll ans = 0;
    std::cin >> n;
    std::cin >> a;
    a = '0' + a;
    for (int i = 1; i <= n; i++) {
        int p = get(i - 1, a[i]);
        g[i] = p;
        if (p > 0) f[i] = f[p - 1] + 1;
        ans += f[i];
        // std::cout << i << ": " << g[i] << " " << f[i] << "\n";
    }
    std::cout << ans << std::endl;
    return 0;
}
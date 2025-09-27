#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
const int mod = 998244353;

void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int mul(int a, int b) {
    return 1LL * a * b % mod;
}

int qpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mul(ans, a);
        b >>= 1;
        a = mul(a, a);
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int B, a, b, c, d;
    cin >> B >> a >> b >> c >> d;
    int p0 = mul(a, qpow(b, mod - 2));
    const int N = 1e5;
    vector<int> p(N + 1);
    vector<bool> is_zero(N + 1, true);
    for (int i = 1; i <= B; i++) {
        p[i] = p0;
        if (a != 0) is_zero[i] = false;
    }
    // std::cout << p0 << std::endl;
    for (int i = B + 1; i <= N; i++) {
        __int128_t up = __int128_t(a) * d + __int128_t(b) * c * (i - B);  // 这里原来可以直接强制转换
        LL down = 1LL * b * d;
        if (up >= down) {
            p[i] = 1;
            is_zero[i] = false;
            break;
        } else {
            p[i] = mul(up % mod, qpow(down % mod, mod - 2));
            if (up != 0) {
                is_zero[i] = false;
            }
        }
    }  // 预处理的过程，但是不知到is_zero是干嘛的

    vector<int> q(N + 1);
    {
        int remain = 1;
        for (int i = 1; i <= N; i++) {
            q[i] = mul(remain, p[i]);
            remain = mul(remain, (mod + 1 - p[i]) % mod);  // 求（1-p）！！！
        }
    }

    vector<int> inv(N + 1);
    for (int i = 1; i <= N; i++) {
        inv[i] = qpow(q[i], mod - 2);  // 是res的逆元
    }

    int n;
    cin >> n;
    vector<int> s(n + 1);
    for (int i = n; i >= 1; i--) {
        cin >> s[i];
        if (is_zero[s[i]]) {  // 如果成功概率为0的话就输出-1
            cout << -1 << '\n';
            return 0;
        }
    }
    vector<int> fail(n + 1);
    for (int i = 2, j = 0; i <= n; i++) {
        while (j and s[j + 1] != s[i]) j = fail[j];
        if (s[j + 1] == s[i]) j++;
        fail[i] = j;
    }  // 求失配数组
    vector<int> pre(n + 1);
    pre[0] = 1;
    for (int i = 1; i <= n; i++) {
        std::cout << q[i] << std::endl;
        pre[i] = mul(pre[i - 1], inv[s[i]]);
        std::cout << pre[i] << std::endl;
    }
    int ans = 0;
    int t = n;
    while (t > 0) {
        std::cout << t << std::endl;
        add(ans, pre[t]);
        t = fail[t];
    }
    cout << ans << '\n';
}
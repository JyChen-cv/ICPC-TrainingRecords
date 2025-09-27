#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
const int mod = 998244353;
const int N = 1e5;
int xl[N + 2], rp[N + 2], f[N + 2], p[N + 2], res[N + 2], sum[N + 2];
int is_zero[N + 2];

int q_pow(int x, int y) {
    if (y == 0) return 1;
    int mid = q_pow(x, y / 2);
    if (y % 2)
        return mid * mid % mod * x % mod;
    else
        return mid * mid % mod;
}

inline int inv(int x) {
    return q_pow(x, mod - 2);
}

inline int mul(int x, int y) {
    return x * y % mod;
}

inline int sub(int x, int y) {
    return ((x - y) % mod + mod) % mod;
}

inline int add(int x, int y) {
    return (x + y) % mod;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    for (int i = 0; i <= N + 1; i++) is_zero[i] = 1;
    int B, a, b, c, d, k;
    std::cin >> B >> a >> b >> c >> d;
    int p0 = mul(a, inv(b));
    for (int i = 1; i <= B; i++) {
        if (a != 0) is_zero[i] = 0;
        p[i] = p0;
    }
    for (int i = B + 1; i <= N; i++) {
        __int128_t up = __int128_t(a) * d + __int128_t(b) * c * (i - B);  // c++20才能这么用
        __int128_t down = __int128_t(b) * d;                              // 这里要谨防越界
        if (up >= down) {
            p[i] = 1;
            is_zero[i] = 0;
            break;  // 这里注意这里因为必定成功所以直接退出了，所以是不可能特别非的，这点也要意识到
        } else {
            p[i] = mul(up % mod, inv(down % mod));
            if (up != 0) is_zero[i] = 0;
        }
    }
    //    std::cout<<" "<<p0<<std::endl;

    int remain = 1;
    for (int i = 1; i <= N; i++) {
        res[i] = mul(remain, p[i]);
        remain = mul(remain, (mod + 1 - p[i]) % mod);
    }
    //    for (int i=1;i<=N;i++) {
    //        res[i]=mul(res[i],inv(sum));
    //    }

    std::cin >> k;
    for (int i = 1; i <= k; i++) {
        std::cin >> xl[i];
        if (is_zero[xl[i]] == 1) {
            //            std::cout<<xl[i]<<std::endl;
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    rp[1] = 0;
    for (int i = 1, j = 0; i < k; i++) {
        while (j > 0 && xl[i + 1] != xl[j + 1]) j = rp[j];
        if (xl[i + 1] == xl[j + 1]) j++;
        rp[i + 1] = j;
    }

    int near[N + 2], tag[N + 2], vis[N + 2];
    memset(near, 0, sizeof(near));
    memset(tag, 0, sizeof(tag));

    std::vector<int> q;
    for (int i = k; i >= 2; i--) {
        if (vis[i]) continue;
        int ls = i;
        while (ls) {
            vis[ls] = 1;
            q.push_back(ls);
            ls = rp[ls - 1] + 1;
            if (ls == 1) {
                q.push_back(ls);
                break;
            }
        }
        // if (q[q.size() - 1] != 1) q.push_back(1);
        // for (int i = 0; i < (int)q.size(); i++) {
        //     std::cout << q[i] << " ";
        // }
        // std::cout << std::endl;
        for (int j = q.size() - 1; j >= 0; j--) {
            near[q[j]] = tag[xl[q[j]]];
            tag[xl[q[j]]] = q[j];
        }
        for (int j = q.size() - 1; j >= 0; j--) {
            tag[xl[q[j]]] = 0;
        }
        q.clear();
    }
    // near[4] = 1;
    // for (int i = 1; i <= k; i++) {
    //     std::cout << near[i] << " ";
    // }
    // std::cout << std::endl;
    for (int i = 1; i <= k; i++) {
        f[i] = add(f[i - 1], 1);
        int ls = rp[i - 1] + 1;
        sum[i] = sub(sum[ls], mul(res[xl[near[i]]], f[near[i]]));
        // while (ls) {
        //     if (xl[ls] != xl[i])
        //         sum[i] = add(sum[i], mul(res[xl[ls]], f[ls]));
        //     if (ls != 1)
        //         ls = rp[ls - 1] + 1;
        //     else
        //         break;
        // }
        f[i] = mul(sub(f[i], sum[i]), inv(res[xl[i]]));
        sum[i] = add(sum[i], mul(f[i], res[xl[i]]));

        //        std::cout<<res[i]<<" "<<ls<<" "<<sum[ls]<<std::endl;
    }
    //    std::cout<<inv(4)<<std::endl;
    std::cout << f[k] << std::endl;

    return 0;
}

/*
1
1 2 0 1
2
1
2

1
1 2 1 2
2
1
1

1
1 2 0 1
12
1 1 2 1 1 3 1 1 2 1 1 4

1
1 2 0 1
6
1 1 2 1 1 3

73
6 1000 6 100
1
91

3
1 3
1 2
10
1 2 1 2 1 2 0 0 0 0

*/

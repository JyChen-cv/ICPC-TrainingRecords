#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

const long long N = 200000;
const long long mod = 1000000007;
long long mapp[N + 2], num[N + 2];

long long main()
{
    long long n, m;
    std::cin >> n >> m;
    for (long long i = 2; i <= n; i++)
    {
        std::cin >> mapp[i];
        mapp[i] += mapp[i - 1];
        mapp[i] %= mod;
    }
    for (long long i = 1; i <= n; i++)
    {
        std::cin >> num[i];
    }

    while (m--)
    {
        long long x, l, r;
        std::cin >> x >> l >> r;
        long long ans = 0;
        for (long long i = l; i <= r; i++)
        {
            ans += (std::abs(mapp[x] - mapp[i]) % mod * num[i] % mod);
            ans %= mod;
        }
        std::cout << ans << std::endl;
    }

    return 0;
}
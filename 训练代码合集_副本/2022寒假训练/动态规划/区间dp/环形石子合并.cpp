#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstring>

const long long N = 1000;
long long mapp[N * 2 + 2], f[N * 2 + 2][N * 2 + 2], sum[N * 2 + 2];

long long main()
{
    long long n, ans2 = 0, ans1 = 0x3f3f3f3f;
    std::cin >> n;
    for (long long i = 1; i <= n; i++)
        std::cin >> mapp[i];
    for (long long i = n + 1; i <= n * 2; i++)
        mapp[i] = mapp[i - n];
    for (long long i = 1; i <= n * 2; i++)
        sum[i] = sum[i - 1] + mapp[i];

    for (long long i = 1; i <= n * 2; i++)
        f[i][i] = 0;
    for (long long len = 2; len <= n; len++)
    {
        for (long long l = 1; l + len - 1 <= n * 2; l++)
        {
            long long r = l + len - 1;
            for (long long k = l; k < r; k++)
            {
                f[l][r] = std::max(f[l][r], f[l][k] + f[k + 1][r] + sum[r] - sum[l - 1]);
            }
            if (len == n)
                ans2 = std::max(ans2, f[l][r]);
        }
    }

    memset(f, 0x3f, sizeof(f));
    for (long long i = 1; i <= n * 2; i++)
        f[i][i] = 0;
    for (long long len = 2; len <= n; len++)
    {
        for (long long l = 1; l + len - 1 <= n * 2; l++)
        {
            long long r = l + len - 1;
            for (long long k = l; k < r; k++)
            {
                f[l][r] = std::min(f[l][r], f[l][k] + f[k + 1][r] + sum[r] - sum[l - 1]);
            }
            if (len == n)
                ans1 = std::min(ans1, f[l][r]);
        }
    }

    std::cout << ans1 << std::endl
              << ans2 << std::endl;

    return 0;
}
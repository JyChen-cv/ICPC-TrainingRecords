#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>

const long long N = 300;
long long head[N + 2], ver[N * 2 + 2], nxt[N * 2 + 2], edge[N * 2 + 2];
long long tot, root, d[N + 2], D, ans = 0x3f3f3f3f, hh[N + 2];
struct group
{
    long long num;
    long long s;
};
std::vector<group> v;

void add(long long x, long long y, long long z)
{
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
    edge[tot] = z;
}

long long dfs(long long x, long long fa)
{
    long long max_son = x;
    for (long long i = head[x]; i; i = nxt[i])
    {
        long long y = ver[i];
        long long z = edge[i];
        if (y == fa)
            continue;
        long long ls = dfs(y, x);
        if (d[y] + z > d[x])
        {
            d[x] = d[y] + z;
            max_son = ls;
        }
    }
    return max_son;
}

void deal1(long long x, long long fa)
{
    for (long long i = head[x]; i; i = nxt[i])
    {
        long long y = ver[i];
        long long z = edge[i];
        if (y == fa)
            continue;
        d[y] = d[x] + z;
        deal1(y, x);
    }
}

bool deal2(long long x, long long fa)
{
    if (d[x] == D)
    {
        return 1;
    }

    for (long long i = head[x]; i; i = nxt[i])
    {
        long long y = ver[i];
        long long z = edge[i];
        if (y == fa)
            continue;
        d[y] = d[x] + z;
        if (deal2(y, x))
        {
            group ls;
            ls.num = y;
            ls.s = d[y];
            v.push_back(ls);
            return 1;
        }
    }
    return 0;
}

void dfs2(long long x)
{
    for (long long i = head[x]; i; i = nxt[i])
    {
        long long y = ver[i];
        long long z = edge[i];
        if (hh[y])
            continue;
        hh[y] = 1;
        d[y] = d[x] + z;
        dfs2(y);
    }
}

long long main()
{
    // freopen("data.in", "r", stdin);

    long long n, m;
    std::cin >> n >> m;
    for (long long i = 1; i < n; i++)
    {
        long long a, b, c;
        std::cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    root = dfs(1, 0);
    memset(d, 0, sizeof(d));
    deal1(root, 0);
    for (long long i = 1; i <= n; i++)
    {
        D = std::max(D, d[i]);
    }
    // std::cout << root << " " << D << std::endl;
    deal2(root, 0);
    group roo;
    roo.num = root;
    roo.s = 0;
    v.push_back(roo);
    long long tag = 0, tag1 = 0;
    while (tag1 < (long long)v.size())
    {
        memset(d, 0, sizeof(d));
        if (std::abs(v[tag1].s - v[tag].s) <= m)
        {
            memset(d, 0, sizeof(d));
            memset(hh, 0, sizeof(hh));
            for (long long i = tag; i <= tag1; i++)
                hh[v[i].num] = 1;
            for (long long i = tag; i <= tag1; i++)
            {
                dfs2(v[i].num);
            }
            long long lls = 0;
            for (long long i = 1; i <= n; i++)
            {
                lls = std::max(lls, d[i]);
            }
            ans = std::min(ans, lls);
            tag1++;
        }
        else
        {
            tag++;
        }
    }
    std::cout << ans << std::endl;

    return 0;
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

#define int long long
const int N = 2e5;
struct group {
    std::vector<std::pair<int, int>> c, k;
    int sz;
} rem[N + 2], ini;
std::queue<int> f;
std::vector<int> tag(N + 2), sum(N + 2);
std::vector<std::pair<int, int>> de[N + 2];
std::map<int, int> qq;
int ans = 0, tot = 0;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        std::cin >> a >> b;
        if (qq[a])
            a = qq[a];
        else {
            qq[a] = ++tot;
            a = qq[a];
        }
        ini.c.push_back({a, b});
    }
    int m;
    std::cin >> m;
    for (int i = 1; i <= m; i++) {
        int k;
        std::cin >> k;
        rem[i].sz = k;
        if (k == 0) {
            f.push(i);
            ans++;
        }
        for (int j = 1; j <= k; j++) {
            int a, b;
            std::cin >> a >> b;
            if (qq[a])
                a = qq[a];
            else {
                qq[a] = ++tot;
                a = qq[a];
            }
            rem[i].c.push_back({a, b});
        }
        std::cin >> k;
        for (int j = 1; j <= k; j++) {
            int a, b;
            std::cin >> a >> b;
            if (qq[a])
                a = qq[a];
            else {
                qq[a] = ++tot;
                a = qq[a];
            }
            rem[i].k.push_back({a, b});
        }
    }

    // 上面都是在离散化
    for (int i = 1; i <= m; i++) {
        for (auto j : rem[i].c) {
            de[j.first].push_back({j.second, i});
        }
    }
    // std::cout << 1 << std::endl;
    for (int i = 1; i <= N; i++) std::sort(de[i].begin(), de[i].end());
    for (auto i : ini.c) {
        int a = i.first, b = i.second;
        sum[a] += b;
        while (tag[a] < (int)de[a].size()) {
            if (de[a][tag[a]].first <= sum[a]) {
                rem[de[a][tag[a]].second].sz--;
                if (!rem[de[a][tag[a]].second].sz) {
                    ans++;
                    f.push(de[a][tag[a]].second);
                    // std::cout << a << " " << de[a][tag[a]].second << std::endl;
                }
                tag[a]++;
            } else
                break;
        }
    }
    // std::cout << f.size() << std::endl;
    while (f.size()) {
        int x = f.front();
        // std::cout << x << std::endl;
        f.pop();
        for (auto i : rem[x].k) {
            int a = i.first, b = i.second;
            sum[a] += b;
            while (tag[a] < (int)de[a].size()) {
                if (de[a][tag[a]].first <= sum[a]) {
                    rem[de[a][tag[a]].second].sz--;
                    if (!rem[de[a][tag[a]].second].sz) {
                        ans++;
                        f.push(de[a][tag[a]].second);
                    }
                    tag[a]++;
                } else
                    break;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
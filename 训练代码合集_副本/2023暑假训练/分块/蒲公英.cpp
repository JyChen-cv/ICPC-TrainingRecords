#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 4e4;
long n, m, mapp[N + 2], tot, l[N + 2], r[N + 2];
int pos[N + 2], z[2402][2402], num[2402][2402];
std::vector<int> cnt[N + 2], dis;

int deal(int x, int ll, int rr) {
    if (x == 0) return 0;
    int ls1 = lower_bound(cnt[x].begin(), cnt[x].end(), ll) - cnt[x].begin();
    int ls2 = lower_bound(cnt[x].begin(), cnt[x].end(), rr) - cnt[x].begin();
    if (ls2 == (int)cnt[x].size()) ls2--;  // 要不就得插入边界
    int ls = ls2 - ls1 + 1;
    if (cnt[x][ls2] > rr) ls--;
    return ls;
}

int ask(int x, int y) {
    int xx = pos[x], yy = pos[y];
    if (xx == yy) {
        int ans = 0, ccnt = 0;
        for (int i = x; i <= y; i++) {
            int ls1 = lower_bound(cnt[mapp[i]].begin(), cnt[mapp[i]].end(), x) - cnt[mapp[i]].begin();
            int ls2 = lower_bound(cnt[mapp[i]].begin(), cnt[mapp[i]].end(), y) - cnt[mapp[i]].begin();
            if (ls2 == (int)cnt[mapp[i]].size()) ls2--;  // 要不就得插入边界
            int ls = ls2 - ls1 + 1;
            if (cnt[mapp[i]][ls2] > y) ls--;
            if (ls > ccnt) {
                ccnt = ls;
                ans = mapp[i];
            } else if (ls == ccnt) {
                if (ans > mapp[i]) ans = mapp[i];
            }
        }
        return ans;
    } else {
        int ans = z[xx + 1][yy - 1];
        int ccnt = deal(ans, x, y);
        for (int i = x; i <= r[xx]; i++) {
            int ls1 = lower_bound(cnt[mapp[i]].begin(), cnt[mapp[i]].end(), x) - cnt[mapp[i]].begin();
            int ls2 = lower_bound(cnt[mapp[i]].begin(), cnt[mapp[i]].end(), y) - cnt[mapp[i]].begin();
            if (ls2 == (int)cnt[mapp[i]].size()) ls2--;  // 要不就得插入边界
            int ls = ls2 - ls1 + 1;
            if (cnt[mapp[i]][ls2] > y) ls--;
            if (ls > ccnt) {
                ccnt = ls;
                ans = mapp[i];
            } else if (ls == ccnt) {
                if (ans > mapp[i]) ans = mapp[i];
            }
        }
        for (int i = l[yy]; i <= y; i++) {
            int ls1 = lower_bound(cnt[mapp[i]].begin(), cnt[mapp[i]].end(), x) - cnt[mapp[i]].begin();
            int ls2 = lower_bound(cnt[mapp[i]].begin(), cnt[mapp[i]].end(), y) - cnt[mapp[i]].begin();
            if (ls2 == (int)cnt[mapp[i]].size()) ls2--;  // 要不就得插入边界
            int ls = ls2 - ls1 + 1;
            if (cnt[mapp[i]][ls2] > y) ls--;
            if (ls > ccnt) {
                ccnt = ls;
                ans = mapp[i];
            } else if (ls == ccnt) {
                if (ans > mapp[i]) ans = mapp[i];
            }
        }
        return ans;
    }
}

int main() {
    freopen("/Users/chenjiayou/Desktop/Cpp/分块/data.in", "r", stdin);

    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
        dis.push_back(mapp[i]);
    }
    std::sort(dis.begin(), dis.end());
    dis.erase(unique(dis.begin(), dis.end()), dis.end());
    for (int i = 1; i <= n; i++) {
        mapp[i] = lower_bound(dis.begin(), dis.end(), mapp[i]) - dis.begin() + 1;
        // std::cout << mapp[i] << std::endl;
        cnt[mapp[i]].push_back(i);
    }
    // for (int i = 1; i <= n; i++) std::cout << cnt[i].size() << std::endl;
    int t = sqrt((double)m * log(n) / log(2));
    for (int i = 1; i <= t; i++) {
        l[i] = (i - 1) * (n / t) + 1;
        r[i] = i * (n / t);
    }
    if (r[t] < n) {
        t++;
        l[t] = r[t - 1] + 1;
        r[t] = n;
    }
    for (int i = 1; i <= t; i++) {
        for (int j = l[i]; j <= r[i]; j++) {
            pos[j] = i;
        }
    }
    // prework
    for (int len = 0; len <= t - 1; len++) {
        for (int ll = 1; ll + len <= t; ll++) {
            int rr = ll + len;
            int tag = 0, ccnt = 0;
            for (int i = l[rr]; i <= r[rr]; i++) {
                int ls1 = lower_bound(cnt[mapp[i]].begin(), cnt[mapp[i]].end(), l[ll]) - cnt[mapp[i]].begin();
                int ls2 = lower_bound(cnt[mapp[i]].begin(), cnt[mapp[i]].end(), r[rr]) - cnt[mapp[i]].begin();
                if (ls2 == (int)cnt[mapp[i]].size()) ls2--;  // 要不就得插入边界
                int ls = ls2 - ls1 + 1;
                if (cnt[mapp[i]][ls2] > r[rr]) ls--;
                // std::cout << ls1 << " " << ls2 << " " << l[ll] << " " << r[rr] << " " << ls << std::endl;
                if (ls > ccnt) {
                    ccnt = ls;
                    tag = mapp[i];
                } else if (ls == ccnt) {
                    if (tag > mapp[i]) tag = mapp[i];
                }
            }
            int lss = deal(z[ll][rr - 1], l[ll], r[rr]);
            if (ccnt > lss) {
                num[ll][rr] = ccnt;
                z[ll][rr] = tag;
            } else if (ccnt == lss) {
                num[ll][rr] = lss;
                if (tag > z[ll][rr - 1])
                    z[ll][rr] = z[ll][rr - 1];
                else
                    z[ll][rr] = tag;
            } else {
                num[ll][rr] = lss;
                z[ll][rr] = z[ll][rr - 1];
            }
            // std::cout << ll << " " << rr << " " << dis[z[ll][rr] - 1] << std::endl;
        }
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        std::cin >> a >> b;
        std::cout << dis[ask(a, b) - 1] << std::endl;
    }
    return 0;
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;
const int N = 1e5;

int ga[N + 2], gb[N + 2], f[N + 2][32][2], t;
ll mapp[N + 2], x0, da[N + 2][32][2], db[N + 2][32][2];
struct group {
    ll zhi;
    int hao;
    bool operator<(const group &t) const {
        if (zhi < t.zhi)
            return 1;
        else if (zhi == t.zhi)
            return mapp[hao] < mapp[t.hao];
        else
            return 0;
    }
};
std::set<group> que;

void calc(int s, ll x, ll &la, ll &lb) {
    int p = s;
    for (int i = t; i >= 0; i--) {
        if (!f[i][p][0])
            continue;
        else if (la + lb + da[i][p][0] + db[i][p][0] <= x) {
            la += da[i][p][0];
            lb += db[i][p][0];
            p = f[i][p][0];
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    t = log(n) / log(2) + 1;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &mapp[i]);
    }
    scanf("%lld", &x0);
    que.insert(group{mapp[n], n});
    // end()是空
    for (int i = n - 1; i >= 1; i--) {
        std::set<group>::iterator l = que.lower_bound(group{mapp[i], i});
        std::vector<group> mm;
        if (l != que.end()) {
            mm.push_back(group{(l->zhi) - mapp[i], l->hao});
            l++;
            if (l != que.end()) mm.push_back(group{(l->zhi) - mapp[i], l->hao});
            l--;
        }
        if (l != que.begin()) {
            l--;
            mm.push_back(group{mapp[i] - (l->zhi), l->hao});
            if (l != que.begin()) {
                l--;
                mm.push_back(group{mapp[i] - (l->zhi), l->hao});
            }
        }

        std::sort(mm.begin(), mm.end());
        gb[i] = mm[0].hao;
        if (mm.size() > 1) ga[i] = mm[1].hao;
        que.insert(group{mapp[i], i});
    }
    // for (int i = 1; i <= n; i++) {
    //     std::cout << ga[i] << "*" << gb[i] << std::endl;
    // }

    for (int i = 1; i <= n; i++) {
        f[0][i][0] = ga[i];
        f[0][i][1] = gb[i];
    }
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k <= 1; k++) {
                if (i == 1) {
                    f[1][j][k] = f[0][f[0][j][k]][1 - k];
                    // std::cout << j << " " << k << " " << f[1][j][k] << std::endl;
                } else
                    f[i][j][k] = f[i - 1][f[i - 1][j][k]][k];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        da[0][i][0] = std::abs(mapp[i] - mapp[ga[i]]);
        da[0][i][1] = 0;
        db[0][i][0] = 0;
        db[0][i][1] = std::abs(mapp[i] - mapp[gb[i]]);
    }
    for (int i = 1; i <= t; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k <= 1; k++) {
                if (i == 1) {
                    da[1][j][k] = da[0][j][k] + da[0][f[0][j][k]][1 - k];
                    db[1][j][k] = db[0][j][k] + db[0][f[0][j][k]][1 - k];
                } else {
                    da[i][j][k] = da[i - 1][j][k] + da[i - 1][f[i - 1][j][k]][k];
                    db[i][j][k] = db[i - 1][j][k] + db[i - 1][f[i - 1][j][k]][k];
                }
            }
        }
    }

    double mmin = 0x7f7f7f7f;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ll la = 0, lb = 0;
        calc(i, x0, la, lb);
        // std::cout << i << " " << x0 << " " << la << " " << lb << std::endl;
        double bi = 0;
        if (!lb) {
            bi = 0x7f7f7f7f;
        } else
            bi = (double)la / lb;
        if (bi < mmin) {
            mmin = bi;
            ans = i;
        } else if (bi == mmin) {
            if (mapp[ans] < mapp[i]) ans = i;
        }
    }
    std::cout << ans << std::endl;
    int m;
    std::cin >> m;
    for (int i = 1; i <= m; i++) {
        int si;
        ll xi, la = 0, lb = 0;
        scanf("%d%lld", &si, &xi);
        calc(si, xi, la, lb);
        printf("%lld %lld\n", la, lb);
    }

    return 0;
}

// 这道题目的精妙之处在于看似一人一天是不能叠加的，但是结果却是可以叠加的
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1e4;
int mapp[N + 2], s[N + 2], f[N + 2], anss;
std::vector<int> ans;

void dfs(int d, int x, int t) {
    if (t > anss) return;
    if (d == 0) {
        anss = std::min(anss, t);
        return;
    }
    for (int i = x; i >= 0; i--) {
        if (d >= ans[i])
            dfs(d - ans[i], i, t + 1);
    }
}
int main() {
    std::string p;
    std::cin >> p;
    int n = p.size();
    for (int i = 0; i < (int)p.size(); i++) {
        if (p[i] == '0')
            mapp[i + 1] = 0;
        else
            mapp[i + 1] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (mapp[i])
            s[i] = s[i - 1] + 1;
        else
            s[i] = s[i - 1];
    }

    int num10 = 0, num01 = 0;
    for (int i = 1; i <= n; i++) {
        if (mapp[i]) {
            num01 += i - 1 - s[i - 1];
        } else
            num10 += s[i];
    }
    std::cout << num10 << " " << num01 << std::endl;
    if (num10 == num01)
        std::cout << 0 << std::endl;
    else {
        int d = 0;
        ans.clear();
        if (num10 > num01) {
            d = (num10 - num01) / 2;
            for (int i = 1; i <= n; i++) {
                if (mapp[i]) continue;
                for (int j = 1; j < i; j++) {
                    if (!mapp[j]) continue;
                    // std::cout << i << " " << j << std::endl;
                    ans.push_back(i - j);
                }
            }
        } else {
            d = (num01 - num10) / 2;
            for (int i = 1; i <= n; i++) {
                if (mapp[i]) continue;
                for (int j = i + 1; j <= n; j++) {
                    if (!mapp[j]) continue;
                    ans.push_back(j - i);
                }
            }
        }
        std::sort(ans.begin(), ans.end());
        for (int i = 0; i < (int)ans.size(); i++) std::cout << ans[i] << " ";
        std::cout << std::endl;
        anss = 1e9;
        // dfs(d, (int)ans.size() - 1, 0);
        for (int i = 1; i <= d; i++) f[i] = 1e9;
        for (int i = 1; i <= d; i++) {
            for (int j = 0; j < (int)ans.size(); j++) {
                if (ans[j] > i) break;
                f[i] = std::min(f[i], f[i - ans[j]] + 1);
            }
        }
        std::cout << f[d] << std::endl;
    }
    return 0;
}
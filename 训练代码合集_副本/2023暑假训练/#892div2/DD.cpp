#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

struct group {
    int first, second;
    bool operator<(const int &t) const {
        return second < t;
    }
    bool operator<(const group &t) const {
        if (first < t.first)
            return 1;
        else if (first == t.first)
            return second < t.second;
        else
            return 0;
    }
};
std::vector<group> mapp, ans;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        mapp.clear();
        ans.clear();
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            mapp.push_back((group){a, d});
        }
        std::sort(mapp.begin(), mapp.end());
        ans.push_back(mapp[0]);
        for (int i = 1; i < (int)mapp.size(); i++) {
            group up = ans[(int)ans.size() - 1];
            if (mapp[i].first > up.second)
                ans.push_back(mapp[i]);
            else {
                up.second = std::max(up.second, mapp[i].second);
                ans.pop_back();
                ans.push_back(up);
            }
        }

        int m;
        std::cin >> m;
        for (int i = 1; i <= m; i++) {
            int a;
            scanf("%d", &a);
            int s = std::lower_bound(ans.begin(), ans.end(), a) - ans.begin();
            if (s < (int)ans.size()) {
                if (a >= ans[s].first && a <= ans[s].second)
                    std::cout << ans[s].second << " ";
                else
                    std::cout << a << " ";
            } else
                std::cout << a << " ";
        }
    }
}
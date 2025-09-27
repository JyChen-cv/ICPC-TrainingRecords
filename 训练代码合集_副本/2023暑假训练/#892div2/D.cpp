#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

struct group {
    int x1, x2, a1, a2;
    bool operator<(const group &t) const {
        if (x1 > t.x1)
            return 1;
        else if (x1 == t.x1)
            return x2 > t.x2;
        else
            return 0;
    }
    bool operator<(const int &t) const {
        return x2 < t;
    }
};
std::priority_queue<group> mapp;
std::vector<group> ans;

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        ans.clear();

        int n;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            int x1, x2, a1, a2;
            scanf("%d%d%d%d", &x1, &x2, &a1, &a2);
            mapp.push((group){x1, x2, a1, a2});
        }
        ans.push_back(mapp.top());
        mapp.pop();
        while (mapp.size()) {
            group up = ans[ans.size() - 1];
            group point = mapp.top();
            mapp.pop();
            // std::cout << ans.size() << std::endl;
            if (up.x2 < point.x1) {
                ans.push_back(point);
                continue;
            }
            if (up.a1 > point.x2) {
                continue;
            }
            if (up.a2 < point.x1) {
                ans.pop_back();
                up.x2 = point.x1 - 1;
                ans.push_back(up);
                ans.push_back(point);
                continue;
            }
            ans.pop_back();
            up.x2 = std::max(up.x2, point.x2);
            if (up.a2 >= point.a1) {
                up.a2 = std::max(up.a2, point.a2);
                up.a1 = std::min(up.a1, point.a1);
            } else {
                if (up.a2 < point.a2) {
                    up.a1 = point.a1;
                    up.a2 = point.a2;
                } else if (up.a2 == point.a2) {
                    up.a1 = std::min(up.a1, point.a1);
                }
            }
            ans.push_back(up);
        }
        // for (int i = 0; i < (int)ans.size(); i++) std::cout << ans[i].x1 << " " << ans[i].x2 << std::endl;
        int m;
        std::cin >> m;
        for (int i = 1; i <= m; i++) {
            int a;
            scanf("%d", &a);
            int s = std::lower_bound(ans.begin(), ans.end(), a) - ans.begin();
            if (s < (int)ans.size()) {
                if (a >= ans[s].x1 && a <= ans[s].x2)
                    std::cout << std::max(ans[s].a2, a) << " ";
                else
                    std::cout << a << " ";
            } else
                std::cout << a << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
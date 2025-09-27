#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
struct que {
    int ft, t, at1, at2;
};
map<string, map<string, que>> q;
struct group {
    int pan, num;
};
map<string, group> ans;
struct group2 {
    string nam;
    int pan, num;
    bool operator<(const group2& k) const {
        if (num > k.num)
            return 1;
        else if (num == k.num)
            return pan < k.pan;
        else
            return 0;
    }
};

void solve() {
    q.clear();
    int n;
    std::cin >> n;
    int award;
    if (n % 10)
        award = n / 10 + 1;
    else
        award = n / 10;
    award = min(award, 35);

    for (int i = 1; i <= n; i++) {
        std::string a, b, d;
        int c;
        std::cin >> a >> b >> c >> d;
        if (d == "accepted") {
            if (q[a][b].ft == 0) {
                q[a][b].at1 = q[a][b].ft = c;
                ans[a].pan += c;
                ans[a].num++;
            } else {
                if (!q[a][b].at1) {
                    q[a][b].at1 = c;
                    ans[a].pan += c + (q[a][b].t * 20);
                    ans[a].num++;
                } else {
                    if (!q[a][b].at2) {
                        q[a][b].at2 = c;
                    }
                }
            }
        } else {
            if (q[a][b].at2)
                continue;
            else {
                q[a][b].t++;
            }
        }
    }
    std::vector<group2> res;
    for (auto i : ans) {
        res.push_back({i.first, i.second.pan, i.second.num});
    }
    std::sort(res.begin(), res.end());
    for (int i = 0; i < award; i++) {
        std::cout << res[i].nam << std::endl;
    }
    // for (int i = award; i < (int)res.size(); i++) {
    //     if (deal(i))
    // }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
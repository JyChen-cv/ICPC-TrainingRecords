#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

#define int long long
void solve() {
    int n, ans = 0;
    std::string a;
    std::cin >> n >> a;
    std::vector<int> le;
    std::vector<std::pair<int, int> > ri;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] == '_') {
            if (le.size()) {
                ri.push_back({i, le[le.size() - 1]});
                ans += i - le[le.size() - 1];
                le.pop_back();
            } else
                le.push_back(i);
        } else if (a[i] == '(') {
            le.push_back(i);
        } else {
            if (le.size()) {
                ans += i - le[le.size() - 1];
                le.pop_back();
            } else {
                std::pair<int, int> ls = ri[ri.size() - 1];
                ri.pop_back();
                ans -= ls.first - ls.second;
                le.push_back(ls.second);
                ans += i - ls.first;
            }
        }
        // std::cout << le.size() << " " << ri.size() << std::endl;
    }
    std::cout << ans << std::endl;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    int times = 1;
    std::cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}

/*
1
10
___))((___

_ ( _ ( _ ) _ )

( ( ) ( ( ) ) )
( ( ) ( ) ) ( )
  ^   ^   ^   ^
*/
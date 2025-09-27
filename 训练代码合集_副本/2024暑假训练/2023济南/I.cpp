#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1e4;
int mapp[N + 2];
void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
    }
    int i = 1;
    std::vector<std::pair<int, int>> ans;
    while (i <= n) {
        if (mapp[i] != i) {
            for (int j = n; j > i; j--) {
                if (mapp[j] < mapp[i]) {
                    std::sort(mapp + i, mapp + j + 1);
                    ans.push_back(std::make_pair(i, j));
                }
            }
        }
        i++;
    }
    std::cout << ans.size() << std::endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        std::cout << ans[i].first << " " << ans[i].second << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
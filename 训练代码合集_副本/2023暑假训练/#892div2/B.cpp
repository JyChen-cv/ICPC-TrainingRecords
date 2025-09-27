#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::vector<std::pair<int, int> > m;
        std::cin >> n;
        for (int i = 1; i <= n; i++) {
            int num, min1 = 1e9 + 1, min2 = 1e9 + 1;
            std::cin >> num;
            for (int j = 1; j <= num; j++) {
                int a;
                std::cin >> a;
                if (a <= min1) {
                    min2 = min1;
                    min1 = a;
                } else if (a < min2) {
                    min2 = a;
                }
                // std::cout << min1 << " " << min2 << std::endl;
            }
            m.push_back(std::make_pair(min2, min1));
        }
        std::sort(m.begin(), m.end());
        long long ans = 0;
        int mmin = 1e9 + 1;
        for (int i = (int)m.size() - 1; i >= 1; i--) {
            // std::cout << m[i].first << " " << m[i].second << std::endl;
            ans += m[i].first;
            mmin = std::min(mmin, m[i].second);
        }

        std::cout << ans + std::min(mmin, m[0].second) << std::endl;
    }
    return 0;
}
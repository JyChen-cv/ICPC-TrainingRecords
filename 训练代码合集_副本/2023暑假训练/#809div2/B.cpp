#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> mapp[n + 1];
        for (int i = 1; i <= n; i++) {
            int a;
            std::cin >> a;
            if (!mapp[a].size())
                mapp[a].push_back(i);
            else if (!((i - mapp[a][mapp[a].size() - 1] - 1) % 2))
                mapp[a].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            std::cout << mapp[i].size() << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
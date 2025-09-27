#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::priority_queue<std::pair<int, int> > mapp;
        int n, m;
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            int a;
            std::cin >> a;
            mapp.push(std::make_pair(a, -i));
        }
        while (mapp.size()) {
            std::pair<int, int> x = mapp.top();
            mapp.pop();
            if (x.first <= m)
                std::cout << -x.second << " ";
            else {
                x.first %= m;
                if (!x.first) x.first = m;
                mapp.push(x);
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
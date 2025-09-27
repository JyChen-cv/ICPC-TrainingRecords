#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>

const int N = 2e5;
int ma[N + 2], s[N + 2], k[N + 2];

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::map<std::pair<int, int>, int> mapp;
        int n, m;
        std::cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            ma[i] = s[i] = k[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            char c;
            std::cin >> c;
            if (c == '0')
                ma[i] = 0;
            else
                ma[i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (ma[i]) s[i] = s[i - 1] + 1;
            // std::cout << s[i] << " ";
        }
        // std::cout << std::endl;
        for (int i = n; i >= 1; i--) {
            if (!ma[i]) k[i] = k[i + 1] + 1;
            // std::cout << k[i] << " ";
        }
        // std::cout << std::endl;
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            int a, b;
            std::cin >> a >> b;
            a = a + k[a];
            b = b - s[b];
            if (a > b) {
                if (mapp[std::make_pair(0, 0)])
                    continue;
                else {
                    cnt++;
                    mapp[std::make_pair(0, 0)] = 1;
                }
            } else {
                if (mapp[std::make_pair(a, b)])
                    continue;
                else {
                    cnt++;
                    mapp[std::make_pair(a, b)] = 1;
                }
            }
        }
        std::cout << cnt << std::endl;
    }
    return 0;
}
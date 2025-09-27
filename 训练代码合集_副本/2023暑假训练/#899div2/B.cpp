#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

const int N = 100;
int mapp[N + 2];
std::set<int> s[N + 2];

int dd(int x, int y, std::string d) {
    int pow = 1;
    int ans = 0;
    for (int i = y; i >= x; i--) {
        ans += (d[i] - '0') * pow;
        pow *= 10;
    }
    return ans;
}

void deal(int x, std::string d)  // 关于数组的传递
{
    for (int i = 0; i < (int)d.size(); i++) {
        if (d[i] <= '9' && d[i] >= '0') {
            int p = i + 1;
            while (d[p] <= '9' && d[p] >= '0') {
                p++;
            }
            --p;
            s[x].insert(dd(i, p, d));
            std::cout << dd(i, p, d) << " ";
            i = p;
        }
    }
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::set<int> l;
        for (int i = 0; i <= 100; i++) s[i].clear();

        int n;
        std::cin >> n;
        // getchar();
        for (int i = 1; i <= n; i++) {
            // std::string d;
            // getline(std::cin, d);
            // deal(i, d);
            int a;
            std::cin >> a;
            for (int j = 1; j <= a; j++) {
                int b;
                std::cin >> b;
                s[i].insert(b);
                l.insert(b);
            }
        }

        int ans = 0;
        for (int i = 1; i <= 50; i++) {
            if (l.find(i) == l.end()) continue;
            std::set<int> ls;
            for (int j = 1; j <= n; j++) {
                if (s[j].find(i) != s[j].end()) continue;
                for (auto k : s[j]) {
                    ls.insert(k);
                }
            }
            // std::cout << i;
            ans = std::max(ans, (int)ls.size());
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
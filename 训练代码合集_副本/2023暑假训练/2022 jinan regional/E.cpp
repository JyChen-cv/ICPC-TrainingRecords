#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 100;
int tag[N + 2], t;
std::vector<int> l;
void dfs(int x, int y, int p) {
    if (t) return;
    if (p == x) {
        std::vector<int> s;
        for (int i = 0; i < x; i++) {
            if (i == 0)
                s.push_back(l[0]);
            else
                s.push_back(s[s.size() - 1] + l[i]);
        }
        int res = 0;
        for (int i = 0; i + y - 1 < x; i++) {
            int j = i + y - 1;
            int ls = s[j] - (i ? s[i - 1] : 0);
            if (!res)
                res = ls % 2 + 1;
            else if (res != ls % 2 + 1)
                return;
        }
        // std::cout << x << " " << y << std::endl;
        // for (int i = 0; i < x; i++) {
        //     std::cout << l[i] << " ";
        // }
        // std::cout << std::endl;
        t = 1;
        return;
    }
    for (int i = 1; i <= x; i++) {
        if (!tag[i]) {
            l.push_back(i);
            tag[i] = 1;
            dfs(x, y, p + 1);
            tag[i] = 0;
            l.pop_back();
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            t = 0;
            dfs(i, j, 0);
            if (t == 1)
                std::cout << 1 << " ";
            else
                std::cout << 0 << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
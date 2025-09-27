#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1e5;
const int mod = 1e9 - 3;
#define a first
#define b second
std::pair<int, int> mapp[N + 2];
std::vector<int> li;
int tr[N + 2], n;

int lowbit(int x) {
    return x & (-x);
}

void insert(int p, int x) {
    while (p <= n) {
        tr[p] += x;
        p += lowbit(p);
    }
}

int query(int p) {
    int res = 0;
    while (p) {
        res += tr[p];
        p -= lowbit(p);
    }
    return res;
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i].a;
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i].b;
        li.push_back(mapp[i].b);
    }
    std::sort(li.begin(), li.end());
    li.erase(unique(li.begin(), li.end()), li.end());

    std::sort(mapp + 1, mapp + n + 1);
    for (int i = 1; i <= n; i++) {
        // std::cout << mapp[i].a << " " << mapp[i].b << std::endl;
    }
    int cnt = 0;
    for (int i = n; i >= 1; i--) {
        mapp[i].b = std::lower_bound(li.begin(), li.end(), mapp[i].b) - li.begin() + 1;
    }
    for (int i = n; i >= 1; i--) {
        cnt += query(mapp[i].b - 1);
        cnt %= mod;
        insert(mapp[i].b, 1);
        // std::cout << mapp[i].b << " " << cnt << std::endl;
    }
    std::cout << cnt << std::endl;
    return 0;
}
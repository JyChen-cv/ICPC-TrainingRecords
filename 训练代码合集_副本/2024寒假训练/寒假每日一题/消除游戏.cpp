#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 1e6;
char c[N + 2];
int l[N + 2], r[N + 2];
std::vector<int> pos;
bool v[N + 2];

void remove(int x) {
    r[l[x]] = r[x];
    l[r[x]] = l[x];
}

void check(int x) {
    if (c[l[x]] == '#' || c[r[x]] == '#') return;
    if (c[l[x]] == c[x] && c[x] != c[r[x]]) pos.push_back(x), pos.push_back(r[x]);
    if (c[l[x]] != c[x] && c[x] == c[r[x]]) pos.push_back(l[x]), pos.push_back(x);
}

int main() {
    scanf("%s", c + 1);
    int n = strlen(c + 1);

    c[0] = c[n + 1] = '#';
    for (int i = 1; i <= n; i++) {
        l[i] = i - 1;
        r[i] = i + 1;
    }
    for (int i = 1; i <= n; i++) check(i);

    int i = 0;
    while (i < (int)pos.size()) {
        std::vector<int> p;
        for (; i < (int)pos.size(); i++) {
            int j = pos[i];
            if (v[j]) continue;
            v[j] = 1;
            remove(j);
            p.push_back(l[j]), p.push_back(r[j]);
        }
        for (int j = 0; j < (int)p.size(); j++) {
            if (v[p[j]]) continue;
            check(p[j]);
        }
    }

    bool tag = 1;
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            std::cout << c[i];
            tag = 0;
        }
    }
    if (tag) std::cout << "EMPTY";
    std::cout << std::endl;
    return 0;
}
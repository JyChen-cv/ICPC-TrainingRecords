#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

const int N = 6e5;
int root[N + 2], latest[N * 25 + 2], total;  // total点总数，tot边总数
int trie[N * 25 + 2][2], s[N + 2];

void insert(int i, int k, int p, int q) {
    if (k < 0) {
        latest[p] = i;
        return;
    }
    int c = (s[i] >> k) & 1;
    if (q) {
        trie[p][c ^ 1] = trie[q][c ^ 1];
    }
    trie[p][c] = ++total;
    insert(i, k - 1, trie[p][c], trie[q][c]);
    latest[p] = std::max(latest[trie[p][0]], latest[trie[p][1]]);
}

int ask(int a, int p, int d, int k) {
    if (k < 0) return s[latest[p]] ^ d;
    int c = (d >> k) & 1;
    if (trie[p][c ^ 1] && latest[trie[p][c ^ 1]] >= a)
        return ask(a, trie[p][c ^ 1], d, k - 1);
    else
        return ask(a, trie[p][c], d, k - 1);
}

int main() {
    latest[0] = -1;
    root[0] = ++total;
    insert(0, 24, root[0], 0);
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a;
        std::cin >> a;
        s[i] = s[i - 1] ^ a;
        // std::cout << s[i] << " ";
        root[i] = ++total;
        insert(i, 24, root[i], root[i - 1]);
    }
    for (int i = 1; i <= m; i++) {
        char c;
        std::cin >> c;
        if (c == 'A') {
            int a;
            std::cin >> a;
            s[n] = s[++n - 1] ^ a;
            root[n] = ++total;
            insert(n, 24, root[n], root[n - 1]);
        } else {
            int a, b, d;
            std::cin >> a >> b >> d;
            std::cout << ask(a - 1, root[b - 1], d ^ s[n], 24) << std::endl;
        }
    }
    return 0;
}
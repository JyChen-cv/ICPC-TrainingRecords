#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

const int N = 6e5, M = N * 25;
int n, m, mapp[N + 2], s[N + 2], latest[M + 2], root[N + 2], trie[M + 2][2],
    tot;

// 这里为了方便更新latest，进行了递归插入。在普通trie中可以直接用循环去跳
// 当前插入的位置是s[i]的第k位,p表示在上一个跟节点中与q（当前跟节点）相同的层的点点序号
void insert(int i, int k, int p, int q) {
    if (k < 0) {
        // 表示插入结束
        latest[q] = i;
        return;
    }
    int c = (s[i] >> k) & 1;
    // 查询s[i]第k位是0还是1
    // 通过观察可持久化trie的图与目的即可得到如下两条规律
    if (p) {
        trie[q][c ^ 1] = trie[p][c ^ 1];
        // 1.对于新根下与原树不相同的部分直接复制即可
    }
    trie[q][c] = ++tot;  // 2.对于新根下与原树相同的部分要建立新节点
    insert(i, k - 1, trie[p][c], trie[q][c]);
    // 对于新根下与原树相同的部分继续递归处理，不同部分复制结束后已经不用再去处理了
    latest[q] = std::max(latest[trie[q][0]], latest[trie[q][1]]);
}

int ask(int now, int val, int k, int limit) {
    if (k < 0) {
        return val ^ s[latest[now]];
    }
    int c = (val >> k) & 1;
    if (latest[trie[now][c ^ 1]] >= limit) {
        // 肯定满足latest[trie[now][c ^ 1]] != -1
        now = trie[now][c ^ 1];
    } else
        now = trie[now][c];
    return ask(now, val, k - 1, limit);
}

int main() {
    latest[0] = -1;
    // 在trie中，节点序号为0表示空，表示没有这条边，所以标记为-1
    root[0] = ++tot;
    insert(0, 24, 0, root[0]);  // s[0]也是合法前缀和,需要先插入

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
        s[i] = s[i - 1] ^ mapp[i];
        root[i] = ++tot;
        insert(i, 24, root[i - 1], root[i]);
    }
    while (m--) {
        char c;
        std::cin >> c;
        if (c == 'A') {
            int a;
            std::cin >> a;
            mapp[++n] = a;
            s[n] = s[n - 1] ^ a;
            root[n] = ++tot;
            insert(n, 24, root[n - 1], root[n]);
        } else {
            int l, r, x;
            std::cin >> l >> r >> x;
            // 本体使用了前缀和进行计算，所以范围转变为[l-1,r-1];
            std::cout << ask(root[r - 1], x ^ s[n], 24, l - 1) << std::endl;
        }
    }
    return 0;
}
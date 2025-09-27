#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

const int N = 2e6, M = 1e5;
struct node {
    // 这里存的是左右儿子的编号，不是区间的左右端点
    int lc, rc;
    int cnt;
} setr[N + 2];
int n, m, mapp[M + 2], tot, root[M + 2];
std::vector<int> dis;

// 这道题目不会用到
int build(int l, int r) {
    // 这里建立的线段树由于可持久化操作，所以并不满足二叉树的子父逻辑
    // 采用与trie相似的迭代方式
    int p = ++tot;
    if (l == r) {
        // 不用去更新lc和rc，默认为0即可，表示没有子节点
        setr[p].cnt = 1;
        return p;
    } else {
        int mid = (l + r) >> 1;
        setr[p] = (node){build(l, mid), build(mid + 1, r), setr[setr[p].lc].cnt + setr[setr[p].rc].cnt};
        return p;
    }
}

int ask(int p, int q, int l, int r, int k) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    int lcnt = setr[setr[p].lc].cnt - setr[setr[q].lc].cnt;
    // cnt表示的是当前节点所包含的数字个数，这里作差是同一层但是不同版本的作差，用来求出来题目要求的[l,r]内的数字个数
    if (k <= lcnt)
        return ask(setr[p].lc, setr[q].lc, l, mid, k);
    else
        return ask(setr[p].rc, setr[q].rc, mid + 1, r, k - lcnt);
}

// 这题由于是在值域上开可持久化线段树，所以插入的所有值全都是1，不需要最后一个参数
int insert(int now, int l, int r, int x) {
    int p = ++tot;
    setr[p] = setr[now];
    if (l == r) {
        setr[p].cnt++;
        return p;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        setr[p].lc = insert(setr[now].lc, l, mid, x);
    else
        setr[p].rc = insert(setr[now].rc, mid + 1, r, x);
    setr[p].cnt = setr[setr[p].lc].cnt + setr[setr[p].rc].cnt;
    return p;
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> mapp[i];
        dis.push_back(mapp[i]);
    }
    std::sort(dis.begin(), dis.end());
    dis.erase(unique(dis.begin(), dis.end()), dis.end());
    // root[0] = ++tot;
    // insert(0, 1, (int)dis.size(), 0);
    for (int i = 1; i <= n; i++) {
        mapp[i] = std::lower_bound(dis.begin(), dis.end(), mapp[i]) - dis.begin() + 1;
        root[i] = tot + 1;
        insert(root[i - 1], 1, (int)dis.size(), mapp[i]);
    }
    for (int i = 1; i <= m; i++) {
        int a, b, x;
        std::cin >> a >> b >> x;
        std::cout << dis[ask(root[b], root[a - 1], 1, (int)dis.size(), x) - 1] << std::endl;
    }
    return 0;
}
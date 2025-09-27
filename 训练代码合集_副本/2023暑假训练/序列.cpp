#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long ll;
const ll inf = 1e15;
const int N = 1e5;
int mapp[N + 2];
struct group {
    int l, r;
    int s;  // 这里必须是32位
    ll sum, lm, rm, mm;
    group() {
        l = r = 0;
        s = -1;
        sum = 0;
        lm = rm = mm = 0;
    }
} node[N + 2];
int n, m, len, k;

void qiu(group &x, int l, int r)  // 计算一个区间的所有值
{
    x.s = -1;
    x.sum = 0;
    x.lm = x.rm = x.mm = -inf;
    ll lls = -inf;
    for (int i = l; i <= r; i++) {
        x.s &= mapp[i];
        x.sum += mapp[i];
        x.lm = std::max(x.lm, x.sum);
        lls = std::max(x.mm + mapp[i], (long long)mapp[i]);
        x.mm = std::max(lls, x.mm);
    }
    ll ls = 0;
    for (int i = r; i >= l; i--) {
        ls += mapp[i];
        x.rm = std::max(x.rm, ls);
    }
}

group deal(group x, group y) {  // 合并两个区间
    group res;
    res.lm = std::max(x.lm, x.sum + y.lm);
    res.rm = std::max(y.rm, y.sum + x.rm);
    res.sum = x.sum + y.sum;
    res.mm = std::max(x.rm + y.lm, std::max(x.mm, y.mm));
    return res;
}

ll query(int x, int y) {
    group res;
    // std::cout << res.lm << " " << res.rm << " " << res.mm << std::endl;
    for (int i = 1; i <= k; i++) {
        int l = node[i].l, r = node[i].r;
        if (x <= l && r <= y)
            res = deal(res, node[i]);
        else if (l <= x && y <= r) {
            group ls;
            qiu(ls, x, y);
            res = deal(res, ls);
        } else {
            if (x <= r && x >= l) {
                group ls;
                qiu(ls, x, r);
                res = deal(res, ls);
            } else if (y <= r && y >= l) {
                group ls;
                qiu(ls, l, y);
                res = deal(res, ls);
                // break;
            }
        }
        // std::cout << x << " " << y << " " << l << " " << r << std::endl;
        // std::cout << res.lm << " " << res.rm << " " << res.mm << std::endl;
    }
    return res.mm;
}

void modify(int x, int y, int p) {
    for (int i = 1; i <= k; i++) {
        int l = node[i].l, r = node[i].r;
        // std::cout << x << " " << y << " " << l << " " << r << std::endl;
        if ((node[i].s | p) == node[i].s)
            continue;
        if (x <= l && r <= y) {
            for (int j = l; j <= r; j++) {
                mapp[j] |= p;
            }
            qiu(node[i], l, r);
        } else if (l <= x && y <= r) {
            for (int j = x; j <= y; j++) {
                mapp[j] |= p;
            }
            qiu(node[i], l, r);
        } else {
            if (x <= r && x >= l) {
                for (int j = x; j <= r; j++) {
                    mapp[j] |= p;
                }
                qiu(node[i], l, r);
            } else if (y <= r && y >= l) {
                for (int j = l; j <= y; j++) {
                    mapp[j] |= p;
                }
                qiu(node[i], l, r);
                break;
            }
        }
    }
}

int main() {
    // freopen("/Users/chenjiayou/Desktop/Cpp/students.txt", "r", stdin);
    // freopen("/Users/chenjiayou/Desktop/Cpp/student.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", mapp + i);
    }
    len = sqrt(n);
    k = n / len;
    if (n % len) k++;
    for (int i = 1; i <= k; i++) {
        int l = (i - 1) * len + 1, r = std::min(i * len, n);
        node[i].l = l, node[i].r = r;
        qiu(node[i], l, r);
        // std::cout << l << " " << r << " " << node[i].lm << " " << node[i].rm << " " << node[i].mm << std::endl;
    }

    for (int i = 1; i <= m; i++) {
        int op, l, r;
        int p;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1) {
            // for (int j = 1; j <= n; j++) std::cout << mapp[j] << " ";
            // std::cout << std::endl;
            printf("%lld\n", query(l, r));
        } else {
            scanf("%d", &p);
            modify(l, r, p);
        }
    }
    return 0;
}

/*
15 7
512 -65 33554432 32 8194 13 16 2 67108872 131072 -8192 8194 16 2048 4096
2 1 7 671367424
2 13 13 335579137
2 2 13 5376
2 5 6 8392768
2 2 14 201335872
2 1 14 0
1 4 9
*/

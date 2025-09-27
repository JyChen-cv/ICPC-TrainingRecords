#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define int long long
const int N = 10;
int map_a[N + 2], map_b[N + 2], atk_a[N + 2], atk_b[N + 2];
long long gcd(long long x, long long y) {
    return y ? gcd(y, x % y) : x;
}

void add(long long &fx, long long &x, long long fy, long long y) {
    long long fres = fx * y + fy * x;
    long long res = x * y;
    long long g = gcd(fres, res);
    fres /= g;
    res /= g;
    fx = fres;
    x = res;
}

double fa = 0, fb = 0, fc = 0;
int n, m;
void dfs(int x, int y, int now, double al_a, double al_b, double gl) {
    // std::cout << x << " " << y << " " << now << " " << al_a << " " << al_b << " " << gl << std::endl;
    if (!al_a && !al_b) {
        fc += gl;
        // add(fc, c, 1, gl);
        return;
    } else if (!al_a) {
        fb += gl;
        // add(fb, b, 1, gl);
        return;
    } else if (!al_b) {
        fa += gl;
        // add(fa, a, 1, gl);
        return;
    }

    if (now == 1) {
        for (int i = x;; i++, i %= (n + 1)) {
            if (!map_a[i] || !i) continue;
            for (int j = 1; j <= m; j++) {
                if (!map_b[j]) continue;
                int &aa = map_a[i], &bb = map_b[j];
                int at = atk_a[i], bt = atk_b[j];
                if (at >= bb && bt >= aa) {
                    int ls1 = aa, ls2 = bb;
                    aa = 0;
                    bb = 0;
                    dfs(i + 1, y, 0, al_a - 1, al_b - 1, gl / al_b);
                    aa = ls1;
                    bb = ls2;
                } else if (at >= bb) {
                    int ls1 = aa, ls2 = bb;
                    aa -= bt;
                    bb = 0;
                    dfs(i + 1, y, 0, al_a, al_b - 1, gl / al_b);
                    aa = ls1;
                    bb = ls2;
                } else {
                    int ls1 = aa, ls2 = bb;
                    aa = 0;
                    bb -= at;
                    dfs(i + 1, y, 0, al_a - 1, al_b, gl / al_b);
                    aa = ls1;
                    bb = ls2;
                }
            }
            break;
        }
    } else {
        for (int i = y;; i++, i %= (m + 1)) {
            if (!map_b[i] || !i) continue;
            for (int j = 1; j <= n; j++) {
                if (!map_a[j]) continue;
                int &aa = map_a[j], &bb = map_b[i];
                int at = atk_a[j], bt = atk_b[i];
                if (at >= bb && bt >= aa) {
                    int ls1 = aa, ls2 = bb;
                    aa = 0;
                    bb = 0;
                    dfs(x, i + 1, 1, al_a - 1, al_b - 1, gl / al_a);
                    aa = ls1;
                    bb = ls2;
                } else if (at >= bb) {
                    int ls1 = aa, ls2 = bb;
                    aa -= bt;
                    bb = 0;
                    dfs(x, i + 1, 1, al_a, al_b - 1, gl / al_a);
                    aa = ls1;
                    bb = ls2;
                } else {
                    int ls1 = aa, ls2 = bb;
                    aa = 0;
                    bb -= at;
                    dfs(x, i + 1, 1, al_a - 1, al_b, gl / al_a);
                    aa = ls1;
                    bb = ls2;
                }
            }
            break;
        }
    }
}

signed main() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", map_a + i);
        atk_a[i] = map_a[i];
    }
    for (int i = 1; i <= m; i++) {
        scanf("%lld", map_b + i);
        atk_b[i] = map_b[i];
    }
    if (n > m)
        dfs(1, 1, 1, n, m, 1);
    else if (n < m)
        dfs(1, 1, 0, n, m, 1);
    else {
        dfs(1, 1, 1, n, m, 0.5);
        dfs(1, 1, 0, n, m, 0.5);
    }

    printf("%.10lf\n", fa);
    printf("%.10lf\n", fb);
    printf("%.10lf\n", fc);
    return 0;
}
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int mod = 998244353;
int n, m, a[502], b[502];
long long f[502], g[502], p[502][502];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    for (int i = 500; i >= 0; i--) {
        memset(p, 0, sizeof(p));
        p[0][0] = 1;
        for (int j = 1; j <= m; j++) {
            int t = 0;
            for (int k = 1; k <= n; k++)
                if (b[j] - a[k] >= i) t = k;
            for (int k = 0; k <= t; k++) {
                p[j][k] = p[j - 1][k];
                if (k) p[j][k] = (p[j][k] + p[j - 1][k - 1] * (t - k + 1)) % mod;
            }
        }
        for (int j = 1; j <= m; j++) f[i] = (f[i] + p[m][j]) % mod;
    }
    long long ans = 0;
    for (int i = 500; i >= 0; i--) {
        g[i] = f[i];
        for (int j = i + 1; j <= 500; j++) g[i] = (g[i] - g[j] + mod) % mod;
        ans = (ans + g[i] * i) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
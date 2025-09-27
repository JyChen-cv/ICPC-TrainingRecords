#include <bits/stdc++.h>
using namespace std;
#define re register
#define in inline
#define ll long long
#define get getchar()
in int read() {
    int t = 0;
    char ch = get;
    while (ch < '0' || ch > '9') ch = get;
    while (ch <= '9' && ch >= '0') t = t * 10 + ch - '0', ch = get;
    return t;
}
const int _ = 1e5 + 23;
int n, k, a[_];
int f[5010][5011];
in int check(int x) {
    f[0][0] = 1;
    for (re int i = 1; i <= n; ++i)
        for (re int j = 0; j <= k; ++j) f[i][j] = 0;
    for (re int i = 1; i <= n; ++i) {
        for (re int j = 0; j < k; ++j) f[i][j] = f[i - 1][j];
        if (x == i || a[i] > k) continue;
        for (re int j = 0; j + a[i] < k; ++j) f[i][j + a[i]] = max(f[i][j + a[i]], f[i - 1][j]);
    }
    for (re int i = 0; i < k; ++i)
        if (f[n][i] && i + a[x] >= k) return 1;
    return 0;
}
int main() {
    n = read(), k = read();
    for (re int i = 1; i <= n; ++i) a[i] = read();
    sort(a + 1, a + n + 1);
    if (a[1] > k) {
        cout << n << endl;
        return 0;
    }
    int l = 1, r = n, ans = n + 1;
    //    check(1); return 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    //    cout<<ans<<endl;
    cout << n - ans + 1 << endl;
    return 0;
}
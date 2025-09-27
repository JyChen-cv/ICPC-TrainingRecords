#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;
const int N = 2e5;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    ll suf = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i & 1)
            ans = max(ans, suf);
        else
            ans = max(ans, suf + a[i]);
        suf += max((ll)0, a[i]);
    }
    cout << ans << '\n';
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
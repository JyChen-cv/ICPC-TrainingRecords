#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long ll;
const int N = 1e5;
struct group {
    ll a, b, c;
    ll ls;
} mapp[N + 2];
ll ans, n;
ll sum;

void deal(int tag) {
    if (tag == 1)
        for (int i = 1; i <= n; i++) {
            mapp[i].ls = mapp[i].a - mapp[i].b - mapp[i].c;
        }
    else if (tag == 2)
        for (int i = 1; i <= n; i++) {
            mapp[i].ls = mapp[i].b - mapp[i].a - mapp[i].c;
        }
    else
        for (int i = 1; i <= n; i++) {
            mapp[i].ls = mapp[i].c - mapp[i].b - mapp[i].a;
        }
}

bool cmp(group a, group b) {
    return a.ls < b.ls;
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++) std::cin >> mapp[i].a;
    for (int i = 1; i <= n; i++) std::cin >> mapp[i].b;
    for (int i = 1; i <= n; i++) std::cin >> mapp[i].c;

    sum = 0;
    deal(1);
    std::sort(mapp + 1, mapp + n + 1, cmp);
    for (int i = n; i >= 1; i--) {
        if (sum + mapp[i].ls > 0)
            sum += mapp[i].ls;
        else {
            ans = std::max(ans, n - i);
            break;
        }
    }

    sum = 0;
    deal(2);
    std::sort(mapp + 1, mapp + n + 1, cmp);
    for (int i = n; i >= 1; i--) {
        if (sum + mapp[i].ls > 0)
            sum += mapp[i].ls;
        else {
            ans = std::max(ans, n - i);
            break;
        }
    }

    sum = 0;
    deal(3);
    std::sort(mapp + 1, mapp + n + 1, cmp);
    for (int i = n; i >= 1; i--) {
        if (sum + mapp[i].ls > 0)
            sum += mapp[i].ls;
        else {
            ans = std::max(ans, n - i);
            break;
        }
    }

    if (ans)
        std::cout << ans << std::endl;
    else
        std::cout << -1 << std::endl;
    return 0;
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 10000;
typedef long long ll;
ll mapp[N + 2];
struct node {
    ll sum, ls, rs, ms;
};

node dfs(int l, int r) {
    if (l == r) {
        node res = {mapp[l], mapp[l], mapp[l], mapp[l]};
        return res;
    }
    int mid = (l + r) / 2;
    node left = dfs(l, mid);
    node right = dfs(mid + 1, r);
    node res = {left.sum + right.sum, std::max(left.sum + right.ls, left.ls), std::max(right.rs, left.rs + right.sum), std::max(left.ms, std::max(right.ms, left.rs + right.ls))};
    return res;
}
int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", mapp + i);
    }
    std::cout << dfs(1, n).ms << std::endl;
    return 0;
}
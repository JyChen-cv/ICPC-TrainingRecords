#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

long long ans = 0;
int n, tag[12][12];
std::vector<int> a;

void dfs(int x) {
    if (x > n) {
        int l = 1;
        for (int i = 0; i < (int)a.size(); i++) {
            ans += tag[l][a[i] - 1];
            l = a[i];
        }
        ans += tag[l][n];
        return;
    }
    a.push_back(x);
    dfs(x + 1);
    a.pop_back();
    dfs(x + 1);
}
int main() {
    std::cin >> n;
    for (int i = 1; i <= 11; i++) {
        for (int j = i; j <= 11; j++) {
            tag[i][j] = n /
        }
    }
    dfs(2);
    return 0;
}
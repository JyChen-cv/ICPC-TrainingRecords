#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 201;
#define endl '\n'
#define ll long long
long long Sg[N][N], f[N][N];
ll sg(int a, int b) {
    if (f[a][b] != -1) return f[a][b];
    set<int> S;
    for (int i = 2; i <= a - 2; i++) {
        S.insert(sg(i, b) ^ sg(a - i, b));
    }
    for (int i = 2; i <= b - 2; i++) {
        S.insert(sg(a, i) ^ sg(a, b - i));
    }
    for (int i = 0;; i++) {
        if (!S.count(i)) {
            return f[a][b] = f[b][a] = i;
        }
    }
    return 0;
}
int main() {
    memset(f, -1, sizeof(f));
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        if (sg(a, b))  // 不为0先手胜
            printf("WIN\n");
        else {
            printf("LOSE\n");
        }
    }
    return 0;
}
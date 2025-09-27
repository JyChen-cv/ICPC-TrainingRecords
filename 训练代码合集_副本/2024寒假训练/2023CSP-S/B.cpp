#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 2e6;
int n;
char m[N + 2];
int rem[30];
bool v[8002][8002];

bool check(int l, int r) {
    std::vector<char> q;
    for (int i = l; i <= r; i++) {
        if (q.size() == 0 || q[q.size() - 1] != m[i])
            q.push_back(m[i]);
        else
            q.pop_back();
    }
    return q.size() == 0 ? 1 : 0;
}

int main() {
    scanf("%d", &n);
    scanf("%s", m + 1);
    if (n <= 800) {
        int ans = 0;
        for (int len = 2; len <= n; len++) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;
                if (check(l, r)) ans++;
                // if (m[l] == m[r]) {
                //     if (len == 2 || v[l + 1][r - 1] == 1) {
                //         v[l][r] = 1;
                //         ans++;
                //     }
                // }
            }
        }
        std::cout << ans << std::endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (rem[i] == 0) {
            rem[m[i] - 'a' + 1] = i;
            continue;
        }

        rem[m[i] - 'a' + 1] = i;
    }
    return 0;
}
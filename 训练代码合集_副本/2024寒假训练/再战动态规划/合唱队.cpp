#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int MaxN = 1000;
int a[MaxN + 5], f[MaxN + 5][MaxN + 5][2];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i][i][0] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if (a[l] < a[l + 1]) f[l][r][0] += f[l + 1][r][0];
            f[l][r][0] %= 19650827;
            if (a[l] < a[r]) f[l][r][0] += f[l + 1][r][1];
            f[l][r][0] %= 19650827;
            if (a[r - 1] < a[r]) f[l][r][1] += f[l][r - 1][1];
            f[l][r][1] %= 19650827;
            if (a[l] < a[r]) f[l][r][1] += f[l][r - 1][0];
            f[l][r][1] %= 19650827;
        }
    }

    cout << (f[1][n][0] + f[1][n][1]) % 19650827 << endl;
    return 0;
}
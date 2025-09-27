
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

const int N = 3000;
double A[N + 2][N + 2], B[N + 2][N + 2], C[N + 2][N + 2];
int num[N + 2], ans = 0;

double cost(int x) {
    double res = 0;
    int ls = std::max(1, x - 200);
    for (int i = ls; i <= x; i++) {
        for (int j = ls; j <= x; j++) {
            res += (num[i] == num[j] ? (A[i][j] + A[j][i] + B[i][j] + B[j][i]) : 0) + (num[i] % 3 == num[j] % 3 ? (C[i][j] + C[j][i]) : 0);
        }
    }
    return res;
}
void dfs(int x) {
    std::cout << x << std::endl;
    if (x > 2067) return;
    double res = 100000000000;
    int tag = 0;
    for (int i = 0; i <= 1007; i++) {
        num[x] = i;
        double ls = cost(x);
        if (res <= 100) break;
        if (ls < res) {
            res = ls;
            tag = i;
        }
    }
    num[x] = tag;
    ans += res;
    dfs(x + 1);
}

int main() {
    FILE *fpa = fopen("/Users/chenjiayou/Desktop/2024寒假训练/A.txt", "r");
    FILE *fpb = fopen("/Users/chenjiayou/Desktop/2024寒假训练/B.txt", "r");
    FILE *fpc = fopen("/Users/chenjiayou/Desktop/2024寒假训练/C.txt", "r");
    for (int i = 1; i <= 2067; i++) {
        for (int j = 1; j <= 2067; j++) {
            int a;
            fscanf(fpa, "%lfe+%d", &A[i][j], &a);
        }
    }
    for (int i = 1; i <= 2067; i++) {
        for (int j = 1; j <= 2067; j++) {
            int a;
            fscanf(fpb, "%lfe+%d", &B[i][j], &a);
        }
    }
    for (int i = 1; i <= 2067; i++) {
        for (int j = 1; j <= 2067; j++) {
            int a;
            fscanf(fpc, "%lfe+%d", &C[i][j], &a);
        }
    }
    dfs(1);
    fclose(fpa);
    fclose(fpb);
    fclose(fpc);

    FILE *fp = fopen("/Users/chenjiayou/Desktop/2024寒假训练/res.txt", "r+");
    // fprintf(f)
    for (int i = 1; i <= 2067; i++) {
        fprintf(fp, "%d %d\n", i, num[i]);
    }
    return 0;
}
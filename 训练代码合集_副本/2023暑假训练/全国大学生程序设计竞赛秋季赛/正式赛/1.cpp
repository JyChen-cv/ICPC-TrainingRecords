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
unsigned ll n;
int main() {
    cin >> n;
    int sum = 0;
    while (n) {
        if (n % 2 == 0) sum++;
        n /= 2;
    }
    cout << sum << endl;
    return 0;
}
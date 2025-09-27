#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
#define re
#define db double
db n, p1, v1, p2, v2;
const db eps = 0.0000000000001;
db calc1() { return min(p1 / v1, (n - p1) / v1) + n / v1; }
db calc2() { return min(p2 / v2, (n - p2) / v2) + n / v2; }
db calc3() {
    return (n - p1) / v1 + p2 / v2;
}
db calc4() {
    db l = p1, r = p2;
    while (l + eps < r) {
        db mid = (l + r) / 2.0;
        if ((p1 + mid) * v2 < (n + n - mid - p2) * v1)
            l = mid;
        else
            r = mid;
    }
    return max((p1 + l) / v1, (n + n - l - p2) / v2);
}
db calc5() {
    db l = p1, r = p2;
    while (l + eps < r) {
        db mid = (l + r) / 2.0;
        if ((mid + mid - p1) * v2 < (p2 + n - mid - mid) * v1)
            l = mid;
        else
            r = mid;
    }
    return max((l + l - p1) / v1, (p2 + n - l - l) / v2);
}
db calc6() {
    return max((n - p2) / v2, min(p2 + p2 - p1, p1 + p2) / v1);
}
db calc7() {
    return max((p1) / v1, min(n - p1 + p2 - p1, n - p1 + n - p2) / v2);
}
db calc8() {
    db l = p1, r = p2;
    while (l + eps < r) {
        db mid = (l + r) / 2;
        if ((p1 + mid) * v2 < (p2 + n - mid - mid) * v1)
            l = mid;
        else
            r = mid;
    }
    return max((p1 + l) / v1, (p2 + n - l - l) / v2);
}
db calc9() {
    db l = p1, r = p2;
    while (l + eps < r) {
        db mid = (l + r) / 2;
        if ((mid + mid - p1) * v2 < (n + n - mid - p2) * v1)
            l = mid;
        else
            r = mid;
    }
    return max((l + l - p1) / v1, (n + n - l - p2) / v2);
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> p1 >> v1 >> p2 >> v2;
        if (p1 > p2 + eps) swap(p1, p2), swap(v1, v2);
        db ans = min(calc1(), calc2());
        //        cout << calc1() << ' ' << calc2() << ' ' << calc3() << ' ' << calc4() << ' ' << calc5() << endl;
        ans = min(calc3(), ans);
        ans = min(ans, calc4());
        ans = min(calc5(), ans);
        ans = min(calc6(), ans);
        ans = min(calc7(), ans);
        ans = min(calc8(), ans);
        ans = min(calc9(), ans);
        printf("%.9lf\n", ans);
    }
}
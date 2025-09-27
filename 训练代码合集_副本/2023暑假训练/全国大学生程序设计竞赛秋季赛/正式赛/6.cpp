#include <bits/stdc++.h>
using namespace std;
#define re register
#define ll long long
#define in inline
int ff[101] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
int main() {
    string s;
    getline(cin, s);  // 输入
    int n = s.size(), ans = 0;
    for (re int i = 0; i < n; ++i) {
        if (s[i] == ' ')
            ans++;
        else
            ans += ff[s[i] - 'a'];
    }
    cout << ans << endl;
}
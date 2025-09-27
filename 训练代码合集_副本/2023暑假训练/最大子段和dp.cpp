#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define inf 1e18;
const int N = 5000;
typedef long long ll;
ll mapp[N + 2], dp[N + 2];
int main() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", mapp + i);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = std::max(mapp[i], dp[i - 1] + mapp[i]);
        ans = std::max(ans, dp[i]);
    }
    std::cout << ans << std::endl;
    return 0;
}

/*
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const int MaxN=2000000;
int a[MaxN+5];

int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }

    int ans=-1000000000;
    int summ=-1000000000;
    for (int i=1;i<=n;i++) {
        if (summ+a[i]>=a[i]) summ+=a[i];
        else summ=a[i];
        ans=max(ans,summ);
    }

    cout<<ans<<endl;
    return 0;
}
*/
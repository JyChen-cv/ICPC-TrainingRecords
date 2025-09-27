#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

const long long MaxN=10000;
using namespace std;

vector<long long> f[MaxN+5];

vector <long long> add(vector <long long> &A, vector <long long> &B)
{
	long long t = 0;
	vector <long long> C;
	for(long long i = 0; i < (long long)A.size() || i < (long long)B.size(); i ++)
	{
		if(i < (long long)A.size()) t += A[i];
		if(i < (long long)B.size()) t += B[i];
		C.push_back(t % 10);
		t =(t-(t%10))/10;
	}
	if(t) C.push_back(t);
	// reverse(C.begin(),C.end());
	return C;
}

long long main()
{
    long long n;
    f[1].push_back(1);
    f[0].push_back(1);
    f[2].push_back(2);

    for (long long i=3;i<=3000;i++) {
        f[i]=add(f[i-1],f[i-2]);
        f[i]=add(f[i],f[i-3]);
    }

    while (cin>>n) {
        for (long long i=(long long)f[n].size()-1;i>=0;i--) cout<<f[n][i];
        cout<<endl;
    }

    return 0;
}
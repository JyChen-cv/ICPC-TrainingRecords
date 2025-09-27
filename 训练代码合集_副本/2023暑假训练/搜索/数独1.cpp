#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;
int a[15][15];
int ha[15],li[15],point[15][15];  //二进制压缩数组，行，列，每个九宫格的中心（表示这个九宫格） 
int num[1<<20];  //lowbit预处理数组 

int deal1(int x)
{
	//返回值是这个数字所在的九宫格的中心坐标的一个值 
	int e=x%3;
	if (e==0) e+=3;
	return x-e+2;
}

bool dfs(int x,int y)
{
	//通过二进制压缩就不用每次都判断哪个数字了，变成了维护三个数组，卡常操作 
	if (x==10) {
		return 1;
	}
	if (a[x][y]) {
		if (y+1<=9) return dfs(x,y+1);
		else return dfs(x+1,1);
	}
	
	int b=((ha[x]|li[y])|point[deal1(x)][deal1(y)]); //b的二进制表示所有的已经用过的数字
	b=b^((1<<10)-1);  //方便后面写代码，取反一下，必须异或1023，保证把所有的“位”都考虑进来 
	//接下来用位运算可以在O(n)的时间复杂度内拿出里面的“1”，n为里面包含的“1”的个数（概括引用《算法竞赛》的话，不要挑刺...）
	if ((b&(-b))==1) b--; // b&(-b)可以求算出b中第一个"1"与它后面的所有的"0"构成的数字，这一步是去掉0这个数字，因为数独里面只能填1-9 
	while (b>0) {   //其实就是标准的lowbit运算，只是把式子化简了一下
		int m=b&(-b);
		ha[x]+=m;  //更改各项的值 
		li[y]+=m;
		point[deal1(x)][deal1(y)]+=m;
		a[x][y]=num[m];   //填空或更新 
		if (y+1<=9) { if (dfs(x,y+1)==1) return 1; } //把“1”传递下去 
		else { if (dfs(x+1,1)==1) return 1; }
		ha[x]-=m;   //回溯 
		li[y]-=m;
		point[deal1(x)][deal1(y)]-=m;
		b-=m;
	}
	a[x][y]=0;  //找不到的话就还原 
	return 0;
}

int main()
{
	int w=0;
	for (int i=1;i<=9;i++) {
		for (int j=1;j<=9;j++) {
			cin>>a[i][j];
			if (a[i][j]!=0) {  //注意特判，不然会加一堆1 
				w=1<<a[i][j];   //位运算有优先级，所以可以乱搞
				ha[i]+=w;  //顺手预处理，标记那些数字用过了 
				li[j]+=w;
				point[deal1(i)][deal1(j)]+=w;
			}
		}
	}
	
	for (int i=0;i<20;i++) num[1<<i]=i; 
	if (dfs(1,1)==0) cout<<"No Solution";
	else {
		for (int i=1;i<=9;i++) {
			for (int j=1;j<=9;j++) {
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	return 0;
} 

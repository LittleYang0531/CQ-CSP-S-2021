#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#define maxn 100002
#define inf (1<<30)
typedef long long ll;
using namespace std;
int read()
{
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=='-'?f=-f,c=getchar():c=getchar();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=getchar();
	return x*f;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n=read(),m=read(),t=read();
	srand(time(0)+n+m);
	for(int i=1;i<=t;i++)
	{
		printf("%d\n",rand());
	}
	return 0;
}



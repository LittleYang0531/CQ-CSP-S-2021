#include <bits/stdc++.h>
using namespace std;

struct node
{
	int x,y;
}a[100005],b[100005],f1[100005],f2[100005];

int n,air_1,air_2,f_a[100005],f_b[100005],ans;

bool operator < (node x,node y)
{
	return x.x < y.x;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&air_1,&air_2);
	for(int i = 1;i <= air_1;i++) scanf("%d %d",&a[i].x,&a[i].y);
	for(int i = 1;i <= air_2;i++) scanf("%d %d",&b[i].x,&b[i].y);
	f1[1] = 1;
	for(int i = 2,R = a[1].y;i <= air_1;i++)
	{
		if(a[i].x < R) f1[i].x = f1[i + 1].x + 1;
		else f1[i].x = f1[i + 1].x;
		f1[i].y = i;
		R = max(R,a[i].y);
	}
	f2[1] = 1;
	for(int i = 2,R = b[1].y;i <= air_2;i++)
	{
		if(b[i].x < R) f2[i].x = f2[i + 1].x + 1;
		else f2[i].x = f2[i + 1].x;
		f2[i].y = i;
		R = max(R,b[i].y);
	}
	sort(f1 + 1,f1 + 1 + air_1);
	sort(f2 + 1,f2 + 1 + air_2);
	for(int i = 1;i <= air_1;i++) f_a[f1[i].x] = f1[i].y;
	for(int i = 1;i <= air_2;i++) f_b[f2[i].x] = f2[i].y;
	for(int i = 0;i <= n;i++)
	{
		ans = max(f_a[i] + f_b[n - i],ans);
	}
	printf("%d",ans);
	return 0;
}

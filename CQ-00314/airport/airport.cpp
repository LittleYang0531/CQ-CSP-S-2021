#include<bits/stdc++.h>
using namespace std;
const int MAXN=100001;
int n,m1,m2,ans=0;
struct plane{
	int from,to;
};
plane ch[MAXN],fo[MAXN];
bool cmp(plane x,plane y)
{
	return x.from<y.from;
}
struct data{
	int t;
	friend bool operator<(data x,data y)
	{
		return x.t>y.t;//Ð¡¸ù¶Ñ 
	}
};
priority_queue<data>q;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d%d",&ch[i].from,&ch[i].to);
	for(int i=1;i<=m2;i++) scanf("%d%d",&fo[i].from,&fo[i].to);
	sort(ch+1,ch+m1+1,cmp);
	sort(fo+1,fo+m2+1,cmp);
	for(int i=max(0,n-m2);i<=min(n,m1);i++)
	{
		int tempans=0;
		if(i<m1&&i!=0)
		{
			tempans=i;
			for(int j=1;j<=i;j++) q.push((data){ch[j].to});
			for(int j=i+1;j<=m1;j++)
				if(q.top().t<ch[j].from) q.pop(),q.push((data){ch[j].to}),tempans++;
		}
		else if(i!=0) tempans=m1;
		while(!q.empty()) q.pop();
		if(n-i<m2&&n-i!=0)
		{
			tempans+=(n-i);
			for(int j=1;j<=(n-i);j++) q.push((data){fo[j].to});
			for(int j=n-i+1;j<=m2;j++)
				if(q.top().t<fo[j].from) q.pop(),q.push((data){fo[j].to}),tempans++;
		}
		else if(n-i!=0) tempans+=m2;
		ans=max(ans,tempans);
		while(!q.empty()) q.pop();
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10

3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

*/

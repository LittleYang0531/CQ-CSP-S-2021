#include<bits/stdc++.h>
using namespace std;
inline void qr(int &ret){int x=0,f=0;char ch=getchar();while(ch<'0'||ch>'9'){f|=ch=='-';ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}ret=f?-x:x;}

typedef struct air
{
	int ari,lef;
}IN,OUT;
IN plane[100005];
OUT port[100005];
bool cmp_in(IN a,IN b)
{
	return a.ari<b.ari;
}
bool cmp_out(OUT a,OUT b)
{
	return a.ari<b.ari;
}
int ans_in[100005],ans_out[100005];
bool book[100005];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,i,j;
	qr(n),qr(m1),qr(m2);
	for(i=1;i<=m1;i++)
		qr(plane[i].ari),qr(plane[i].lef);
	for(i=1;i<=m2;i++)
		qr(port[i].ari),qr(port[i].lef);
	sort(plane+1,plane+1+m1,cmp_in);
	sort(port+1,port+1+m2,cmp_out);
	int time_leave;
	for(i=1;i<=n;i++)
	{
		time_leave=0;
		if(ans_in[i-1]==m1)
		{
			ans_in[i]=m1;
			continue;
		}
		ans_in[i]=ans_in[i-1];
		for(j=1;j<=m1&&time_leave<=plane[m1].ari;j++)
		{
			if(!book[j]&&time_leave<=plane[j].ari)
			{
				book[j]=1;
				time_leave=plane[j].lef;
				ans_in[i]++;
			}
		}
	}
	memset(book,0,sizeof(book));
	for(i=1;i<=n;i++)
	{
		time_leave=0;
		if(ans_out[i-1]==m2)
		{
			ans_out[i]=m2;
			continue;
		}
		ans_out[i]=ans_out[i-1];
		for(j=1;j<=m2&&time_leave<=port[m2].ari;j++)
		{
			if(!book[j]&&time_leave<=port[j].ari)
			{
				book[j]=1;
				time_leave=port[j].lef;
				ans_out[i]++;
			}
		}
	}
	int ax=0;
	for(i=0;i<=n;i++)
		ax=max(ax,ans_in[i]+ans_out[n-i]);
	printf("%d",ax);
	return 0;
}

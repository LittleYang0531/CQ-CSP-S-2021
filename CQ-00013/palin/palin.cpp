#include<bits/stdc++.h>
using namespace std;
inline void qr(int &ret){int x=0,f=0;char ch=getchar();while(ch<'0'||ch>'9'){f|=ch=='-';ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}ret=f?-x:x;}

int num[1000005],used[500005],n;
bool p;
char lr[1000005];
void gz(int l,int r,int sum)
{
	if(l>r||sum==2*n+1)
	{
		p=1;
		return;
	}
	if(p)
		return;
	if(sum<=n)
	{
		if(used[num[l]]==-1)
		{
			used[num[l]]=sum;
			lr[sum]='L';
			gz(l+1,r,sum+1);
			used[num[l]]=-1;
			if(p)
				return;
		}
		if(used[num[r]]==-1)
		{
			used[num[r]]=sum;
			lr[sum]='R';
			gz(l,r-1,sum+1);
			used[num[r]]=-1;
			if(p)
				return;
		}
	}
	else
	{
		if((double)(sum+used[num[l]]-1)/2.0==(double)n)
		{
			lr[sum]='L';
			gz(l+1,r,sum+1);
			if(p)
				return;
		}
		if((double)(sum+used[num[r]]-1)/2.0==(double)n)
		{
			lr[sum]='R';
			gz(l,r-1,sum+1);
			if(p)
				return;
		}
		return;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int i,t;
	qr(t);
	while(t--)
	{
		p=0;
		memset(lr,0,sizeof(lr));
		memset(used,-1,sizeof(used));
		qr(n);
		for(i=1;i<=2*n;i++)
			qr(num[i]);
		gz(1,2*n,1);
		if(!p)
			printf("-1\n");
		else
			puts(lr+1);
	}
	return 0;
}

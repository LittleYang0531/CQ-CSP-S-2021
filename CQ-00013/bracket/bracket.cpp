#include<bits/stdc++.h>
using namespace std;
inline void qr(int &ret){int x=0,f=0;char ch=getchar();while(ch<'0'||ch>'9'){f|=ch=='-';ch=getchar();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}ret=f?-x:x;}

const int mod=1e9+5;
char brac[505];
int n,k,bra[505],tot;
long long brack(int now)
{
	int i,c;
	if(now==n)
	{
		if(tot||brac[now-1]=='*'||brac[0]=='*')
			return 0;
		return 1;
	}
	if(brac[now]=='(')
	{
		bra[tot++]=now;
		int val=brack(now+1)%mod;
		tot--;
		return val;
	}
	if(brac[now]==')')
	{
		if(!tot)
			return 0;
		int x=bra[--tot];
		int val=brack(now+1)%mod;
		bra[tot++]=x;
		return val;
	}
	if(brac[now]=='*')
	{
		int sum=1,x=now-1;
		while(x>-1&&brac[x]=='*')
		{
			sum++;
			if(sum>k)
				return 0;
			x--;
		}
		if(sum>k)
			return 0;
		for(i=now-3;i>-1&&i<now;i+=3)
			if(brac[i]=='*'&&brac[i+1]=='('&&brac[i+2]==')')
				return 0;
		return brack(now+1)%mod;
	}
	bra[tot++]=now;
	brac[now]='(';
	long long sum=brack(now+1)%mod;
	if(tot)
		tot--;
	brac[now]='?';
	if(now>0&&now<n-1)
	{
		int num=0,x=now-1;
		while(x>-1&&brac[x]=='*')
		{
			num++;
			if(num>k)
				return 0;
			x--;
		}
		if(now>2&&brac[now-3]=='*'&&brac[now-2]=='('&&brac[now-1]==')')
			return 0;
		if(num<k)
		{
			brac[now]='*';
			sum=(sum+brack(now+1))%mod;
			brac[now]='?';
		}
	}
	if(now>0)
	{
		if(!tot)
			return sum;
		c=bra[--tot];
		brac[now]=')';
		sum=(sum+brack(now+1))%mod;
		bra[tot++]=c;
		brac[now]='?';
	}
	return sum;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	qr(n),qr(k);
	scanf("%s",brac);
	if(brac[0]=='*'||brac[n-1]=='*'||brac[0]==')')
	{
		printf("0");
		return 0;
	}
	printf("%lld",brack(0)%mod);
	return 0;
}
//By the way,if you(CCF) see it,I'll AK IOI!

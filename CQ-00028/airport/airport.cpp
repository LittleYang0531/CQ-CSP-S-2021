#include<bits/stdc++.h>
using namespace std;

long long n,m1,m2,ans=-1; long long pan1[1000005],duan1[1000005],pan2[1000005],duan2[1000005];

struct in_zh { long long a1,b1; } k1[1000005];

struct out_zh { long long a2,b2; } k2[1000005];

bool cmp1(in_zh a,in_zh b) { if(a.a1!=b.a1) return a.a1<b.a1; return a.b1<b.b1; }

bool cmp2(out_zh a,out_zh b) { if(a.a2!=b.a2) return a.a2<b.a2; return a.b2<b.b2; }

void S_canf_he_paixu_huo_comp()
{
	scanf("%lld%lld%lld",&n,&m1,&m2);
	
	for(long long i=1ll;i<=m1;i+=1ll) 
	{
		scanf("%lld%lld",&k1[i].a1,&k1[i].b1);
	}
	
	for(long long i=1ll;i<=m2;i+=1ll) 
	{
		scanf("%lld%lld",&k2[i].a2,&k2[i].b2);
	}
	
	sort(k1+1ll,k1+m1+1ll,cmp1); 
	
	sort(k2+1ll,k2+m2+1ll,cmp2);
}

void yuchuli()
{
	memset(pan1,0ll,sizeof(pan1)); memset(duan1,0ll,sizeof(duan1));
	memset(pan2,0ll,sizeof(pan2)); memset(duan2,0ll,sizeof(duan2));
}

void zuiduo_inguo_he_outguo(int i)
{
	yuchuli();
	long long qiao1=i,qiao2=n-i,cnt1=0ll,cnt2=0ll,sum1=0ll,sum2=0ll;
	if(qiao1>0ll)
	{
		long long cnt3=1ll;
		for(long long j=1ll;j<=m1;j+=1ll)
		{
			for(long long k=cnt3;k<=cnt1;k+=1ll) 
			{ 
				if(duan1[k]!=0ll&&duan1[k]<k1[j].a1) { qiao1+=1ll; cnt3+=1ll; } 
				if(duan1[i]>=k1[j].a1) break; 
			}
			if(qiao1>0ll) { pan1[++cnt1]=k1[j].a1; duan1[cnt1]=k1[j].b1; qiao1--; sum1+=1ll; }
		}
	}
	if(qiao2>0ll)
	{
		long long cnt4=1ll;
		for(long long j=1ll;j<=m2;j+=1ll)
		{
			for(long long k=cnt4;k<=cnt2;k+=1ll) 
			{ 
				if(duan2[k]!=0ll&&duan2[k]<k2[j].a2) { qiao2+=1ll; cnt4+=1ll; }
				if(duan2[i]>=k2[j].a2) break; 
			}
			if(qiao2>0ll) { pan2[++cnt2]=k2[j].a2; duan2[cnt2]=k2[j].b2; qiao2--; sum2+=1ll; }
		}
	}
	ans=max(ans,(long long)(sum1+sum2));
}

void P_rintf() { printf("%lld",ans); }
							
int main()
{
	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);

	S_canf_he_paixu_huo_comp();
	
	for(long long i=0ll;i<=n;i+=1ll)
	{
		zuiduo_inguo_he_outguo(i);
	}
	
	P_rintf();
	
	return 0;
}

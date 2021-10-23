#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
using namespace std;
int rd()
{
	int s=0;bool bj=0;char ch=getchar();
	while(ch<'0'||ch>'9'){bj|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return bj?-s:s;
}
void ptnum(int x)
{
	if(x>9)ptnum(x/10);
	putchar(x%10^48);
}
void pt(int x,char ch)
{
	if(x<0){x=-x;putchar('-');}
	ptnum(x);
	putchar(ch);
}
int T;
int n,dn;
int a[1000005];
struct node{int l,r;}bj[500005];
int tmp[45],tmpp[1000005],no[1000005];
bool flag;
bool vst[500005];
void DFS(int st,int l,int r)
{
	if(flag==1)return;
	if(st==n+1)
	{
		int num=n;
		for(int i=n;i>=1;--i)
		{
			if(a[l]==tmp[i]){++l;tmpp[++num]=0;}
			else if(a[r]==tmp[i]){--r;tmpp[++num]=1;}
			else return;
		}
		for(int i=1;i<=dn;++i)no[i]=tmpp[i];
//		for(int i=1;i<=n;++i)cout<<tmp[i]<<" ";cout<<endl;
		flag=1;
		return;
	}
	if(!vst[a[l]])
	{
		vst[a[l]]=1;tmp[st]=a[l];tmpp[st]=0;
		DFS(st+1,l+1,r);
		vst[a[l]]=0;
	}
	if(!vst[a[r]])
	{
		vst[a[r]]=1;tmp[st]=a[r];tmpp[st]=1;
		DFS(st+1,l,r-1);
		vst[a[r]]=0;
	}
}
void _Compare()
{
	if(!flag){flag=1;memcpy(no,tmpp,sizeof(tmpp));return;}
	for(int i=1;i<=dn;++i)
	if(tmpp[i]<no[i]){memcpy(no,tmpp,sizeof(tmpp));return;}
	else if(tmpp[i]>no[i])return;
}
int num;
void Work(int l,int r)
{
	++num;if(n>=5000&&num>=100)return;
//	cout<<l<<" "<<r<<endl;
	int bj1=n,bj2=n+1;
	int nol=l-1,nor=r+1;//Íâ 
	int noL=l,noR=r;//Àï 
	for(int i=1;i<=n;++i)
	{
//		cout<<nol<<" "<<nor<<" "<<noL<<" "<<noR<<endl;
		if(a[nor]==a[noR])
		{
			tmpp[bj1]=1;tmpp[bj2]=1;
			if(noR==noL)tmpp[bj2]=0;
			++nor;--noR;
		}
		else if(a[nor]==a[noL])
		{
			tmpp[bj1]=1;tmpp[bj2]=0;
			++nor;++noL;
		}
		else if(a[nol]==a[noR])
		{
			tmpp[bj1]=0;tmpp[bj2]=1;
			if(noR==noL)tmpp[bj2]=0;
			--nol;--noR;
		}
		else if(a[nol]==a[noL])
		{
			tmpp[bj1]=0;tmpp[bj2]=0;
			--nol;++noL;
		}
		else return;
//		if(a[nol]==a[noL])
//		{
//			tmpp[bj1]=0;tmpp[bj2]=0;
//			--nol;++noL;
//		}
//		else if(a[nol]==a[noR])
//		{
//			tmpp[bj1]=0;tmpp[bj2]=1;
//			--nol;--noR;
//		}
//		else if(a[nor]==a[noL])
//		{
//			tmpp[bj1]=1;tmpp[bj2]=0;
//			++nor;++noL;
//		}
//		else if(a[nor]==a[noR])
//		{
//			tmpp[bj1]=1;tmpp[bj2]=1;
//			++nor;--noR;
//		}
//		else return;
		--bj1;++bj2;
	}
//	for(int i=1;i<=dn;++i)cout<<tmpp[i]<<" ";cout<<endl;
	_Compare();
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=rd();
	while(T--)
	{
		flag=num=0;
		n=rd();dn=n<<1;
		for(int i=1;i<=dn;++i)a[i]=rd();
		if(n<=20)
		{
			DFS(1,1,dn);
			if(!flag)puts("-1");
			else 
			{
				for(int i=1;i<=dn;++i)putchar(!no[i]?'L':'R');puts("");
			}
			continue;
		}
		memset(vst,0,sizeof(vst));
		int L=0,R=500001;
		for(int i=1;i<=dn;++i)
		{
			if(!vst[a[i]]){vst[a[i]]=1;L=max(i,L);}
			else R=min(i,R);
		}
		swap(L,R);
		L=min(n+1,L);R=max(n,R);
		for(int i=L;i>=1;--i)
		if(i+n-1>=R)Work(i,i+n-1);
		if(!flag)puts("-1");
		else 
		{
			for(int i=1;i<=dn;++i)putchar(!no[i]?'L':'R');puts("");
		}
//		cout<<L<<" "<<R<<endl;
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/

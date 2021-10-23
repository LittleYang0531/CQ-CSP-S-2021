#include<cstdio>//JZM yyds!!
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<ctime>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<random>
#define ll long long
#define uns unsigned
#define MOD 
#define MAXN 200005
#define INF 1e17
#define IF (it->first)
#define IS (it->second)
using namespace std;
inline ll read(){
	ll x=0;bool f=1;char s=getchar();
	while((s<'0'||s>'9')&&s>0){if(s=='-')f^=1;s=getchar();}
	while(s>='0'&&s<='9')x=(x<<1)+(x<<3)+(s^48),s=getchar();
	return f?x:-x;
}
inline ll lowbit(ll x){return x&-x;}
int n,m,k;
struct itn{
	int l,r;itn(){}
	itn(int L,int R){l=L,r=R;}
}a[MAXN];
int b[MAXN],n1[MAXN],n2[MAXN],ans;
set<int>st;
map<int,int>mp;
map<int,int>::iterator it;
signed main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),k=read(),m=read();
	m+=k;
	for(int i=1;i<=m;i++)a[i].l=read(),a[i].r=read();
	for(int i=1;i<=m+1;i++)st.insert(i);
	for(int i=1;i<=k;i++)mp[a[i].l]=i,mp[a[i].r]=i;
	for(it=mp.begin();it!=mp.end();it++){
		int t=IF,i=IS;
		if(t==a[i].l)b[i]=*st.begin(),st.erase(b[i]);
		else st.insert(b[i]);
	}
	mp.clear();
	for(int i=1;i<=m+1;i++)st.insert(i);
	for(int i=k+1;i<=m;i++)mp[a[i].l]=i,mp[a[i].r]=i;
	for(it=mp.begin();it!=mp.end();it++){
		int t=IF,i=IS;
		if(t==a[i].l)b[i]=*st.begin(),st.erase(b[i]);
		else st.insert(b[i]);
	}
	for(int i=1;i<=k;i++)n1[b[i]]++;
	for(int i=k+1;i<=m;i++)n2[b[i]]++;
	for(int i=1;i<=n;i++)n1[i]+=n1[i-1],n2[i]+=n2[i-1];
	for(int a=0,b=n;a<=n;a++,b--)
		ans=max(ans,n1[a]+n2[b]);
	printf("%d\n",ans);
	return 0;
}

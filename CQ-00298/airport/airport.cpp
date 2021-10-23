#include<bits/stdc++.h>
#define inl inline
typedef long long ll;
using namespace std;
const int maxn=1e5+5;
struct node
{
	int num,pos; bool flag;
	bool operator <(const node &t) const
	{
		return pos<t.pos;
	}
}a[maxn<<1];
priority_queue<int,vector<int>,greater<int> > q,em;
int n,m[2],mt,cnt,ans,wz[maxn],sum[2][maxn];
inl int Read()
{
	int s=0; char c;
	while(!isdigit(c=getchar()));
	for(;isdigit(c);c=getchar()) s=s*10+c-'0';
	return s;
}
inl void Get(int fl)
{
	swap(q,em); cnt=0; mt=m[fl]<<1;
	for(int i=1;i<=m[fl];++i) a[i]=(node){i,Read(),false}, a[i+m[fl]]=(node){i,Read(),true};
	sort(a+1,a+mt+1);
	for(int i=1;i<=mt;++i)
		if(a[i].flag) q.push(wz[a[i].num]);
		else
			if(q.empty()) wz[a[i].num]=++cnt, sum[fl][cnt]=1;
			else wz[a[i].num]=q.top(), ++sum[fl][q.top()],q.pop();
	for(int i=2;i<=n;++i) sum[fl][i]+=sum[fl][i-1];
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=Read(); m[0]=Read(); m[1]=Read(); Get(0); Get(1);
	for(int i=0;i<=n;++i) ans=max(ans,sum[0][i]+sum[1][n-i]);
	printf("%d\n",ans);
	return 0;
}

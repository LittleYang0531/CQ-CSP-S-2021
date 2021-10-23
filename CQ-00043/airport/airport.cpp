#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e5+5;
struct node
{
	int l,r;
	bool operator<(const node&w)const{return l<w.l;}
}e[xx];
int n,m1,m2,ans1[xx],ans2[xx],ans[xx];//ans1表示m1这边放x个廊桥有几个飞机可用 
void solve(int m)
{
	multiset<node>s;
	for(int i=1;i<=m;i++)s.insert(e[i]);
	ans[0]=0;
	for(int i=1;i<=n;i++)//这边放几个 
	{
		ans[i]=ans[i-1];
		if(!s.size())continue;
		else 
		{
			node now=*s.begin();
			while(1)
			{
				s.erase(s.find(now));
				ans[i]++;
				multiset<node>::iterator it=s.lower_bound((node){now.r,now.r});
				if(it==s.end())break;
				now=*it;
			}
		}
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++)
		e[i].l=read(),e[i].r=read();
	solve(m1);
	for(int i=1;i<=n;i++)ans1[i]=ans[i];
	for(int i=1;i<=m2;i++)
		e[i].l=read(),e[i].r=read();
	solve(m2);
	for(int i=1;i<=n;i++)ans2[i]=ans[i];
	int res=0;
	for(int i=0;i<=n;i++)res=max(res,ans1[i]+ans2[n-i]);
	cout<<res<<"\n";
	return 0;
}
/*
21!9-324@emb
*/


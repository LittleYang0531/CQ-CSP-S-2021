#include<bits/stdc++.h>
using namespace std;
# define ll long long
# define read read1<ll>()
# define Type template<typename T>
Type T read1(){
	T t=0;
	char k;
	bool vis=0;
	do (k=getchar())=='-'&&(vis=-1);while('0'>k||k>'9');
	while('0'<=k&&k<='9')t=(t<<3)+(t<<1)+(k^'0'),k=getchar();
	return vis?-t:t;
}
# define fre(k) freopen(k".in","r",stdin);freopen(k".out","w",stdout)
int s,n,m,av[100005],bv[100005];
pair<int,int>a[100005],b[100005];
set<pair<int,int> >sex,sey;
int main(){fre("airport");
	s=read,n=read,m=read;
	for(int i=1;i<=n;++i)a[i].first=read,a[i].second=read,sex.insert(make_pair(a[i].first,i));
	for(int i=1;i<=m;++i)b[i].first=read,b[i].second=read,sey.insert(make_pair(b[i].first,i));
	for(int i=1;i<=n;++i){
		if(sex.empty())break;
		int t=0;
		for(int j=0;;){
			set<pair<int,int> >::iterator it=sex.lower_bound(make_pair(j,0));
			if(it==sex.end())break;
			++t;j=a[it->second].second;sex.erase(it);
		}av[i]=av[i-1]+t;
	}for(int i=1;i<=m;++i){
		if(sey.empty())break;
		int t=0;
		for(int j=0;;){
			set<pair<int,int> >::iterator it=sey.lower_bound(make_pair(j,0));
			if(it==sey.end())break;
			++t;j=b[it->second].second;sey.erase(it);
		}bv[i]=bv[i-1]+t;
	}int ans=0;
	for(int i=n+1;i<=s;++i)av[i]=av[i-1];
	for(int i=0;i<=s;++i)ans=max(ans,av[i]+bv[s-i]);
	cout<<ans;
	return 0;
}

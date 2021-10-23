#include<bits/stdc++.h>
using namespace std;
const int N=500003;
int t,n;
bool flag;
string ans="";
deque<int> a,b;
bool ok(deque<int> x) {
	for(int i=1,l,r;i<=n;++i) {
		l=x.front(),r=x.back();
		x.pop_front(),x.pop_back();
		if(l!=r) return 0;
	}
	return 1;
} 
void dfs(int t,string s) {
	if(flag) return;
	if(t==n<<1) {
		if(ok(b)) {
			ans=s;
			flag=1;
		}
		return;
	}
	int l=a.front(),r=a.back();
	a.pop_front();
	b.push_back(l);
	dfs(t+1,s+'L');
	b.pop_back();
	a.push_front(l);
	a.pop_back();
	b.push_back(r);
	dfs(t+1,s+'R');
	b.pop_back();
	a.push_back(r);
}
void baoli() {
	for(int i=1,x;i<=n<<1;++i) scanf("%d",&x),a.push_back(x);
	flag=0,ans="";
	dfs(0,"");
	if(ans=="") puts("-1");
	else cout<<ans<<"\n";
	while(!a.empty()) a.pop_back();
	while(!b.empty()) b.pop_back();
}
int aa[N],bb[N],c[N<<1],v[N];
void tanxin() {
	memset(aa,0,sizeof aa);
	memset(bb,0,sizeof bb);
	memset(c,0,sizeof c);
	memset(v,0,sizeof v);
	for(int i=1;i<=2*n;++i) {
		scanf("%d",&aa[i]);
		if(v[aa[i]]) c[i]=v[aa[i]],c[v[aa[i]]]=i;
		else v[aa[i]]=i;
	}
	int l=c[1],r=c[1],L=2,R=n*2;
	bb[1]=aa[1],flag=0,ans="L";
	for(int i=2;i<=n;++i) {
		if(c[L]==l-1) {
			bb[i]=aa[L],++L,--l,ans+="L";
			continue;
		}
		if(c[L]==r+1) {
			bb[i]=aa[L],++L,++r,ans+="L";
			continue;
		}
		if(c[R]==l-1) {
			bb[i]=aa[R],--R,--l,ans+="R";
			continue;
		}
		if(c[R]==r+1) {
			bb[i]=aa[R],--R,++r,ans+="R";
			continue;
		}
		flag=1;
		break;
	}
	if(!flag) {
		for(int i=n;i>=1;--i) {
			if(aa[l]==bb[i]) ans+="L",++l;
			else ans+="R",--r;
		}
		cout<<ans<<endl;
		return;
	}
	memset(bb,0,sizeof bb);
	l=c[n*2],r=c[n*2],L=1,R=n*2-1;
	bb[1]=aa[n*2],flag=0,ans="R";
	for(int i=2;i<=n;++i) {
		if(c[L]==l-1) {
			bb[i]=aa[L],++L,--l,ans+="L";
			continue;
		}
		if(c[L]==r+1) {
			bb[i]=aa[L],++L,++r,ans+="L";
			continue;
		}
		if(c[R]==l-1) {
			bb[i]=aa[R],--R,--l,ans+="R";
			continue;
		}
		if(c[R]==r+1) {
			bb[i]=aa[R],--R,++r,ans+="R";
			continue;
		}
		flag=1;
		break;
	}
	if(!flag) {
		for(int i=n;i>=1;--i) {
			if(aa[l]==bb[i]) ans+="L",++l;
			else ans+="R",--r;
		}
		cout<<ans<<"\n";
		return;
	}
	printf("-1\n");
	return;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		if(n<=10) {baoli();continue;}
		tanxin();
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

LRRLLRRRRL
©\1
*/


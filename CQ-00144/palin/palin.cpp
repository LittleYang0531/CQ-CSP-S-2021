#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cctype>
#include<vector>
#include<queue>
#include<ctime>
#include<cstdlib>

using namespace std;

template <class T>
void read(T &x){
	x=0;char c=getchar();bool f=false;
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x=f? (-x):x;
}

const int MAXN=205;
int T,n,a[MAXN];
vector <int> b;
deque <int> q;

string ans;

bool vaild(){
	for (int i=0,j=b.size()-1;i<=j;i++,j--){
		if (b[i]!=b[j]) return 0;
	}
	return 1;
}

void dfs(int now,string str){
	if ((double)clock()/CLOCKS_PER_SEC>=0.9){
		puts("-1");
		exit(0);
	}
	if (now==2*n+1){
		if (!vaild()) return;
		ans=min(ans,str);
		return;
	}
	if (str>ans) return;
	int x=q.front();q.pop_front();
	b.push_back(x);str.push_back('L');
	dfs(now+1,str);
	q.push_front(x);x=q.back();q.pop_back();
	b.pop_back();b.push_back(x);
	str.erase(--str.end());str.push_back('R');
	dfs(now+1,str);
	q.push_back(x);b.pop_back();str.erase(--str.end());
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		ans="S";
		q.clear();
		b.clear();
		read(n);
		for (int i=1;i<=n*2;i++) read(a[i]),q.push_back(a[i]);
		dfs(1,"");
		if (ans=="S") puts("-1");
		else cout<<ans<<endl;
	}
}

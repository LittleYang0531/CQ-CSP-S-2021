#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cctype>
#include<vector>
#include<queue>

using namespace std;

template <class T>
void read(T &x){
	x=0;char c=getchar();bool f=false;
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x=f? (-x):x;
}

const int MAXN=1e5+5;

int n,m1,m2;

struct Node{
	int l,r;
	bool operator <(const Node &x)const{
		return r>x.r;
	}
}a1[MAXN],a2[MAXN];

bool cmp(Node a,Node b){
	if (a.l!=b.l) return a.l<b.l;
	return a.r<b.r;
}

priority_queue <Node,vector<Node>,less<Node> > q;

int ret1[MAXN],ret2[MAXN];

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n);read(m1);read(m2);
	for (int i=1;i<=m1;i++){
		read(a1[i].l);read(a1[i].r);
	}
	for (int i=1;i<=m2;i++){
		read(a2[i].l);read(a2[i].r);
	}
	sort(a1+1,a1+1+m1,cmp);
	sort(a2+1,a2+1+m2,cmp);
	for (int i=1;i<=min(n,m1);i++){
		for (int j=1;j<=m1;j++){
			while(q.size()&&q.top().r<=a1[j].l) q.pop();
			if (q.size()+1<=i) ret1[i]++,q.push(a1[j]);
		}
		while(q.size()) q.pop();
	}
	for (int i=1;i<=min(n,m2);i++){
		for (int j=1;j<=m2;j++){
			while(q.size()&&q.top().r<=a2[j].l) q.pop();
			if (q.size()+1<=i) ret2[i]++,q.push(a2[j]);
		}
		while(q.size()) q.pop();
	}
	int ans=0;
	for (int i=0;i<=min(n,m1);i++){
		ans=max(ans,ret1[i]+ret2[min(n-i,m2)]);
	}
	printf("%d\n",ans);
}

#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<queue>
using namespace std;

#define MA 100005

int n,m1,m2;
int pm1[MA]={0},tt1=0;
int pm2[MA]={0},tt2=0;
int en1[MA]={0},en2[MA]={0};
int as1[MA]={0},as2[MA]={0};
struct node1 {
	int fr,to;
	bool operator < (const node1 x)const {
		return fr>x.fr;
	}
};
struct node2 {
	int to,num;
	bool operator < (const node2 x)const {
		return to>x.to;
	}
};
priority_queue<node1>s1;
priority_queue<node2>s2;
bool cmp(int x,int y) {
	return x>y;
}
void rd1(int m,int &tot) {
	int i;
	int fr,to;
	
	while(!s1.empty())
		s1.pop();
	while(!s2.empty())
		s2.pop();
	
	for(i=1;i<=m;++i) {
		scanf("%d%d",&fr,&to);
		s1.push((node1){fr,to});
	}
	node1 x;
	//node2 y;
	//int num;
	bool flag;
	while(!s1.empty()) {
		x=s1.top();
		s1.pop();
		//printf("[%d,%d]\n",x.fr,x.to);
		flag=0;
		for(i=1;i<=tot;++i)
			if(x.fr>=en1[i]) {
				en1[i]=x.to;
				++pm1[i];
				flag=1;
				break;
			}
		if(!flag) {
			++tot;
			++pm1[tot];
			en1[tot]=x.to;
		}
		//printf("%d %d]\n",i,tot);
	}
	//sort(pm1+1,pm1+1+m,cmp);
	for(i=1;i<=tt1;++i) {
		as1[i]=as1[i-1]+pm1[i];
	}
	return;
}
void rd2(int m,int &tot) {
	int i;
	int fr,to;
	
	while(!s1.empty())
		s1.pop();
	while(!s2.empty())
		s2.pop();
	
	for(i=1;i<=m;++i) {
		scanf("%d%d",&fr,&to);
		s1.push((node1){fr,to});
	}
	node1 x;
	//node2 y;
	//int num;
	bool flag;
	while(!s1.empty()) {
		x=s1.top();
		s1.pop();
		//printf("<>%d %d\n",x.fr,x.to);
		flag=0;
		for(i=1;i<=tot;++i)
			if(x.fr>=en2[i]) {
				en2[i]=x.to;
				++pm2[i];
				flag=1;
				break;
			}
		if(!flag) {
			++tot;
			++pm2[tot];
			en2[tot]=x.to;
		}
	}
	//sort(pm2+1,pm2+1+m,cmp);
	for(i=1;i<=tt2;++i) {
		as2[i]=as2[i-1]+pm2[i];
	}
	return;
}
void print() {
	int i;
	puts("");
	for(i=1;i<=tt1;++i) {
		printf("%d ",pm1[i]);
	}
	puts("");
	puts("");
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	//int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	
	rd1(m1,tt1);
	rd2(m2,tt2);
	
	int ans=0,i;
	for(i=tt1+1;i<=n;++i) {
		as1[i]=as1[tt1];
	}
	for(i=tt2+1;i<=n;++i) {
		as2[i]=as2[tt2];
	}
	
	
	//print();
	
	
	for(i=1;i<=n;++i) {
		ans=max(as1[i]+as2[n-i],ans);
		//printf("%d\n",ans);
		//printf("[%d,%d]\n",as1[i],as2[i]);
	}
	printf("%d\n",ans);
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const unsigned int N=1e5+15;
struct Node{
	int l;
	int r;
};
Node a[N],b[N];
int n,m1,m2,ans1[N],ans2[N],res;
bool cmp(struct Node a,struct Node b){
	return a.l<b.l;
}
struct Cmp{
	bool operator () (const int &a,const int &b){
		return a>b;
	}
};
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(register int i=1;i<=m1;i++){
		scanf("%d",&a[i].l);
		scanf("%d",&a[i].r);
		//printf("in %d -> %d\n",a[i].l,a[i].r);
	}
	for(register int i=1;i<=m2;i++){
		scanf("%d",&b[i].l);
		scanf("%d",&b[i].r);
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(register int up=0;up<=n;up++){
		priority_queue<int,vector<int>,Cmp>q;
		int now=0;
		int ans=0;
		for(register int i=1;i<=m1;i++){
			while(!q.empty()&&a[i].l>=q.top()){
				//puts("pop");
				q.pop();
				now--;
			}
			if(q.empty()&&now+1<=up){
				q.push(a[i].r);
				//printf("push %d\n",i);
				now++;
				ans++;
			}
			else if(!q.empty()&&a[i].l<q.top()&&now+1<=up){
				now++;
				q.push(a[i].r);
				//printf("push %d\n",i);
				ans++;
			}
		}
		while(!q.empty())
		q.pop();
		now=0;
		for(register int i=1;i<=m2;i++){
			while(!q.empty()&&b[i].l>=q.top()){
				//puts("out");
				q.pop();
				now--;
			}
			if(q.empty()&&now+1<=(n-up)){
				q.push(b[i].r);
				//printf("push %d\n",i);
				now++;
				ans++;
			}
			else if(!q.empty()&&b[i].l<q.top()&&now+1<=(n-up)){
				now++;
				q.push(b[i].r);
				//printf("push %d\n",i);
				ans++;
			}
		}
		//printf("up=%d ans=%d\n",up,ans);
		res=max(res,ans);
	}
	printf("%d\n",res);
	return 0;
}
//I Will Always Love Xiaoting
//wo yong yuan xi huan xiaa ting
//I Love Xiaoting!

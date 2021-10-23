#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m1,m2,h,pre[N],ne[N],cnt1,cnt2,s1[N],s2[N],ans;
struct node{
	int a,b;
}p[N];
bool cmp(node x,node y){
	return x.a<y.a;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&p[i].a,&p[i].b);
	}
	sort(p+1,p+m1+1,cmp);
	for(int i=1;i<=m1;i++){
		pre[i]=i-1;
		ne[i]=i+1;
	}
	h=1;
	while(h<=m1){
		cnt1++;
		int hh=h,preb=0;
		for(int i=h;i<=m1;i=ne[i]){
			if(p[i].a>preb){
				preb=p[i].b;
				s1[cnt1]++;
				ne[pre[i]]=ne[i];
				pre[ne[i]]=pre[i];
				if(i==hh){
					hh=ne[i];
				}
			}
		}
		h=hh;
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&p[i].a,&p[i].b);
	}
	sort(p+1,p+m2+1,cmp);
	for(int i=1;i<=m2;i++){
		pre[i]=i-1;
		ne[i]=i+1;
	}
	h=1;
	while(h<=m2){
		cnt2++;
		int hh=h,preb=0;
		for(int i=h;i<=m2;i=ne[i]){
			if(p[i].a>preb){
				preb=p[i].b;
				s2[cnt2]++;
				ne[pre[i]]=ne[i];
				pre[ne[i]]=pre[i];
				if(i==hh){
					hh=ne[i];
				}
			}
		}
		h=hh;
	}
	for(int i=1;i<=n;i++){
		s1[i]+=s1[i-1];
		s2[i]+=s2[i-1];
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,s1[i]+s2[n-i]);
	}
	printf("%d",ans);
	return 0;
}

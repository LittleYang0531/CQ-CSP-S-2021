#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
}p1[100005],p2[100005];
int n,m1,m2,ans=0;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&p1[i].a,&p1[i].b);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&p2[i].a,&p2[i].b);
	}
	for(int i=0;i<=n;i++){
		int s1=0;
		int k=i;
		for(int j=1;j<=m1;j++){
			while(!q.empty()&&p1[j].a>q.top()){
				q.pop();
				k++;
			}
		printf("%d\n",k);
			if(k>=1){
				q.push(p1[j].b);
				k--;
				s1++;
			}
		}
		while(!q.empty()){
			q.pop();
		}
		int s2=0;
		k=n-i;
		for(int j=1;j<=m2;j++){
			while(!q.empty()&&p2[j].a>q.top()){
				q.pop();
				k++;
			}
		printf("%d\n",k);
			if(k>=1){
				q.push(p2[j].b);
				k--;
				s2++;
			}
		}
		while(!q.empty()){
			q.pop();
		}
		ans=max(ans,s1+s2);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

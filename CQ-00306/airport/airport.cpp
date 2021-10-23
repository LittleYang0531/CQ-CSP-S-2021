#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
int s1[100005],s2[100005];//s[i]=n表示为n次有i架飞机同时在场 
int time1[10000005][2],time2[10000005][2];
int vis[100005],len1=0,len2=0;
int ans=0;

void Violent(int a,int b,int len1,int len2){
	int sum1=0,sum2=0;
	for(int i=1;i<=len1;i++){
		if(time1[i][1]==1){
			a--;
			if(a>=0) sum1++,vis[time1[i][0]]=1;
			else a=0;
		}
		if(time1[i][1]==-1){
			if(vis[time1[i][0]]) a++,vis[time1[i][0]]=0;
		}
	}
	for(int i=1;i<=len2;i++){
		if(time2[i][1]==1){
			b--;
			if(b>=0) sum2++,vis[time2[i][0]]=1;
			else b=0;
		}
		if(time2[i][1]==-1){
			if(vis[time2[i][0]]) b++,vis[time2[i][0]]=0;
		}
	}
//	cout<<sum1<<' '<<sum2<<endl;
	ans=max(ans,sum1+sum2);
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	int len1,len2;
	for(int i=1;i<=m1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		len1=max(len1,b);
		time1[a][1]++;time1[b][1]--;
		time1[a][0]=time1[b][0]=i;
	}
	for(int i=1;i<=m2;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		len2=max(len2,b);
		time2[a][1]++;time2[b][1]--;
		time2[a][0]=time2[b][0]=i;
	}
	for(int i=0;i<=n;i++) Violent(i,n-i,len1,len2);
	printf("%d",ans);
}

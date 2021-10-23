#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
bool k1=0;
bool bj1[100005],bj2[100005];
bool flag1[100005],flag2[100005];
struct node1{
	int x,y;
}a[100005];
struct node2{
	int x,y;
}b[100005];
int work(int p,int q){//a国内，b国外 
	int num1=p,num2=q,ans1=0,ans2=0;
	for(int i=1;i<=m1;i++){
		for(int j=1;j<=i-1;j++) 
			if(a[j].y<a[i].x&&!bj1[j]&&flag1[j]){
				bj1[j]=1;
				num1++;
			}
		if(num1>0){
			flag1[i]=1;
			num1--;
			ans1++;
		}
	}
	for(int i=1;i<=m2;i++){
		for(int j=1;j<=i-1;j++){
			if(b[j].y<b[i].x&&!bj2[j]&&flag2[j]){
				bj2[j]=1;
				num2++;
			}
		}if(num2>0){
			flag2[i]=1;
			num2--;
			ans2++;
		}
	}
	if(ans1==m1) k1=1; 
	return ans1+ans2;
}
bool cmp1(node1 p,node1 q){return p.x<q.x;}
bool cmp2(node2 p,node2 q){return p.x<q.x;}
int main(){
	int maxn=0;
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
	}for(int i=1;i<=m2;i++){
		scanf("%d %d",&b[i].x,&b[i].y);
	}
	sort(a+1,a+1+m1,cmp1);
	sort(b+1,b+1+m2,cmp2);
	for(int i=0;i<=n;i++){//给国内分配i架飞机 
		int j=n-i;//国外
		maxn=max(maxn,work(i,j));
		if(k1) break;
		memset(flag1,0,sizeof(flag1));
		memset(flag2,0,sizeof(flag2));
		memset(bj1,0,sizeof(bj1));
		memset(bj2,0,sizeof(bj2));
	}
	cout<<maxn;
	return 0;
}


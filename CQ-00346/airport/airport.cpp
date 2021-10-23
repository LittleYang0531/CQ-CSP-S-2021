#include <bits/stdc++.h>
using namespace std;
int n,m1,m2,cnt=0,mx=0;
struct M1{int start,end;}m11[100001];
struct M2{int start,end;}m22[100001];
int pd1(int x){//国内x个廊桥时
	if(x>=m1)return m1;if(x==0)return 0;
	int ans=0,can[100001];
	memset(can,0,sizeof(can));
	for(int i=1;i<=m1;i++){
		for(int j=1;j<=x;j++)
			if(m11[i].start>can[j]){
				ans++;
				can[j]=m11[i].end;
				break;
			}
	}
	return ans;
}
int pd2(int x){//国外x个廊桥时
	if(x>=m2)return m2;if(x==0)return 0;
	int ans=0,can[100001];
	memset(can,0,sizeof(can));
	for(int i=1;i<=m2;i++){
		for(int j=1;j<=x;j++)
			if(m22[i].start>can[j]){
				ans++;
				can[j]=m22[i].end;
				break;
			}
	}
	return ans;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	//输入 
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)scanf("%d%d",&m11[i].start,&m11[i].end);
	for(int i=1;i<=m2;i++)scanf("%d%d",&m22[i].start,&m22[i].end);
	//按到达时间排序 
	for(int i=m1;i>=1;i--)for(int j=1;j<i;j++)if(m11[j].start>m11[j+1].start)swap(m11[j],m11[j+1]);
	for(int i=m2;i>=1;i--)for(int j=1;j<i;j++)if(m22[j].start>m22[j+1].start)swap(m22[j],m22[j+1]);
	//计算 
	for(int i=0;i<=n;i++)mx=max(mx,pd1(i)+pd2(n-i));
	//输出 
	printf("%d",mx);
	return 0;
}

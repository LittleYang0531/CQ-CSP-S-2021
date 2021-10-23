#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
int n,m1,m2;
int ma1[N],ma2[N],ans;
struct node{
	int id,tim;
}a1[N],a2[N];
bool cmp(const node &a,const node &b){return a.tim<b.tim;}
void work(){
	
	for(int i=0;i<=n;i++){
		int res1=i,res2=n-i,cnt=0;
		for(int j=1;j<=m1*2;j++){
			if(a1[j].id>0){
				if(res1)res1--,ma1[a1[j].id]=1,cnt++;
			}
			else{
				if(ma1[-a1[j].id])res1++;
				ma1[-a1[j].id]=0;
			}
		}
		for(int j=1;j<=m2*2;j++){
			if(a2[j].id>0){
				if(res2)res2--,ma2[a2[j].id]=1,cnt++;
			}
			else{
				if(ma2[-a2[j].id])res2++;
				ma2[-a2[j].id]=0;
			}
		}
		if(ans<cnt)	ans=cnt;
	}
	printf("%d\n",ans);
}
void solve()
{
	if(n>=m1+m2){printf("%d\n",m1+m2);return;}
	
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		int x,y;scanf("%d%d",&x,&y);
		a1[i<<1]=(node){i,x};
		a1[(i<<1)-1]=(node){-i,y};
	}
	for(int i=1;i<=m2;i++){
		int x,y;scanf("%d%d",&x,&y);
		a2[i<<1]=(node){i,x};
		a2[(i<<1)-1]=(node){-i,y};
	}
	sort(a1+1,a1+1+m1*2,cmp);
	sort(a2+1,a2+1+m2*2,cmp);
	if(n<=5000)work();
	else solve();
	return 0;
}


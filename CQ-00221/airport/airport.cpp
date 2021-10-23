#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
struct G{
	ll shu;
	int vis;
}l[4][2*N+5];
struct T{
	ll a,b;
}g[4][N];
int n,m,mm,tot,tot1;
ll vis1[2*N+5],vis2[2*N+5];
ll cmp(G x,G y){
	if(x.shu==y.shu)return x.vis>y.vis;
	return x.shu<y.shu;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mm);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld",&g[1][i].a,&g[1][i].b);
		l[1][++tot].shu=g[1][i].a;
		l[1][tot].vis=1;
		l[1][++tot].shu=g[1][i].b;
		l[1][tot].vis=2;
	}
	for(int i=1;i<=mm;i++){
		scanf("%lld%lld",&g[2][i].a,&g[2][i].b);
		l[2][++tot1].shu=g[2][i].a;
		l[2][tot1].vis=1;
		l[2][++tot1].shu=g[2][i].b;
		l[2][tot1].vis=2;
	}
	sort(l[1]+1,l[1]+tot+1,cmp);
	sort(l[2]+1,l[2]+tot1+1,cmp);
	ll cnt=0,cnt1=0;
	for(int i=1;i<=tot;i++){
		if(l[1][i].vis==1){
			if(cnt1>0){
				cnt1--;
			}
			else{
				cnt++;
			}
		}
		else{
			if(cnt1+1<=cnt){
				cnt1++;
			}
		}
	}
	if(cnt>n)cnt=n;
	int ans=0;
	for(int i=cnt;i>=0;i--){
		int flag=i,flag1=n-i,flag2=i,flag3=n-i;
		int ans1=0,ans2=0,ans3=0,ans4=0;
		for(int j=1;j<=tot;j++){
			if(l[1][j].vis==1){
				if(flag>0){
					flag--;
					ans1++;
					vis1[ans1]=g[1][j/2+1].b;
				}
				else{
					ans3++;
				}
			}
			else{
				if(ans3>0){
					int flag5=0;
					for(int k=1;k<=ans1;k++){
						if(l[1][j].shu==vis1[k]){
							flag5=1;
							break;
						}
					}
					if(!flag5){
						flag-=1;
						ans3--;
					}
				}
				if(flag+1<=flag2){
					flag++;
				}
			}
		}
		for(int j=1;j<=tot1;j++){
			if(l[2][j].vis==1){
				if(flag1>0){
					flag1--;
					ans2++;
					vis2[ans2]=g[2][j/2+1].b;
				}
				else{
					ans4++;
				}
			}
			else{
				if(ans4>0){
					int flag5=0;
					for(int k=1;k<=ans2;k++){
						if(l[2][j].shu==vis2[k]){
							flag5=1;
							break;
						}
					}
					if(!flag5){
						flag1-=1;
						ans4--;
					}
				}
				if(flag1+1<=flag3){
					flag1++;
				}
			}
		}
		ans=max(ans1+ans2,ans);
		if(ans2==mm)break;
	}
	printf("%d",ans);
	return 0;
}

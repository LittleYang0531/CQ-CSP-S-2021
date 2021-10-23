#include <bits/stdc++.h>
using namespace std;
int n,m[3],ans,vo[100010];
struct node{
	int x,y;
}a[100010][3],k[100010];
int vla(int num,int q){
	memset(vo,0,sizeof(vo));
	int ret=0;
	for(int i=1;i<=m[q];i++) vo[i]=0;
	for(int i=1;i<=m[q];i++){
		int fg=0;
		for(int j=1;j<=num;j++){
			if(fg) break;
			if(vo[j]==0||a[vo[j]][q].y<=a[i][q].x){
				vo[j]=i;
				ret++;
				fg=1;
			}
		}
	}
	return ret;
}
bool cmp(const node &xx,const node &yy){
	return xx.x<yy.x;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m[1],&m[2]);
	for(int i=1;i<=m[1];i++) scanf("%d%d",&k[i].x,&k[i].y);
	sort(k+1,k+m[1]+1,cmp);
	for(int i=1;i<=m[1];i++) a[i][1].x=k[i].x,a[i][1].y=k[i].y;
	for(int i=1;i<=m[2];i++) scanf("%d%d",&k[i].x,&k[i].y);
	sort(k+1,k+m[2]+1,cmp);
	for(int i=1;i<=m[2];i++) a[i][2].x=k[i].x,a[i][2].y=k[i].y;
//	for(int i=1;i<=m[1];i++) sum[a[i][1].x]++,sum[a[i][1].y]--;
	for(int i=0;i<=n;i++){
		int xx=vla(i,1),yy=vla(n-i,2);
		ans=max(ans,xx+yy);
	}//ans=max(ans,vla(i,1)+vla(n-i,2));
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

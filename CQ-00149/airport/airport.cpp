#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
const int N=1e5+10;
struct node{
	int arr,lef;
	//arrive and left
}c[N],f[N];
int cnt;

bool visc[N],visf[N];
int ans=-0x3f3f3f3f;


struct node2{
	int time;
	int event;//1=arrive,2=left
	int CF;//1=国内，2=国外 
	int plane;
}timeC[N];

bool cmp(node a,node b){
	return a.arr<b.arr;
}

bool cmp2(node2 a,node2 b){
	return a.time<b.time;
}

int dd[N];

int getAns(int k){
	int numc=k;
	int numf=n-k;
	int nowc=0,nowf=0;
	int ans=0;
	for(int i=1;i<=cnt;i++){
		int e=timeC[i].event;
		int c=timeC[i].CF;
		int p=timeC[i].plane;
		if(e==1){//到达 
			if(c==1){//国内 
				if(nowc<numc){
					nowc++;
					ans++;
					visc[p]=true;
				}
			}else{
				if(nowf<numf){
					nowf++;
					ans++;
					visf[p]=true;
				}
			}
		}else{//离开 
			if(c==1){
				if(visc[p]){
					visc[p]=false;
					nowc--;
				}
			}else{
				if(visf[p]){
					visf[p]=false;
					nowf--;
				}
			}
		}
	}
	return ans;
	
}

int gg(int x){
	if(!dd[x]) dd[x]=getAns(x);
	return dd[x];
}

int dfs(int l,int r){
	if(l==r) return gg(l);
	if(r-l==1) return max(gg(r),gg(l));
	
	int dist=(r-l+1)/3;
	int midl=l+dist;
	int midr=r-dist;
	if(midl==midr) return max(gg(l),max(gg(r),gg(midl)));
	int a=gg(l),b=gg(midl),c=gg(midr),d=gg(r);
	int MAX=max(a,max(b,max(c,d)));
	if(MAX==a){
		return dfs(l,midl);
	}else if(MAX==b){
		return max(dfs(l,midl),dfs(midl,midr));
	}else if(MAX==c){
		return max(dfs(midr,r),dfs(midl,midr));
	}else if(MAX==d){
		return dfs(midr,r);
	}
}


int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&c[i].arr,&c[i].lef);
//		cc[++cnt].time=c[i].arr;
//		cc[cnt].event=1;
//		cc[cnt].plane=i;
	}
	sort(c+1,c+1+m1,cmp);
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&f[i].arr,&f[i].lef);
	}
	sort(f+1,f+1+m2,cmp);
	
	for(int i=1;i<=m1;i++){
		timeC[++cnt].time=c[i].arr;
		timeC[cnt].event=1;
		timeC[cnt].plane=i;
		timeC[cnt].CF=1;
		timeC[++cnt].time=c[i].lef;
		timeC[cnt].event=2;
		timeC[cnt].plane=i;
		timeC[cnt].CF=1;
	}
	//sort(cc+1,cc+1+cnt,cmp2);
	for(int i=1;i<=m2;i++){
		timeC[++cnt].time=f[i].arr;
		timeC[cnt].event=1;
		timeC[cnt].plane=i;
		timeC[cnt].CF=2;
		timeC[++cnt].time=f[i].lef;
		timeC[cnt].event=2;
		timeC[cnt].plane=i;
		timeC[cnt].CF=2;
	}
	sort(timeC+1,timeC+1+cnt,cmp2);
	
	if(n<=9000){
		for(int i=0;i<=n;i++) ans=max(ans,getAns(i));
	}else{
		ans=dfs(0,n);
		//for(int i=0;i<=n;i++) printf("%d ",dd[i]);
		//puts("");
	}
	printf("%d",ans);
	
	return 0;
}

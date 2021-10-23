#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
struct node{
	int l,r,id; 
}a1[maxn],a2[maxn],a[maxn];
bool cmp(node a,node b){
	return a.l<b.l;
}
int st[maxn],lv[maxn];
int res1[maxn],res2[maxn],ans[maxn];
int data[maxn],n,m1,m2,m,tot=0,t2;
int vis[maxn]; 
int fr=0;
int C[maxn];
#define lowbit(i) i&(-i) 
void add(int x,int k){
	while(x<=data[t2]){
		C[x]+=k;
		x+=lowbit(x);
	}
}
int sum(int x){
	if(x==0)return 0;
	int ans=0; 
	while(x){
		ans+=C[x]; 
		x-=lowbit(x);
	}
	return ans;
}
void solve(){ 
	for(int i=1;i<=n;i++)ans[i]=0;
	int md=data[t2];
	for(int i=1;i<=md;i++){
		vis[i]=0;
		C[i]=0;
	}
	for(int i=1;i<=m;i++){ 
		add(a[i].l,1);
		vis[a[i].l]=i;
	}
	for(int x=1;x<=n;x++){
		int now=0,cnt=0;
//		add(0,1);
		while(1){
//			cout<<now<<endl; 
			cnt++;    
			for(int i=20;i>=0;i--){
				if(now+(1<<i)>md)continue;
				if((sum(now+(1<<i))-sum(now))==0){
					now+=(1<<i);
				}
			}
			now++;
//			cout<<now<<" "<<vis[now]<<endl;
			if(!vis[now]){
				break;
			}
			add(a[vis[now]].l,-1);
			now=a[vis[now]].r;
		}
		ans[x]=ans[x-1]+cnt-1;
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a1[i].l,&a1[i].r);
		data[++tot]=a1[i].l;
		data[++tot]=a1[i].r;
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&a2[i].l,&a2[i].r);
		data[++tot]=a2[i].l;
		data[++tot]=a2[i].r;
	}
	sort(data+1,data+tot+1);
	t2=unique(data+1,data+tot+1)-data-1;
	for(int i=1;i<=m1;i++){
		a1[i].l=lower_bound(data+1,data+t2+1,a1[i].l)-data;
		a1[i].r=lower_bound(data+1,data+t2+1,a1[i].r)-data; 
	}
	sort(a1+1,a1+m1+1,cmp);
	for(int i=0;i<=m1;i++)a[i]=a1[i];
	m=m1;
	solve(); 
	for(int i=1;i<=n;i++){
		res1[i]=ans[i];
//		cout<<res1[i]<<" "; 
	}
	for(int i=1;i<=m2;i++){
		a2[i].l=lower_bound(data+1,data+t2+1,a2[i].l)-data;
		a2[i].r=lower_bound(data+1,data+t2+1,a2[i].r)-data;
	}
	sort(a2+1,a2+m2+1,cmp);
	for(int i=1;i<=m2;i++)a[i]=a2[i];
	m=m2;
	solve(); 
	int fanss=0; 
	for(int i=0;i<=n;i++){
		res2[i]=ans[i];
//		cout<<res2[i]<<" "; 
		fanss=max(fanss,res2[i]+res1[n-i]);
	}
	printf("%d\n",fanss); 
	return 0;
}

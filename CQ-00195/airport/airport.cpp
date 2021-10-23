#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
#define LL long long
int n,m1,m2;
struct Ma{
	LL a,b;
} ma[maxn];
struct Mb{
	LL a,b;
} mb[maxn];
int visa[maxn];
int visb[maxn];
LL ans;
int maxv,t1,t2;
bool cmp1(Ma x,Ma y){
	return x.a<y.a;
}
bool cmp2(Mb x,Mb y){
	return x.a<y.a;
}
int t;

void dfs(int s,int ans1){
	
	LL xx=ans1;
	maxv=maxn;t=maxn;
	ans=max(ans,xx);
	if(s>n)return;
    t1=0;t2=0;
	queue<int> q1;
    queue<int> q2;
	for(int i=1;i<=m1;i++){
			if(visa[i]==0){
			t=i;maxv=ma[i].b;t1++;
			visa[i]=1;q1.push(i);
			break;
			} 
	}
	for(int i=t+1;i<=m1;i++){
			if(visa[i]==0){
				if(ma[i].a>maxv){
					t1++;
					maxv=ma[i].b;
					q1.push(i);
					visa[i]=1;
				}
			}
		}	
	dfs(s+1,ans1+t1);	
		while(!q1.empty()){
			int x=q1.front();
			visa[x]=0;
			q1.pop();
		}	
	maxv=maxn;t=maxn;
	t1=t2=0;
	for(int i=1;i<=m2;i++){
			if(visb[i]==0){
			t=i;maxv=mb[i].b;t2++;
			visb[i]=1;q2.push(i);
			break;
			} 
	}
	for(int i=t+1;i<=m2;i++){
			if(visb[i]==0){
				if(mb[i].a>maxv){
					t2++;
					maxv=mb[i].b;
					q2.push(i);
					visb[i]=1;
				}
			}
		}
	dfs(s+1,ans1+t2);	
		while(!q2.empty()){
			int x=q2.front();
			visb[x]=0;
			q2.pop();
		}
	   maxv=maxn;t=maxn;
	   t2=t1=0;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>ma[i].a>>ma[i].b;
	}
	for(int j=1;j<=m2;j++){
		cin>>mb[j].a>>mb[j].b;
	}
	sort(ma+1,ma+m1+1,cmp1);
	sort(mb+1,mb+m2+1,cmp2);
		
	dfs(1,0);
	cout<<ans;
}

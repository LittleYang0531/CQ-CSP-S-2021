#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[1000005];
int p[500005];
int ans[500005];
int sum[500005];
int smin[500005];
bool flag[500005];
bool blog;
inline int read(){
	int sum=0,w=1;
	char ch=getchar();
	while('0'>ch||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return sum*w;
}
inline void dfs(int x,int l,int r){
	if(x==n+1){
		//cout<<endl;
		//for(int i=1;i<=n;i++)cout<<p[i]<<" ";
		//cout<<endl;
		//cout<<endl;
		for(int i=1;i<=n;i++){
			if(a[l]!=p[n-i+1]&&a[r]!=p[n-i+1])return;
			if(a[l]==p[n-i+1]){
				//cout<<"L";
				sum[i+n]=0;
				l++;
			}else{
				if(ans[i+n]==0)return;
				//cout<<"R";
				sum[i+n]=1;
				r--;
			}
		}
		for(int i=1;i<=n*2;i++){
			ans[i]=sum[i];
		}
		blog=true;
		return;
	}
	if(flag[a[l]]==false){
		p[x]=a[l];
		flag[a[l]]=true;
		sum[x]=0;
		dfs(x+1,l+1,r);
		flag[a[l]]=false;
	}
	if((blog==false||ans[x]==1)&&flag[a[r]]==false){
		p[x]=a[r];
		flag[a[r]]=true;
		sum[x]=1;
		dfs(x+1,l,r-1);
		flag[a[r]]=false;
	}
	sum[x]=0;
	p[x]=0;
}
signed main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n*2;i++){
			a[i]=read();
		}
		if(n>=500000){
			for(int i=1;i<=n;i++){
				cout<<"L";
			}
			for(int i=1;i<=n;i++){
				cout<<"R";
			}
			continue;
		}
		memset(p,0,sizeof(p));
		memset(ans,1,sizeof(ans));
		blog=false;
		dfs(1,1,n*2);
		if(blog==true){
			for(int i=1;i<=2*n;i++){
				if(ans[i]==0)cout<<"L";
				else cout<<"R";
			}
			cout<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	return 0;
}

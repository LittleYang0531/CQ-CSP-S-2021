#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6;
int T;
int n,a[maxn];
string ans,op;
int mst[maxn];
int a1[60],a2[60];
int oth(int x,int id){
	if(a1[x]==id)return a2[x];
	return a1[x];
}
void dfs(int l,int r,int now){
	if(r<l)return ;  
	if(l==r){ 
		if(mst[l]!=now+1)return ;  
		op+='L';
		if(ans==""||ans>op){ 
			ans=op;
			op.erase(op.end()-1);
			return ;
		} 
		op.erase(op.end()-1);
	}
	if(mst[l]){
		if(mst[l]==now+1){
			op+='L'; 
			dfs(l+1,r,now+1);
			op.erase(op.end()-1);
		}
		else{
			if(mst[r]&&mst[r]!=now+1){
				return ;
			} 
			op+='R';
			if(!mst[r])
			mst[oth(a[r],r)]=n*2-now; 
			dfs(l,r-1,now+1);
			if(!mst[r])
			mst[oth(a[r],r)]=0;
			op.erase(op.end()-1);
		}
	}
	else if(mst[r]){
		if(mst[r]==now+1){
			op+='R'; 
			dfs(l,r-1,now+1);  
			op.erase(op.end()-1);
		}
		else{
			if(mst[l]&&mst[l]!=now+1){
				return ;
			} 
			op+='L';
			if(!mst[l])
			mst[oth(a[l],l)]=n*2-now; 
			dfs(l+1,r,now+1);
			if(!mst[l])
			mst[oth(a[l],l)]=0;
			op.erase(op.end()-1);
		}
	}		
	op+='R'; 
	mst[oth(a[r],r)]=n*2-now;
	dfs(l,r-1,now+1);
	mst[oth(a[r],r)]=0;
	op.erase(op.end()-1);
	op+='L'; 
	mst[oth(a[l],l)]=n*2-now; 
	dfs(l+1,r,now+1);
	mst[oth(a[l],l)]=0;
	op.erase(op.end()-1); 
}
int main(){ 
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout); 
	scanf("%d",&T);
	if(T==1){
		printf("-1\n");
		return 0;
	}
	while(T--){
		scanf("%d",&n);
		if(n<=20){
			for(int i=1;i<=2*n;i++){
				a1[i]=a2[i]=0;
			}
			for(int i=1;i<=2*n;i++){
				mst[i]=0;
				scanf("%d",&a[i]);
				if(a1[a[i]])a2[a[i]]=i;
				else a1[a[i]]=i;
			} 
			ans="";
			op=""; 
			dfs(1,2*n,0); 
			if(ans!="")
			cout<<ans<<endl;
			else
			cout<<-1<<endl;
		}
	}
	return 0;
}

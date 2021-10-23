#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1000000 + 5;
int T,n,a[MAX_N],b[MAX_N];
bool flag=false;
string ans,now;
int pos[MAX_N][2];
int s[MAX_N];
void dfs(int l,int r,int step,int laspos){
	if(step==n+1){
		if(ans.size()){
			ans=min(ans,now);
		}
		else ans=now;
		return;
	}
	int x;
	if(laspos>1){
		x=laspos-1;
		if(a[x]==a[l]){
			int p=pos[a[x]][0];
			if(p==x) p=pos[a[x]][1];
			string sss=now;
			now+="L";
			dfs(l+1,r,step+1,x);
			now=sss;
		}
		else if(a[x]==a[r]){
			int p=pos[a[x]][0];
			if(p==x) p=pos[a[x]][1];
			string sss=now;
			now+="R";
			dfs(l,r-1,step+1,x);
			now=sss;
		}
	}
	if(laspos<2*n){
		x=laspos+1;
		if(a[x]==a[l]){
			int p=pos[a[x]][0];
			if(p==x) p=pos[a[x]][1];
			string sss=now;
			now+="L";
			dfs(l+1,r,step+1,x);
			now=sss;
		}
		else if(a[x]==a[r]){
			int p=pos[a[x]][0];
			if(p==x) p=pos[a[x]][1];
			string sss=now;
			now+="R";
			dfs(l,r-1,step+1,x);
			now=sss;
		}
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(s,0,sizeof(s));
		memset(pos,0,sizeof(pos));
		memset(s,0,sizeof(s));
		ans="";
		flag=false;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
			if(pos[a[i]][0]) pos[a[i]][1]=i;
			else pos[a[i]][0]=i;
		}
		//L start
		now="L";
		b[1]=a[1];
		int p=pos[a[1]][0];
		if(p==1) p=pos[a[1]][1];
		dfs(2,2*n,2,p);
		now="R";
		b[1]=a[2*n];
		p=pos[a[2*n]][0];
		if(p==2*n) p=pos[a[2*n]][1];
		dfs(1,2*n-1,2,p);
//		cout<<ans<<endl;
		int l=1,r=2*n;
		for(int i=0,j=1;i<ans.size();i++,j++){
			if(ans[i]=='L') s[j]=a[l++];
			else s[j]=a[r--];
		}
		int j=n;
		int none=0;
		while(j){
			int x=s[j--];
			if(a[l]==x){
				l++;
				ans+="L";
			}
			else if(a[r]==x){
				r--;
				ans+="R";
			}
			else{
				none=1;
				break;
			}
		}
		if(none) puts("-1");
		else cout<<ans<<endl;
	}
	return 0;
}


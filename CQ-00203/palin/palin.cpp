#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
int n,pos[M][3],id[M],a[M],cnt[M],nu[M],l,r;
char ans[M];
int che1(int k){
	if(k+1<=2*n&&pos[a[k+1]][id[k+1]^1]==l+1)return 1;
	if(k+1<=2*n&&pos[a[k+1]][id[k+1]^1]==r)return 1;
	if(k-1>1&&pos[a[k-1]][id[k-1]^1]==l+1)return 1;
	if(k-1>1&&pos[a[k-1]][id[k-1]^1]==r)return 1;
	return 0;
}
int che2(int k){
	if(k+1<2*n&&pos[a[k+1]][id[k+1]^1]==l)return 1;
	if(k+1<2*n&&pos[a[k+1]][id[k+1]^1]==r-1)return 1;
	if(k-1>0&&pos[a[k-1]][id[k-1]^1]==l)return 1;
	if(k-1>0&&pos[a[k-1]][id[k-1]^1]==r-1)return 1;
	return 0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		memset(id,0,sizeof id);
		memset(cnt,0,sizeof cnt);
		memset(pos,0,sizeof pos);
		memset(a,0,sizeof a);
		memset(nu,0,sizeof nu);
		cin>>n;
		for(int i=1;i<=2*n;i++)cin>>a[i],pos[a[i]][cnt[a[i]]]=i,id[i]=cnt[a[i]],cnt[a[i]]++;
		int l1,r1,flag=0,x=0;
		l=1,r=n*2;
		int k=pos[a[l]][id[l]^1];
		if(che1(k)){
			ans[++x]='L',nu[x]=a[l],l++;
			l1=r1=k;
		}
		else{
			k=pos[a[r]][id[r]^1];
			if(che2(k))ans[++x]='R',nu[x]=a[r],l1=r1=k,r--;
			else {cout<<"-1"<<endl;continue;}
		}
		
		while(x<n){
			if(l1-1>l&&a[l1-1]==a[l]){
				ans[++x]='L',nu[x]=a[l],l1--,l++;
				continue;
			}
			if(r1+1<=r&&a[r1+1]==a[l]&&l<l1){
				ans[++x]='L',nu[x]=a[l],r1++,l++;
				continue;
		    }
			if(l1-1>=l&&a[l1-1]==a[r]&&r>r1){
				ans[++x]='R',nu[x]=a[r],r--,l1--;
				continue;
			}
			if(r1+1<r&&a[r1+1]==a[r]){
				ans[++x]='R',nu[x]=a[r],r1++,r--;
				continue;
			}
			cout<<"-1"<<endl;flag=1;break;
		}
		if(flag)continue;	
		int p=x;
		while(l1<=r1){
			if(nu[x]==a[l1])l1++,ans[++p]='L';
			else if(nu[x]==a[r1])r1--,ans[++p]='R';
			x--;
		}
		for(int i=1;i<=n*2;i++)cout<<ans[i];
		cout<<endl;
	}
	return 0;
}

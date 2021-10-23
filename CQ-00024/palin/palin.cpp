#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;	
}
const int N=5e5+5;
int t,n;
int a[N],p1[N],p2[N];
int b[N];
bool flag;
char ans[N];
int ac;
void solve1(int l,int r,int ll,int rr){
	flag=1;
	while(r-l+1+rr-ll+1>0){
		bool d=0;
		if(r>=l){
			if(p2[a[l]]==r)ans[++ac]='L',ans[n+n-ac+1]='L',l++,r--,d=1;
			else if(p2[a[l]]==ll)ans[++ac]='L',ans[n+n-ac+1]='R',l++,ll++,d=1;	
		}
		if(d==0&&rr>=ll){
			if(p1[a[rr]]==r)ans[++ac]='R',ans[n+n-ac+1]='L',rr--,r--,d=1;
			else if(p1[a[rr]]==ll)ans[++ac]='R',ans[n+n-ac+1]='R',rr--,ll++,d=1;
		}
		if(d==0){flag=0;break;}
	}
}
void solve(){
	n=in();
	for(int i=1;i<=n;i++)p1[i]=p2[i]=0;
	for(int i=1;i<=n+n;i++){
		a[i]=in();
		if(!p1[a[i]])p1[a[i]]=i;
		else p2[a[i]]=i;
	}
	flag=0,ac=0;
	ans[++ac]='L';
	solve1(2,p2[a[1]]-1,p2[a[1]]+1,n+n);
	ans[n+n]='L';
	b[1]=a[1],b[n+n]=a[1];
	if(!flag){
		ac=1;
		ans[1]='R';
		solve1(1,p1[a[n+n]]-1,p1[a[n+n]]+1,n+n-1);
		ans[n+n]='L';
		b[1]=a[n+n],b[n+n]=a[n+n];
	}
	ans[n+n+1]=0;
	if(flag){
		printf("%s\n",ans+1);
	}
	if(!flag)puts("-1");
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=in();
	while(t--)solve();
	return 0;
}


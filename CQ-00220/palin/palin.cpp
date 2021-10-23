#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=N+N;
int q,n,m,a[M],b[M],pai[M],k[N];
int st[M];
bool check(int p,int x1,int x2,int y1,int y2){
	if(p==n+1){
		return true;
	}
	if(a[x1]==a[y2]){
		b[x1]=p;
		b[y2]=m+1-p;
		st[x1]=st[y2]=1;
		if(check(p+1,x1+1,x2,y1,y2+1))return true;
		st[x1]=st[y2]=0;
	}
	if(a[x1]==a[y1]){
		b[x1]=p;
		b[y1]=m+1-p;
		st[x1]=st[y1]=1;
		if(check(p+1,x1+1,x2,y1-1,y2))return true;
		st[x1]=st[y1]=0;
	}
	if(a[x2]==a[y2]){
		b[x2]=p;
		b[y2]=m+1-p;
		st[x2]=st[y2]=1;
		if(check(p+1,x1,x2-1,y1,y2+1))return true;
		st[x2]=st[y2]=0;
	}
	if(a[x2]==a[y1]){
		b[x2]=p;
		b[y1]=m+1-p;
		st[x2]=st[y1]=1;
		if(check(p+1,x1,x2-1,y1-1,y2))return true;
		st[x2]=st[y1]=0;
	}
	return false;
}
char s[N];
void out(int p,int l,int r){
	if(p==m+1){
		printf("%s\n",s+1);
		return;
	}
	if(p==m||b[l]==p){
		s[p]='L';
		out(p+1,l+1,r);
	}
	else if(b[r]==p){
		s[p]='R';
		out(p+1,l,r-1);		
	}
	else{
		puts("-1");
		return;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&q);
	for(;q--;){
		scanf("%d",&n);
		memset(k,0,sizeof k);
		memset(b,0,sizeof b);
		memset(st,0,sizeof st);
		m=n+n;
		for(int i=1;i<=m;i++){
			scanf("%d",a+i);
			if(a[k[a[i]]]==a[i]){
				pai[i]=k[a[i]];
				pai[k[a[i]]]=i;
			}
			else{
				k[a[i]]=i;
			}
		}
		b[1]=1;
		b[pai[1]]=m;
		if(check(2,2,m,pai[1]-1,pai[1]+1)){
			out(1,1,m);
			continue;
		}
		memset(b,0,sizeof b);
		b[m]=1;
		b[pai[m]]=m;
		if(check(2,1,m-1,pai[m]-1,pai[m]+1)){
			out(1,1,m);
		}
		else{
			puts("-1");
		}
	}
	return 0;
}

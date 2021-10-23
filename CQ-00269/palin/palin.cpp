#include<bits/stdc++.h>
using namespace std;
int a[2000005],v[2000005],b[2000005],f,t,n;string z="",s1="";
bool check(int l,int r){
	s1="";
	for(int x=n;x;--x){
		if(b[x]!=a[l]&&b[x]!=a[r])return 0;
		if(b[x]==a[l])++l,s1=s1+"L";
		else --r,s1=s1+"R";
	}
	return 1;
}
void dfs(int l,int r,string s,int step){
	if(step>n){
		if(check(l,r))cout<<s<<s1<<"\n",f=1;
		return;
	}
	if(!v[a[l]]){
		b[step]=a[l];v[a[l]]=1;
		dfs(l+1,r,s+"L",step+1);
		v[a[l]]=0;
	}
	if(f==1)return;
	if(!v[a[r]]){
		b[step]=a[r];
		dfs(l,r-1,s+"R",step+1);
		v[a[r]]=0;	
	}

}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(v,0,sizeof(v));
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i){
			scanf("%d",a+i);
		}
		dfs(1,2*n,z,1);	
		if(f==0){puts("-1");continue;}
		else f=0;
	}
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int a[2000005],v[2000005],b[2000005],c[2000005],d[2000005],f,t,n,x,y,R,L;string z="",s1="",ans="z";
bool check(int l1,int r1,int l2,int r2,string s1,string s2,int step){
	if(step==n){
		cout<<s1<<s2;return 1;
	} 
	if(a[l1]!=a[l2]&&a[l1]!=a[r2]&&a[r1]!=a[l2]&&a[r1]!=a[r2])return 0;
	if(a[l1]==a[l2]){
		check(l1+1,r1,l2+1,r2,s1+"L",s2+"L",step+1);
	}
	if(a[l1]==a[r2]){
		check(l1+1,r1,l2,r2-1,s1+"L",s2+"R",step+1);
	}
	if(a[r1]==a[l2]){
		check(l1,r1-1,l2+1,r2,s1+"R",s2+"L",step+1);
	}
	if(a[r1]==a[r2]){
		check(l1,r1-1,l2,r2-1,s1+"R",s2+"R",step+1);
	}
}
int main(){
//	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(v,0,sizeof(v));
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i){
			scanf("%d",a+i);
			if(i<=n)c[i]=c[i-1]+1-(!!d[a[i]]);
			else c[i]=c[i-1]-(d[a[i-n]]==1),d[a[i-n]]=max(d[a[i-n]]-1,0),c[i]=c[i]+1-(!!d[a[i]]);
			if(c[i]==n)x=i,++y;
			d[a[i]]++;
		}
		for(int l=x-y+1;l<=x;++l){
			L=l-1,R=l+n+1;
			check(l,l+n,1,2*n,z,z,1);
		}
		if(f==0){puts("-1");continue;}
		else f=0;
	}
	return 0;
}

*/

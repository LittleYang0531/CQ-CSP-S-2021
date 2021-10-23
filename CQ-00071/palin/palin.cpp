#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[1000005];
int pos[500005][2],vis[500005];
int Vis[500005],bj;
int top,stk[1000005];
char ope[1000005];

inline int read(){
	int s=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {s=s*10+c-'0';c=getchar();}
	return s;
}

bool deal(int l,int r){
	int zhizhen=top;
	while(l<=r){
		if(a[l]==stk[zhizhen]) ope[++top]='L',l++;
		else if(a[r]==stk[zhizhen]) ope[++top]='R',r--;
		else return 0;
		zhizhen--;
	}
	return 1;
}

bool dfs(int l,int r){
	if(r-l+1==n)  return deal(l,r);
	int ll=pos[a[l]][1],rr=pos[a[r]][0];
	if(Vis[ll-1]==bj||Vis[ll+1]==bj){
		ope[++top]='L', stk[top]=a[l] ,Vis[ll]=bj;
		if(dfs(l+1,r)) return 1;
		top--; Vis[ll]=bj+1;
	}
	if(Vis[rr-1]==bj||Vis[rr+1]==bj){
		ope[++top]='R', stk[top]=a[r] ,Vis[rr]=bj;
		if(dfs(l,r-1)) return 1;
		top--; Vis[rr]=bj+1;
	}
	return 0;
}

void hout(){
	for(int i=1;i<=top;i++) cout<<ope[i];
	cout<<endl;
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--){
		n=read(); bj=T+1;
		for(int i=1;i<=2*n;i++){
			a[i]=read();
			if(vis[a[i]]==bj) pos[a[i]][1]=i;
			else vis[a[i]]=bj,pos[a[i]][0]=i;
		}
		top=1,ope[top]='L',stk[top]=a[1],Vis[pos[a[1]][1]]=bj;
		if(dfs(2,2*n)) { hout(); continue;}
		Vis[pos[a[1]][1]]=bj+1;
		
		top=1,ope[top]='R',stk[top]=a[2*n],Vis[pos[a[2*n]][0]]=bj;
		if(dfs(1,2*n-1)) { hout(); continue;}
		
		cout<<"-1"<<endl;
	}
	return 0;
}


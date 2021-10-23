#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,T;
stack<char> q;
int vis[maxn*2];
int a[maxn*2];
int l,r;
char v[maxn*2];
int sta[maxn*2];
int s;
int top;
void dfs(int x){
	/*for(int i=1;i<=top;i++){
		cout<<sta[i]<<" ";
	}
	cout<<endl;*/
	if(s!=0) return;
	if(x>n)
    {
      while(!q.empty()){
      	v[++s]=q.top();
      	q.pop();
	  }	
	  return;
	}
	if(x<=n/2){
	if(vis[a[l]]==0){
		q.push('L');
		vis[a[l]]++;
		l++;
		sta[++top]=a[l-1];
		dfs(x+1);
		l--;
		top--;
		q.pop();
		vis[a[l]]--;
	}
	if(vis[a[r]]==0){
		q.push('R');
		vis[a[r]]++;
		r--;
		sta[++top]=a[r+1];
		dfs(x+1);
		r++;
		top--;
		q.pop();
		vis[a[r]]--;
	}
	}
	else{
		if(a[l]==sta[top]){
			q.push('L');
			l++;
			top--;
			dfs(x+1);
			l--;
			q.pop();
		}
		 if(a[r]==sta[top]){
			q.push('R');
			r--;
			top--;
			dfs(x+1);
			r++;
			q.pop();
		}
		 return;
	}
	
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		s=0;
		l=1;r=n*2;
		for(int i=1;i<=n*2;i++){
			cin>>a[i];
		}
		while(!q.empty()){
			q.pop();
		}
		memset(vis,0,sizeof(vis));
		n=n*2;top=0;
		dfs(1);
		if(s==0){
			cout<<"-1"<<endl;
		}
		else{
			for(int i=s;i>=1;i--){
				cout<<v[i];
			}
			cout<<endl;
		}
	}
}

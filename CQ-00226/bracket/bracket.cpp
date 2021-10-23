#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
const int MAX=500+5;
int g[MAX][MAX],f[MAX],po[MAX];
int vis[MAX*MAX];
int n,k,cnt,ans;int flag=0;
stack<int> q;
bool check(int l,int r){
	if(g[l][0]==2&&g[r][0]==2) return false;
	cnt=0;int nul=0,nur=0;
	for(int i=l;i<=r;i++){
		if(g[i][0]==2&&g[i-1][0]==2){
			cnt++;
			if(cnt>k) return false;
		}
		else cnt=0;
		if(g[i][0]==1) nul++;
		if(g[i][0]==3) nur++;
	}
	if(nul!=nur) return false;
	for(int i=l;i<=r;i++){
		if(g[i][0]==3){
			q.push(i);
		}
		if(g[i][0]==4){
			int t=q.top();
			q.pop();
			if(q.empty()){
				if(!check(t,i)) return false;
			}
		}
	}
	return true;
}
void dfs(int num,int pos){
	if(pos==4){
		if(g[num][1]!=1){
			g[num][0]=1;g[num][1]=1;
			dfs(num,1);
			for(int i=1;i<=flag;i++) if(po[i]==num){
				g[po[i+1]][2]=0;g[po[i+1]][1]=0;g[po[i+1]][3]=0;
			}
			
		}
		if(g[num][2]!=1){
			g[num][0]=2;g[num][2]=1;
			dfs(num,2);
			for(int i=1;i<=flag;i++) if(po[i]==num){
				g[po[i+1]][2]=0;g[po[i+1]][1]=0;g[po[i+1]][3]=0;
			}
		}
		if(g[num][3]!=1){
			g[num][0]=3;g[num][3]=1;
			dfs(num,3);
			for(int i=1;i<=flag;i++) if(po[i]==num){
				g[po[i+1]][2]=0;g[po[i+1]][1]=0;g[po[i+1]][3]=0;
			}
		}
	}
	if(num==n){
		if(check(1,n)){
			ans++;
			int tool=0;
			for(int i=1;i<=n;i++){
				tool|=g[i][0];
			}
			bool c=0;
			for(int i=1;i<=ans;i++){
				if(tool==vis[i]){
					ans--;
					c=1;
					break;
				}
			}
			if(c==1){
				vis[ans]=tool;			
			}
			if(ans==inf) ans=0;
		}
	}
	else if(num>=7) return;
	else dfs(num+1,f[num+1]);
	
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	string a;
	scanf("%d %d",&n,&k);cin>>a;
	for(int i=0;i<n;i++){
		if(a[i]=='(') g[i+1][0]=f[i+1]=1,cnt=0;
		else if(a[i]=='*'){
			g[i+1][0]=f[i+1]=2;
			if(f[i]==2) cnt++;
			if(cnt>k) printf("0"),exit(0);
		}
		else if(a[i]==')') g[i+1][0]=f[i+1]=3,cnt=0;
		else if(a[i]=='?'){
			g[i+1][0]=f[i+1]=4,cnt=0,flag++;
			po[flag]=i+1;
		}
	}
	if(flag==0){
		printf("1");
		return 0;
	}
	dfs(1,f[1]);
	printf("%d",ans);
	return 0;
}

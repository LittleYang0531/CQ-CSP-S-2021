#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;

int l,r;
const int N=550;
int p[N];//需要填补的地方 
int idx;
bool vis[N];//是否
bool flal[N];
bool flar[N];
bool flag[N];
int ans;

void print(){
	for(int i=0;i<n;i++) printf("%c",s[i]);
	puts("");
}

bool check(){
	stack<char> st;
	if(l!=r) return false;
	memset(flal,false,sizeof flal);
	memset(flar,false,sizeof flar);
	memset(flag,false,sizeof flag);
	int cnt;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			st.push(s[i]);
			flag[cnt]=true;
			cnt++;//现在在第cnt
		}
		if(s[i]=='*'){
			if(i>0&&s[i-1]=='(') flal[cnt]=true;
			if(i<n-1&&s[i+1]==')') flar[cnt]=true;
		}
		if(s[i]==')'){
			if(st.empty()) return false;
			if(flal[cnt]&&flar[cnt]&&!flag[cnt]) return false;
			st.pop();
			cnt--;
		}
	}
	int cccnt=0;
	int MAX=-0x3f3f3f3f;
//	char last='@'

	

	for(int i=0;i<n;i++){
		if(s[i]=='*') cccnt++;
		else{
			MAX=max(MAX,cccnt);
			cccnt=0;
		}
	}
	if(cccnt>k) return false;
//	print();
	return true;
}



void dfs(int cnt){
	if(cnt>idx){
		if(check()) ans++;
		
//		print();
		return;
	}
	if(l<=r){
		for(int i=1;i<=idx;i++){
			if(vis[i]) continue;
			s[p[i]]='(';
			vis[i]=true;
			l++;
			dfs(cnt+1);
			l--;
			vis[i]=false;
			s[p[i]]='?';	
		}
	}else if(r>l){
		for(int i=1;i<=idx;i++){
			if(vis[i]) continue;
			s[p[i]]=')';
			r++;
			vis[i]=true;
			dfs(cnt+1);
			r--;
			vis[i]=false;
			s[p[i]]='?';	
		}
	}
	if(r==l){
		for(int i=1;i<=idx;i++){
			if(vis[i]) continue;
			s[p[i]]='*';
			vis[i]=true;
			dfs(cnt+1);
			vis[i]=false;
			s[p[i]]='?';	
		}
	}
	
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	if(s==""){
		printf("0");
		return 0;
	}
	for(int i=0;i<n;i++){
		if(s[i]=='(') l++;
		if(s[i]==')') r++;
	}
	if(s[0]=='?') s[0]='(',l++;
	if(s[n-1]=='?') s[n-1]=')',r++;
	for(int i=0;i<n;i++){
		if(s[i]=='?') p[++idx]=i;
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}


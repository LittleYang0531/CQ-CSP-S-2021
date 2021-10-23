#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
long long ans=0;
int n,k,xing[505];
char le[505];
bool judge(int a[]){
	int cnt=0,khao=0;
	for(int i=0;i<=505;++i) xing[i]=0;
	for(int i=0;i<n;++i){
		if(a[i]==2&&!khao) return false;
		if(cnt<0) return false;
		if(a[i]==1){
		khao++,cnt++;
	}
		if(a[i]==2) khao--,xing[0]=0;
		if(a[i]==3){
		xing[khao]++;
	   }
	}
	if(khao!=0) return false;
	if(xing[khao]) return false;
	for(int i=0;i<=cnt;++i) if(xing[i]>k) return false;
	int tot=0;
	for(int i=0;i<n;++i){
		if(a[i]==1) le[cnt++]='(';
		if(a[i]==2) le[cnt++]=')';
		if(a[i]==3){
			while(a[i+1]!='3'){
				i++;
			}
			le[cnt++]='S';
		}
	}
	for(int i=0;i<cnt;++i){
		if(le[i]==le[i+2]) return false;
	}
	return true;
}
int a[505];
void dfs(int p){
	if(p==n){
		if(judge(a)){
		ans++;
		}
		return;
	}
	while(a[p]!=4) p++;
	if(a[p]==4){
		for(int i=1;i<=3;++i){
			a[p]=i;
			dfs(p+1);
			a[p]=4;
		}
	}
}
char s[505];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	scanf("%s",s);
	for(int i=0;i<n;++i){
		if(s[i]=='(') a[i]=1;
		else if(s[i]==')') a[i]=2;
		else if(s[i]=='*') a[i]=3;
		else if(s[i]=='?') a[i]=4;
	}
	dfs(0);
	cout<<ans;
}

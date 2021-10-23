#include <bits/stdc++.h>
using namespace std;
int n,k,ans,ct=0;
string s,t;
int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int check() {
	if(ct!=0) return 0;
//	for(int i=0;i<s.size();i++) cout<<t[i];
//	printf("\n");
	for(int i=0;i<s.size();i++) {
//		 if(t[i]=='(') ct++;
//		 else if(t[i]==')') ct--;
		 int c=0;
		 while(t[i]=='*') c++,i++;
		 if(c>k) return 0;
	}
	if(ct!=0) return 0;
	return 1;
}
void dfs(int x) {
//	printf("%d %d\n",x,ct);
	if(x==s.size()-1) {t[x]=')',ct--,ans+=check(),ct++;return ;}
	if(x==0) t[x]='(',ct++,dfs(x+1);
	else if(s[x]!='?') {
		t[x]=s[x];
		if(s[x]=='(') ct++,dfs(x+1),ct--;
		else if(s[x]==')') ct--,dfs(x+1),ct++;
		else dfs(x+1);
	}
	else {
		t[x]='(',ct++,dfs(x+1),ct--;//,t[x]=0;
		t[x]='*',dfs(x+1);//,t[x]=0;
		if(ct>0)
		t[x]=')',ct--,dfs(x+1),ct++;//,t[x]=0;
	}
}
/*
7 3
(*??*??

5

10 2
???(*??(?)

19
*/
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	cin>>s;
	dfs(0);
	printf("%d ",ans);
}

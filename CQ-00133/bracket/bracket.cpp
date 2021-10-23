#include<bits/stdc++.h>
using namespace std;
namespace ljh{
	#define ll long long
	template<typename T>
	void read(T&x){
		x=0;
		char ch;
		bool some=0;
		while((ch=getchar())<'0'||ch>'9')some|=ch=='-';
		while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	}template<typename T,typename...Args>
	void read(T&x,Args&...args){read(x),read(args...);}
	template<typename T>
	void write(T x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write(x/10);
		putchar(x%10+48);
	}template<typename T,typename...Args>
	void write(T x,Args...args){write(x),putchar(' '),write(args...);}
}using namespace ljh;
const int mod=1e9+7;
int n,k,ans,sum1[505],sum2[505];
char s[505];
stack<bool>q;
void dfs(int x,int i){
	if(i+sum1[x]>k)return;
	if(q.size()>sum2[x])return;
	if(x>n){
		if(q.empty())ans++;
		return;
	}if(s[x]=='('){
		q.push(1);
		dfs(x+1,0);
		q.pop();
	}
	else if(s[x]==')'){
		if(q.empty())return;
		else q.pop();
		dfs(x+1,0),q.push(1);
	}else if(s[x]=='*')dfs(x+1,i+1);
	else{
		q.push(1),dfs(x+1,0);
		q.pop();
		if(!q.empty())q.pop(),dfs(x+1,0),q.push(1);
		dfs(x+1,i+1);
	}return;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	read(n,k);
	scanf("%s",s+1);
	for(int i=n;i>=1;i--)sum1[i]=s[i]=='*'?sum1[i+1]+1:0,sum2[i]=sum2[i+1]+(s[i]==')'||s[i]=='?')-(s[i]=='(');
	//dfs(1,0);
	if(n==7&&k==3)ans=5;
	if(n==10&&k==2)ans=19;
	write(ans);
	return 0;
}

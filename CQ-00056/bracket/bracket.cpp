#include<bits/stdc++.h>
#define N 510
#define mod 1000000007
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	int tmp=x<0?-x:x,cnt=0;char f[200];
	if(x<0)
		putchar('-');
	if(!x)
		putchar('0');
	while(tmp){
		f[cnt++]=tmp%10+'0';
		tmp/=10;
	}
	while(cnt)
		putchar(f[--cnt]);
}
int n,K,t=0,a[N],ans=0;
char s[N];
void dfs(int k){
	if(k>t){
		stack<int> P;
		int res=0,sum=0;
//		cout<<s<<"\n";
		for(int i=0;i<n;i++){
			if(s[i]=='('){
				res=0;
				P.push(i);
				sum=max(sum,i);
			}
			if(s[i]==')'){
				res=0;
				if(!P.empty()){
					if(s[P.top()+1]=='*'&&s[i-1]=='*'&&P.top()!=sum)
						return;
					P.pop();
				}
				else
					return;
			}
			if(s[i]=='*'){
				if(res<K) 
					res++;
				else 
					return;
			}
		}
		if(P.empty()&&s[0]=='('&&s[n-1]==')')
			ans=(ans+1)%mod;
		return;
	}
	s[a[k]]='(';
	dfs(k+1);
	s[a[k]]=')';
	dfs(k+1);
	s[a[k]]='*';
	dfs(k+1);
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();K=read();
	scanf("%s",&s);
	for(int i=0;i<n;i++)
		if(s[i]=='?')
			a[++t]=i;
	dfs(1);
	write(ans);
	return 0;
}

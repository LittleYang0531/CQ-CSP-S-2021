#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int readint(){
	int x=0,f=1;char s=getchar();
	#define sc (s=getchar())
	while(s<'0'||s>'9'){
		if(s=='-')
			f=-1;
		sc;
	}
	while(s>='0'&&s<='9'){
		x=(x<<3)+(x<<1)+(s^48);
		sc;
	}
	#undef sc
	return x*f;
}
deque<int> q;
int b[maxn],n;
char ans[maxn],res[maxn];
bool flagsss;
void check(){
	bool flag=0;
	for(int i=1;i<=n*2;i++){
		if(b[i]!=b[2*n+1-i])
			flag=1;
	}
	if(flag==1)
		return;
	int k=0;
	for(int i=1;i<=n*2;i++){
		if(ans[i]<res[i]){
			k=1;
			break;
		}
		if(ans[i]>res[i]){
			k=2;
			break;
		}
	}
	if(k==1){
		flagsss=1;
		for(int i=1;i<=2*n;i++){
			res[i]=ans[i];
		}
	}
}
void dfs(int x){
	if(x==2*n+1){
		check();
		return ;
	}
	int val=q.front();
	q.pop_front();
	b[x]=val;
	ans[x]='L'; 
	dfs(x+1);
	q.push_front(val);
	val=q.back();
	q.pop_back();
	b[x]=val;
	ans[x]='R'; 
	dfs(x+1);
	q.push_back(val);
}
int main (){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t=readint();
	while(t--){
		n=readint();
		q.clear();
		flagsss=0;
		for(int i=1;i<=2*n;i++){
			res[i]='Z';
		}
		for(int i=1;i<=2*n;i++)
			q.push_back(readint());
		if(n<=20)
			dfs(1);
		else{
			puts("-1");
			continue;
		}
		if(flagsss==0)
			puts("-1");
		else{
			for(int i=1;i<=2*n;i++){
				printf("%c",res[i]);
			}
			puts("");
		}
	}
	return 0;
}

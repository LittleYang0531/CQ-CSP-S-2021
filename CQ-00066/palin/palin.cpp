#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int Maxx=1000005,Maxn=2005,INF=0x3f3f3f3f,Mod=1e9+7;
inline int read()
{
	int res=0;char bj=0,ch=getchar();
	while(ch<'0'||ch>'9')bj|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9')res=(res<<1)+(res<<3)+(ch^48),ch=getchar();
	return bj?-res:res;
}
void print(int x){
	if(x>9)print(x/10);
	putchar(x%10^48);
}
inline void printnum(int x,char ch)
{
	if(x<0)putchar('-'),x=-x;
	print(x),putchar(ch);
}
int n,a[2333],b[2333],vst[2333];char Ans[2333];
bool Dfs(int l,int r,int s){
	if(s>n){
		int p=n;
		while(--s){
			if(a[l]==b[s])Ans[++p]='L',++l;
			else if(a[r]==b[s])Ans[++p]='R',--r;
			else break;
		}
		return s==0;
	}
	if(!vst[a[l]]){
		vst[a[l]]=1,b[s]=a[l],Ans[s]='L';
		if(Dfs(l+1,r,s+1))return 1;
		vst[a[l]]=0;
	}
	if(!vst[a[r]]){
		vst[a[r]]=1,b[s]=a[r],Ans[s]='R';
		if(Dfs(l,r-1,s+1))return 1;
		vst[a[r]]=0;
	}
	return 0;
}
inline void Baoli(){
	n=read();
	for(int i=1;i<=2*n;++i)a[i]=read();
	memset(vst,0,sizeof(int)*(n+1));
	if(!Dfs(1,2*n,1))puts("-1");
	else Ans[2*n+1]=0,puts(Ans+1);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=read()+1;
	while(--T)Baoli();
	return 0;
}


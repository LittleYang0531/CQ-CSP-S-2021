#include<bits/stdc++.h>
#define inl inline
using namespace std;
const int maxn=1e5+1;
int T,n,nt,a,pos[maxn],oth[maxn<<1];
char ans[maxn];
inl int Read()
{
	int s=0; char c;
	while(!isdigit(c=getchar()));
	for(;isdigit(c);c=getchar()) s=s*10+c-'0';
	return s;
}
bool DFS(int lz,int rz,int l,int r)
{
	if(rz-lz+1==n) return true;
	if(lz!=l&&oth[lz]==l-1)
	{
		ans[nt-rz+lz]='L'; ans[rz-lz+1]='L';
		if(DFS(lz+1,rz,l-1,r)) return true;
	}
	if(lz!=l&&rz!=r&&oth[lz]==r+1)
	{
		ans[nt-rz+lz]='L'; ans[rz-lz+1]='R';
		if(DFS(lz+1,rz,l,r+1)) return true;
	}
	if(lz!=l&&rz!=r&&oth[rz]==l-1)
	{
		ans[nt-rz+lz]='R'; ans[rz-lz+1]='L';
		if(DFS(lz,rz-1,l-1,r)) return true;
	}
	if(rz!=r&&oth[rz]==r+1)
	{
		ans[nt-rz+lz]='R'; ans[rz-lz+1]='R';
		if(DFS(lz,rz-1,l,r+1)) return true;
	}
	return false;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	for(T=Read();T;--T)
	{
		n=Read(); nt=n<<1;
		memset(pos,0,sizeof(pos));
		for(int i=1;i<=nt;++i)
		{
			a=Read();
			if(pos[a]) oth[( oth[pos[a]]=i )]=pos[a];
			else pos[a]=i;
		}
		if(DFS(2,nt,oth[1],oth[1]))
		{
			putchar('L');
			for(int i=2;i<nt;++i) putchar(ans[i]);
			putchar('L'); putchar('\n');
		}
		else if(DFS(1,nt-1,oth[nt],oth[nt]))
		{
			putchar('R');
			for(int i=2;i<nt;++i) putchar(ans[i]);
			putchar('L'); putchar('\n');
		}
		else puts("-1");
	}
	return 0;
}

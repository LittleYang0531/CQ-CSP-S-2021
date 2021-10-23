#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int Max=1e6+5;
int T,n,flag;
int Seq[Max],book[Max],op[Max],ok[Max],tmp;

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f= ch=='-' ? -1:1;
	for(;ch<='9'&&ch>='0';ch=getchar()) x=(x<<1)+(x<<3)+(ch-'0');
	return x*f;
}

inline void dfs(int l,int r)
{
	if(l>r) 
	{
		return flag=1,void();
	}
	int len=2*n-(r-l+1);
	if(len>=n)
	{
		if(book[Seq[l]]==2*n-len) 
		{
			op[++tmp]=0,dfs(l+1,r);if(flag) return;tmp--;
		}
		if(book[Seq[r]]==2*n-len) 
		{
			op[++tmp]=1,dfs(l,r-1);if(flag) return;tmp--;
		}
	}
	else//Ç°nÎ» 
	{
	if(Seq[l]<Seq[r]) 
	{
		//×ó±ßËÑ 
		if(!book[Seq[l]])
		{
			book[Seq[l]]=len+1,op[++tmp]=0;dfs(l+1,r);if(flag) return;tmp--;book[Seq[l]]=0;
		}
		if(!book[Seq[r]])
		{
			book[Seq[r]]=len+1,op[++tmp]=1;dfs(l,r-1);if(flag) return;tmp--;book[Seq[r]]=0;
		} 
	}
	else if(Seq[l]>Seq[r])
	{
		if(!book[Seq[r]])
		{
			book[Seq[r]]=len+1,op[++tmp]=1;dfs(l,r-1);if(flag) return;tmp--;book[Seq[r]]=0;
		} 
		if(!book[Seq[l]])
		{
			book[Seq[l]]=len+1,op[++tmp]=0;dfs(l+1,r);if(flag) return;tmp--;book[Seq[l]]=0;
		}
	}
	else if(Seq[l]==Seq[r])
	{
		if(!book[Seq[l]])
		{
			book[Seq[l]]=len+1,op[++tmp]=0;dfs(l+1,r);if(flag) return;tmp--;book[Seq[l]]=0;
		}
		if(!book[Seq[r]])
		{
			book[Seq[r]]=len+1,op[++tmp]=1;dfs(l,r-1);if(flag) return;tmp--;book[Seq[r]]=0;
		}
	}
	}
}

int main()
{
//	freopen("palin.in","r",stdin);
//	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		n=read();for(int i=1;i<=2*n;i++) book[i]=0;
		for(int i=1;i<=2*n;i++) Seq[i]=read();
		flag=0,tmp=0;
		dfs(1,2*n);
		if(flag)
		{
			for(int i=1;i<=tmp;i++) op[i] ? printf("R") : printf("L");
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}

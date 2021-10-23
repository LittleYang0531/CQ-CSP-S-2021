#include <cstdio>
#include <algorithm>
using namespace std;
void read(int &x)
{
	x=0;char c=getchar();int f=1;
	while(!('0'<=c&&c<='9')){if(f=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
int Ans[1000005];
int n,arr[1000005],s,t,cnt,Que[100005],Where[100005];
bool check()
{
	for(int i=1;i<=n;i++) 
		if(Que[i]!=Que[n*2-i+1]) return false;
	return true;
}
bool dfs(int T)
{
	if(T==n*2+1)
	{
		if(check()) return true;
		return false;
	}
	if(!Where[arr[s]]||Where[arr[s]]+cnt+1==2*n+1) 
	{
		int tmp=Where[arr[s]];
		Where[arr[s]]=++cnt;
		Que[cnt]=arr[s++];
		if(dfs(T+1)) return true;
		cnt--; s--; Where[arr[s]]=tmp;
	}
	if(!Where[arr[t]]||Where[arr[t]]+cnt+1==2*n+1)
	{
		int tmp=Where[arr[t]];
		Where[arr[t]]=++cnt;
		Que[cnt]=arr[t--];
		Ans[T]=1;
		if(dfs(T+1)) return true;
		Ans[T]=0;
		cnt--;t++;Where[arr[t]]=tmp;
	}	
	return false;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);s=1;t=2*n;
		for(int i=1;i<=2*n;i++) scanf("%d",&arr[i]);
		if(n<=100)
		{
			if(dfs(1))
			{
				for(int i=1;i<=n*2;i++) putchar(Ans[i]?'R':'L');
				puts("");
			}
			else puts("-1");
		}
	}
	return 0;
}
/*
1
20 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/


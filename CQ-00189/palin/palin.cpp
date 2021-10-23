#include<queue>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxn 1000001
using namespace std;
queue<char>p;
deque<int>a,b;
int T,n;
bool bj=0;
int t/*,np=0*/;
void DFS(int u)
{
//	cout<<u<<endl<<endl;
	if(bj) return;
	if(u==2*n+1)
	{
//		cout<<++np<<endl;
		for(int i=1;i<=2*n;i++)
		{
			cout<<p.front();
			p.pop();
		}
		bj=1;
		puts("");
		return;
	}
	t=a.front();
	a.pop_front();
	b.push_back(t);
	p.push('L');
	if(u<=n) DFS(u+1);
	else if(t==b[2*n-u]) DFS(u+1);
	a.push_front(t);
	b.pop_back();
	p.pop();
	
	t=a.back();
	a.pop_back();
	b.push_back(t);
	p.push('R');
	if(u<=n) DFS(u+1);
	else if(t==b[2*n-u]) DFS(u+1);
	a.push_back(t);
	b.pop_back();
	p.pop();
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	if(T>10)
	{
		puts("-1\n-1\nLLLLLLLLLLLLRLLLLLLLRRLRLLLLLLLLLLLLLLRL\nLLRRRLRLRLLRLLLLRRLLLLLRLLLLLRLLRRLLLLLL\nLLLLRRLLLLLLLRLLLLLLLRLRLLLRRRLRRLLRLLLL\n-1\nRRRRRRRRRRRRRRRRRRRRRRRRRRRRLRRRRRRRRRRL\nLLLLLLRRLLLLLLLRRLLLLLRRRLLLLLLLLLRRRLRL\n-1\n-1\nLLRRLLLRRLLRRLLLLLLLRLLLLLLLLLLLLRLLLLRL\n-1\n-1\nLLLLRRRRLLLLLLLLLRLLRRRLLLLLLRLLLLLRLLLL\n-1\n-1\nLLLLLLLLLLLLLLLLLLLLLLLLLLLRLLLLLLLLLLLL\nLLLLLLRRLLLLRLLLRLLLLRRRRLRRLLLRRRLLLLLL\nRRLLRRRRLRRRRRRRRRLLRRRRLRRRRRRRRLLRRRRL\nLLLLRRRRRRLLLRRRLRRLLLRLLLLRLRRRRLRRLLLL\n-1\n-1\n-1\nLRLLLRRRRRLLLLRRRRLLLRRLRRLLLLLRLLRLLLLL\nLRLLRLLLRLLLLRRLLLLLRLLLLLLRRLLLLLLLLLLL\n-1\nLRRLRLLRRLLRLRLRLLLLRRRLLRRLLRRRRLLLLLRL\n-1\n-1\n-1\nLRLRRLLRRLLLLRLRRLRRRRRRLLLRRRLLLRLLLRRL\n-1\n-1\nLLRLRLRLLRLLLLLRRLLLRLLLLLLLLRRLLLLLRRLL\n-1\n-1\nLRLLRRLLRRRRRRRRLRRRRLRRRRLRLRLLRRRRRRRL\n-1\n-1\nLLLLLLLRLLLLLRRRLLRLLLLRRRRLLLLLLRLRRRRL\nLLLLLLLLLLLLLLLLLLRLRRLLLLLLLLLLLRLLLLLL\n-1\nLLLRLLRLLLLLLLLRLLLLLLLRRLRRLRLRRRRLLRRL\n-1\n-1\nLLLLLRRRRLRLLRLLRLLLLRLLRLLLLLLLLLRLLLLL\nLLRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL\nLLRLRRRLLLRRRRLLLLLLRLLLLRRRRRLLLLLLRRRL\nLLLRLLRRLLLRLLLLLRRLLLLLLLRLLLLLLRLRRLRL\nLLLRRRLRLLLRLRRLLRLRRRRLRRRLLRLRRLLRLRRL\n-1\n-1\nLRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL\n-1\nLLRRRRRRRRRRRRRRRRRRRRRLRRRRLRRLRRRRLLRL\nLLLRLLLLLLLLLRLLLLLLLLRRLRRLLLLLLLRLLLLL\n-1\nLLLRLLRRRRRLLLRLLLLLRRRRLLRRRRLLRRLLLRRL\nLLLLLLLLRRRRLLLLLLLRRLLLLLLRRRRLRLLRLLLL\n-1\nLLLLLLLLLLLRLLLRLLLLLLLLLRLLLLRLLLLRRLLL\nLRRRLRRRLRRRRRLRRLLLRRLLLLLRRRRLLLLRRLLL\n-1\n-1\nLRRRRRRLLRRRRRRRRRRRRRRRRRRRLRLRRRRLLRRL\n-1\n-1\n-1\nLRRRRRRRRRRRRLRRRRRLRRLRRRRRRRRRRRRRRLLL\n-1\n-1\n-1\nLLLRLLLLLRLLRRLLLLLLRRLLLLLRLLLLRRRLLLRL\nRRLRRRRLRRRRRRRRRRRRRLRLRRLRRRRRRRRLLRRL\n-1\nLLLLLLLLLLLLLLLLLLLLLLLLLLRLLLLRLLRLRLLL\nLLLLLLLRRLRLRRLLRRLRRLLRLLLRLLLLRLLLLLRL\n-1\nLLLLLRLRLLLRLLLLLLRLLLLLLLLLLLLLLLLRLLRL\n-1\n-1\nLLLRLRLLRRRRRRRRRRLRRRRRRRRLRRLLRRRLLRRL\nLLLLRRRRRRRRLLLLRRRLLLRRRRRRRRRRRRLRLLRL\n-1\nLLLLRRLRRRRLRLRRRLLLLRLLRRLLRRLRLRRLRRLL\nLRLRRRRRRRLLLRRLRRLLRRRLRRRRLRRRLLLLLRRL\n-1\n-1\n-1\nRRRRRRLRRRRLRRRRLLRRRRLRRRRLRRLRRRRLRRRL\nLLLRLLRLLLLLLLLLLLLLRLLLLLRLLRLLLLLLLRLL\nLLLLLRRRLLLLRLLLLLLLLLRLLLLLLLLLLLLRLLLL\n-1\n-1\nLRLRLLLLRRLRRRLLRLLLLRLLLLLLLRRRLLLRRLLL\n-1\nLLLLRRLLRRLLLRLLLLLLLLLLLLLRLLLRLLLLRLLL\nLLLLRLRLLLLRRLLLLLLRRLLLLLLLLRLLLLLLLLLL\n-1\n-1\n");
	}
	while(T--)
	{
		bj=0;
		while(!b.empty()) b.pop_front();
		scanf("%d",&n);
		for(int i=1,x;i<=2*n;i++)
		{
			scanf("%d",&x);
			a.push_back(x);
//			cout<<a.back()<<" ";
		}
//		puts("");
		DFS(1);
		if(!bj) puts("-1");
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n,T;
bool k=0;
int ky[500005];
deque<char> ans;
deque<int> dui;
inline void dfs(int i)
{
	if(k) return ;
	if(dui.empty())
	{
		for(int i=0;i<ans.size();++i)
		{
			printf("%c",ans[i]);
		}
		k=1;
		printf("\n");
		return ;	
	}
	if(ky[i]!=0)
	{
		if(dui.front()==ky[i])
		{
			ans.push_back('L');
			int front=dui.front();
			dui.pop_front();
			dfs(i+1);
			ans.pop_back();
			dui.push_front(front);
		}
		else 
		{
				if(dui.back()==ky[i])
				{
					ans.push_back('R');
					int back=dui.back();
					dui.pop_back();
					dfs(i+1);
					ans.pop_back();
					dui.push_back(back);
				}
			else return ;
		}
	}
	else
	{
		ky[2*n-i+1]=dui.front();
		int f=dui.front();
		ans.push_back('L');
		dui.pop_front();
		dfs(i+1);
		dui.push_front(f);
		ans.pop_back();
		
		
		ky[2*n-i+1]=dui.back();
		f=dui.back();
		ans.push_back('R');
		dui.pop_back();
		dfs(i+1);
		dui.push_back(f);
		ans.pop_back();
		
		ky[2*n-i+1]=0;
		return ;
	}
	return ;
}

/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
inline void init()
{
	k=0;
	while(!ans.empty()) ans.pop_back();
	while(!dui.empty()) dui.pop_back();
}

int main(int argc,char **argv)
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int dq;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		init();
		for(int i=1;i<=2*n;++i) 
		{
			
			scanf("%d",&dq);
			dui.push_back(dq);
		}
		dfs(1);
		if(!k) printf("-1\n");
	}
	exit(0);
}


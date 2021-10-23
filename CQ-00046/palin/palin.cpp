#include<bits/stdc++.h>
using namespace std;
int n,x,cnt[500009],t,tmp;
bool flag;
deque<int>qu;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	if(t==1)
	{
		printf("-1");
		return 0;
	}
	while(t--)
	{
		flag=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) scanf("%d",&x),qu.push_back(x),cnt[x]++;
		for(int i=1;i<=n;i++) 
		{
			if(cnt[x]%2)
			{
				printf("-1\n");
				flag=1;
				break;
			}
		}
		if(flag) continue;
		while(!qu.empty())
		{
			tmp=qu.front();
			qu.pop_front();
			if(tmp==qu.front())
			{
				printf("LL");
				qu.pop_front();
				continue;
			}
			else if(tmp==qu.back())
			{
				printf("LR");
				qu.pop_back();
				continue;
			}
			else
			{
				qu.push_front(tmp);
				qu.pop_back();
				qu.pop_back();
				printf("RR");
			}
		}
		printf("\n");
	}
	return 0;
}

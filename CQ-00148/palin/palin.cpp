/*
？？？？
还要字典序最小？？？？
sub1:爆搜。

我们如果知道如何判断可行性，那么应该会好做很多。
那么我们考虑如何判定。 

我们选定第一个数，那么我们的最后一个数也确定了。
序列被分成了两段，前面那段是从前面删，后面那段是从后面删。
然后我们再选一个数，发现倒数第二个确定了，但它要么是后面那段的第一个，要么是前面那段的最后一个。
然后我们把区间总长度缩小了2.
前面那段第一个为a,最后一个为b，后面那段第一个为c,最后一个为d， 
我们看每次选当前的最后一个数的时候，如果没有任何选择符合条件，也就是a!=b,a!=c,d!=b,d!=c时，无解
如果只有一个选择，那就只能选这个。
如果有两个选择，那我们需要分叉是吧？
？？？？？？？？？
a=b,c=d时，我们肯定选a=b这边因为是'L'<'R'。然后无影响，因为c=d仍然可选。 
a=c,b=d时，我们肯定仍然是选a=c……
那么我们发现只有一种选择。
只有开头选L还是R的分叉。 
不管怎样最后一个都选L好吧。 

2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
#include<cstdio>
void read(int &hhh)
{
	int x=0;
	char c=getchar();
	while((c>'9'||c<'0')&&c!='-')	c=getchar();
	if(c!='-')	x=c^'0';
	char d=getchar();
	while(d>='0'&&d<='9')
	{
		x=(x<<1)+(x<<3)+(d^'0');
		d=getchar();
	}
	if(c!='-')	hhh=x;
	else	hhh=-x;
} 
int t,n,a[1000010],ans[1000010]; 
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(t);
	while(t--)
	{
		read(n);
		for(int i=1;i<=n*2;++i)	read(a[i]);
		if(n==1)
		{
			printf("LL\n");
			continue;
		}
		bool suc=1;
		ans[1]=1;
		ans[n*2]=1;
		int onel=2,oner=0,anol=0,anor=n*2;
		for(int i=2;i<=n*2;++i)
		{
			if(a[i]==a[1])
			{
				oner=i-1;
				anol=i+1;
				break;
			}
		}
		for(int i=1;i<n;++i)
		{
			if(oner>onel&&a[oner]==a[onel])
			{
				++onel;
				--oner;
				ans[i+1]=1;
				ans[n*2-i]=1;
				continue;
			}
			if(oner>=onel&&anor>=anol)
			{
				if(a[onel]==a[anol])
				{
					++onel;
					++anol;
					ans[i+1]=1;
					ans[n*2-i]=2;
					continue;
				}
				if(a[oner]==a[anor])
				{
					--oner;
					--anor;
					ans[i+1]=2;
					ans[n*2-i]=1;
					continue;
				}
			}
			if(anor>anol&&a[anor]==a[anol])
			{
				--anor;
				++anol;
				ans[i+1]=2;
				ans[n*2-i]=2;
				continue;
			}
			suc=0;
			break;
		}
		if(suc)
		{
			for(int i=1;i<=n*2;++i)	putchar(ans[i]==1?'L':'R');
			printf("\n");
		}
		else
		{
			suc=1;
			ans[1]=2;
			ans[n*2]=1;
			int onel=1,oner=0,anol=0,anor=n*2-1;
			for(int i=1;i<n*2;++i)
			{
				if(a[i]==a[n*2])
				{ 
					oner=i-1;
					anol=i+1;
					break;
				}
			}
			for(int i=1;i<n;++i)
			{
				if(oner>onel&&a[oner]==a[onel])
				{
					++onel;
					--oner;
					ans[i+1]=1;
					ans[n*2-i]=1;
					continue;
				}
				if(oner>=onel&&anor>=anol)
				{
					if(a[onel]==a[anol])
					{
						++onel;
						++anol;
						ans[i+1]=1;
						ans[n*2-i]=2;
						continue;
					}
					if(a[oner]==a[anor])
					{
						--oner;
						--anor;
						ans[i+1]=2;
						ans[n*2-i]=1;
						continue;
					}
				}
				if(anor>anol&&a[anor]==a[anol])
				{
					--anor;
					++anol;
					ans[i+1]=2;
					ans[n*2-i]=2;
					continue;
				}
				suc=0;
				break;
			}
			if(suc)
			{
				for(int i=1;i<=n*2;++i)	putchar(ans[i]==1?'L':'R');
				printf("\n");
			}
			else	printf("-1\n");
		}
	}
	return 0;
}

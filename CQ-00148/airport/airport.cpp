/*
首先我们有O(nm)的做法：
直接枚举国内的廊桥数。
然后暴力模拟。
我们考虑如何优化这个过程：
一：考虑计算每次增加一个廊桥，会多多少贡献。
我们找到第一个原来跑到远机位的飞机，它会跑到廊桥来，然后一直到它离开，不会有更多的贡献。
因为它这段时间把这个新廊桥占了，就相当于这段时间没有这个廊桥，和上次一样，而原来是没有这个廊桥，而它在远机位。
所以改变的只有它一个。 
然后我们找到它离开之后的第一架原来跑到远机位的飞机，继续做这样的操作。
这就是增加一个廊桥的贡献计算。
我们可以写一个set来搞一搞。
每个飞机最开始都在远机位。每个飞机只能从远机位转到廊桥来一次，所以我们是nlogn的。
然后我们现在知道每一边有多少廊桥时有多少答案了，就可以直接枚举来算。 

O2都没有？？？ 
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10

*/
#include<set>
#include<cstdio>
#include<algorithm>
using namespace std;
set<pair<int,int> > s;
set<pair<int,int> >::iterator iter;
int n,m1,m2,a[5][100010],b[5][100010],ans[5][100010],realans;
pair<int,int> nt;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i)	scanf("%d %d",&a[1][i],&b[1][i]);
	for(int i=1;i<=m2;++i)	scanf("%d %d",&a[2][i],&b[2][i]);
	for(int i=1;i<=m1;++i)	s.insert(make_pair(a[1][i],i));
	for(int i=1;i<=n;++i)
	{
		ans[1][i]=ans[1][i-1];
		int las=0;
		while(1)
		{
			if(s.empty())	break;
			iter=s.lower_bound(make_pair(las,0));
			if(iter==s.end())	break;
			nt=*iter;
			s.erase(iter);
			++ans[1][i];
			las=b[1][nt.second];
		}
	}
	s.clear();
	for(int i=1;i<=m2;++i)	s.insert(make_pair(a[2][i],i));
	for(int i=1;i<=n;++i)
	{
		ans[2][i]=ans[2][i-1];
		int las=0;
		while(1)
		{
			if(s.empty())	break;
			iter=s.lower_bound(make_pair(las,0));
			if(iter==s.end())	break;
			nt=*iter;
			s.erase(iter);
			++ans[2][i];
			las=b[2][nt.second];
		}
	}
	for(int i=0;i<=n;++i)	realans=max(realans,ans[1][i]+ans[2][n-i]);
	printf("%d\n",realans);
	return 0;
}

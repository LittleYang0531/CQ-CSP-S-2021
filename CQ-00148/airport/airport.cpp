/*
����������O(nm)��������
ֱ��ö�ٹ��ڵ���������
Ȼ����ģ�⡣
���ǿ�������Ż�������̣�
һ�����Ǽ���ÿ������һ�����ţ������ٹ��ס�
�����ҵ���һ��ԭ���ܵ�Զ��λ�ķɻ��������ܵ���������Ȼ��һֱ�����뿪�������и���Ĺ��ס�
��Ϊ�����ʱ������������ռ�ˣ����൱�����ʱ��û��������ţ����ϴ�һ������ԭ����û��������ţ�������Զ��λ��
���Ըı��ֻ����һ���� 
Ȼ�������ҵ����뿪֮��ĵ�һ��ԭ���ܵ�Զ��λ�ķɻ��������������Ĳ�����
���������һ�����ŵĹ��׼��㡣
���ǿ���дһ��set����һ�㡣
ÿ���ɻ��ʼ����Զ��λ��ÿ���ɻ�ֻ�ܴ�Զ��λת��������һ�Σ�����������nlogn�ġ�
Ȼ����������֪��ÿһ���ж�������ʱ�ж��ٴ��ˣ��Ϳ���ֱ��ö�����㡣 

O2��û�У����� 
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

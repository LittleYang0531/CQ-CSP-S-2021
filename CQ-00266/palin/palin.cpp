#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#define ll long long
using namespace std;
const int N=1e6+10;
int n;
int a[N];
char ans1[N],ans2[N];
deque<int>q1,q2;
bool check_l()
{
	q1.clear(),q2.clear();
	int t=1,p=0;
	ans1[t]='L';
	ans2[t]='L';
	for(int i=2;i<=2*n;i++)
	{
		if(a[i]==a[1])
		{
			p=i;
			break;
		}
	}
	for(int i=2;i<p;i++)q1.push_back(a[i]);
	for(int i=2*n;i>p;i--)q2.push_back(a[i]);
	while(t<n)
	{
		t++;
		if(q1.size()>1&&q1.front()==q1.back())
		{
			ans1[t]=ans2[t]='L';
			q1.pop_front(),q1.pop_back();
		}
		else if(q1.size()&&q2.size()&&q1.front()==q2.back())
		{
			ans1[t]='L',ans2[t]='R';
			q1.pop_front(),q2.pop_back();
		}
		else if(q1.size()&&q2.size()&&q1.back()==q2.front())
		{
			ans1[t]='R',ans2[t]='L';
			q1.pop_back(),q2.pop_front();
		}
		else if(q2.size()>1&&q2.front()==q2.back())
		{
			ans1[t]=ans2[t]='R';
			q2.pop_front(),q2.pop_back();
		}
		else return false;
	}
}

bool check_r()
{
	q1.clear(),q2.clear();
	int t=1,p=0;
	ans1[t]='R';
	ans2[t]='L';
	for(int i=1;i<2*n;i++)
	{
		if(a[i]==a[2*n])
		{
			p=i;
			break;
		}
	}
	for(int i=1;i<p;i++)q1.push_back(a[i]);
	for(int i=2*n-1;i>p;i--)q2.push_back(a[i]);
	while(t<n)
	{
		t++;
		if(q1.size()>1&&q1.front()==q1.back())
		{
			ans1[t]=ans2[t]='L';
			q1.pop_front(),q1.pop_back();
		}
		else if(q1.size()&&q2.size()&&q1.front()==q2.back())
		{
			ans1[t]='L',ans2[t]='R';
			q1.pop_front(),q2.pop_back();
		}
		else if(q1.size()&&q2.size()&&q1.back()==q2.front())
		{
			ans1[t]='R',ans2[t]='L';
			q1.pop_back(),q2.pop_front();
		}
		else if(q2.size()>1&&q2.front()==q2.back())
		{
			ans1[t]=ans2[t]='R';
			q2.pop_front(),q2.pop_back();
		}
		else return false;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
		if(check_l())
		{
			for(int i=1;i<=n;i++)printf("%c",ans1[i]);
			for(int i=n;i>=1;i--)printf("%c",ans2[i]);
			puts("");
		}
		else if(check_r())
		{
			for(int i=1;i<=n;i++)printf("%c",ans1[i]);
			for(int i=n;i>=1;i--)printf("%c",ans2[i]);		
			puts("");
		}
		else printf("-1\n");
	}
	return 0;
}

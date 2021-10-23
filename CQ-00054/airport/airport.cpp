#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m1,m2,a,b,flor,pos1,pos2,ans;//此前的飞机数
int cnt1[N],cnt2[N],que1[N],que2[N];//到时已有cnt[i]架飞机的飞机数 
struct Node{
	int pos,op,id;
}arr1[2*N],arr2[2*N];
bool cmp(Node x,Node y)
{
	return x.pos < y.pos;
}
set <int> st1,st2;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d %d",&a,&b);
		arr1[++pos1] = {a,1,i};
		arr1[++pos1] = {b,-1,i};//开始结束 
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d %d",&a,&b);
		arr2[++pos2] = {a,1,i};
		arr2[++pos2] = {b,-1,i};
	}
	sort(arr1+1,arr1+pos1+1,cmp);
	sort(arr2+1,arr2+pos2+1,cmp);
	for(int i=0;i<=m1;i++)	st1.insert(i);
	for(int i=0;i<=m2;i++)	st2.insert(i);//i号停机坪就绪 
	for(int i=1;i<=pos1;i++)
	{
		if(arr1[i].op == -1)
			st1.insert(que1[arr1[i].id]);//归还 
		else
		{
			int X = *st1.begin();//最小 
			cnt1[X] ++;
			que1[arr1[i].id] = X;
			st1.erase(st1.begin()); 
		 } 
	}
	for(int i=1;i<=pos2;i++)
	{
		if(arr2[i].op == -1)
			st2.insert(que2[arr2[i].id]);
		else
		{
			int X = *st2.begin();
			cnt2[X]++;
			que2[arr2[i].id] = X;
			st2.erase(st2.begin()); 
		 } 
	 } 
	for(int i=m1;i>=0;i--)
		cnt1[i] += cnt1[i+1];//求后缀
	for(int i=m2;i>=0;i--)
		cnt2[i] += cnt2[i+1];
	for(int i=0;i<=n;i++)//i架国内部 
		ans = max(ans,m1 + m2 - cnt1[i] - cnt2[n-i]);//总数-停不了的
	printf("%d",ans); 
	return 0;
}
/*
	十年OI一场空，图论DP高精度
	题虽简单需看清，一二爆零泪沾襟
	rp++;
	
*/ 
